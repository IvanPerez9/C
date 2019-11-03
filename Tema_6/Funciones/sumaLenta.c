/*
Implementa un programa que realice la suma lenta de manera recursiva. La
suma lenta entre dos números se realiza restando uno al segundo y sumándoselo
al primero hasta que el segundo llegue a 0. Por ejemplo, la suma lenta de 3+2 se
realiza:3 2, 4 1, 5 0, siendo 5 el resultado.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int sumaLenta (int n1 , int n2);

int main(int argc, char const *argv[])
{
    printf("Introduce el primer sumando: ");
    int n1 = 0;
    scanf("%d" , &n1);
    int n2 = 0;
    printf("Introduce el segundo sumando: ");
    scanf("%d" , &n2);
    int suma = sumaLenta(n1,n2);
    printf("Suma: %d" , suma);
    return 0;
}

int sumaLenta (int n1 , int n2){
    while (n2 != 0)
    {
        n1++;
        n2--;
    }
    return n1;
}
