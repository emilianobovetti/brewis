<?php

namespace App;

use Illuminate\Database\Eloquent\Model;
use App\Exceptions\BrewingMeasurementException;

class BrewingMeasurement extends Model
{
    /**
     * The database table used by the model.
     *
     * @var string
     */
    protected $table = 'brewing_measurements';

    /**
     * The attributes that are mass assignable.
     *
     * @var array
     */
    protected $fillable = ['temperature', 'density'];

    /**
     * Indicates if the model should be timestamped.
     *
     * @var bool
     */
    public $timestamps = false;

    /**
     * Map measurement - value
     *
     * E.g.
     *  'temp' => 20.1,
     *  'dens' => 1020
     *
     * @var array
     */
    private $measurements = [];

    public static function upload($input)
    {
        $model = new self;
        $model->parseMeasurements($input);
        return $model->save();
    }

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

    private function assignProperty($name, $key)
    {
        if (array_key_exists($key, $this->measurements))
        {
            $this->{$name} = $this->measurements[$key];
        }
    }

    public function parseMeasurements($data)
    {
        // ([^=,\s]+)=([0-9]+\.?[0-9]*) -- no negative numbers
        preg_match_all('/([^=,\s]+)=(-?[0-9]+\.?[0-9]*)/x', $data, $matches);

        $keys = $matches[1];
        $values = $matches[2];

        array_walk($keys, function($key, $index) use ($values)
        {
            $this->measurements[$key] = floatval($values[$index]);
        });

        $this->assignProperty('temperature', 'temp');
        $this->assignProperty('density', 'dens');

        if ($this->temperature === null && $this->density === null)
        {
            throw new BrewingMeasurementException('Unable to parse relevant measurements');
        }
    }
}
