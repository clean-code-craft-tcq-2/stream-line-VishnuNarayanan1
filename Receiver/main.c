#include "receiver.h"

int main()
{
    float Temperature[50], Voltage[50] = {0};
    readfromConsole(Temperature, Voltage, 50);  
    FindMinandMaxValue(Temperature, Voltage, 50);
    return 0;
}
