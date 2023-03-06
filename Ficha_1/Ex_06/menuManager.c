#include <stdio.h>
#include "include\prototypes.h"

void mainMenuText()
{
    printf("[1] - Imprimir matriz\n");
    printf("[2] - Calcular média dos elementos da matriz\n");
    printf("[3] - Calcular média dos elementos de uma coluna da matriz\n");
    printf("[4] - Calcular média dos elementos de uma linha da matriz\n");
    printf("[5] - Calcular o número de zeros acima da diagonal principal\n");
    printf("[6] - Determinar linha com maior soma de elementos\n");
    printf("[7] - Trocar duas colunas da matriz\n");
    printf("[8] - Somar duas matrizes\n");
    printf("[0] - Sair\n");
}

void mainMenu()
{
    int userRows = userMatrixRows();
    int userColumns = userMatrixColumns();
    float **matrix1 = createUserMatrix(userRows, userColumns);
    int option;
    do
    {
        mainMenuText();
        printf("Insira a opção: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option)
        {
            case 1: printMatrix(matrix1, userRows, userColumns);
                break;
            case 2: calculateAndPrintAverageMatrixElements(matrix1, userRows, userColumns);
                break;
            case 3: calculateAndPrintAverageColumnElements(matrix1, userRows, userColumns);
                break;
            case 4: calculateAndPrintAverageRowElements(matrix1, userRows, userColumns);
                break;
            case 5: calculateAndPrintNumberOfZerosAboveMainDiagonal(matrix1, userRows, userColumns);
                break;
            case 6: findRowWithGreatestSumOfElements(matrix1, userRows, userColumns);
                break;
            case 7: changePlaceOfTwoColumns(matrix1, userRows, userColumns);
                break;
            case 8: sumTwoMatrices(matrix1, userRows, userColumns);
                break;
            case 0: printf("A sair...\n");
                break;
            default: printf("Opção inválida!\n");
                break;
        }
    } while (option != 0);
}