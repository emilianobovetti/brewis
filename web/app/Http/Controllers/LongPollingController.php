<?php

namespace App\Http\Controllers;

use \Closure;
use Illuminate\Http\Request;
use App\CommandQueue;
use App\ExecutedCommand;
use App\BrewingMeasurement;
use App\Http\Controllers\BaseController;
use App\Exceptions\CommandParserException;

class LongPollingController extends BaseController
{
    public static $longPollingTimeout;

    public static function init()
    {
        self::$longPollingTimeout = intval(ini_get('max_execution_time')) - 2;
    }

    public function __construct()
    {
        $this->middleware('jwt.auth');
    }

    private function serveLongPolling(Closure $getResponse, $timeoutResponse)
    {
        $start = time();

        while (time() - $start < self::$longPollingTimeout)
        {
            $response = $getResponse();

            if ($response !== null)
            {
                return $response;
            }

            sleep(1);
        }

        return $timeoutResponse;
    }

    public function getLatestMeasurements()
    {
        $initial = BrewingMeasurement::latest();

        $getResponse = function () use ($initial)
        {
            $result = BrewingMeasurement::latest();

            if ($result === null)
            {
                return response()->json(['measurements' => 'empty']);
            }
            else if ($initial === null || $result->timestamp !== $initial->timestamp)
            {
                return response()->json($result);
            }
            else
            {
                return null;
            }
        };

        return $this->serveLongPolling($getResponse, response()->json(['measurements' => 'no_new_measurements']));
    }

    public function postEnqueueCommand(Request $request)
    {
        $initial = ExecutedCommand::latest();

        $input = $request->only(['command']);

        try
        {
            $success = CommandQueue::enqueue($input['command']);
        }
        catch (CommandParserException $e)
        {
            return $this->unableToParseJsonResponse($e->getMessage());
        }

        if ( ! $success)
        {
            return $this->internalServerErrorJsonResponse('Unable to enqueue command correctly');
        }

        // Command enqueued successfully, now wait for response
        $getResponse = function () use ($initial)
        {
            $result = ExecutedCommand::latest();

            if ($result && $result->response && ( ! $initial || $result->timestamp !== $initial->timestamp))
            {
                return response()->json($result);
            }
            else
            {
                return null;
            }
        };

        return $this->serveLongPolling($getResponse, response()->json(['response' => 'none']));
    }

    public function getDequeueCommand()
    {
        $getResponse = function ()
        {
            $result = CommandQueue::dequeue();

            if ($result !== null)
            {
                return response()->json($result);
            }
            else
            {
                return null;
            }
        };

        return $this->serveLongPolling($getResponse, response()->json(['commands' => 'empty']));
    }
}

LongPollingController::init();
