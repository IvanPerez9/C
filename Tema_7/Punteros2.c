
#include <stdio.h>

/* REVISAR
Implementa el juego del ahorcado. Para ello, se pedirá al usuario que introduzca
por teclado una palabra de como máximo 10 letras. A continuación, se
almacenará dicha palabra en un array. Utilizando únicamente punteros, se
pedirá al usuario que introduzca letras hasta completar la palabra o hasta haber
realizado 5 intentos erróneos
*/

int main(int argc, char const *argv[])
{
    int array[10];

    printf("Introducir un palabra como maximo de 10 caracteres \n");
    scanf("Palabra: %s \n" , &(array[0]));

    for (int i = 0; i < 5; i++)
    {
        /* code */
        printf("Introduzca una letra de esa palabra, tiene %d intentos \n" , i );
        char letra = NULL;
        scanf("%c" , &letra);
    }

    printf("Introduzca letras sueltas \n");
    


    return 0;
}
