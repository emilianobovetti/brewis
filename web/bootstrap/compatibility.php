<?php

require_once __DIR__.'/PasswordHashingLib/passwordLib.php';

if ( ! function_exists('env'))
{
    function env($key, $default = null)
    {
        if (isset($_ENV[$key]))
        {
            $value = $_ENV[$key];
        }
        else
        {
            return value($default);
        }

        switch (strtolower($value))
        {
            case 'true':
            case '(true)':
                return true;

            case 'false':
            case '(false)':
                return false;

            case 'empty':
            case '(empty)':
                return '';

            case 'null':
            case '(null)':
                return;
        }

        if (preg_match('/^"[^"]+"$/', $value))
        {
            return substr($value, 1, -1);
        }
        else
        {
            return $value;
        }
    }
}
