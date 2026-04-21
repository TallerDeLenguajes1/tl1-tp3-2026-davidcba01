#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5 // cantidad de nombres

void MostrarPersonas(char *nombres[], int n);
int BuscarNombre(char *nombres[], int n, char *clave);

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

    printf("\n--- Lista de personas ---\n");
    MostrarPersonas(nombres, N);

    char clave[50];

    printf("\nIngrese palabra a buscar: ");
    gets(clave);

    int resultado = BuscarNombre(nombres, N, clave);

    if(resultado != -1) {
        printf("Nombre encontrado: %s\n", nombres[resultado]);
    } else {
        printf("No se encontró el nombre\n");
    }

    return 0;
}

// 2. Implementar una función llamada MostrarPersonas que reciba el vector y muestre 
// todos los nombres almacenados en él por pantalla.
void MostrarPersonas(char *nombres[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Persona %d: %s\n", i + 1, nombres[i]);
    }
}

// Implementar una nueva versión de la función BuscarNombre. Esta versión 
// deberá recibir una palabra clave como argumento y retornar el primer nombre 
// dentro del vector que contenga dicha palabra. Si no existe, debería devolver -1. 
// (Investigá el uso de la función strstr para esta implementación.)
int BuscarNombre(char *nombres[], int n, char *clave) {
    for(int i = 0; i < n; i++) {
        if(strstr(nombres[i], clave) != NULL) {
            return i; // devuelve posición
        }
    }
    return -1; // no encontrado
}