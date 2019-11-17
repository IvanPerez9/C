/*
 Escribe un programa que, dado un array de floats, imprima por pantalla el mayor valor
encontrado
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 10

int main(int argc, char const *argv[])
{
    float array [N] = {1,22,34,55,6,2,7,8,9,11} ;
    int max = 0;

    for (int i = 0; i < N; i++)
    {
        if (array[i] > max){
            max = array[i];
        }
    }
    printf("El mayor float del array es: %d" , max);
    return 0;
}
