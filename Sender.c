#include <Config_Sender.h>

void Interpret()
{
  int loopIndex = 0;
  float loadSensorOutput;
  for(loopIndex = 0; loopIndex < MAX_BATTERY_PARAMETERS; loopIndex++)
  {
    if((BatteryParameters_st + loopIndex)->SensorReadFunc_fp != NULL)
    {
       sensorValue = (BatteryParameters_st + loopIndex)->SensorReadFunc_fp();
       processedSensorValue = (BatteryParameters_st + loopIndex)->ProcessSensorValue_fp(sensorValue);
       (BatteryParameters_st + loopIndex)->PrintInConsole_fp(loopIndex, processedSensorValue);     
    }
  }
}

float ReadTemperatureFromSensor(void)
{
   return TemperatureValue;
}

float ReadVoltage(void)
{
   return VoltageValue;
}

float ProcessTemperatureValue (float sensorValue)
{
  if(sensorValue > MIN_TEMP_LIMIT && sensorValue < MAX_TEMP_LIMIT)
    return (sensorValue + TEMPERATURE_OFFSET);
  else
    return INVALID_TEMPERATURE;
}

float ProcessVoltage (float voltageValue)
{
  if(voltageValue > MIN_VOLTAGE_LIMIT && voltageValue < MAX_VOLTAGE_LIMIT)
    return voltageValue;
  else
    return INVALID_VOLTAGE;
}

void PrintInJSONFormat(int batteryParameter, float processedSensorValue)
{
   printf("%x %.1f", BatteryParametersJSONString[batteryParameter] , processedSensorValue);
}
