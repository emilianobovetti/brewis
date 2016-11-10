<?php

use Illuminate\Support\Facades\Config;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class CommandsQueue extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('commands_queue', function(Blueprint $table)
        {
            $table->engine = 'MEMORY';

            $table->increments('id');
            $table->string('command', Config::get('arduino.max_command_length'));
            $table->timestamp('timestamp')
                ->default(DB::raw('CURRENT_TIMESTAMP'));
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::drop('commands_queue');
    }
}
