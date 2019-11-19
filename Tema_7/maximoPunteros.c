/*
Maximo de un array con punteros -> Como ejercicio1.c de T7
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

int main(int argc, char const *argv[])
{
    printf("Introduce %d numeros al array: " , N);
    int array[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }
    
    printf("Calculo el maximo con punteros \n");
    int * max = array;
    for (int i = 0; i < N; i++)
    {
        if (array[i] > *max){
            max = &array[i]; // Necesario apuntar a esa direccion de memoria
        }
    }

    printf("El maximo es: %d" , *max);

    return 0;
}
