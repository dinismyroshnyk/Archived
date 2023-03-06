#include <stdio.h>
#include <stdlib.h>

float **createDefaultMatrix(int row, int column, float value)
{
    float **matrix = (float **)malloc(row * sizeof(float *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (float *)malloc(column * sizeof(float));
        for (int j = 0; j < column; j++)
        {
            matrix[i][j] = value;
        }
    }
    return matrix;
}

float **createUserMatrix(int row, int column)
{
    float **matrix = (float **)malloc(row * sizeof(float *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (float *)malloc(column * sizeof(float));
        for (int j = 0; j < column; j++)
        {
            printf("Insira o valor da posição [%d][%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
            fflush(stdin);
        }
    }
    return matrix;
}

int userMatrixRows()
{
    int rows;
    printf("Insira o número de linhas da matriz: ");
    scanf("%d", &rows);
    fflush(stdin);
    return rows;
}

int userMatrixColumns()
{
    int columns;
    printf("Insira o número de colunas da matriz: ");
    scanf("%d", &columns);
    fflush(stdin);
    return columns;
}

void printMatrix(float **matrix, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%.2f ", matrix[i][j]);
        printf("\n");
    }
}

void calculateAndPrintAverageMatrixElements(float **matrix, int row, int column)
{
    float sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            sum += matrix[i][j];
    }
    printf("A média dos elementos da matriz é: %.2f\n", sum / (row * column));
}

void calculateAndPrintAverageColumnElements(float **matrix, int row, int column)
{
    float sum = 0;
    int columnNumber;
    printf("Insira o número da coluna: ");
    scanf("%d", &columnNumber);
    fflush(stdin);
    if (columnNumber < column && columnNumber >= 0)
    {
        for (int i = 0; i < row; i++)
            sum += matrix[i][columnNumber];
        printf("\nA média dos elementos da coluna %d é: %.2f", columnNumber, sum / row);
    }
    else printf("Coluna inválida!\n");
}

void calculateAndPrintAverageRowElements(float **matrix, int row, int column)
{
    float sum = 0;
    int rowNumber;
    printf("Insira o número da linha: ");
    scanf("%d", &rowNumber);
    fflush(stdin);
    if (rowNumber < row && rowNumber >= 0)
    {
        for (int i = 0; i < column; i++)
            sum += matrix[rowNumber][i];
        printf("\nA média dos elementos da linha %d é: %.2f", rowNumber, sum / column);
    }
    else printf("Linha inválida!\n");
}

void calculateAndPrintNumberOfZerosAboveMainDiagonal(float **matrix, int row, int column)
{
    int zeros = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < column; j++)
        {
            if (matrix[i][j] == 0)
                zeros++;
        }
    }
    printf("O número de zeros acima da diagonal principal é: %d\n", zeros);
}

void findRowWithGreatestSumOfElements(float **matrix, int row, int column)
{
    float sum = 0;
    int rowNumber = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            sum += matrix[i][j];
        if (sum > rowNumber)
            rowNumber = i;
        sum = 0;
    }
    printf("A linha com a maior soma é a linha %d\n", rowNumber);
}

void changePlaceOfTwoColumns(float **matrix, int row, int column)
{
    int column1, column2;
    printf("Insira o número da primeira coluna: ");
    scanf("%d", &column1);
    fflush(stdin);
    printf("Insira o número da segunda coluna: ");
    scanf("%d", &column2);
    fflush(stdin);
    if (column1 < column && column1 >= 0 && column2 < column && column2 >= 0)
    {
        for (int i = 0; i < row; i++)
        {
            float aux = matrix[i][column1];
            matrix[i][column1] = matrix[i][column2];
            matrix[i][column2] = aux;
        }
    }
    else printf("Coluna inválida!\n");
}

void sumTwoMatrices(float **matrix1, int row, int column)
{
    float **matrix2 = createUserMatrix(row, column);
    float **matrixSum = (float **)malloc(row * sizeof(float *));
    for (int i = 0; i < row; i++)
    {
        matrixSum[i] = (float *)malloc(column * sizeof(float));
        for (int j = 0; j < column; j++)
        {
            matrixSum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("A soma das matrizes é:\n");
    printMatrix(matrixSum, row, column);
}