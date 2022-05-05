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
void readfromConsole(float* temperatureReading, float* voltageReading, int lengthOfInputData)
{
  char ReadString[MAX_SIZE_TO_READ];
  for(int i = 0; i < lengthOfInputData; i++)
  {
	  scanf("%20s", ReadString);
	  if(scanf("%20s", ReadString) == EOF) 
	  {
		  /* The coverage for this line cannot be achieved since the input from sender is always taken as per 
		  this project use case. Therefore the associated branch coverage is not reachable. */
		  break;
	  }
	  scanf("%f", &temperatureReading[i]);
	  scanf("%20s", ReadString); //,
	  scanf("%20s", ReadString); // 
	  scanf("%20s", ReadString); // Voltage
	  scanf("%20s", ReadString); // :
	  scanf("%20s", ReadString); //
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
 * Function Description: Extract the Simple moving average value of previous "numOfElements" elements
 *
 * \param   float input[]              : Array upon which SMA value has to be calcutated for
 * \param   int lengthOfInputData      : total stream size
 * \param   int numOfElements          : number of elements to calculate moving average for 
 * \return  None
 ***************************************************************************************************
 */
void FindSMAValue(float input[], int lengthOfInputData, int numOfElements)
{
	int i;
	float avg;
	float sum = 0;
	printf("SMA of the requested range of elements:\n");
	/* Initial sum of the required number of elements */
	for (i = 0; i < numOfElements; i++)
	{
		sum += input[i];
        	printf("%.2f ",sum/numOfElements);
	}
 
    	// Compute Moving Average value from the index numOfElements considered
    	for (i = numOfElements; i < lengthOfInputData; i++)
	{
		sum -= input[i - numOfElements];
        	sum += input[i];
        	avg = sum / numOfElements;
		printf("%.2f ",avg);
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

