const tst_ReadBatteryParameters ReadBatteryParameters_st[MAX_BATTERY_PARAMETERS] =
{
    {&ReadTemperatureFromSensor, &ProcessTemperatureValue, &PrintInJSONFormat},
    {&ReadVoltage, &ProcessVoltage, &PrintInJSONFormat}
};

char BatteryParametersJSONString[MAX_BATTERY_PARAMETERS][50] =
{"Temperature : ","Voltage : \n"};


