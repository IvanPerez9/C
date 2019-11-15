/*
Crea un programa que tenga dos opciones: permitir escribir una serie de letras por
consola y almacenarlas en un fichero binario (pudiendo escoger si se desea un fichero
nuevo o añadirlas al final del fichero existente. Por otro lado, el programa permitirá
buscar la letra que ocupa una posición determinada (utilice la función fseek para
extraer la letra).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64

void menu (int opcion);
void buscarLetra ();
void escribirNuevoFichero();
void escribirFicheroYaExistente();
void leerFicheroBinario();

int main(int argc, char const *argv[])
{
    int opcion;
    printf("Introduce una opcion: \n");
    printf("Opcion 1: Almacenar entrada en nuevo fichero \n");
    printf("Opcion 2: Almacenar entrada en fichero ya usado \n");
    printf("Opcion 3: Buscar letra en una posicion determinada \n");
    printf("Opcion 4: Imprimir fichero por pantalla \n");
    printf("Opcion 5: Salir \n");
    scanf("%d" , &opcion);
    do
    {
        menu(opcion);
    } while (opcion < 1 || opcion > 4);

    return 0;
}

void menu (int opcion){
    switch (opcion)
    {
    case 1:
        printf("Opcion 1: \n");
        escribirNuevoFichero();
        break;
    
    case 2:
        printf("Opcion 2: \n");
        escribirFicheroYaExistente();
        break;
    
    case 3:
        printf("Opcion 3: \n");
        buscarLetra();
        break;

    case 4:
        printf("Opcion 4: \n");
        leerFicheroBinario();
        break;

    case 5:
        printf("Saliendo.. \n");
        break;

    default:
        perror("Error al elegir la opcion");
        exit(0);
        break;
    }
}

void escribirNuevoFichero (){
    FILE * fichero;
    if ( (fichero = fopen("fichero7.bin" , "wb")) == NULL){
        perror("Error al abir el fichero binario \n");
        exit(1);
    }
    printf("Escriba lo que deasea escribir en el fichero: \n");
    char * array;
    array = (char *) malloc (SIZE * sizeof(char));
    scanf("%s" , &array);
    if (fwrite(array , sizeof(char) , strlen(array) , fichero) != strlen(array)){
        perror("Error al escribir en el fichero \n");
    }
    free(array);
    fclose(fichero);
}

void escribirFicheroYaExistente (){
    FILE * fichero;
    if ((fichero = fopen("fichero7.bin", "ab")) == NULL){
        perror("Error al abrir el fichero binario \n");
        exit(1);
    }
    printf("Escriba lo que desea annadir al fichero: \n");
    char * array;
    array = (char * ) malloc (SIZE * sizeof(char));
    scanf("%s" , &array);
    if (fwrite(array , sizeof(char) , strlen(array) , fichero) != strlen(array)){
        perror("Error al escribir en el fichero \n");
    }
    free(array);
    fclose(fichero);
}

void buscarLetra (){
    FILE * fichero;
    if ((fichero = fopen("fichero7.bin", "rb")) == NULL){
        perror("Error al abrir el fichero binario \n");
        exit(1);
    }
    printf("Introduzca la posicion de la que desea saber la letra: \n");
    int posicion;
    scanf("%d" , &posicion);
    if ( fseek(fichero , sizeof(char)*(posicion -1) , SEEK_SET) != 0){ // Muevo el puntero hasta donde quiera
       perror("Error al hacer fseek, devuelve 0 si correcto \n"); 
    }
    int valor = ftell(fichero); // Valor de donde esta el puntero -> Numero de bytes desde el inicio
    char c = (char) valor;
    printf("La letra es: %c -> %d \n" , c, c) ;
}

void leerFicheroBinario(){
    FILE * fichero;
    if ((fichero = fopen("fichero7.bin", "rb")) == NULL){
        perror("Error al abrir el fichero binario \n");
        exit(1);
    }

    printf("Leyendo fichero binario... \n");

    char palabras [256] ;
     if ((fread(palabras , sizeof(char *) , SIZE , fichero)) != SIZE){
        if (feof(fichero)){
            printf("Fichero EOF temprano \n");
        } else {
            printf("Error leyendo fichero \n");
            exit(1);
        }
    }
    for (int i = 0; i < strlen(palabras); i++)
    {
        printf("%s" , palabras[i]);
    }
    printf("%s" , palabras);
    fclose(fichero);
}
