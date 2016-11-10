<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Database\Eloquent\ModelNotFoundException;
use Tymon\JWTAuth\Facades\JWTAuth;
use App\User;
use App\Http\Controllers\BaseController;

class UserController extends BaseController
{
    public function __construct()
    {
        $this->middleware('jwt.auth');
    }

    public function getIndex()
    {
        $user = JWTAuth::parseToken()->toUser();

        return response()->json($user);
    }

    public function postUserCreate(Request $request)
    {
        $input = $request->only('name', 'password');

        $this->validate($request, [
            'name'     => 'required|unique:users,name|max:255',
            'password' => 'required|min:4',
        ]);

        $user = new User;
        $user->name = trim($input['name']);
        $user->hashPassword($input['password']);

        if ($user->save())
        {
            return response()->json(['success' => 'User \'' . $user->name . '\' created successfully']);
        }
        else
        {
            return $this->internalServerErrorJsonResponse('Unable to create user');
        }
    }

    public function postUserDelete(Request $request)
    {
        $input = $request->only('name');

        try
        {
            $name = trim($input['name']);
            $user = User::byName($name);
        }
        catch (ModelNotFoundException $e)
        {
            return response()->json(['error' => 'Unknown user \'' . $name . '\''], 400);
        }

        if ($user->delete())
        {
            return response()->json(['success' => 'User \'' . $user->name . '\' deleted successfully']);
        }
        else
        {
            return $this->internalServerErrorJsonResponse('Unable to delete user');
        }
    }
}
