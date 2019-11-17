/*
Puntero que apunte a un vector para recorrer o lo que sea
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // Este puntero primero inicializa a la primera posicion
    int *p;
    int array[5] = {22,66,5,6,7};
    p = array;
    printf("%d \n" , *p); // Señala a la primera posicion
    printf("%d \n" , *(p+1)); // Siguientes posiciones +1 , +2 ... ojo parentesis
    

    // Este segundo puntero, inicializa a todo el array
    int (*ptr) [5];
    ptr = &array;
    printf("%d \n", *(ptr[0]));
    printf("%d \n", *(ptr[0]+1)); // Igual arriba
    

    // Array dinamico
    int * arrayD;
    int *po;
    arrayD = (int *) malloc (5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        arrayD[i] = i+3;
    }
    po = arrayD;
    printf("%d \n", arrayD[2]);
    printf("%d \n", *(po+2));
    
    free(p);
    p = NULL; // Buena practica
    free(ptr); 
    ptr = NULL;
    free(po);
    po = NULL;
    free(arrayD);
    
    return 0;
}
