/*
Crea un programa que abra un archivo de texto, lea su contenido línea por línea y lo
muestre por consola
*/
#include<stdio.h>
#define MAX 15

int main(int argc, char const *argv[])
{
    FILE * fichero;
    if ((fichero = fopen("fichero.txt" , "r")) == NULL){
        perror("Error al abrir el fichero");
    } 
    char buf[MAX];
    while(!feof(fichero)){
        fgets(buf,MAX,fichero);
        printf("%s", buf);
    }
    fclose(fichero);
    return 0;
}
