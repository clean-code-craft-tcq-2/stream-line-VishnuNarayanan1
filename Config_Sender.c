const tst_ReadBatteryParameters ReadBatteryParameters_st[MAX_BATTERY_PARAMETERS] =
{
    {&ReadTemperatureFromSensor, &ProcessTemperatureValue, &PrintInJSONFormat},
    {&ReadChargeRateFromSensor, &ProcessChargeRate, &PrintInJSONFormat}
};

char BatteryParametersJSONString[MAX_BATTERY_PARAMETERS][50] =
{"Temperature : ","ChargeRate : "};


