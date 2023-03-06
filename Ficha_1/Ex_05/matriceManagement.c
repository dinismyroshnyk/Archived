#include <stdio.h>

void matriz_1(int m1[5][7]) 
{ 
    int i,j; 
    for(i=0;i<5;i++) 
        for (j=0;j<7;j++) 
            m1[i][j]=j; 
} 

void matriz_2(int m2[][7]) 
{ 
    int i,j; 
    for(i=0;i<5;i++) 
        for (j=0;j<7;j++) 
            m2[i][j]=i; 
}

void escreveMatriz(int m[][7], int matriz)
{
    printf("Matriz %d:\n",matriz);
    for(int i=0;i<5;i++)
    {
        for (int j=0;j<7;j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }
}