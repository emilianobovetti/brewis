(function (window) {
    'use strict';

    function show(measurements) {
        var options =  {
                width: '100%',
                height: '400px',
                showArea: false,
                showLine: true,
                showPoint: false,
                axisX: {
                    type: Chartist.FixedScaleAxis,
                    showLabel: true,
                    showGrid: false,
                    divisor: 5,
                    labelInterpolationFnc: function(value) {
                        return moment(value).format('MMM D, H:mm');
                    }
                },
            },

            data = measurements.map(function (element) {
                return { x: new Date(element.timestamp), y: element.temperature };
            }),

            chart = new Chartist.Line('.ct-chart', {
                series: [
                    { name: 'temperature', data }
                ]
            }, options);
    }

    GLOBALS.session.get('measurements/all').onComplete(function (xhr) {
        try {
            show(JSON.parse(xhr.responseText));
        } catch (e) {}
    });

})(window);
