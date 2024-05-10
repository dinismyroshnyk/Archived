#include <stdio.h>

int defineArraySize()
{
    printf("Introduza o tamanho da tabela: ");
    int arraySize;
    scanf("%d", &arraySize);  
    return arraySize;
}

void createArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = 0;
    }
}

void readArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("Introduza o valor do %dº elemento da tabela: ", i + 1);
        scanf("%d", &array[i]);
    }
}

void printArray(int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%dº elemento da tabela: %d\n", i + 1, array[i]);
    }
}

void shiftArrayLeft(int array[], int arraySize)
{
    int temporaryArray = array[0];
    for (int i = 0; i < arraySize - 1; i++)
    {
        array[i] = array[i + 1];
    }
    array[arraySize - 1] = temporaryArray;
}