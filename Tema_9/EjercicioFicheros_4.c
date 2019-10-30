/*
Crea un programa que abra un fichero de texto llamado “origen.txt”, lo lea y copie su
contenido en otro fichero llamado “copia.txt”
*/

#include <stdio.h>
#define MAX 15

int main(int argc, char const *argv[])
{
    FILE * fichero;
    FILE * copia;
    if ((fichero = fopen("origen.txt" , "r")) == NULL){
        perror("Error al abrir el fichero origen");
    } 
    if ((copia = fopen("copia.txt", "w"))== NULL){
        perror("Error al abrir el fichero copia");
    }
    char buf[MAX];
    while(!feof(fichero)){
        fgets(buf,MAX,fichero);
        fputs(buf , copia);
    }
    fclose(fichero);
    fclose(copia);
    return 0;
}
