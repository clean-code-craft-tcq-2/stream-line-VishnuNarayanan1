int ReadAndSendBatteryParameters(void);
float ReadTemperatureFromSensor(void);
float ReadVoltage(void);
float ProcessTemperatureValue (float sensorValue);
float ProcessVoltage (float voltageValue);
int PrintInJSONFormat(int batteryTempParameter , int batteryvoltageParameter, float processedSensorValue, float processedSensorValue1);
