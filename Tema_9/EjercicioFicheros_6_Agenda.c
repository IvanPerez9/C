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
	char telefono[15];
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
        fwrite(&contacto , sizeof(contacto), 1, fichero);
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

    fwrite(&nuevoC , sizeof(nuevoC), 1, fichero);
    printf("Nueno contacto annadido \n");
    fclose(fichero);
}

void mostrarListaContactos (char nombreFichero[]){
    FILE * fichero;
    if ((fichero = fopen(nombreFichero, "a")) == NULL){
        perror("Error al abrir el fichero binario \n");
        exit(1);
    }

    struct datosContacto contacto;
    fread(&contacto , sizeof(contacto), 1, fichero); // Saco los contactos 1 a 1 ?

    while(!feof(fichero)){

    }

    fclose(fichero);
}

void buscarContacto (char nombreFichero[]){
    FILE * fichero;
    if ((fichero = fopen(nombreFichero, "a")) == NULL){
        perror("Error al abrir el fichero binario \n");
        exit(1);
    }

    struct datosContacto contacto;
    fgets(contacto.nombre , sizeof contacto , fichero);
    printf("Introduce el nombre del contacto que quiere buscar: ");
    char nombreBuscar [60];
    scanf("%s" , &nombreBuscar);
    printf("%s", nombreBuscar);
    printf("%s" , contacto.nombre);

    while(!feof(fichero)){
        int ret = strcmp(strlwr(contacto.nombre), strlwr(nombreBuscar));
        if (ret == 0){
            printf("\n Nombre: %s \n" , contacto.nombre);
            printf("\n Apellido: %s" , contacto.apellido);
            printf("\n Telefono: %s" , contacto.telefono);
            return;
        } else {
            printf("Nombre no encontrado \n");
            fclose(fichero);
            return;
        }
        fgets(contacto.nombre , sizeof contacto , fichero);
    }
    fclose(fichero);
}