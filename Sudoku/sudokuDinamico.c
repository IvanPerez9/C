#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 9

void pintarTablero(int ** tablero);
void introducirSudoku (int ** tablero);
int checkFilas (int ** tablero);
int checkColumnas (int ** tablero);
int check3x3 (int ** tablero , int iniColumna, int iniFila);
int checkAll3x3 (int ** tablero);
int checkConditions (int ** tablero);
void menu (int **tablero);

int main(int argc, char const *argv[])
{
    // Inicio la matriz dinamica
    int **tablero = (int **) malloc (N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        tablero[i] = (int *) malloc (N * sizeof(int));
    }
    printf("\t\t MENU SUDOKU \n");
    printf("\n");
    printf("\n");
    menu(tablero);

    free(tablero);
    for (int i = 0; i < N; i++)
    {
        free(tablero[i]);
    }
}

void menu (int **tablero){
    int opcion = 0;
    printf("Opcion 1: Introducir nuevo sudoku \n");
    printf("Opcion 2: Pintar el sudoku por pantalla \n");
    printf("Opcion 3: Validar sudoku \n");
    printf("Opcion 4: Salir \n");

    printf("Introduce una opcion:  ");
    scanf("%d" , &opcion);
    printf("\n");

    do
    {
        switch (opcion)
        {
        case 1:
            introducirSudoku(tablero);
            printf("Final de introducir sudoku\n");
            menu(tablero);

        case 2:
            pintarTablero(tablero);
            printf("\n");
            menu(tablero);

        case 3:
            checkConditions(tablero);
            printf("\n");
            menu(tablero);

        case 4:
            printf("Saliendo.. \n");
            break;
        
        default:
            perror("Error en el menu \n");
            exit(0);
            break;
        }
    } while (opcion != 4);
}

/*
Pintar por pantalla el tablero -> Sudoku
params: Tablero o sudoku introducido por consola
return: void
*/
void pintarTablero (int ** tablero){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d " , tablero[i][j]);
        }
        printf("\n");
    }
}

/*
Introducir por consola el sudoku -> Introducir por filas el sudoku
params: Entrada por consola -> Array de 10 posiciones
return: Matriz NxN
*/
void introducirSudoku (int ** tablero){
    printf("Introduce los valores del sudoku de 9x9 \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d " , &tablero[i][j]);
        }
        printf("\n");
    }
}

/*
Comprobar las filas -> Que las filas del sudoku no se repita ningun numero del 1 al 9
params: Tablero, usar un array booleano para controlar
return: Bool si el numero está en la fila si no false
*/
int checkFilas (int ** tablero){
    for (int fil = 0; fil < N; fil++)
    {
        // Array de booleanos -> Ini a 0 "false"
        int rep[N+1] = {0}; 
        for (int col = 0; col < N; col++)
        {
            if (rep[tablero[fil][col]] == 0){
                rep[tablero[fil][col]] ++;
            } else
            {
                printf("No cumple el checkFilas \n");
                return 0 ;
            }
        }
    }
    return 1; // True
}

/*
Comprobar las columnas -> Que las columnas del sudoku no se repita ningun numero del 1 al 9
params: Tablero
return: Bool -> si el numero del 1 al 9 está en la columna o no
*/
int checkColumnas (int ** tablero){
    for (int col = 0; col < N; col++)
    {
        // Empezar en +1 porque 0 no está
        int rep[N+1] = {0};
        for (int fil = 0; fil < N; fil++)
        {
            if (rep[tablero[fil][col]] == 0){
                rep[tablero[fil][col]] ++;
            } else
            {
                printf("No cumple el checkColumnas \n");
                return 0 ;
            }
        }
    }
    return 1; // True
 }

 /*
Comprobar los subtableros -> Que los subtableros de 3x3 no se repita los numeros del 1 al 9
params: Tablero, columna por la que empieza, fila por la que empieza y el num inicial a comprobar
return: Bool -> Si el numero ya está en el subtablero 3x3 o no
*/
int check3x3 (int ** tablero, int iniFila, int iniCol){
    int rep[N+1] = {0};

    for (int fil = iniFila; fil < iniFila+3; fil++)
    {
        for (int col = iniCol; col < iniCol+3; col++)
        {
            if (rep[tablero[fil][col]] == 0){
                rep[tablero[fil][col]]++;
            } else {
                printf("No chequea el 3x3 de la fila %d y la columna %d ", iniFila , iniCol);
                return 0;
            }
        }
    }
    return 1; // True
}

/*
Comprobar todos los cuadrados de la matriz 9x9.
El cuadrado se mueve de 3 en 3
params: Tablero
return: Bool -> Si todos los tableros cumplen
*/
int checkAll3x3 (int ** tablero){
    for (int fil = 0; fil < N; fil+3)
    {
        for (int col = 0; col < N; col+3)
        {
            if (check3x3(tablero , fil, col) != 1){
                perror("Error All3x3 \n");
                return 0;
            }
        }
    }
    return 1; // True
}

/*
Mira si sudoku es valido.
Check if is a valid sudoku
return void -> Frase "Valido"
*/
int checkConditions (int ** tablero){
    if ((checkAll3x3(tablero) && checkColumnas(tablero) && checkFilas(tablero)) == 1){
        printf("Sudoku valido \n");
    } else {
        printf("Sudoku no valido \n");
    }
}

