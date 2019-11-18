/*
Linked list de ejemplo y funciones
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int valor;
    struct node * next;
} nodo;

void add (nodo * cabecera , int value);
void mostrarLista (nodo *cabecera);
void addIni (nodo * cabecera, int val);
void addIni2 (nodo ** cabecera, int val);
void primero(nodo ** cabecera);
void borrarUltimo (nodo * cabecera);
void borrarIndex (nodo ** cabecera , int index);


int main(int argc, char const *argv[])
{
    struct node * head = NULL; // Cabecera
    head = (struct node *) malloc (sizeof(struct node));
    struct node * second = NULL; 
    second = (struct node *) malloc (sizeof(struct node));
    // Lo mismo pero con el typeDef
    nodo * third = NULL; 
    third = malloc (sizeof(nodo));

    head->valor = 1; // Acceso con -> como . en los punteros
    head->next = second;
    second->valor = 2;
    second->next = third;
    third->valor = 12;
    third->next = NULL;


    // Mostrar
    mostrarLista (head);
    printf("\n");
    // Añadir nodo al final
    add(head , 4);
    // Añadir al principio -> Ojo el paso con & por ser puntero a puntero lo necesario
    addIni2(&head , 11);
    mostrarLista(head);
    printf("\n");
    // Eliminar el primer item de la lista
    primero(&head);
    mostrarLista(head);
    printf("\n");
    // Borrar por index
    borrarIndex(&head, 3); // No empieza en 0
    mostrarLista(head);
    printf("\n");
    // Borrar ultimo elemento
    borrarUltimo(head);
    mostrarLista(head);
    printf("\n");
    
    free(head);
    free(second);
    free(third);
}

/*
Añadir al final de la lista
*/
void add (nodo * cabecera , int value){
    nodo * actual = cabecera;
    while (actual->next != NULL){
        actual = actual->next;
    }
    // Distinto que en el main -> Aqui uso el typedef
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

    while (aux != NULL){
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
Mover la cabecera, mejor que el anterior, mover el puntero
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
    if (index == 1){
        primero(cabecera);
    }

    for (int i = 0; i < index; i++)
    {
        if (actual->next == NULL){
            perror("No he encontrado ese index \n");
        }
        aux = actual;
        actual = actual->next;
    }

    // Ya lo he encontrado
    aux->next = actual->next;
    free(actual);

}