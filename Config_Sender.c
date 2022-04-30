#include <stdio.h>
#include "Config_Sender.h"
#include "Sender.h"

const tst_ReadBatteryParameters ReadBatteryParameters_st[MAX_BATTERY_PARAMETERS] =
{
    // Here, based on the interface required functions can be mapped :
    // For e.g. If the temperature/voltage needs to be read from a file, then that function needs to be defined and mapped here.
    // Similarly, if there is a different format expected to be printed, other than JSON, that function needs to be defined and mapped here.
    {&ReadTemperatureFromSensor, &ProcessTemperatureValue, &PrintInJSONFormat, &ReadVoltage, &ProcessVoltage, &PrintInJSONFormat}
};

char BatteryParametersJSONString[MAX_BATTERY_PARAMETERS][50] =
{"Temperature : ","Voltage : "};

// To simulate temperature and voltage value as read from the sensor
float TemperatureValue;
float VoltageValue;


