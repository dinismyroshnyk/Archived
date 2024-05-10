#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

int binarySearch(int* array, int size, int element)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (array[middle] == element)
            return middle;
        else if (array[middle] < element)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}

void printBinarySearch(int* array, int size)
{
    int element;
    clearScreen();
    printf("Insira o elemento a pesquisar: ");
    scanf("%d", &element);
    fflush(stdin);
    int index = binarySearch(array, size, element);
    if (index == -1)
    {
        clearScreen();
        printf("Elemento não encontrado!\n");
        insertAnyKey();
    }
    else
    {
        clearScreen();
        printf("Elemento encontrado na posição [%d].\n", index);
        insertAnyKey();
    }
}