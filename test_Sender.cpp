#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "Config_Sender.h"
#include "Sender.h"

// Simulated values of temperature 

float SimulatedTemperatureValue [DATA_STREAM_SIZE] = 
{24.1,24.3,25,24.9,79,24,24.7,25,25.6,26.9,
 27.1,28,29.4,31.1,32.5,33.7,34,100,35,35.3,
 0,-1.5,-4,-5.9,-20,-7,-3.9,1,2,3,
 4,5.1,6.2,7.3,7.4,7.5,8.9,9.9,10.9,11.1,
 12,13.4,0,100,-100,0,-10.1,50.1,50,-10};
										 
float SimulatedVoltageValue [DATA_STREAM_SIZE] = 
{2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,
 3.5,3.6,3.7,3.8,3.9,4.0,15.1,12,12.1,10,
 10.1,10.2,10.3,10.4,10.5,10.6,10.7,10.8,10.9,11.0,
 2.4,2.3,7.0,7.1,7.2,7.3,7.4,7.5,7.6,7.7,
 1.0,9.0,9.1,9.7,10.2,15.1,12.2,12.0,10,5};


TEST_CASE("Check battery parameters read , process and print cycle") 
{
	int sensorValuesIndex;
	int functionExecutionStatus = 0;
	for(sensorValuesIndex = 0; sensorValuesIndex < DATA_STREAM_SIZE; sensorValuesIndex++)
	{
		TemperatureValue = SimulatedTemperatureValue[sensorValuesIndex];
		VoltageValue = SimulatedVoltageValue[sensorValuesIndex];
		functionExecutionStatus = ReadAndSendBatteryParameters();
		REQUIRE(functionExecutionStatus == 1);
	}
}

TEST_CASE("Temperature within the permissibl range - Expected processed temperature is equal to sensed temperature + offset") 
{
	float processedTemperatureValue;
	float sensorTemperatureValue = 25.5;
	processedTemperatureValue = ProcessTemperatureValue(sensorTemperatureValue);
	REQUIRE(processedTemperatureValue == (sensorTemperatureValue + TEMPERATURE_OFFSET ));
}

TEST_CASE("Temperature out of the range - Expected processed temperature is equal to INVALID_TEMPERTURE") 
{
	float processedTemperatureValue;
	float sensorTemperatureValue = -10.1;
	processedTemperatureValue = ProcessTemperatureValue(sensorTemperatureValue);
	REQUIRE(processedTemperatureValue == INVALID_TEMPERATURE );
	sensorTemperatureValue = 50.1;
	processedTemperatureValue = ProcessTemperatureValue(sensorTemperatureValue);
	REQUIRE(processedTemperatureValue == INVALID_TEMPERATURE );
}

TEST_CASE("Voltage within the permissible range - Expected processed voltage value is equal to sensed voltage") 
{
	float processedVoltageValue;
	float sensorVoltageValue = 10;
	processedVoltageValue = ProcessVoltage (sensorVoltageValue);
	REQUIRE(processedVoltageValue == sensorVoltageValue);
}

TEST_CASE("Voltage out of the range - Expected processed Voltage is equal to INVALID_VOLTAGE") 
{
	float processedVoltageValue;
	float sensorVoltageValue = 2.4;
	processedVoltageValue = ProcessVoltage(sensorVoltageValue);
	REQUIRE(processedVoltageValue == INVALID_VOLTAGE );
	sensorVoltageValue = 12.1;
	processedVoltageValue = ProcessVoltage(sensorVoltageValue);
	REQUIRE(processedVoltageValue == INVALID_VOLTAGE );
}
