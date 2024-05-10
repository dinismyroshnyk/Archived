#include <stdio.h>
#include "include\prototypes.h"

int main() 
{
    int arraySize = defineArraySize();
    int array[arraySize];
    createArray(array, arraySize);
    readArray(array, arraySize);
    printArray(array, arraySize);
    shiftArrayLeft(array, arraySize);
    printArray(array, arraySize);
    return 0;
}