<?php

namespace App\Http\Controllers;

use App\BrewingMeasurement;
use App\Exceptions\BrewingMeasurementException;
use App\Http\Controllers\BaseController;
use Illuminate\Http\Request;

class MeasurementController extends BaseController
{
    public function __construct()
    {
        $this->middleware('jwt.auth');
    }

    public function getLatestMeasurements()
    {
        $result = BrewingMeasurement::latest();

        if ($result === null)
        {
            return response()->json(['measurements' => 'empty']);
        }
        else
        {
            return response()->json($result);
        }
    }

    public function postUploadMeasurements(Request $request)
    {
        $input = $request->input('measurements');

        try
        {
            $success = BrewingMeasurement::upload($input);
        }
        catch (BrewingMeasurementException $e)
        {
            return $this->unableToParseJsonResponse($e->getMessage());
        }

        if ($success)
        {
            return response()->json(['message' => 'measurements_inserted_successfully']);
        }
        else
        {
            return $this->internalServerErrorJsonResponse('Unable to store measurements correctly');
        }
    }
}
