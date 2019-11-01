/*
 Escribe un programa que genere un array con N números aleatorios en el rango [0,100]. Tras
ello, el programa deberá calcular el array con las sumas acumuladas, que guardará en cada
posición i la suma de todos los elementos de ese array entre las posiciones [0,i]
*/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define N 10

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int array [N];
    int suma [N];

    for (int i = 0; i < N; i++)
    {
        array[i] = rand()%101;
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += array[i];
        suma[i] = sum;
    }
    
    for (int i = 0; i < N; i++)
    {
        printf("%d ", suma[i]);
    }

    printf("\nSuma total %d: " , sum);
    return 0;
}
