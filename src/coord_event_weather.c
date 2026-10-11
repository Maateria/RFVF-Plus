#include "global.h"
#include "coord_event_weather.h"
#include "field_weather_util.h"
#include "constants/weather.h"

// Port of pokeemerald's coord_event_weather.c: a map.json coord event of type "weather"
// holds a COORD_EVENT_WEATHER_* value, and stepping on it changes the weather.
static const u8 sCoordEventWeathers[][2] =
{
    {COORD_EVENT_WEATHER_SUNNY_CLOUDS,      WEATHER_SUNNY_CLOUDS},
    {COORD_EVENT_WEATHER_SUNNY,             WEATHER_SUNNY},
    {COORD_EVENT_WEATHER_RAIN,              WEATHER_RAIN},
    {COORD_EVENT_WEATHER_SNOW,              WEATHER_SNOW},
    {COORD_EVENT_WEATHER_RAIN_THUNDERSTORM, WEATHER_RAIN_THUNDERSTORM},
    {COORD_EVENT_WEATHER_FOG_HORIZONTAL,    WEATHER_FOG_HORIZONTAL},
    {COORD_EVENT_WEATHER_FOG_DIAGONAL,      WEATHER_FOG_DIAGONAL},
    {COORD_EVENT_WEATHER_VOLCANIC_ASH,      WEATHER_VOLCANIC_ASH},
    {COORD_EVENT_WEATHER_SANDSTORM,         WEATHER_SANDSTORM},
    {COORD_EVENT_WEATHER_SHADE,             WEATHER_SHADE},
    {COORD_EVENT_WEATHER_DROUGHT,           WEATHER_DROUGHT},
    {COORD_EVENT_WEATHER_ROUTE119_CYCLE,    WEATHER_ROUTE119_CYCLE},
    {COORD_EVENT_WEATHER_ROUTE123_CYCLE,    WEATHER_ROUTE123_CYCLE},
};

void DoCoordEventWeather(u8 coordEventWeather)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sCoordEventWeathers); i++)
    {
        if (sCoordEventWeathers[i][0] == coordEventWeather)
        {
            SetWeather(sCoordEventWeathers[i][1]);
            return;
        }
    }
}
