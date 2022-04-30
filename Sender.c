#include <stdio.h>
#include "Config_Sender.h"
#include "Sender.h"

int ReadAndSendBatteryParameters(void)
{
  int batteryParameterIndex = 0;
  int functionExecutionStatus = 0;
  int functionExecutionStatus1 = 0;
  float sensorValue, sensorValue1,processedSensorValue, processedSensorValue1;
  for(batteryParameterIndex = 0; batteryParameterIndex < MAX_BATTERY_PARAMETERS;)
  {
    functionExecutionStatus = 0;
    if((ReadBatteryParameters_st + batteryParameterIndex)->ReadSensorFunc_fp != NULL)
    {
       sensorValue = (ReadBatteryParameters_st + batteryParameterIndex)->ReadSensorFunc_fp();
	     sensorValue1 = (ReadBatteryParameters_st + (batteryParameterIndex+1))->ReadSensorFunc_fp();
       processedSensorValue = (ReadBatteryParameters_st + batteryParameterIndex)->ProcessSensorValue_fp(sensorValue);
	     processedSensorValue1 = (ReadBatteryParameters_st + batteryParameterIndex+1)->ProcessSensorValue_fp(sensorValue1);
       functionExecutionStatus = (ReadBatteryParameters_st + batteryParameterIndex)->PrintInConsole_fp(batteryParameterIndex, batteryParameterIndex+1, processedSensorValue, processedSensorValue1);
	   
    }
	batteryParameterIndex+=2;
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

int PrintInJSONFormat(int batteryTempParameter,int batteryvoltageParameter, float processedSensorValue, float processedSensorValue1)
{
   printf("%s %.1f\t%s %.1f \n", BatteryParametersJSONString[batteryTempParameter], processedSensorValue,BatteryParametersJSONString[batteryvoltageParameter], processedSensorValue1);
   return 1;
}
