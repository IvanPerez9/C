// Comprobar si un numero es primo o no
#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    /* code */
    int num;
    printf("Introduce el numero que quiere comprobar si es primo o no: ");
    scanf("%d" , &num);
    int esPrimo = 0;

    for (int i = 2; i <= num/2; i++)
    {
        if ((num % i) == 0)
        {
            esPrimo = 1;
            break;
        }
    }

    if (num == 1){
        printf("El 1 no cuenta para primo o no");
    } else {
        if (esPrimo == 0){
            printf("El numero %d es primo" , num);
        } else {
            printf("El numero %d no es primo" , num);
        }
    }
    return 0;
}


