/*
Funcion para mostrar la matriz, no dinamica
*/
#include <stdio.h>
#include <stdlib.h>

#define FIL 3
#define COL 2

void mostrarMatriz (int matriz [FIL][COL]);
void sumaMatriz (int matriz1 [FIL][COL] , int matriz2 [FIL][COL], int ret [FIL][COL]);
void transpuestaMatriz (int matriz[FIL][COL] , int ret[COL][FIL]);
void mostrarTranspuesta (int matriz [COL][FIL]);

int main(int argc, char const *argv[])
{
    int matriz1[FIL][COL] = {{1,2},
                        {3,4},
                        {1,2}};

    int matriz2[FIL][COL] = {{1,1},
                        {1,2},
                        {1,2}};

    int sum [FIL][COL] = {0}; // Relleno de 0
    int trans[COL][FIL] = {0};

    printf("Mostrado matriz 1:  \n");
    mostrarMatriz(matriz1);
    printf("Mostrado matriz 2:  \n");
    mostrarMatriz(matriz2);

    // Suma
    printf("Suma de las matrices: \n");
    sumaMatriz(matriz1, matriz2, sum);
    mostrarMatriz(sum);

    // Transpuesta
    printf("Transpuesta de una matriz1: \n");
    transpuestaMatriz(matriz1 , trans);
    mostrarTranspuesta(trans);

    // Falta punteros, como ejercicio 4 de punteros, pero para 2 2 por ejemplo

    return 0;
}

void mostrarMatriz (int matriz [FIL][COL]){
    for (int i = 0; i < FIL; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("\t%d " , matriz[i][j] );
        }
        printf("\n");
    }
}

void mostrarTranspuesta (int matriz [COL][FIL]){
    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < FIL; j++)
        {
            printf("\t%d " , matriz[i][j] );
        }
        printf("\n");
    }
}

/*
Array cannot be passed by value -> https://stackoverflow.com/questions/6567742/passing-an-array-as-an-argument-to-a-function-in-c
*/
void sumaMatriz (int matriz1 [FIL][COL] , int matriz2 [FIL][COL], int ret [FIL][COL]){
    for (int i = 0; i < FIL; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            ret[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

/*
Transpuesta de una matriz
*/
void transpuestaMatriz (int matriz[FIL][COL] , int ret[COL][FIL]){
    for (int i = 0; i < FIL; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            ret[j][i] = matriz[i][j];
        }
    }
}
