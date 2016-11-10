<?php

namespace App;

use App\Command;
use App\ExecutedCommand;
use Illuminate\Database\Eloquent\Model;

class CommandQueue extends Model
{
    /**
     * The database table used by the model.
     *
     * @var string
     */
    protected $table = 'commands_queue';

    /**
     * The attributes that are mass assignable.
     *
     * @var array
     */
    protected $fillable = ['command'];

    /**
     * Indicates if the model should be timestamped.
     *
     * @var bool
     */
    public $timestamps = false;

    public static function enqueue($command)
    {
        $model = new self;
        $model->setCommand(new Command($command));
        return $model->save();
    }

    public static function dequeue()
    {
        $result = self::query()
            ->orderBy('timestamp', 'asc')
            ->take(1)
            ->get();

        if ($result->isEmpty())
        {
            return null;
        }
        else
        {
            $result = $result[0];

            // save executed command
            $executed = new ExecutedCommand;
            $executed->command = $result->command;
            $executed->save();

            // delete queued command from queue
            $result->delete();
            return $result;
        }
    }

    public function setCommand(Command $cmd)
    {
        $this->command = $cmd->__toString();
    }
}
