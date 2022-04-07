#include <stdio.h>
#include "Config_Sender.h"
#include "Sender.h"

void ReadAndSendBatteryParameters(void)
{
  int loopIndex = 0;
  float loadSensorOutput;
  for(loopIndex = 0; loopIndex < MAX_BATTERY_PARAMETERS; loopIndex++)
  {
    if((ReadBatteryParameters_st + loopIndex)->SensorReadFunc_fp != NULL)
    {
       sensorValue = (ReadBatteryParameters_st + loopIndex)->SensorReadFunc_fp();
       processedSensorValue = (ReadBatteryParameters_st + loopIndex)->ProcessSensorValue_fp(sensorValue);
       (ReadBatteryParameters_st + loopIndex)->PrintInConsole_fp(loopIndex, processedSensorValue);     
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
   printf("%s %.1f", BatteryParametersJSONString[batteryParameter] , processedSensorValue);
}
