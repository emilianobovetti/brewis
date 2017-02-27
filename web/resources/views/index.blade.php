@extends('app')

@section('title') Homebrew @endsection

@section('description') TODO @endsection

@section('css')
    <link media="all" type="text/css" rel="stylesheet" href="{{ asset('node_modules/chartist/dist/chartist.min.css') }}" />
@endsection

@section('content')

        <div class="row">
          <div class="col-xs-12">
            <div class="ct-chart"></div>
          </div>
        </div>

        <div class="row">
          <div class="col-md-4">
            <h2>Latest Measurements</h2>
            <p id="latest-measurements"></p>
            <p>
              <a type="button" class="btn btn-primary" id="update-measurements">Update &raquo;</a>
            </p>
          </div>
          <div class="col-md-4">
            <h2>Command Execution</h2>
            <form id="command-execution">
              <div class="form-group">
                <input type="text" class="form-control" id="input-command">
              </div>
              <button type="submit" class="btn btn-default">Send to Arduino</button>
            </form>
            <p id="command-result"></p>
         </div>
        </div>

@endsection

@section('script')

    <script type="text/javascript" src="{{ asset('node_modules/moment/min/moment.min.js') }}"></script>
    <script type="text/javascript" src="{{ asset('node_modules/chartist/dist/chartist.min.js') }}"></script>
    <script type="text/javascript" src="{{ asset('js/chart.js') }}"></script>

    <script type="text/javascript">
      (function (window) {
          // update measurements
          DOM.get('update-measurements').addEventListener('click', function(event) {
              event.preventDefault();

              GLOBALS.session
                  .get('measurements/latest')
                  .onComplete(function (xhr) {
                      DOM.get('latest-measurements').innerHTML = xhr.responseText.replace(/,/g, ', ');
                  });
          });

          // command-execution
          DOM.get('command-execution').onsubmit = function (event) {
              var payload = {};

              event.preventDefault();

              payload.command = DOM.get('input-command').value.split(',');

              GLOBALS.longPollingSession.post('longpolling/command/enqueue', payload)
                  .onComplete(function (xhr) {
                      DOM.get('command-result').innerHTML = xhr.responseText.replace(/,/g, ', ');
                  });
          };
      })(window);
    </script>

@endsection
