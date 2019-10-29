#include<stdio.h>

int main(int argc, char const *argv[])
{
    /*
    Crea un programa que abra un archivo de texto, lea su contenido carácter a carácter y
    lo muestre por consola
    */
   FILE *fichero;
   if ((fichero = fopen("fichero.txt", "r"))== NULL){
       printf("Error al abrir el fichero \n");
   } 
   while (!feof(fichero))
   {
        int c = fgetc(fichero); // Check EOF
        printf("%c\n" , c);
   }
    return 0;
}
