/*
Implementa una función que reciba dos matrices del mismo tamaño y devuelva
una nueva matriz con la suma de ambas matrices
*/

#include <stdlib.h>
#include <stdio.h>

#define M 3
#define N 3

void mostrarMatrix (int ** matrix );

int main(int argc, char const *argv[])
{

    int ** matrix2;
    int ** matriz;
    int ** ret;
    int ** sum;
    int m = 3;
    int n = 3;

    // Primero el numero de filas y luego cada una de las por separado
    matriz = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        matriz[i] = (int *) malloc (n * sizeof(int));
    }
    matrix2 = (int **) malloc (m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        matrix2[i] = (int *) malloc (n * sizeof (int));
    }
    ret = (int **) malloc (m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        ret[i] = (int *) malloc (n * sizeof(int)); 
    }
    sum = (int **) malloc (m*sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        sum[i] = (int *) malloc (n * sizeof(int));
    }
    
    // Rellenar de numeros random
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
        }
    }

    // Multiplicacion
    for (int i = 0; i < m; i++) // filas A
    {
        for (int j = 0; j < m; j++) // Col B
        {
            ret[i][j] = 0;
            for (int k = 0; k < n; k++) // Col A
            {
                ret[i][j] += matriz[i][k] * matrix2[k][j];
            }
        }
    }

    // Suma
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum[i][j] = matriz[i][j] + matrix2[i][j];
        }
    }
    
    printf("Matriz 1: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d " , matriz[i][j] );
        }
        printf("\n");
    }

    printf("Matriz 2: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d " , matrix2[i][j] );
        }
        printf("\n");
    }

    printf("\n");
    printf("Multiplicacion : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d " , ret[i][j] );
        }
        printf("\n");
    }
    printf("\n");

    printf("Suma: \n");
    mostrarMatrix(sum);
    printf("\n");

    // Liberar
    free(matrix2);
    free(matriz);
    free(ret);
    free(sum);
    for (int i = 0; i < n; i++)
    {
        free(matriz[i]);
        free(matrix2[i]);
        free(ret[i]);
        free(&sum[i]); // Es lo mismo
    }
    return 0;
}

// Pasarle un puntero -> Matriz dinamica
void mostrarMatrix (int ** matrix ){
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d " , matrix[i][j] );
        }
        printf("\n");
    }
}

