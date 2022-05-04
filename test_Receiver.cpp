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
    	
	printf(" Temperature: %.2f , Voltage: %.2f \n", temperature_ref[0],  voltage_ref[0]);
	printf("Sender fetched data\n");
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
	/* Sender data used for test purposes */
	float temperature[50] = {24.1,24.3,25,24.9,79,24,24.7,25,25.6,26.9,27.1,28,29.4,31.1,32.5,33.7,34,100,35,35.3,0,-1.5,-4,-5.9,-20,-7,-3.9,1,2,3,4,5.1,6.2,7.3,7.4,7.5,8.9,9.9,10.9,11.1,12,13.4,0,100,-100,0,-10.1,50.1,50,-10};
	float voltage[50] = {2.5,2.6,2.7,2.8,2.9,3.0,3.1,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0,15.1,12,12.1,10,10.1,10.2,10.3,10.4,10.5,10.6,10.7,10.8,10.9,11.0,2.4,2.3,7.0,7.1,7.2,7.3,7.4,7.5,7.6,7.7,1.0,9.0,9.1,9.7,10.2,15.1,12.2,12.0,10,5};
	FindMinandMaxValue(temperature, voltage, 50);
	float avg_temp = FindAvgValue(temperature, 50);
	float avg_volt = FindAvgValue(voltage, 50);
	REQUIRE( abs(avg_temp - 16.74f) <= 0.001);
	REQUIRE( abs(avg_volt - 7.27f) <= 0.001);
	printf("The average temperature is %.3f\n", avg_temp);
	printf("The average voltage is %.3f\n", avg_volt);
}
