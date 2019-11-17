/*
Diferencia entre paso por valor y referencia en arrays
*/
#include <stdlib.h>
#include <stdio.h>

int valor (int array[10], int pos);
int referencia (int * array);
void rellenarArray (int *array , int size);
void introducirSudoku (int tablero[2][2] );

int main(int argc, char const *argv[])
{
    // Pasan ambos por referencia
    int array [10] = {1,2,3,5,5,5,5,6,88,9};
    printf("Posicion 8 por valor: %d \n" , valor(array,8));
    printf("%d \n" , array[8]);
    printf("Posicion 8 por referencia: %d \n" , referencia(array));
    printf("%d \n" , array[8]);

    int array2 [5] ;
    rellenarArray(array2 , 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d" , array2[i]);
    }
    printf("\n");

    int matrix [2][2] = {0};
    introducirSudoku(matrix);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d" , matrix[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}

int referencia (int * array){
    return array[8]+8;
}

int valor (int array[10], int pos){
    return array[pos] + pos;
}

// Array con punteros -> Vale sin el puntero para persistir
void rellenarArray (int *array , int size){
    printf("Introduzca los valores para su array de 5 \n");
    for (int i = 0; i < 5; i++)
    {
        int value = 0;
        scanf("%d" , &value);
        array[i] = value;
    }
    
}

// Rellenar matriz
void introducirSudoku (int tablero[2][2] ){
    printf("Introduzca los valores para matrix de 2x2 \n");
    for (int fil = 0; fil < 2; fil++)
    {
        for (int col = 0; col < 2; col++)
        {
            scanf("%d" , &tablero[fil][col]);
        }
        printf("\n");
    }
}