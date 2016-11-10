<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />

    <title>@yield('title')</title>
    <meta name="description" content="@yield('description')" />
    <!-- CSS -->
    @section('css')
      <link media="all" type="text/css" rel="stylesheet" href="{{ asset('css/app.css') }}" />
      <link media="all" type="text/css" rel="stylesheet" href="{{ asset('bootstrap-3.3.5-dist/css/bootstrap.min.css') }}" />
    @show
    <!-- end CSS -->

    <script type="text/javascript">
        var GLOBALS = (function () {
            'use strict';
            var _GLOBALS = GLOBALS || {};

            _GLOBALS.baseUrl = '{{ base_url() }}';

            return _GLOBALS;
        })();
    </script>
  </head>

  <body>

    <nav class="navbar navbar-inverse navbar-fixed-top">
      <div class="container">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a href="{{ url('/') }}" class="navbar-brand">Homebrew</a>
        </div>
        <div id="navbar" class="navbar-collapse collapse">
          <form class="navbar-form navbar-right" id="login-form">
            <div class="form-group">
              <input type="text" placeholder="Name" class="form-control" id="login-name" />
            </div>
            <div class="form-group">
              <input type="password" placeholder="Password" class="form-control" id="login-password" />
            </div>
            <button type="submit" class="btn btn-success">Sign in</button>
          </form>
        </div>
      </div>
    </nav>

    <div class="jumbotron">
      <div class="container">
        <div class="row">
          <div class="col-md-8">
            <h1>Hello, world!</h1>
            <p>
              This is the awesome homebrewing system made by Emiliano Bovetti.
            </p>
          </div>
          <div class="col-xs-4 dialog-box">
            <p class="bg-success hide" id="login-success">Login successfull</p>
            <p class="bg-danger hide" id="login-error">Login error</p>
            <p class="bg-info hide" id="session-refreshed">Session refreshed</p>
            <p class="bg-danger hide" id="session-expired">Session expired</p>
          </div>
        </div>
      </div>
    </div>

    <div class="container">

    <!-- page content -->
    @yield('content')
    <!-- end page content -->

      <footer>
        <p>&copy; Emiliano Bovetti 2015</p>
      </footer>
    </div> <!-- /container -->

    <script type="text/javascript" src="{{ asset('js/jwt_sessions.js') }}"></script>
    <script type="text/javascript" src="{{ asset('js/cookies.js') }}"></script>
    <script type="text/javascript" src="{{ asset('js/app.js') }}"></script>

    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
    <!-- getbootstrap js -->
    <script type="text/javascript" src="{{ asset('bootstrap-3.3.5-dist/js/bootstrap.min.js') }}"></script>
  </body>
</html>
