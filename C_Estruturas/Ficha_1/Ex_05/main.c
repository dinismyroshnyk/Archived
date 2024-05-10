#include <stdio.h>
#include "include\prototypes.h"

int main()
{
    int mat1[5][7], mat2[5][7];
    matriz_1(mat1); 
    escreveMatriz(mat1, 1); 
    matriz_2(mat2); 
    escreveMatriz(mat2, 2);
    return 0;
}