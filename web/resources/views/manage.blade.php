@extends('app')

@section('title') Managing system @endsection

@section('description') TODO @endsection

@section('content')

        <div class="row">
          <div class="col-md-4">
            <h2>Create User</h2>
            <form id="create-user">
              <div class="form-group">
                <label for="new-user-name">Name</label>
                <input type="text" class="form-control" id="new-user-name">
                <label for="new-user-password">Password</label>
                <input type="password" class="form-control" id="new-user-password">
              </div>
              <button type="submit" class="btn btn-default">Create</button>
            </form>
            <p id="user-creation-result"></p>
          </div>
        </div>

        <div class="row">
          <div class="col-md-4">
            <h2>Delete User</h2>
            <form id="delete-user">
              <div class="form-group">
                <label for="delete-user-name">Name</label>
                <input type="text" class="form-control" id="delete-user-name">
              </div>
              <button type="submit" class="btn btn-default">Delete</button>
            </form>
            <p id="user-deletion-result"></p>
          </div>
        </div>

@endsection

@section('script')

    <script type="text/javascript">
      (function (window) {
        // create-user
        DOM.get('create-user').onsubmit = function (event) {
            var payload = {};

            event.preventDefault();

            payload.name = DOM.get('new-user-name').value.trim();
            payload.password = DOM.get('new-user-password').value;

            GLOBALS.session.post('user/create', payload)
                .onComplete(function (xhr) {
                    DOM.get('user-creation-result').innerHTML = xhr.responseText.replace(/,/g, ', ');
                });
        };

        // delete-user
        DOM.get('delete-user').onsubmit = function (event) {
            var payload = {};

            event.preventDefault();

            payload.name = DOM.get('delete-user-name').value.trim();

            GLOBALS.session.post('user/delete', payload)
                .onComplete(function (xhr) {
                    DOM.get('user-deletion-result').innerHTML = xhr.responseText.replace(/,/g, ', ');
                });
        };
      })(window);
    </script>

@endsection

