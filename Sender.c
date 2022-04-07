#include <stdio.h>
#include "Config_Sender.h"
#include "Sender.h"

int ReadAndSendBatteryParameters(void)
{
  int batteryParameterIndex = 0;
  int functionExecutionStatus = 0;
  float sensorValue,processedSensorValue;
  for(batteryParameterIndex = 0; batteryParameterIndex < MAX_BATTERY_PARAMETERS; batteryParameterIndex++)
  {
    functionExecutionStatus = 0;
    if((ReadBatteryParameters_st + batteryParameterIndex)->ReadSensorFunc_fp != NULL)
    {
       sensorValue = (ReadBatteryParameters_st + batteryParameterIndex)->ReadSensorFunc_fp();
       processedSensorValue = (ReadBatteryParameters_st + batteryParameterIndex)->ProcessSensorValue_fp(sensorValue);
       functionExecutionStatus = (ReadBatteryParameters_st + batteryParameterIndex)->PrintInConsole_fp(batteryParameterIndex, processedSensorValue);     
    }
  }
  return functionExecutionStatus;
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

int PrintInJSONFormat(int batteryParameter, float processedSensorValue)
{
   printf("%s %.1f\n", BatteryParametersJSONString[batteryParameter] , processedSensorValue);
   return 1;
}
