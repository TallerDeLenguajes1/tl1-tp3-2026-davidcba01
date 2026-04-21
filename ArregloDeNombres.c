#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5 // cantidad de nombres

int main() {
    char *nombres[N];   // vector de punteros
    char buff[50];    // auxiliar (nota 2)
    
    // 1. El programa deberá pedir al usuario que ingrese 5 nombres de personas. Estos nombres 
    // se almacenarán en un vector donde cada elemento sea un puntero a un bloque de 
    // memoria (de tipo char) asignado dinámicamente para contener cada nombre.
    for(int i = 0; i < N; i++) {
        printf("Ingrese el nombre %d: ", i + 1);
        gets(buff);  // nota 3

        // Reservo memoria exacta
        nombres[i] = (char *) malloc((strlen(buff) + 1) * sizeof(char));

        // Copio el contenido
        strcpy(nombres[i], buff);
    }

    return 0;
}