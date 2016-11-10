<?php

use Illuminate\Support\Facades\Config;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class ExecutedCommands extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('executed_commands', function(Blueprint $table)
        {
            $table->increments('id');
            $table->string('command', Config::get('arduino.max_command_length'));
            $table->string('response', Config::get('arduino.max_response_length'))
                ->nullable();
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
        Schema::drop('executed_commands');
    }
}
