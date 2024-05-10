#include <stdio.h>
#include <stdlib.h>
#include "include\prototypes.h"

void printInedxOfLargestElement(int* array, int size)
{
    int highestValue = array[0];
    int highestValueIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (array[i] > highestValue)
        {
            highestValue = array[i];
            highestValueIndex = i;
        }
    }
    clearScreen();
    printf("O maior elemento do array é %d e encontra-se na posição [%d].\n", highestValue, highestValueIndex);
    insertAnyKey();
}

void swap(int* array, int index1, int index2)
{
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

int getUserIndex(int size, int number)
{
    int index;
    do
    {
        printf("Insira o índice do %dº elemento a trocar: ", number);
        scanf("%d", &index);
        fflush(stdin);
        if (index < 0 || index >= size)
        {
            clearScreen();
            printf("Índice inválido!\n");
            insertAnyKey();
        }
    } while (index < 0 || index >= size);
    return index;
}

void swapElements(int* array, int size)
{
    int index1 = getUserIndex(size, 1);
    int index2 = getUserIndex(size, 2);
    swap(array, index1, index2);
    clearScreen();
    printf("Os elementos foram trocados com sucesso!\n");
    insertAnyKey();
}

void selectionSort(int* array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int lowest_value = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[lowest_value])
                lowest_value = j;
        }
        if (lowest_value != i)
            swap(array, i, lowest_value);
    }
    clearScreen();
    printf("O array foi ordenado com sucesso!\n");
    insertAnyKey();
}