/*
Implementa un programa que encripte y desencripte un mensaje. Para encriptar,
sumará 2 al código ASCII del carácter. Para desencriptar, realizará la operación
contraria. Las funciones correspondientes deberán modificar el parámetro de
entrada, no devolver una nueva cadena.
Paso por referencia
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void encriptar (char palabra[]);

int main(int argc, char const *argv[])
{
    printf("Introduce palabra a encriptar: ");
    char palabra [15];
    scanf("%s" , palabra);
    encriptar(&palabra); // Paso por referencia
    printf("Palabra modificada +2 :");
    for (int i = 0; i < 15+1; i++)
    {
        printf("%d", palabra[i]);
    }
    
    return 0;
}

void encriptar (char *palabra){
    int encriptado [15];
    for (int i = 0; i < 15+1; i++)
    {
        encriptado[i] = palabra[i];
    }
    printf("La palabra %s en ASCII es: ");
    for (int i = 0; i < 15+1; i++)
    {
        printf("%d", encriptado[i]);
        palabra[i] = palabra[i] + 2;
    }
    printf("\n");
    
}
