/*
Implementa una función que reciba un entero y devuelva el inverso de ese
entero
*/

#include <stdlib.h>
#include <stdio.h>

int funcionInverso ();

int main(int argc, char const *argv[])
{
    int ret = funcionInverso();
    printf("Numero inverso: %d" , ret);
    return 0;
}

// Numero dado la vuelta
int funcionInverso (){
    printf("Introduce un numero entero: ");
    int num = 0;
    scanf("%d" , &num);
    int inverso = 0;
    while (num != 0){
        inverso = inverso * 10;
        inverso = inverso +  (num % 10);
        num = num / 10;
    }
    return inverso;
}