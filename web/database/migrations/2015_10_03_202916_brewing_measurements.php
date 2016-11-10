<?php

use Illuminate\Database\Schema\Blueprint;
use Illuminate\Database\Migrations\Migration;

class BrewingMeasurements extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('brewing_measurements', function(Blueprint $table)
        {
            $table->increments('id');
            $table->decimal('temperature', 5, 2)
                ->nullable();
            $table->decimal('density', 6, 2)
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
        Schema::drop('brewing_measurements');
    }
}
