#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float* lines_from_coordinates(int* array)
{
    const int len = 8; // triangle coord array
    float* lines_array = (float*)calloc(3, sizeof(float));
    float a = sqrt(pow(array[0] - array[2], 2) + pow(array[1] - array[3], 2));
    float b = sqrt(pow(array[2] - array[4], 2) + pow(array[3] - array[5], 2));
    float c = sqrt(pow(array[4] - array[6], 2) + pow(array[5] - array[7], 2));
    lines_array[0] = a;
    lines_array[1] = b;
    lines_array[2] = c;
    return lines_array;
}

float perimeter(int* array)
{
    float* lines_array = lines_from_coordinates(array);
    float perimeter = 0;
    for (int i = 0; i < 3; i++) {
        perimeter += lines_array[i];
    }
    return perimeter;
}