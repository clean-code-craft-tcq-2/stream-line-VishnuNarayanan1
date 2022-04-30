#ifndef RECEIVER_H
#define RECEIVER_H

#include <stdio.h>

typedef struct
{
	float min;
	float max;
}minMax_st;

typedef enum
{
	Failure,
	Success
}ResultType;

typedef enum
{
	ToFindMinValue,
	ToFindMaxValue
}UserRequestOperation;

typedef struct
{
	UserRequestOperation UserRequestOperator;
	int IndexOfBatteryMessage;
	int LengthOfAvgArray;
}PrintingData;

#define MAX_SIZE_TO_READ 400
#define TEMPERATURE 0
#define VOLTAGE 1

extern float Temperature[MAX_SIZE_TO_READ];
extern float Voltage[MAX_SIZE_TO_READ];
extern int lengthOfInputData;
extern minMax_st minMax_data;

ResultType FindMaxValue(float InputReading[]);
ResultType FindMinValue(float InputReading[]);
ResultType ExtractBatteryData_FromInput(char *InputData, float Temperature[], float Voltage[]);
ResultType ProcessReadData(char *InputData, float Temperature[], float Voltage[]);
ResultType FindMovingAverage(float arrayvalue[],int lengthofData,float OutputAveragearray[]);
ResultType readfromConsole(float Temperature[], float Voltage[]);
ResultType FindMinandMaxValue(float InputReading[], UserRequestOperation UserRequestOperator);
ResultType PrintToConsole( float PrintData[],PrintingData DataToPrint);

#endif /* RECEIVER_H */
