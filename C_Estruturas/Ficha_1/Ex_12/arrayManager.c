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
    printf("Insira o tamanho do array: ");
    scanf("%d", &size);
    fflush(stdin);
    return size;
}

int* removeDuplicates(int* array, int size, int* new_size)
{
    int* new_array = malloc(size * sizeof(int));
    int unique_elements = 0;
    for (int i = 0; i < size; i++)
    {
        int is_unique = 1;
        for (int j = 0; j < unique_elements; j++)
            if (array[i] == new_array[j])
            {
                is_unique = 0;
                break;
            }
        if (is_unique)
        {
            new_array[unique_elements] = array[i];
            unique_elements++;
        }
    }
    if (unique_elements != size)
    {
        new_array = realloc(new_array, unique_elements * sizeof(int));
        *new_size = unique_elements;
    }
    return new_array;
}

void getUniqueArray(int* array, int size)
{
    int new_size;
    int* new_array = removeDuplicates(array, size, &new_size);
    printArray(array, size, 1);
    printArray(new_array, new_size, 2);
    free(new_array);
}