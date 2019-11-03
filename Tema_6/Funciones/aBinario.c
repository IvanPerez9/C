/*
Implementa un programa que convierta de manera recursiva un número en base
decimal a binario
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int convertirBinario (int n);

int main(int argc, char const *argv[])
{
    printf("Introduce el numero que desea convertir a binario: ");
    int num = 0;
    scanf("%d" , &num);
    int conversion = convertirBinario (num);
    printf("Binario de %d es: %d" , num , conversion);
    return 0;
}

// Funcion recursiva
int convertirBinario(int num){
    if (num == 0){
        return 0;
    } else
    {
        return (num % 2) + (10 * convertirBinario(num / 2));
    }
    
}
