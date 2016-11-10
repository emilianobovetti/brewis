#include "DensityReader.h"

static Hx711 scale(HX711_DOUT_PIN, HX711_SCK_PIN);

void initializeDensityReader(void)
{
    scale.setScale(7925.159);

    enableDensityReader();
}

void enableDensityReader(void)
{
    setTaskState(&densityReaderTask, RUNNING);
}

void disableDensityReader(void)
{
    setTaskState(&densityReaderTask, NOT_RUNNING);
}


float densityCorrectionFactor(void)
{
    float t = getCurrentTemperature();

    return -9.74615e-13 * pow(t, 7)
        + 3.10341e-10 * pow(t, 6)
        - 4.16775e-08 * pow(t, 5)
        + 3.19793e-06 * pow(t, 4)
        - 0.000169723 * pow(t, 3)
        + 0.0102786 * pow(t, 2)
        - 0.0789893 * t
        - 1.59511;
}

float getScaleGram(void)
{
    return scale.getGram();
}

void readDensity(void)
{
    //                      M S weight                   -  M S weight in liquid
    //                           (g)                             (g)
    float density = (MEASUREMENT_STANDARD_WEIGHT - getScaleGram())
    //  / M S volume                  + temperature correction
    //         (l)
        / MEASUREMENT_STANDARD_VOLUME + densityCorrectionFactor();

    /*
     * If measured density is too low or too high, discard it.
     */
    if (density < 980 || density > MEASUREMENT_STANDARD_DENSITY)
    {
        setCurrentDensity(UNKNOWN_DENSITY);
    }
    else
    {
        setCurrentDensity(density);
    }
}
