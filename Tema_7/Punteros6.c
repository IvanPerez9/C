/*
Parejas de numeros no tienen porque ser negativo y positivo
Adivinar cual no tiene pareja
*/

#include <math.h>
#include<stdio.h>
#include <stdlib.h>

int pertenece (int num , int *array[]);

int main(int argc, char const *argv[])
{
    int array[10] = {1,1,2,3,4,2,3,5,6,5}; // 4 y 6
    int * p = NULL;

    for (int i = 0; i < 10; i++)
    {
        if (!(pertenece(array[i], array[1]))){
            printf("El valor %d no tiene pareja" , array[i]);
        }
    }
    return 0;
}

int pertenece (int num , int *array[]){ // Puntero al array con *array[] si le quiero pasar el mismo array
    for (int i = 0; i < 10; i++)
    {
        if (num == array[i]){
            return 1;
        }
    }
    return 0;
}
