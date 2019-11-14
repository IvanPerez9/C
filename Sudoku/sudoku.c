// Matriz de 9x9 , asegurandome de que tengo memoria
// Ojo a la introduccion, por filas, por columnas o por submatrices
// Analizar filas, analizar columnas y analizar submatrices
// Analizar submatrices quizá punteros ?? Tomando una posicion como referencia
// Verificar que los numeros aparezcan solo 1 vez, guardarlos en una lista sin repetidos (conjunto)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 9

void pintarTablero(int tablero[N][N]);
void introducirSudoku (int tablero[N][N]);
int checkFilas (int tablero[N][N]);
int checkColumnas (int tablero[N][N]);
int check3x3 (int tablero[N][N] , int iniColumna, int iniFila);
int checkAll3x3 (int tablero[N][N]);
int checkConditions (int tablero[N][N]);

void writeSudokuFile (int tablero[N][N]);
void readSudokuFromFile ();

int main(int argc, char const *argv[])
{
    int tablero[N][N] = {{8,3,5, 4,1,6, 9,2,7},
                         {2,9,6, 8,5,7, 4,3,1},
                         {4,1,7, 2,9,3, 6,5,8},
                         
                         {5,6,9, 1,3,4, 7,8,2},
                         {1,2,3, 6,7,8, 5,4,9},
                         {7,4,8, 5,2,9, 1,6,3},
                         
                         {6,5,2, 7,8,1, 3,9,4},
                         {9,8,1, 3,4,5, 2,7,6},
                         {3,7,4, 9,6,2, 8,1,5}};

        /* Prueba entrada teclado
        int tableroPrueba [N][N] = {};
        introducirSudoku(tableroPrueba);
        pintarTablero(tableroPrueba);
        */
    int opcion;
    do
    {
        printf("Menu: \n");
        printf("1. Introducir nuevo Sudoku \n");
        printf("2. Comprobar si fichero es correcto \n");
        printf("3. Guardar sudoku en fichero binario \n");
        printf("4. Leer sudoku de fichero binario y mostrarlo \n");
        printf("5. Salir del programa \n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            introducirSudoku(tablero);
            break;
        
        case 2:
            checkConditions(tablero);
            break;
        
        case 3:
            writeSudokuFile(tablero);
            break;

        case 4:
            readSudokuFromFile();
            break;

        case 5:
            printf("Saliendo.. \n");
            break;
        
        default:
            printf("La opcion elegida no es correcta \n");
            exit(0);
            break;
        }
    } while (opcion != 5);
}

/*
Pintar por pantalla el tablero -> Sudoku
params: Tablero o sudoku introducido por consola
return: void
*/
void pintarTablero(int tablero[N][N]){
    for (int fil = 0; fil < N; fil++)
    {
        for (int col = 0; col < N; col++)
        {
            printf("%d ", tablero[fil][col]);
        }
        printf("\n");
    }
    printf("\n");
}

/*
Introducir por consola el sudoku -> Introducir por filas el sudoku
params: Entrada por consola -> Array de 10 posiciones
return: Matriz NxN
*/
void introducirSudoku (int tablero[N][N]){
    printf("Introduzca valores al nuevo sudoku:  \n");
    for (int fil = 0; fil < N; fil++)
    {
        for (int col = 0; col < N; col++)
        {
            scanf("%d" , &tablero[fil][col]);
        }
        printf("\n");
    }
}

/*
Comprobar las filas -> Que las filas del sudoku no se repita ningun numero del 1 al 9
params: Tablero, usar un array booleano para controlar
return: Bool si el numero está en la fila si no false
*/
int checkFilas (int tablero[N][N]){

    for (int fil = 0; fil < N; fil++){
        // Array booleano -> No empezar en 0
        int repe [N+1] = {0};

        for (int col = 0; col < N; col++)
        {
            // Paro en cuando tenga un valor mayor a 0
            // Si lo encuentro -> Arrya bool, sustituyo 0 por 1 en ese valor
            if (repe[tablero[fil][col]] == 0){
                repe[tablero[fil][col]]++;
            } else {
                return 0;
            }
        }
    }
    return 1; // True -> Valido
}

/*
Comprobar las columnas -> Que las columnas del sudoku no se repita ningun numero del 1 al 9
params: Tablero
return: Bool -> si el numero del 1 al 9 está en la columna o no
*/
int checkColumnas (int tablero[N][N]){
    for (int col = 0; col < N; col++){
        // Array booleano -> No empezar en 0
        int repe [N+1] = {0};

        for (int fil = 0; fil < N; fil++)
        {
           if (repe[tablero[fil][col]] == 0){
                repe[tablero[fil][col]]++;
            } else {
                return 0;
            }
        }
    }
    return 1; // True -> Valido
}

/*
Comprobar los subtableros -> Que los subtableros de 3x3 no se repita los numeros del 1 al 9
params: Tablero, columna por la que empieza, fila por la que empieza y el num inicial a comprobar
return: Bool -> Si el numero ya está en el subtablero 3x3 o no
*/
int check3x3 (int tablero[N][N] , int iniColumna, int iniFila){
    int repe [N+1] = {0};
    
    for (int i = iniFila; i < iniFila+3; i++)
    {
        for (int j = iniColumna; j < iniColumna+3; j++)
        {
            if (repe[tablero[i][j]] == 0){
                repe[tablero[i][j]]++;
            } else {
                return 0;
            }
        }
    }
    /*OLD: Inicializar en valor 1 -> En el repe de antes menos complejidad
    for (int k = 1; k <= N; k++)
    {
        if (repe[k] != 1){
            return 0;
        }
    }*/
    return 1;
}

/*
Comprobar todos los cuadrados de la matriz 9x9.
El cuadrado se mueve de 3 en 3
params: Tablero
return: Bool -> Si todos los tableros cumplen
*/
int checkAll3x3 (int tablero[N][N]){
    for (int i = 0; i < N; i+=3)
    {
        for (int j = 0; j < N; j+=3)
        {
            if ( ! check3x3(tablero , i ,j)){ // Chequear not -> bool
                return 0;
            }
        }
    }
    return 1;
}

/*
Mira si sudoku es valido.
Check if is a valid sudoku
return void -> Frase "Valido"
*/
int checkConditions (int tablero[N][N]){
    /* La suma de cada fila = 54
       La suma de cada columna = 54
       La suma de cada 3x3 = 54
       Suma total = 486
    */
    if( checkAll3x3(tablero) && checkColumnas(tablero) && checkFilas(tablero)) {
        printf("Sudoku valido \n");
    } else {
        printf("Sudoku no valido \n");
    }
}

/*
Escribir un sudoku en un fichero binario
params: Sudoku
return: Fichero binario
*/
void writeSudokuFile (int tablero[N][N]){
    FILE * fichero;
    if ((fichero = fopen("FicheroSudoku.bin" , "wb+")) == NULL) {
        perror("Error al abrir el fichero modo escritura");
        exit(1);
    }

    if (fwrite(tablero , sizeof(int) , N*N , fichero) != 81){
        printf("Error al escribir");
    }
    fclose(fichero);
}

/*
Leer sudoku desde fichero
params: 
return: Mostrado de sudoku leido desde el fichero
*/
void readSudokuFromFile (){
    FILE * fichero;
    if ((fichero = fopen("FicheroSudoku.bin" , "rb")) == NULL) {
        perror("Error al abrir el fichero modo lectura");
        exit(1);
    }

    int grid [N][N] = {0};

    if ((fread(grid , sizeof(int) , N*N , fichero)) != 81){
        if (feof(fichero)){
            printf("Fichero EOF temprano");
        } else {
            printf("Error leyendo fichero");
        }
    }
    fclose(fichero);
    // Mostrarlo
    pintarTablero(grid);
}