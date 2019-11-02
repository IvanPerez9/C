/*
 Escribe un programa que, dada una contraseña almacenada en una cadena de caracteres,
indique su nivel de seguridad imprimiéndolo por pantalla. Se consideran los siguientes niveles
de seguridad:
• Nivel muy bajo: la contraseña tiene menos de 6 caracteres
• Nivel bajo: la contraseña se compone solo de números o solo de letras
• Nivel medio: la contraseña se compone de al menos un número y una letra
• Nivel alto: la contraseña se compone de al menos un número, una letra y un carácter
especial
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int soloNumeros (char pw []);
int soloLetras (char pw []);

// Faltan bien los bool pero es asi

int main(int argc, char const *argv[])
{
    char pw[20];
    printf("Introduce la constrasenna \n : " );
    scanf("%s" , &pw);

    if (strlen(pw) < 6){
        printf("La contrasena tiene menos de 6 caracteres, nivel muy bajo de seguridad \n");
    } else if (soloLetras(pw) == 1 || soloNumeros(pw) == 1) {
        printf("La contasena solo tiene numeros o letras, nivel bajo de seguridad \n");
    } else if (!soloLetras(pw) == 1 && !soloNumeros(pw) == 1){
        printf("Nivel medio, se compone de letras y numeros \n");
    } else {
        printf("Tiene digitos especial, nivel alto de seguridad \n");
    }
    return 0;
}

// False == 1
// ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90) en ASCII
int soloLetras (char pw []){
    int salida = 0;
    for (int i = 0; i < 20; i++)
    {
        if (!(pw[i] >= 'a' && pw[i] <= 'z') || !(pw[i] >= 'A' && pw[i] <= 'Z')){
            salida = 1;
        }
    }
}

int soloNumeros (char pw []){
    int salida = 0;
    for (int i = 0; i < 20; i++)
    {
        if (!(pw[i] >= '0' && pw[i] <= '9')){
            salida = 1;
        }
    }
}
