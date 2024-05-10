#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

void bubbleSortUnoptimized(int* array, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (array[j] < array[j + 1])
            {
                int swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
            }
    arraySorted();
}

void bubbleSortOptimized(int* array, int size)
{
    int swapped;
    int times_passed = 0;
    do
    {
        swapped = 0;
        for (int i = 0; i < size - 1 - times_passed; i++)
            if (array[i] < array[i + 1])
            {
                int swap = array[i];
                array[i] = array[i + 1];
                array[i + 1] = swap;
                swapped = 1;
            }
        times_passed++;
    } while (swapped);
    arraySorted();
}