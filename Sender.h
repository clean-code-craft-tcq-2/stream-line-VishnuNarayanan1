void ReadAndSendBatteryParameters(void);
float ReadTemperatureFromSensor(void);
float ReadVoltage(void);
float ProcessTemperatureValue (float sensorValue);
float ProcessVoltage (float voltageValue);
void PrintInJSONFormat(int batteryParameter, float processedSensorValue);
