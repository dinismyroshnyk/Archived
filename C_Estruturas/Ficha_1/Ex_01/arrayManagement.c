#include <stdio.h>
#include "include\prototypes.h"

void createArray(int array[])
{
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        array[i] = 0;
    }
}

void readArray(int array[])
{
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        printf("Introduza o valor do %dº elemento da tabela: ", i + 1);
        scanf("%d", &array[i]);
    }
}

void printArray(int array[])
{
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        printf("%dº elemento da tabela: %d\n", i + 1, array[i]);
    }
}