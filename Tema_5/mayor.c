/*
 Escribe un programa que, dado un array de floats, imprima por pantalla el mayor valor
encontrado.
*/

#include <stdio.h>
#include <math.h>
#define N 10

int main(int argc, char const *argv[])
{
    float valores[N] = {0}; // Mejor inicializar a 0
    printf("Escriba los %d valores que va a introducir en el array \n" , N);

    for (int i = 0; i < N; i++)
    {
        printf("Valor %d :" , i);
        scanf("%f \n" ,&valores[i]); // Pasar la direccion
    }
    float max = 0;
    for (int i = 0; i < N+1; i++)
    {
        if (max < valores[i]){
            max = valores[i];
        }
    }
    printf("El valor maximo es: %f \n" , max);
    return 0;
}
