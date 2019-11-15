/*
 Crea un programa que simule la entrada en una agenda de teléfonos y la almacene en
disco. De cada contacto se desea recoger por consola nombre, apellidos y teléfono. 
*/

#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<string.h>

void crearAgendaNueva (char nombreFichero[]);
void nuevoContacto (char nombreFichero[]);
void buscarContacto (char nombreFichero[]);
void mostrarListaContactos (char nombreFichero[]);

struct datosContacto{
	char nombre[60];
    char apellido [60];
	char telefono [10];
};

int main(int argc, char const *argv[])
{
    int opcion;
    do
    {
        printf("Menu: \n");
        printf("1. Nueva agenda \n");
        printf("2. Nuevo contacto \n");
        printf("3. Buscar contacto por nombre \n");
        printf("4. Mostrar lista de contactos \n");
        printf("5. Salir del programa \n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            crearAgendaNueva("agenda.txt");
            break;
        
        case 2:
            nuevoContacto("agenda.txt");
            break;
        
        case 3:
            buscarContacto("agenda.txt");
            break;

        case 4:
            mostrarListaContactos("agenda.txt");
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
    return 0;
}

void crearAgendaNueva (char nombreFichero[]){
    char opcionNueva;
    printf("Va a crear una nueva agenda, en caso de tener una ya se perderá \n");
    printf("Desea continuar? (S/N) : ");
    scanf(" %c" , &opcionNueva); // Dejar espacio

    if (opcionNueva == 'N' || opcionNueva == 'n'){
        printf("Cancelando..\n");
        exit(1);
    }
    printf("\n");
    FILE * fichero;
    if ((fichero = fopen(nombreFichero, "w")) == NULL){
        perror("Error al abrir el fichero binario \n");
        exit(1);
    }

    struct datosContacto contacto;

    printf("Cuantos contactos desea tener inicialmente en la agenda ? \n");
    int numContactos = 0;
    scanf("%d" , &numContactos);
    int contador = 0;

    do
    {
        printf("\n Nombre: ");
        fflush(stdin);
        gets(contacto.nombre);
        printf("\n Apellido: ");
        fflush(stdin);
        gets(contacto.apellido);
        printf("\n Telefono: ");
        fflush(stdin);
        gets(contacto.telefono);
        printf("\n");
        struct datosContacto contactoPrueba = {"Ivan" , "Perez" , "123"}; // Lo meto por defecto
        size_t i = fwrite(&contactoPrueba , sizeof(struct datosContacto), 1, fichero);
        if (i < 1){
            printf("No estoy escribiendo:");
        }
        fwrite(&contacto , sizeof(struct datosContacto), 1, fichero);
        contador++;

    } while (contador != numContactos);
    
    fclose(fichero);

    printf("Agenda creada \n");
    return;
}

void nuevoContacto (char nombreFichero[]){
    FILE * fichero;
    if ((fichero = fopen(nombreFichero, "a")) == NULL){
        perror("Error al abrir el fichero binario \n");
        exit(1);
    }

    struct datosContacto nuevoC;
    printf("\n Nombre: ");
    fflush(stdin);
    gets(nuevoC.nombre);       
    printf("\n Apellido: ");
    fflush(stdin);
    gets(nuevoC.apellido);
    printf("\n Telefono: ");
    fflush(stdin);
    gets(nuevoC.telefono);

    size_t comprobacion = fwrite(&nuevoC , sizeof(struct datosContacto), 1, fichero);
    if (comprobacion < 1){
        printf("Error al escribir");
    }
    printf("Nueno contacto annadido \n");
    fclose(fichero);
}

void mostrarListaContactos (char nombreFichero[]){
    FILE * fichero;
    if ((fichero = fopen(nombreFichero, "r")) == NULL){
        perror("Error al abrir el fichero binario \n");
        exit(1);
    }

    struct datosContacto contacto;
    while(fread(&contacto , sizeof(struct datosContacto), 1, fichero)){
        printf(" \t Nombre: %s \n" , contacto.nombre);
        printf("\t Apellido: %s \n" , contacto.apellido);
        printf("\t Telefono: %s \n" , contacto.telefono);
        printf("\n");
        printf("\n");
    }

    fclose(fichero);
}

void buscarContacto (char nombreFichero[]){
    FILE * fichero;
    if ((fichero = fopen(nombreFichero, "r")) == NULL){
        perror("Error al abrir el fichero binario \n");
        exit(1);
    }

    struct datosContacto contacto;
    printf("Introduce el nombre del contacto que quiere buscar: ");
    char nombreBuscar [60];
    scanf("%s" , &nombreBuscar);

    while(fread(&contacto , sizeof(struct datosContacto), 1, fichero)){
        int ret = strcmp(strlwr(contacto.nombre), strlwr(nombreBuscar));
        if (ret == 0){
            printf("ENCONTRADO \n");
            printf(" \t Nombre: %s \n" , contacto.nombre);
            printf("\t Apellido: %s \n" , contacto.apellido);
            printf("\t Telefono: %s \n" , contacto.telefono);
            printf("\n");
            printf("\n");
            fclose(fichero);
            return;
        } else {
            printf("Nombre no encontrado \n");
            fclose(fichero);
            return;
        }
    }
    fclose(fichero);
    return;
}