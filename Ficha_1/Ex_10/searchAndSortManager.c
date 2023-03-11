#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

void insertElementInsideSortedArray(int* array)
{
    int default_array_size = DEFAULT_ARRAY_SIZE;
    int new_array[default_array_size + 1];
    int element;
    int i = 0;
    clearScreen();
    printf("Insira o elemento a inserir: ");
    scanf("%d", &element);
    fflush(stdin);
    for (i; i < default_array_size && array[i] < element; i++)
        new_array[i] = array[i];
    new_array[i] = element;
    i++;
    for (i; i < default_array_size + 1; i++)
        new_array[i] = array[i - 1];
    printArray(array, default_array_size, 1);
    printArray(new_array, default_array_size + 1, 2);
}

void insertionSort(int* array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    clearScreen();
    printf("Vetor ordenado!\n");
    insertAnyKey();
}