#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    /*  
    Implementa un programa que compruebe si dos números enteros son amigos o
    no. Dos números son amigos si la suma de los divisores de uno coincide con el
    otro y viceversa. Por ejemplo, 220 y 284 son amigos porque la suma de sus
    divisores (1 + 2 + 4 +5 + 10 + 11 + 20 + 22 + 44 + 55 + 110) da 284 y la suma de
    los divisores de 284 (1 + 2 + 4 + 71 + 142) da 220
    */
   int n1 = 220;
   int n2 = 284;

   if ((sonAmigos(n1,n2)) == true) {
       printf ("Son amigos");
   } else {
       printf ("No son amigos");
   }
    return 0;
}

bool sonAmigos (int n1, int n2){
    int array [50] ;
    int array2 [50];
    int suma1 = 0;
    int suma2 = 0;

    for (size_t i = 0; i < n1; i++)
    {
        if (n1 % i == 0){
            array[i] = n1 % i;
        }
    }
    for (size_t i = 0; i < n2; i++)
    {
        if (n2 % i == 0){
            array[i] = n2 % i;
        }
    }

    for (size_t i = 0; i < strlen(array); i++)
    {
        suma1 = suma1 + array[i];
    }

    for (size_t i = 0; i < strlen(array2); i++)
    {
        suma2 = suma2 + array[i];
    }
    
    return suma1 == suma2;
    
}