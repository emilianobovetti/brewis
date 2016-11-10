@extends('app')

@section('title') Homebrew @endsection

@section('description') TODO @endsection

@section('content')

        <!-- Example row of columns -->
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

        <hr>

@endsection
