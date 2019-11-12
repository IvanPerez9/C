/*
Dada una matriz de tamaño 4x3, implementa un programa que, haciendo uso de
aritmética de punteros, calcule la suma de cada una de sus filas y las imprima
por pantalla

USO DE PUNTEROS
*/

#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    // Filas y columnas
    int matriz [4][3] = { {1,2,3},
                          {2,2,2},
                          {3,3,3},
                          {4,4,3}  };
    
    int * fila ;
    int sumaFila = 0;
    // Filas de manera consecutiva 
    for (int i = 0; i < 4; i++)
    {
        fila = matriz[i]; // Puntero
        for (int j = 0; j < 3; j++)
        {
            sumaFila += * fila++;
        }
        printf("%d \n" , sumaFila);
        sumaFila = 0;
    }
    
    return 0;
}
