#include <stdio.h>
#include <stdlib.h>

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

    Cliente *clientes;

    clientes = (Cliente *) malloc(n * sizeof(Cliente));

    if(clientes == NULL)
    {
        printf("Error al reservar memoria\n");
        return 1;
    }

    printf("Memoria reservada para %d clientes\n", n);

    return 0;
}