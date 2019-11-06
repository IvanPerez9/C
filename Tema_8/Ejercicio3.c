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
    for (int i = 0; i < n; i++)
    {
        matriz[i] = (int *) malloc (n * sizeof(int));
    }

    // Multiplicacion
    int tmp = 0;
    for(int i=0; i<m; i++){
        tmp=0;
        for(int j=0; j<m; j++){
            tmp += matriz[i][j]*vector[j] ;
        }
        printf("Resultado[%d]=%lf\n", i, tmp);
    }
    
    free(vector);
    for (int j = 0; j < n; j++)
    {
        free(matriz[j]);
    }
    free(matriz);
    return 0;
}
