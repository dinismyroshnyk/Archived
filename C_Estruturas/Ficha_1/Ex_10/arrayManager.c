#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

int* getDefaultArray()
{
    int* array = (int*)malloc(DEFAULT_ARRAY_SIZE * sizeof(int));
    for (int i = 0; i < DEFAULT_ARRAY_SIZE; i++)
        array[i] = i;
    return array;
}

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

void printArray(int* array, int size, int option)
{
    switch (option)
    {
    case 0:
        clearScreen();
        printf("Array: ");
        for (int i = 0; i < size; i++)
            printf("%d ", array[i]);
        printf("\n");
        insertAnyKey();
        break;
    case 1:
        clearScreen();
        printf("Old Array: ");
        for (int i = 0; i < size; i++)
            printf("%d ", array[i]);
        printf("\n");
        break;
    case 2:
        printf("New Array: ");
        for (int i = 0; i < size; i++)
            printf("%d ", array[i]);
        printf("\n");
        insertAnyKey();
        break;
    default: 
        printf("Ocorreu um erro!");
        insertAnyKey();
        break;
    }
}

int arraySize()
{
    int size;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &size);
    fflush(stdin);
    return size;
}