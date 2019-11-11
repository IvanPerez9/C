
//Implementa un programa que cree dos arrays dinámicos de N elementos y
//guarde en un tercer array dinámico la suma de cada par de posiciones 

// SUMA DE ARRAYS

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int * q;
    int * p;
    int * t;
    int n = 3;

    p = (int *) malloc (n * sizeof(int)) ;// Array hacer 3 , rellenar con rand
    q  = (int *) malloc (n * sizeof(int));
    t = (int *) malloc (n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        // Mismo acceso
        *(q+i) = rand()%100 ;
         q[i] = rand()%100;
    }

    for (int i = 0; i < n; i++)
    {
       *(p+i) = rand()%100 ;
       p[i] = rand()%100;
    }

    for (int i = 0; i < n; i++)
    {
        *(t+i) = *(p+i) + (*(q+i));
        printf("%d + %d = %d\n" , *(p+i), *(q+i) , *(t+i));
    }

    for (int i = 0; i < n; i++)
    {
        /* code */
        free(t[i]);
        free(p[i]);
        free(&q[i]);
    }
    
    return 0;
}
