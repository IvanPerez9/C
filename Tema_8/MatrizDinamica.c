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

int main()
{
    int i,j;
    // Declaro matriz
    int **a=(int **)malloc(M*sizeof(int));
    for(i=0;i<N;i++)
        a[i]=(int *)malloc(N*sizeof(int));

    // Relleno la matriz dinamica
    ini(a,M,N);
    printf("\n");

    // Imprimo
    imprimir(a, M, N);
    printf("\n");

    // Libero
    freeMatrix(a,N);

    return 0;
}