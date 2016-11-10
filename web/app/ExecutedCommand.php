<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class ExecutedCommand extends Model
{
    /**
     * The database table used by the model.
     *
     * @var string
     */
    protected $table = 'executed_commands';

    /**
     * The attributes that are mass assignable.
     *
     * @var array
     */
    protected $fillable = ['command', 'response'];

    /**
     * Indicates if the model should be timestamped.
     *
     * @var bool
     */
    public $timestamps = false;

    public static function latest()
    {
        $result = self::query()
            ->orderBy('timestamp', 'desc')
            ->take(1)
            ->get();

        if ($result->isEmpty())
        {
            return null;
        }
        else
        {
            return $result[0];
        }
    }
}
