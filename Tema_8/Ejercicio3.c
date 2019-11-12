/*
Implementa un programa que, dada una matriz de 3x3 y un vector de 3
elementos, realice la multiplicación de ambos y lo guarde en una matriz de 3x3.
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int * vector ;
    vector = (int *) malloc(3 * sizeof(int));
    // relleno
    for (int i = 0; i < 3; i++)
    {
        vector[i] = rand()%21;
    }

    int ** matriz;
    int m = 3;
    int n = 3;
    // Primero el numero de filas y luego cada una de las por separado
    matriz = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        matriz[i] = (int *) malloc (n * sizeof(int));
    }

    // Rellenar de numeros random
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = rand() % 20;
        }
    }
    
    // Multiplicacion
    int tmp = 0;
    for(int i=0; i<m; i++){
        tmp=1;
        for(int j=0; j<n; j++){
            tmp += matriz[i][j]*vector[j] ;
        }
        printf("Resultado[%d]=%d\n", i, tmp);
    }
    
    free(vector);
    free(matriz);
    // Linberar matriz y cada columna
    for (int j = 0; j < n; j++)
    {
        free(matriz[j]);
    }
    return 0;
}
