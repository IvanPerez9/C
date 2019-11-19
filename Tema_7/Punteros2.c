
#include <stdio.h>

/* REVISAR
Implementa el juego del ahorcado. Para ello, se pedirá al usuario que introduzca
por teclado una palabra de como máximo 10 letras. A continuación, se
almacenará dicha palabra en un array. Utilizando únicamente punteros, se
pedirá al usuario que introduzca letras hasta completar la palabra o hasta haber
realizado 5 intentos erróneos
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define palabra "castigo"
#define vidas 6

int comparar(char*,char*,char);
void rellenar(char*);
int contener(char,char*);
void mostrar(char*);

int main() {
   printf("longitud de la palabra: %d\n",strlen(palabra));
   int restantes = vidas;
   char* letras =(char*) malloc(strlen(palabra)*(sizeof(char)+1)); // Array de letras de la palabra
   rellenar(letras);
   char c;

   do{
       mostrar(letras);

       printf("\n\nVidas restantes: %d\n",restantes);
       do{
           printf("Dame letra\n");
           scanf(" %c",&c);
       
       }while(contener(c,letras));

    restantes = restantes - comparar(palabra,letras,c);    
      


   }while ((restantes>0)&&(strcmp(palabra,letras)!=0));

   if (restantes==0) printf("Fallaste\n");
   else printf("Enhorabuena\n"); 
    free(letras);
    return 0;
  }

int comparar(char* buscada,char*rellena,char letra){
    int encontrar = 0;
    for (int i=0;i<strlen(palabra);i++){
       if (*(buscada + i)== letra){
           encontrar=1;
           *(rellena+i)=letra;
       }
   }
  
   if (encontrar==0) return 1;
   else return 0;

}

/*
Poner al final \0 para saber donde acaba
*/
void rellenar(char* letras){
    for (int i=0;i<strlen(palabra);i++){
       *(letras + i)='_';
   }
   *(letras + strlen(palabra))='\0';
}

int contener(char letra,char* letras){
    int contener=0;
    int i=0;
    do{
       contener=(*(letras + i)== letra);
       i++;
    }while(i<strlen(palabra));
   return contener;
}

void mostrar(char* letras){
     for (int i=0;i<strlen(palabra);i++){
        // printf(" %c ",*(letras + i));
         printf(" %c ",letras[i]);
   }
}
