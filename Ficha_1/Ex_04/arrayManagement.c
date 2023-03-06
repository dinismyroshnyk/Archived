#include <stdio.h>

int defineUserArraySize()
{
    printf("Introduza o tamanho da tabela: ");
    int arraySize;
    scanf("%d", &arraySize);  
    return arraySize;
}

void createDefaultArray(int aArray[], int aSize)
{
    for (int i = 0; i < aSize; i++)
    {
        aArray[i] = 0;
    }
}

void addUserElementsToArray(int aArray[], int aSize)
{
    for (int i = 0; i < aSize; i++)
    {
        printf("Introduza o elemento %dº da tabela: ", i + 1);
        scanf("%d", &aArray[i]);
    }
}

void printArray(int aArray[], int aSize)
{
    for (int i = 0; i < aSize; i++)
    {
        printf("%d ", aArray[i]);
    }
}

void getAndPrintEvenOddAverage(int aArray[], int aSize)
{
    int evenSum = 0;
    int oddSum = 0;
    int evenCount = 0;
    int oddCount = 0;
    for (int i = 0; i < aSize; i++)
    {
        if (aArray[i] % 2 == 0)
        {
            evenSum += aArray[i];
            evenCount++;
        }
        else
        {
            oddSum += aArray[i];
            oddCount++;
        }
    }
    printf("\nA média dos números pares é: %.2f", (float)evenSum / evenCount);
    printf("\nA média dos números ímpares é: %.2f", (float)oddSum / oddCount);
}