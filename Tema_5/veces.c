/*
 Escribe un programa que, dado un array de caracteres y un carácter, cuente cuántas veces
aparece ese carácter en el array
*/

#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    printf("Introduce el caracter a buscar: ");
    char c ;
    scanf("%c" , &c);
    char palabra [25] = "esternocleidomastoideo";
    int contador = 0;
    for (int i = 0; i < 25; i++)
    {
        if (c == palabra[i]){
            contador++;
        }
    }
    printf("El caracter '%c' aparece en la palabra '%s' todas estas veces: %d" , c, palabra , contador);
    
    return 0;
}
