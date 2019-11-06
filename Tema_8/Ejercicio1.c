/*
Implementa un programa que pida por teclado un número N y a continuación
cree un array dinámico con N elementos de tipo float. Después deberás
imprimirlos por pantalla y liberar el array
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("Introduzca un numero N para crear un array \n");
    int n ;
    scanf("%d", &n);
    float * arrayD;
    arrayD = (float *) malloc(n * sizeof(float));
    // Lo relleno de numeros de entre 0 y 20
    for (int i = 0; i < n; i++)
    {
        arrayD[i] = rand()%21;
    }

    // Mostrar
    for (int i = 0; i < n; i++)
    {
        printf("%f \n" , arrayD[i]);
    }

    // Libero memoria
    free(arrayD);
    return 0;
}
