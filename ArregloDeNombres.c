#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5 // cantidad de nombres

void MostrarPersonas(char *nombres[], int n);
void BuscarNombre(char *nombres[], int n, int id);

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

    int id;
    printf("\nIngrese el ID a buscar: ");
    scanf("%d", &id);

    BuscarNombre(nombres, N, id);

    return 0;
}

// 2. Implementar una función llamada MostrarPersonas que reciba el vector y muestre 
// todos los nombres almacenados en él por pantalla.
void MostrarPersonas(char *nombres[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Persona %d: %s\n", i + 1, nombres[i]);
    }
}

// En este branch, implementar una función BuscarNombre que reciba un número 
// entero positivo de ID (índice del vector) como entrada y Escribir por pantalla el 
// nombre ubicado en esa posición dentro del vector. Si el número ingresado no 
// pertenece al vector escribir “no se encontró el valor buscado”.
void BuscarNombre(char *nombres[], int n, int id) {
    if(id >= 0 && id < n) {
        printf("Nombre encontrado: %s\n", nombres[id]);
    } else {
        printf("No se encontró el valor buscado\n");
    }
}