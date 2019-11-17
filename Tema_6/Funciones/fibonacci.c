#include <stdio.h>
#include <stdlib.h>

int calcularFibonacci (int n);

int main(int argc, char const *argv[])
{
    printf("Introduce el numero de sucesiones que deseas calcular: ");
    int n = 0;
    scanf("%d" , &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d " , calcularFibonacci(i));
    }
    
    return 0;
}

int calcularFibonacci (int n){
    if (n == 0){
        return 0;
    } else if (n == 1){
        return 1;
    } else if (n == 2){
        return 1;
    } else if (n > 2){
        return calcularFibonacci(n-1) + calcularFibonacci(n-2);
    }
}
