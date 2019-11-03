/*
Reciba un numero y lo imprima por pantalla
*/

#include <stdio.h>
#include <stdlib.h>

void imprimirN (int n);

int main(int argc, char const *argv[])
{
    printf("Introduce un numero entre 1 y 5 :");
    int n = 0;
    scanf("%d" , &n);
    imprimirN(n);
    return 0;
}

void imprimirN (int n){
    switch (n)
    {
    case 1:
        printf("Uno \n");
        break;
    case 2:
        printf("Dos \n");
        break;
    case 3:
        printf("Tres \n");
        break;
    case 4:
        printf("Cuatro \n");
        break;
    case 5:
        printf("Cinco \n");
        break;
    default:
        perror("Error el numero no está entre 1 y 5");
        break;
    }
}
