<?php

namespace App\Http\Controllers;

use Laravel\Lumen\Routing\Controller;

class BaseController extends Controller
{
    protected function unableToParseJsonResponse($description)
    {
        return response()->json([
            'error'       => 'unable_to_parse',
            'description' => $description,
        ], 400);
    }

    protected function internalServerErrorJsonResponse($description)
    {
        return response()->json([
            'error'       => 'internal_server_error',
            'description' => $description,
        ], 500);
    }
}
