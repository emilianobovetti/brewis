<?php

/*
|--------------------------------------------------------------------------
| Application Routes
|--------------------------------------------------------------------------
|
| Here is where you can register all of the routes for an application.
| It is a breeze. Simply tell Lumen the URIs it should respond to
| and give it the Closure to call when that URI is requested.
|
*/

$app->get('/', function() use ($app)
{
    return view('index');
});

/*
 * Authentication routes
 */
$app->post('authenticate', 'AuthenticationController@postAuthenticate');

$app->get('token/refresh', ['middleware' => 'jwt.refresh', function () {}]);

/*
 * User routes
 */
$app->get('user', 'UserController@getIndex');

$app->post('user/create', 'UserController@postUserCreate');

$app->post('user/delete', 'UserController@postUserDelete');

/*
 * Measurements route
 */
$app->get('measurements/latest', 'MeasurementController@getLatestMeasurements');

$app->post('measurements/upload', 'MeasurementController@postUploadMeasurements');

/*
 * Commands routes
 */
$app->get('command/dequeue', 'CommandController@getDequeueCommand');

$app->post('command/enqueue', 'CommandController@postEnqueueCommand');

$app->get('command/latest', 'CommandController@getRetrieveLatestResponse');

$app->post('command/response', 'CommandController@postUploadLatestResponse');

/*
 * Long polling routes
 */
$app->get('longpolling/measurements/latest', 'LongPollingController@getLatestMeasurements');

$app->post('longpolling/command/enqueue', 'LongPollingController@postEnqueueCommand');

$app->get('longpolling/command/dequeue', 'LongPollingController@getDequeueCommand');
