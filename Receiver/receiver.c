#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "receiver.h"

/**
 ***************************************************************************************************
 * Function Name: readfromConsole
 * 
 * Function Description: Reads data from the console for provided input length
 *
 * \param  temperatureReading : 1st data from stdin(console)
 *         voltageReading     : 2nd data from stdin(console)
 *         voltageReading     : Length of data to read
 *         
 * \return  None
 ***************************************************************************************************
 */
void readfromConsole(float* temperatureReading, float* voltageReading, int c)
{
  char ReadString[MAX_SIZE_TO_READ];
  for(int i = 0; i < lengthOfInputData; i++)
  {
	  scanf("%20s", ReadString);
	  if(scanf("%50s", ReadString) == EOF) 
	  {
		  break;
	  }
	  scanf("%f", &temperatureReading[i]);
	  scanf("%20s", ReadString); 
	  scanf("%20s", ReadString);
	  scanf("%20s", ReadString); 
	  scanf("%20s", ReadString); 
	  scanf("%20s", ReadString); 
	  scanf("%20s", ReadString);
	  scanf("%f", &voltageReading[i]);
	  printf("%.3f \t %.3f\n",temperatureReading[i],voltageReading[i]);
  }
}

/**
 ***************************************************************************************************
 * Function Name: FindMinValue
 * 
 * Function Description: Extract the Minimum float value after segragating string data
 *
 * \param   float *input   : Pointer to array upon which minimum value has to be calcutated for
 * \param   int streamSize : Data Stream size          
 * \return  float min: Returns the minimum float value
 ***************************************************************************************************
 */
float FindMinValue(float* input, int streamSize)
{
  float min = input[0];
  for (int i=1; i<streamSize; i++)
  {
    if(input[i]<min)
      min = input[i];
  }
  return min;
}

/**
 ***************************************************************************************************
 * Function Name: FindMaxValue
 * 
 * Function Description: Extract the Maximum float value after segragating string data
 *
 * \param   float *input   : Pointer to array upon which maximum value has to be calcutated for
 * \param   int streamSize : Data Stream size          
 * \return  float max: Returns the maximum float value
 ***************************************************************************************************
 */
float FindMaxValue(float* input, int streamSize)
{
  float max = input[0];
  for (int i=1; i<streamSize; i++)
  {
    if(input[i]>max)
      max = input[i];
  }
  return max;
}

/**
 ***************************************************************************************************
 * Function Name: FindAvgValue
 * 
 * Function Description: Extract the average float value after segragating string data
 *
 * \param   float *input   : Pointer to array upon which average value has to be calcutated for
 * \param   int streamSize : Data Stream size          
 * \return  float avg: Returns the average float value
 ***************************************************************************************************
 */
float FindAvgValue(float* input, int streamSize)
{
    float avg = 0;
    float sum = 0;
    for(int i = 0; i < streamSize; i++)
    {
        sum = sum + input[i];
    }
    avg = sum/streamSize;
    return avg;
}

/**
 ***************************************************************************************************
 * Function Name: computeSMA
 * 
 * Function Description: Extract the Simple moving average float value after segragating string data
 *
 * \param   float *input     : Pointer to array upon which average value has to be calcutated for
 * \param   int winSize      : Stream size         
 * \param   float *movingAvg : Pointer to moving average array 
 * \return  None
 ***************************************************************************************************
 */
void computeSMA(float *input, int winSize, float *movingAvg)
{
     float sum = 0;
     for (int i = 0; i < 50; i++) 
     {
         sum = sum + input[i];
         if (i >= winSize){
	     sum -= input[i-winSize];
	 }
	 if(i >= winSize - 1) {
            movingAvg[i-winSize] = sum/winSize;
	 }
     }
}
	
void FindMinandMaxValue(float* temperatureReading, float* voltageReading, int streamSize)
{
  float minT, maxT, minV, maxV;
  minT = FindMinValue(temperatureReading, streamSize);
  maxT = FindMaxValue(temperatureReading, streamSize);
  minV = FindMinValue(voltageReading, streamSize);
  maxV = FindMaxValue(voltageReading, streamSize);
  printf("Minimum temperature: %f Maximum temperature: %f Minimum voltage: %f Maximum voltage: %f\n", minT, maxT, minV, maxV);
}

int main()
{
    float Current[50], Voltage[50] = {0};
    readfromConsole(Current, Voltage, 50);  
    FindMinandMaxValue(Current, Voltage, 50);
    return 0;
}
