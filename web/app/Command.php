<?php

namespace App;

use App\CommandKey;
use App\Exceptions\CommandParserException;
use Illuminate\Support\Facades\Config;

class Command
{
    private static $PARAMETERS_LENGTH;
    private static $COMMAND_TERMINATOR;
    private static $COMMAND_FIELD_SEPARATOR;

    /**
     * Command key
     *
     * @var int
     */
    private $key;

    /**
     * Command parameters
     *
     * @var int[]
     */
    private $parameters;

    public static function init()
    {
        self::$PARAMETERS_LENGTH       = Config::get('arduino.max_command_parameters');
        self::$COMMAND_TERMINATOR      = Config::get('arduino.command_terminator');
        self::$COMMAND_FIELD_SEPARATOR = Config::get('arduino.command_field_separator');
    }

    private static function valid($token)
    {
        return ctype_digit($token) || (is_int($token) && $token >= 0);
    }

    public function __construct($commandArray)
    {
        if ( ! is_array($commandArray))
        {
            throw new CommandParserException('Invalid command: array expected, ' . gettype($commandArray) . ' found');
        }

        $key = array_shift($commandArray);
        $parameters = $commandArray;

        // command key must not be empty
        if ( ! $key)
        {
            throw new CommandParserException('Command key must not be empty');
        }

        // command key must contains only numbers
        if ( ! self::valid($key))
        {
            throw new CommandParserException('"' . $key . '" is not a valid command key value');
        }

        $this->key = $key;

        // GET commands don't have parameters
        if ($parameters === null)
        {
            return;
        }

        if ( ! is_array($parameters))
        {
            throw new CommandParserException('"parameters" must be an array. ' + $parameters);
        }

        // all parameters must contain only numbers
        if ( ! array_reduce($parameters, function($acc, $item) { return $acc && self::valid($item); }, true))
        {
            throw new CommandParserException('Command parameters must be numeric');
        }

        // parameters must be at most 'arduino.max_command_parameters'
        if (count($parameters) > self::$PARAMETERS_LENGTH)
        {
            throw new CommandParserException('Command parameters must be at most ' . self::$PARAMETERS_LENGTH);
        }

        $this->parameters = $parameters;
    }

    public function __toString()
    {
        $str = $this->key;

        if ( ! empty($this->parameters))
        {
            $str .= self::$COMMAND_FIELD_SEPARATOR;
            $str .= implode(self::$COMMAND_FIELD_SEPARATOR, $this->parameters);
        }

        $str .= self::$COMMAND_TERMINATOR;

        return $str;
    }
}

Command::init();
