var DOM = (function (document, window) {
    'use strict';
    var _DOM = DOM || {};

    _DOM.get = function (id) {
        return document.getElementById(id);
    };

    _DOM.show = function (id, forMillis) {
        _DOM.get(id).classList.remove('hide');

        if (forMillis) {
            window.setTimeout(function () {
                _DOM.hide(id);
            }, forMillis);
        }
    };

    _DOM.hide = function (id, forMillis) {
        _DOM.get(id).classList.add('hide');

        if (forMillis) {
            window.setTimeout(function () {
                _DOM.show(id);
            }, forMillis);
        }
    };

    return _DOM;
})(document, window),

GLOBALS = (function () {
    'use strict';
    var _GLOBALS = GLOBALS || {};

    _GLOBALS.session = JWT_SESSIONS.create(GLOBALS.baseUrl);
    _GLOBALS.longPollingSession = _GLOBALS.session.fork();

    _GLOBALS.startAutoRefresh = function () {
        // refresh session token every every half hour
        _GLOBALS.session.autoRefresh.start('token/refresh', 30 * 60 * 1000, function () {
            COOKIES.set('token', _GLOBALS.session.getToken());
        });
    };

    _GLOBALS.stopAutoRefresh = function () {
        _GLOBALS.session.autoRefresh.stop();
    };

    return _GLOBALS;
})();

(function (window) {
    'use strict';

    function onAuthentication() {
        GLOBALS.startAutoRefresh();
        GLOBALS.longPollingSession = GLOBALS.session.fork();
        COOKIES.set('token', GLOBALS.session.getToken());

        updateLatestMeasurements();
    }

    // update last measurements
    function updateLatestMeasurements () {
        GLOBALS.session
            .get('measurements/latest')
            .onComplete(function (xhr) {
                DOM.get('latest-measurements').innerHTML = xhr.responseText.replace(/,/g, ', ');
            });
    }

    DOM.get('update-measurements').addEventListener('click', function(event) {
        event.preventDefault();

        updateLatestMeasurements();
    });

    // if the token is present in cookie
    // try to refresh it
    if (COOKIES.get('token')) {
        GLOBALS.session
            .refresh('token/refresh', COOKIES.get('token'))
            .onSuccess(function () {
                DOM.show('session-refreshed', 5000);

                onAuthentication();
            })
            .onError(function (xhr) {
                DOM.show('session-expired', 5000);
                COOKIES.remove('token');
            });
    }

    // login-form
    DOM.get('login-form').onsubmit = function (event) {
        var credentials = {};

        event.preventDefault();

        credentials.name = DOM.get('login-name').value.trim();
        credentials.password = DOM.get('login-password').value;

        GLOBALS.session = JWT_SESSIONS
            .create(GLOBALS.baseUrl, credentials)
            .authenticate('authenticate')
            .onSuccess(function () {
                DOM.hide('login-error');
                DOM.show('login-success', 5000);

                onAuthentication();
            })
            .onError(function () {
                DOM.hide('login-success');
                DOM.show('login-error', 5000);
                COOKIES.remove('token');
            });
    };

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
