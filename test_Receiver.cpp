#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "Receiver/receiver.h"

/* Positive test case */
TEST_CASE("Case for Postive test case :- To read Data from console") 
{
	float current[1] = {0};
	float voltage[1] = {0};
	float current_ref[1] = {29.0};
	float voltage_ref[1] = {2.6};
	printf(" Current: %.2f , Voltage: %.2f ", current_ref[0],  voltage_ref[0]);
  readfromConsole(current, voltage, 1);
  REQUIRE(current[0] - current_ref[0] <= 0.001);
  REQUIRE(voltage[0] - voltage_ref[0] <= 0.001);
}

TEST_CASE("Test for finding maximum value") 
{
  float current[5]= {1.2, 6.7, 9.0, 7.8, 5.6};
  float max = FindMaxValue(current, 5);
  REQUIRE(max == 9.0f);
}
