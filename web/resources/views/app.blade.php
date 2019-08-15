<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />

    <title>@yield('title')</title>
    <meta name="description" content="@yield('description')" />

    <!-- CSS -->
    <link media="all" type="text/css" rel="stylesheet" href="{{ asset('css/app.css') }}" />
    <link media="all" type="text/css" rel="stylesheet" href="{{ asset('node_modules/bootstrap/dist/css/bootstrap.min.css') }}" />
    @yield('css')
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

    <nav class="navbar navbar-inverse">
      <div class="container">
        <div class="navbar-header">
          <div class="nav">
            <a href="{{ url('/') }}" class="navbar-brand">Home</a>
            <a href="{{ url('manage') }}" class="navbar-link">Manage</a>
          </div>

          <form class="navbar-form navbar-right" id="login-form">

            <div class="dialog-box">
              <span class="bg-success hide" id="login-success">Login successfull</span>
              <span class="bg-danger hide" id="login-error">Login error</span>
              <span class="bg-info hide" id="session-refreshed">Session refreshed</span>
              <span class="bg-danger hide" id="session-expired">Session expired</span>
            </div>

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

    <div class="container">

    <!-- page content -->
    @yield('content')
    <!-- end page content -->

      <hr>

      <footer>
        <p>&copy; Emiliano Bovetti {{ date('Y') }}</p>
      </footer>
    </div>

    <script type="text/javascript" src="{{ asset('js/jwt_sessions.js') }}"></script>
    <script type="text/javascript" src="{{ asset('js/cookies.js') }}"></script>
    <script type="text/javascript" src="{{ asset('js/app.js') }}"></script>

    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script type="text/javascript" src="{{ asset('node_modules/jquery/dist/jquery.min.js') }}"></script>
    <!-- getbootstrap js -->
    <script type="text/javascript" src="{{ asset('node_modules/bootstrap/dist/js/bootstrap.min.js') }}"></script>
    @yield('script')

  </body>
</html>
