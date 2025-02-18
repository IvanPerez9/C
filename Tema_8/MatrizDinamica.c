#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 2

void ini(int **arr,int m,int n)
{
    int i, j;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

void imprimir (int **arr, int m, int n){
    // Imprimo la matriz
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++){
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }
}

void freeMatrix ( int **arr, int n){
    printf("Libero memoria.. \n");
    free(arr);
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
}

void writeFile (int **arr){
    FILE * fichero;
    if ((fichero = fopen("ficheroMatriz.bin" , "wb+")) == NULL){
        perror("Error al abrir el fichero");
        exit(1);
    }

    if (fwrite(arr , sizeof(int), M*N , fichero) != N*M){
        perror("Error al escribir en fichero");
    }
    fclose(fichero);
}

void readFile (){
    FILE * fichero;
    if ((fichero = fopen("ficheroMatriz.bin" , "rb")) == NULL){
        perror("Error al ebrir fichero");
        exit(1);
    }

    int ** ret = (int **) malloc (M * sizeof(int *));
    for (int i = 0; i < M; i++)
    {
        ret[i] = (int *) malloc (N * sizeof(int));
    }

    if ((fread(ret , sizeof(int) , M*N, fichero)) != M*N){
        perror("Error al leer fichero \n");
        exit(1);
    }

    fclose(fichero);
    imprimir(ret, M, N);
    
}

int main()
{
    int i,j;
    // Declaro matriz
    int **a=(int **)malloc(M*sizeof(int *));
    for(i=0;i<M;i++)
        a[i]=(int *)malloc(N*sizeof(int));

    // Relleno la matriz dinamica
    printf("Rellena matriz: \n");
    ini(a,M,N);
    printf("\n");

    // Imprimo
    imprimir(a, M, N);
    printf("\n");

    //Escribo en fichero
    writeFile(a);

    // Leo de fichero
    readFile();

    // Libero
    freeMatrix(a,N);

    return 0;
}