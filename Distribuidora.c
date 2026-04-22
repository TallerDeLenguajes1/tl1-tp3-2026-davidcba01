#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct
{
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
                        // “CantidadProductosAPedir”
} Cliente;

int main()
{
    int n;

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &n);
    getchar(); // limpiar buffer (por el scanf anterior)

    Cliente *clientes;

    clientes = (Cliente *) malloc(n * sizeof(Cliente));

    if(clientes == NULL)
    {
        printf("Error al reservar memoria\n");
        return 1;
    }

    printf("Memoria reservada para %d clientes\n", n);

    for(int i = 0; i < n; i++)
    {
        char buffer[50];

        printf("\nCliente %d\n", i + 1);

        // ID
        clientes[i].ClienteID = i + 1;

        // Nombre
        printf("Ingrese nombre: ");
        gets(buffer);

        // Reservar memoria exacta
        clientes[i].NombreCliente = (char *) malloc((strlen(buffer) + 1) * sizeof(char));

        // Copiar
        strcpy(clientes[i].NombreCliente, buffer);
    }

    return 0;
}