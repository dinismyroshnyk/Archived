#include <stdio.h>
#include "include\prototypes.h"

int main() 
{
    int array[MAX_ARRAY_SIZE];
    createArray(array);
    readArray(array);
    printArray(array);
}