/*
Escribe un programa que genere un array con N números aleatorios en el rango [0,100]. Tras
ello, el programa deberá calcular el array con las sumas acumuladas, que guardará en cada
posición i la suma de todos los elementos de ese array entre las posiciones [0,i].

Hechos en el tema 5
*/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define N 10

int main(int argc, char const *argv[])
{
    /* code */

    int suma = 0;
    int a [N];
    int b [N];

    for (int i = 0; i < N; i++)
    {
        a[i] = rand()%101;
    }

    for (int i = 0; i < N; i++)
    {
        suma += a[i];
        b[i] = suma;
    }
    
    for (int i = 0; i < N; i++)
    {
        printf("Suma en %d es: %d \n" , i , b[i]);
    }
    
    printf("Suma total: %d" , suma);

    return 0;
}
