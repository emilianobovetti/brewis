<?php

if ( ! function_exists('config_path'))
{
    /**
     * Get the configuration path.
     *
     * @param  string $path
     * @return string
     */
    function config_path($path = '')
    {
        return app()->basePath() . '/config' . ($path ? '/' . $path : $path);
    }
}

if ( ! function_exists('asset'))
{
    /**
     * Generate an asset path for the application.
     *
     * @param  string  $path
     * @param  bool    $secure
     * @return string
     */
    function asset($path, $secure = null)
    {
        return app('url')->asset($path, $secure);
    }
}

if ( ! function_exists('base_url'))
{
    /**
     * Generate application's base url
     * with trailing 'index.php/'
     *
     * @return base url
     */
    function base_url()
    {
        return strrpos($url = app('url')->to('/') . '/', 'index.php', -1) ? $url : $url . 'index.php/';
    }
}
