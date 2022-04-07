#include <Config_Sender.h>

void Interpret()
{
  int loopIndex = 0;
  float loadSensorOutput[50];
  for(loopIndex = 0; loopIndex < MAX_BATTERY_PARAMETERS; loopIndex++)
  {
    if((BatteryParameters_st + loopIndex)->SensorReadFunc_fp != NULL)
    {
       (BatteryParameters_st + loopIndex)->SensorReadFunc_fp(loadSensorOutput);
       (BatteryParameters_st + loopIndex)->ProcessSensorValue_fp(loadSensorOutput);
       (BatteryParameters_st + loopIndex)->PrintProcessedSensorValue_fp(loadSensorOutput);     
    }
  }
}
