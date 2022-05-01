#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "Receiver/receiver.h"

/* Positive test case */
TEST_CASE("Requirement ID:1: Case for Postive test case :- To read Data from console") 
{
  float temperature_temp[1] = {29.0};
  float voltage_temp[1] = {2.6};
  printf(" Temperature : %.2f  Voltage : %.2f", temperature_temp[0], voltage_temp[0]);
  REQUIRE(readfromConsole(Temperature, Voltage) == Success);
}

/* Positive test case */
TEST_CASE("Requirement ID:2 Case for evaluating Printing to console for Temperature, after finding:Requirement ID:2a:- Minimum,Maximum, Requirement ID:2b:- Moving Average of 5") 
{
	float OutputAveragearray[lengthOfInputData] = {};
	PrintingData DataToPrint;
	DataToPrint.UserRequestOperator = ToFindMinValue;
	DataToPrint.IndexOfBatteryMessage = TEMPERATURE;
	DataToPrint.LengthOfAvgArray = lengthOfInputData;
	REQUIRE(FindMinandMaxValue(Temperature,DataToPrint.UserRequestOperator) == Success);
	DataToPrint.UserRequestOperator = ToFindMaxValue;
	REQUIRE(FindMinandMaxValue(Temperature,DataToPrint.UserRequestOperator) == Success);
  REQUIRE(FindMovingAverage(Temperature,DataToPrint.LengthOfAvgArray,OutputAveragearray) == Success);
  REQUIRE(PrintToConsole(OutputAveragearray,DataToPrint) == Success);
}

/* Positive test case */
TEST_CASE("Requirement ID:2: Case for evaluating Printing to console for State Of charge, after finding:Requirement ID:2a:- Minimum,Maximum, Requirement ID:2b:- Moving Average of 5")  
{
	float OutputAveragearray[lengthOfInputData] = {};
	PrintingData DataToPrint;
	DataToPrint.UserRequestOperator = ToFindMinValue;
	DataToPrint.IndexOfBatteryMessage = VOLTAGE;
	DataToPrint.LengthOfAvgArray = lengthOfInputData;
  REQUIRE(FindMinandMaxValue(Voltage,DataToPrint.UserRequestOperator) == Success);
	DataToPrint.UserRequestOperator = ToFindMaxValue;
  REQUIRE(FindMovingAverage(Voltage,DataToPrint.LengthOfAvgArray,OutputAveragearray) == Success);
  REQUIRE(PrintToConsole(OutputAveragearray,DataToPrint) == Success);
}
