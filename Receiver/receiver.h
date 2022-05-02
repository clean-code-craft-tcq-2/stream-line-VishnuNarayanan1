#ifndef RECEIVER_H
#define RECEIVER_H

#include <stdio.h>

#define MAX_SIZE_TO_READ 400

void readfromConsole(float* currentReading, float* voltageReading, int lengthOfInputData);
float FindMaxValue(float* input, int streamSize);
float FindMinValue(float* input, int streamSize);
float FindAvgValue(float* input, int streamSize);
void computeSMA(float *input, int winSize, float *movingAvg);
void FindMinandMaxValue(float* temperatureReading, float* voltageReading, int streamSize);

#endif /* RECEIVER_H */
