#include <stdio.h>
#include "include\prototypes.h"
#include "include\defines.h"

int main() 
{
    int array[MAX_ARRAY_SIZE];
    createRandomArray(array);
    printArray(array);
    return 0;
}