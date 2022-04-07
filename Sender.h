void ReadAndSendBatteryParameters(void);
float ReadTemperatureFromSensor(void);
float ReadVoltage(void);
float ProcessTemperatureValue (float sensorValue);
float ProcessVoltage (float voltageValue);
int PrintInJSONFormat(int batteryParameter, float processedSensorValue);
