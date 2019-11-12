/*
Implementar en C una programa que dada una matriz, haga su transpuesta
La transpuesta es una matriz que cambia las filas por las columnas
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int ** matriz;
    int ** trans;
    int filas = 3;
    int columnas = 2;

    matriz = (int **) malloc (filas * sizeof( int *));
    trans = (int **) calloc (columnas , sizeof( int *));
    for (int i = 0; i < filas; i++)
    {
        matriz[i] = (int *) malloc (columnas * sizeof(int));
    }
    
    for (int i = 0; i < filas; i++)
    {
         trans[i] = (int *) calloc (columnas , sizeof(int));  // Iini a 0 con calloc
    }
    
    
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
    // Mostrar la matriz original
    printf("Mostrar original: \n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%d, " , matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Transpuesta
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            trans[j][i] = matriz[i][j];
        }
    }

    // Mostrar transpuesta
    printf("Mostrar transpuesta: \n");
    for (int i = 0; i < columnas; i++)
    {
        for (int j = 0; j < filas; j++)
        {
            printf("%d, " , trans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
