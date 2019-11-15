/*
Linked list de ejemplo y funciones
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int valor;
    struct nodo * next;
} nodo;

int main(int argc, char const *argv[])
{
    nodo * head = NULL; // Cabecera
    head = malloc (sizeof(nodo));
    if (head == NULL){
        return 1;
    }
    head->valor = 1; // Acceso con -> como . en los punteros
    head->next = NULL;
    return 0;
}

/*
Añadir al final de la lista
*/
void add (nodo * cabecera , int value){
    nodo * actual = cabecera;
    while (actual->next != NULL){
        actual = actual->next;
    }
    nodo *nuevoNodo;
    nuevoNodo = malloc(sizeof(nodo));
    nuevoNodo->next = NULL;
    nuevoNodo->valor = value;

    // Si encuentro el final lo añado
    actual->next = malloc(sizeof(nodo));
    actual->next = nuevoNodo;
}

/*
Imprimir todos los items de la lista
*/
void mostrarLista (nodo *cabecera){
    nodo * aux = cabecera;

    while (aux->next != NULL){
        printf("%d \n" , aux->valor);
        aux = aux->next;
    }
}

/*
Añadir al principio de la lista
*/
void addIni (nodo * cabecera, int val){
    nodo *nuevoNodo;
    nuevoNodo = malloc(sizeof(nodo));

    nuevoNodo->valor = val;
    nuevoNodo->next = cabecera;
}

/*
Mover la cabecera
*/
void addIni2 (nodo ** cabecera, int val){
    nodo *nuevoNodo;
    nuevoNodo = malloc(sizeof(nodo));

    nuevoNodo->valor = val;
    nuevoNodo->next = *cabecera;
    *cabecera = nuevoNodo;
}

/*
Eliminar el primer item de la lista -> Primero
*/
void primero(nodo ** cabecera){
    nodo * aux = NULL; // Guardar info de a donde apunta la cabecera
    aux = (*cabecera)->next;
    free(*cabecera);
    *cabecera = aux;
}

/*
Borrar el ultimo item de la lista
*/
void borrarUltimo (nodo * cabecera){
    if (cabecera->next == NULL){ // Solo hay 1
        free(cabecera);
    }

    nodo * actual = cabecera;
    nodo * actualSig = actual->next;
    while(actualSig->next != NULL){
        actual = actual->next;
        actualSig = actualSig->next;
    }

    // Legariamos al ultimo y penultimo
    free(actualSig);
    actual->next = NULL;
}

/*
Borrar uno en especifico -> Por index
*/
void borrarIndex (nodo ** cabecera , int index){
    nodo * actual = *cabecera;
    nodo * aux = NULL;
    // Si es solo 1
    if (index == 0){
        primero(cabecera);
    }

    for (int i = 0; i < index-1; i++)
    {
        if (actual->next == NULL){
            perror("No he encontrado ese index \n");
            return -1;
        }
        aux = actual;
        actual = actual->next;
    }

    // Ya lo he encontrado
    aux->next = actual->next;
    free(actual);

}