/*
 Escribe un programa que genere un array con 10 números aleatorios en el rango [50,100] y
después imprima el array por pantalla
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    srand(time(NULL));
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        int r = (rand() % (100 + 1 - 50)) + 50;
        array[i] = r;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}