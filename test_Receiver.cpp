#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "Receiver/receiver.h"

/* Positive test case */
TEST_CASE("Case for Postive test case :- To read Data from console") 
{
	float temperature[1] = {0};
	float voltage[1] = {0};
	float temperature_ref[1] = {24.9};
	float voltage_ref[1] = {0.0};
    	
	printf(" Temperature: %.2f , Voltage: %.2f ", temperature_ref[0],  voltage_ref[0]);
  readfromConsole(temperature, voltage, 1);
  REQUIRE(temperature[0] - temperature_ref[0] <= 0.001);
  REQUIRE(voltage[0] - voltage_ref[0] <= 0.001);
}

TEST_CASE("Test for finding maximum value") 
{
  float temperature[5]= {1.2, 6.7, 9.0, 7.8, 5.6};
  float max = FindMaxValue(temperature, 5);
  REQUIRE(max == 9.0f);
}

TEST_CASE("Test Case to find maximum and minimum values") 
{
	readfromConsole(temperature, voltage, 50);
	FindMinandMaxValue(temperature, voltage, 50);
}
