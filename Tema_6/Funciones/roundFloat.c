/*
Convertir un array de floats a enteros redondeandolos
*/

#include <stdio.h>
#include <stdlib.h>

void round (float array[]);

int main(int argc, char const *argv[])
{
    float array[] = {1.22 , 2.33 , 3.33 , 4.12};
    round (array);
    for (int i = 0; i < 4; i++)
    {
        printf("%f" , array[i]);
    }
    return 0;
}

void round (float * array){
    for (int i = 0; i < 4; i++)
    {
        array = (int) array[i];
    }
    
}
