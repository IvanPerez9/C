/*
Dado un array de números enteros, almacenamos en él parejas de un número y
su opuesto (3 y -3, 4 y -4, etc.) salvo de un elemento que solo almacenamos una
versión (la positiva o la negativa). Implementa un programa que averigüe cuál es
el número sin pareja
*/

#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int array [11] = {1,-1, 2, 3, 4, -2 ,-4, -3, 5, 6, -5}; // El 6
    int * puntero = NULL;
    int suma = 0;

    for (int i = 0; i < 11; i++)
    {
        puntero = &array[i];
        suma += * puntero;
    }
    printf("Numero que no tiene par negativo o positivo es: %d \n" , suma);
    
    return 0;

}

