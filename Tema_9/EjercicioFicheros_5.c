/*
 Crea un programa que lea un fichero de texto que contenga números enteros y escriba
los números pares en un fichero llamado pares.txt y los impares en otro fichero
llamado impares.txt
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE * fichero;
    if ((fichero = fopen("numeros.txt", "r")) == NULL) {
        perror("Error al abrir el fichero numeros.txt");
    }

    // Leer todo de golpe guardarlo en un buff y luego ir sacando 1 a 1 del buff ?
    while(!feof(fichero)){
        int n = fgetc(fichero);
        if (n % 2 == 0){
            FILE * pares = fopen("pares.txt" , "a");
            fputc(n , pares);
            fclose(pares);
        } else {
            FILE * impares = fopen("impares.txt" , "a");
            fputc(n , impares);
            fclose(impares);
        }
    }
    fclose(fichero);

    return 0;
}
