#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

int* getUserArray(int size)
{
    int* array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("Insira o elemento %d: ", i);
        scanf("%d", &array[i]);
        fflush(stdin);
    }
    return array;
}

void printArray(int* array, int size)
{
    clearScreen();
    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    insertAnyKey();
}

int arraySize()
{
    int size;
    printf("Insira o tamanho do array: ");
    scanf("%d", &size);
    fflush(stdin);
    return size;
}