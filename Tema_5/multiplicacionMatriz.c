/*
Escribe un programa que multiplique dos matrices y lo guarde en una matriz resultado.
*/

#include <string.h>
#include<stdio.h>
#include<math.h>

int main()
{
  int m, n, p, q, c, d, k, sum = 0;
  int first[10][10], second[10][10], multiply[10][10];
 
  printf("Numero de columnas y filas de la matriz 1: \n");
  scanf("%d%d", &m, &n);
  printf("Elementos de la primera matriz\n");
 
  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      scanf("%d", &first[c][d]);
 
  printf("Numero de columnas y filas de la matriz 2: \n");
  scanf("%d%d", &p, &q);
 
  if (n != p)
    printf("No puedo multiplicar estas dos matrices.\n");
  else
  {
    printf("Elementos de la segunda matriz\n");
 
    for (c = 0; c < p; c++)
      for (d = 0; d < q; d++)
        scanf("%d", &second[c][d]);
 
    // Suma
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++) {
        for (k = 0; k < p; k++) {
          sum = sum + first[c][k]*second[k][d];
        }
 
        multiply[c][d] = sum;
        sum = 0;
      }
    }
 
    printf("Resultado:\n");
 
    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++)
        printf("%d\t", multiply[c][d]);
 
      printf("\n");
    }
  }
 
  return 0;
}
