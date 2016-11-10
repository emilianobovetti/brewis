var REQUESTS = (function () {
    'use strict';
    var _REQUESTS = REQUESTS || {};

    _REQUESTS.create = function (method, url) {
        var self = {
                xhr: new XMLHttpRequest(),
                json: null,
                token: null
            },

            __self = {
                url: url,
                method: method,
                completeQueue: [],
                successQueue: [],
                errorQueue: []
            };

        self.sendJson = function (json) {
            switch (typeof json) {
                case 'object':
                    self.json = JSON.stringify(json);
                    break;
                case 'string':
                    self.json = json;
                    break;
                default:
                    throw 'Invalid json payload: ' + json;
            }

            return self;
        };

        self.jwt = function (token) {
            self.token = token;

            return self;
        };

        self.send = function () {
            if (self.token !== null) {
                __self.url = __self.url + '?token=' + self.token;
            }

            self.xhr.open(__self.method, __self.url);
            self.xhr.setRequestHeader('Accept', 'application/json');
            self.xhr.setRequestHeader('Content-Type', 'application/json; charset=UTF-8');
            self.xhr.send(self.json);

            return self;
        };

        self.onComplete = function (callback) {
            __self.completeQueue.push(callback);

            return self;
        };

        self.onSuccess = function (callback) {
            __self.successQueue.push(callback);

            return self;
        };

        self.onError = function (callback) {
            __self.errorQueue.push(callback);

            return self;
        };

        self.xhr.onreadystatechange = function () {
            // if request is complete
            if (self.xhr.readyState === self.xhr.DONE) {
                if (self.xhr.status === 200) {
                    // request successfull
                    // call onSuccess callbacks
                    __self.successQueue.forEach(function (callback) {
                        callback(self.xhr);
                    });
                } else {
                    // request not successfull, status != 200
                    // call onError callbacks
                    __self.errorQueue.forEach(function (callback) {
                        callback(self.xhr);
                    });
                }

                // call onComplete callbacks
                __self.completeQueue.forEach(function (callback) {
                    callback(self.xhr);
                });
            }
        };

        return self;
    }

    _REQUESTS.get = function (url) {
        return _REQUESTS.create('GET', url);
    };

    _REQUESTS.post = function (url) {
        return _REQUESTS.create('POST', url);
    };

    return _REQUESTS;
})(),

JWT_SESSIONS = (function (window) {
    'use strict';
    var _JWT_SESSIONS = JWT_SESSIONS || {};

    _JWT_SESSIONS.create = function (baseUrl, credentials) {
        var self = {
                credentials: credentials,
                baseUrl: baseUrl
            },

            __self = {
                token: null,
                intervalID: null,
                updateTokenQueue: [],
                requestsQueue: []
            };

        __self.lastRequest = function () {
            if (__self.requestsQueue.length === 0) {
                throw 'Empty request queue';
            }

            return __self.requestsQueue[__self.requestsQueue.length - 1];
        };

        __self.enqueueRequest = function (request) {
            if (__self.requestsQueue.length > 0) {
                // when last enqueued request is completed
                // we have to:
                // 1. update current request token
                // 2. send current request
                // 3. delete oldest request from queue
                __self.lastRequest().onComplete(function () {
                    request.jwt(__self.token).send();
                    __self.requestsQueue.splice(0, 1);
                });
            } else {
                // the queue is empty, send the request immediatly
                // when the request is done, delete it from the queue
                request.onComplete(function () {
                    __self.requestsQueue.splice(0, 1);
                }).send();
            }

            __self.requestsQueue.push(request);
        };

        __self.refreshToken = function (xhr) {
            var authorizationHeader = xhr.getResponseHeader('Authorization');

            if (authorizationHeader !== null) {
                self.setToken(authorizationHeader.replace('Bearer ', ''));
            }
        };

        self.getToken = function () {
            return __self.token;
        };

        self.setToken = function (token) {
            __self.token = token;

            __self.updateTokenQueue.forEach(function (callback) {
                callback(__self.token);
            });

            return self;
        };

        self.request = function (method, route, json) {
            __self.enqueueRequest(REQUESTS
                .create(method, self.baseUrl + route)
                .jwt(__self.token)
                .sendJson(json)
            );

            return self;
        };

        self.get = function (route) {
            return self.request('GET', route, null);
        };

        self.post = function (route, json) {
            return self.request('POST', route, json);
        };

        self.onComplete = function (callback) {
            __self.lastRequest().onComplete(callback);

            return self;
        };

        self.onSuccess = function (callback) {
            __self.lastRequest().onSuccess(callback);

            return self;
        };

        self.onError = function (callback) {
            __self.lastRequest().onError(callback);

            return self;
        };

        self.onTokenUpdate = function (callback) {
            __self.updateTokenQueue.push(callback);

            return self;
        };

        self.authenticate = function (route) {
            __self.enqueueRequest(REQUESTS
                .post(self.baseUrl + route)
                .sendJson(self.credentials)
                .onSuccess(function (xhr) {
                    self.setToken(JSON.parse(xhr.responseText).token);
                })
            );

            return self;
        };

        self.refresh = function (route, token) {
            if (token) {
                self.setToken(token);
            }

            __self.enqueueRequest(REQUESTS
                .get(self.baseUrl + route)
                .jwt(__self.token)
                .onSuccess(__self.refreshToken)
            );

            return self;
        };

        self.fork = function () {
            var newSession = _JWT_SESSIONS.create(self.baseUrl).setToken(__self.token);

            self.onTokenUpdate(function (newToken) {
                newSession.setToken(newToken);
            });

            delete newSession.refresh;

            return newSession;
        };

        self.autoRefresh = {
            start: function (route, every, onRefresh) {
                if ( ! __self.intervalID) {
                    __self.intervalID = window.setInterval(function () {
                        self.refresh(route)
                            .onSuccess(onRefresh)
                            .onError(function () {
                                self.autoRefresh.stop();
                            });
                    }, every);
                }

                return self;
            },

            stop: function () {
                window.clearInterval(__self.intervalID);
                __self.intervalID = null;

                return self;
            }
        };

        return self;
    };

    return _JWT_SESSIONS;
})(window);
