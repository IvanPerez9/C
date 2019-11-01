/*
Crea un programa que lea de consola una cadena de texto y la almacene en un fichero
de texto en disco
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE * fichero;
    if ((fichero = fopen("ficheroCreado.txt" , "w")) == NULL){
        perror("Error al escribir en el fichero" );
    }
    printf("Introduce un frase a escribir en el fichero: ");
    char entrada[50];
    fgets(entrada, 50, stdin); // stdin entrada standar
    fputs(entrada , fichero);

    fclose(fichero);
    return 0;
}
