<?php

/*
|--------------------------------------------------------------------------
|$routerlication Routes
|--------------------------------------------------------------------------
|
| Here is where you can register all of the routes for an$routerlication.
| It is a breeze. Simply tell Lumen the URIs it should respond to
| and give it the Closure to call when that URI is requested.
|
*/

$router->get('/', function () use ($router) {
    return view('index');
});

$router->get('manage', function () use ($router) {
    return view('manage');
});

/*
 * Authentication routes
 */
$router->post('authenticate', 'AuthenticationController@postAuthenticate');

$router->get('token/refresh', ['middleware' => 'jwt.refresh', function () {}]);

/*
 * User routes
 */
$router->get('user', 'UserController@getIndex');

$router->post('user/create', 'UserController@postUserCreate');

$router->post('user/delete', 'UserController@postUserDelete');

/*
 * Measurements route
 */
$router->get('measurements/latest', 'MeasurementController@getLatestMeasurements');

$router->get('measurements/all', 'MeasurementController@getAllMeasurements');

$router->post('measurements/upload', 'MeasurementController@postUploadMeasurements');

/*
 * Commands routes
 */
$router->get('command/dequeue', 'CommandController@getDequeueCommand');

$router->post('command/enqueue', 'CommandController@postEnqueueCommand');

$router->get('command/latest', 'CommandController@getRetrieveLatestResponse');

$router->post('command/response', 'CommandController@postUploadLatestResponse');

/*
 * Long polling routes
 */
$router->get('longpolling/measurements/latest', 'LongPollingController@getLatestMeasurements');

$router->post('longpolling/command/enqueue', 'LongPollingController@postEnqueueCommand');

$router->get('longpolling/command/dequeue', 'LongPollingController@getDequeueCommand');
