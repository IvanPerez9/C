/*
Implementa una función que reciba dos matrices del mismo tamaño y devuelva
una nueva matriz con la suma de ambas matrices
*/

#include <stdlib.h>
#include <stdio.h>

void mostrarMatrix (int * matrix );

int main(int argc, char const *argv[])
{

    int ** matrix2;
    int ** matriz;
    int ** ret;
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
    // Rellenar de numeros random
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
        }
    }

    int sum = 0;
    // Multiplicacion
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                sum += matriz[i][k] * matriz[k][j];
            }
            ret[i][j] = sum;
            sum = 0;
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

    printf("Resultado : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d " , ret[i][j] );
        }
        printf("\n");
    }

    // Liberar
    free(matrix2);
    free(matriz);
    free(ret);
    for (int i = 0; i < n; i++)
    {
        free(matriz[i]);
        free(matrix2[i]);
        free(ret[i]);
    }
    return 0;
}

/*
void mostrarMatrix (int * matrix ){
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d " , matrix[i][j] );
        }
        printf("\n");
    }
}
*/
