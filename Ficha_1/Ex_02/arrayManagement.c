#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include\defines.h"

void createRandomArray(int array[])
{
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        array[i] = (rand() % (MAX_RANDOM_NUMBER - MIN_RANDOM_NUMBER + 1)) + MIN_RANDOM_NUMBER;
    }
}

void printArray(int array[])
{
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        printf("%dº elemento da tabela: %d\n", i + 1, array[i]);
    }
}