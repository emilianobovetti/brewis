<?php

namespace App\Http\Controllers;

use App\Command;
use App\CommandQueue;
use App\ExecutedCommand;
use App\Exceptions\CommandParserException;
use App\Http\Controllers\BaseController;
use Illuminate\Http\Request;

class CommandController extends BaseController
{
    public function __construct()
    {
        $this->middleware('jwt.auth');
    }

    // use LongPollingController@getDequeueCommand instead
    public function getDequeueCommand()
    {
        $result = CommandQueue::dequeue();

        if ($result === null)
        {
            return response()->json(['commands' => 'empty']);
        }
        else
        {
            return response()->json($result);
        }
    }

    public function postEnqueueCommand(Request $request)
    {
        $input = $request->only(['command']);

        try
        {
            $success = CommandQueue::enqueue($input['command']);
        }
        catch (CommandParserException $e)
        {
            return $this->unableToParseJsonResponse($e->getMessage());
        }

        if ($success)
        {
            return response()->json(['message' => 'command_enqueued_successfully']);
        }
        else
        {
            return $this->internalServerErrorJsonResponse('Unable to enqueue command correctly');
        }
    }

    public function getRetrieveLatestResponse()
    {
        $result = ExecutedCommand::latest();

        if ($result === null)
        {
            return response()->json(['responses' => 'empty']);
        }
        else
        {
            return response()->json($result);
        }
    }

    public function postUploadLatestResponse(Request $request)
    {
        $input = $request->input('response');

        $ec = ExecutedCommand::latest();
        $ec->response = $input;

        if ($ec->save())
        {
            return response()->json(['message' => 'reponse_uploaded_successfully']);
        }
        else
        {
            return $this->internalServerErrorJsonResponse('Unable to upload response');
        }
    }
}
