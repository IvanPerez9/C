#include <stdio.h>
#include <stdlib.h>

    int main(int argc, char * argv[]) {
        int * p;
        p = (int *) malloc(sizeof(int));
        if (p == NULL) {
            printf("Sin memoria\n");
            return -1;
        }
        *p = 10;
    }

    // Ojo calloc -> La reserva no indica que se vaya a utilizar para el tipo de dato lo dimensione
    // Si la reserva es de 2 pero el tipo de datos necesita 4, puede fallar

    // Si tengo un array de 10 y quiero una 11, Realloc ? Sobre donde (direccion) y si ya esta ocupada la contigua ? 
    // Liberar matriz con 2 fors anidados
