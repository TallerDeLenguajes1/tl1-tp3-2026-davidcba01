#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

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
    // i) Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de 
    // clientes.
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

    // ii) Solicitar al usuario la carga de los clientes creados dinámicamente en el paso anterior.
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

        // iii) A medida que se dé de alta cada cliente, Generar aleatoriamente la cantidad de 
        // productos asociados al cliente y sus características.

        srand(time(NULL)); // Para variar lo valores en cada ejecucion

        // Cantidad de productos (1 a 5)
        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;

        // Reservar memoria para productos
        clientes[i].Productos = (Producto *) malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));

        for(int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            // ID
            clientes[i].Productos[j].ProductoID = j + 1;

            // Cantidad (1 a 10)
            clientes[i].Productos[j].Cantidad = rand() % 10 + 1;

            // TipoProducto ("Galletas","Snack","Cigarrillos","Caramelos","Bebidas")
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];

            // Precio (10 a 100)
            clientes[i].Productos[j].PrecioUnitario = (rand() % 91) + 10;
        }
    }

    return 0;
}