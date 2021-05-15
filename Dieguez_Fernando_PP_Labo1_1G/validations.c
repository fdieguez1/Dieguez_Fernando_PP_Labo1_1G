#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validations.h"

int validateInRange(int value, int minVal, int MaxVal, int includingMinMax)
{
    int inRange = 0;
    if (includingMinMax)
    {
        minVal--;
        MaxVal++;
    }
    if (value > minVal && value < MaxVal)
    {
        inRange = 1;
    }
    return inRange;
}
int validateInRangeFloat(float value, float minVal, float MaxVal, int includingMinMax)
{
    int inRange = 0;
    if (includingMinMax)
    {
        minVal -= 0.1;
        MaxVal += 0.1;
    }
    if (value > minVal && value < MaxVal)
    {
        inRange = 1;
    }
    return inRange;
}
