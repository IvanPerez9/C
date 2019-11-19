
/*
Implementa un programa que cree un array de 10 enteros y lo rellene pidiendo
datos de teclado. A continuación, declara dos punteros que apuntarán al máximo
y al mínimo de ese array, e imprime su valor por pantalla
*/
#include<stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    #define N 10

    int array[N];
    printf("Introduzca por pantalla los datos: \n");
    for (int i = 0; i < N; i++)
    {
        printf("Dato %d: " , i);
        scanf("%d", &(array[i]));
    }

    int* min = array;
    int* max = array;

    for (int i = 0; i < N; i++)
    {
        if (array[i]> *max) {
            max = &array[i]; // Max apunta al valor
        }
        if (array[i]< *min){
            min = (array+i); // Lo mismo
        } 
    }

    printf("Min %d , y Max %d" , *min , *max);
    return 0;
}
