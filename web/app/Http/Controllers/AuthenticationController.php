<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Http\Response;
use Illuminate\Http\Exception\HttpResponseException;
use Tymon\JWTAuth\Facades\JWTAuth;
use Tymon\JWTAuth\Exceptions\JWTException;
use App\Http\Controllers\BaseController;

class AuthenticationController extends BaseController
{
    public function getAuthenticate()
    {
        //
    }

    public function postAuthenticate(Request $request)
    {
        try
        {
            $this->validate($request, [
                'name'     => 'required|max:255',
                'password' => 'required',
            ]);
        }
        catch (HttpResponseException $e)
        {
            return response()->json(['error' => 'invalid_authentication'], 400);
        }

        $credentials = $request->only('name', 'password');

        try
        {
            // attempt to verify the credentials
            // and create a token for the user
            if ( ! $token = JWTAuth::attempt($credentials))
            {
                return response()->json(['error' => 'invalid_credentials'], 401);
            }
        }
        catch (JWTException $e)
        {
            // something went wrong whilst attempting
            // to encode the token
            return response()->json(['error' => 'could_not_create_token'], 500);
        }

        // all good so return the token
        return response()->json(compact('token'));
    }
}
