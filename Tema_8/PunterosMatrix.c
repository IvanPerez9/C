/*
Moverse con punteros por una matriz
*/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int matrix [3][2] = {{2,2},
                         {3,3},
                         {4,4}};

    int (*p1) [3] = matrix; // Puntero a filas
    int *p2 = NULL;  // Puntero a columnas

    for ( ; p1 != matrix+3; ++p1)
    {
        // p2 inicializado a *p1 que apunta a la primera columna
        for (p2 = *p1; p2 != *p1+2; ++p2)
        {
            printf("%d " , *p2);
        }
        printf("\n");
    }

    // Recorrer con matriz dinamica

    int ** matrix2D ;
    matrix2D = (int **) malloc (3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        matrix2D[i] = (int*) malloc (2 * sizeof(int)); // OJO
    }
    // Relleno la matriz -> Funcion en MatrizDinamica.c
    printf("Rellena la matriz dinamica: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d" , &matrix2D[i][j]);
        }
        printf("\n");
    }
    printf("Muestro la matriz");
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d " , matrix2D[i][j]);
        }
        printf("\n");
    }
    
    /*
    // Ahora un puntero que la recorra
    int (* fil) [3] = matrix2D;
    int * col = NULL;

    for (; fil != matrix2D+3; ++fil)
    {
        for ( col = *fil; col != *fil+2 ; ++col)
        {
            printf("%d " , *col);
        }
        printf("\n");
    }
    */
    
    free(p1);
    p1 = NULL;
    free(p2);
    p2 = NULL;

    return 0;
}
