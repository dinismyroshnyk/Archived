#include <stdio.h>
#include "include\prototypes.h"

int main()
{
    int arraySize = defineUserArraySize();
    int array[arraySize];
    createDefaultArray(array, arraySize);
    addUserElementsToArray(array, arraySize);
    printArray(array, arraySize);
    getAndPrintEvenOddAverage(array, arraySize);
    return 0;
}