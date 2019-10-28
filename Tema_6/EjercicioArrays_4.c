/*
 Escribe un programa que, dado un array de caracteres y un carácter, cuente cuántas veces
aparece ese carácter en el array
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define N 10

int main(int argc, char const *argv[])
{
    char array [N] = {'a' , 'e' , 'i' , 'o' , 'u', 'e' , 'e' , 'o' , 'o' , 'u'};
    printf("Vocal que desea buscar: ");
    char buscar ;
    scanf("%c" , &buscar);
    int contador = 0;

    for (int i = 0; i < N; i++)
    {
        if (array[i] == buscar){
            contador++;
        }
    }

    printf("El caracter '%c' aparece %d veces " , buscar,  contador);
    
    return 0;
}

