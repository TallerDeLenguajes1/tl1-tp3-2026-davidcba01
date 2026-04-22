#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable
                                 //  “CantidadProductosAPedir”
} Cliente;

float calcularCostoTotalProducto(Producto p);

int main()
{
    srand(time(NULL)); // Para variar lo valores en cada ejecucion

    // i) Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de
    // clientes.
    int cantidadClientes;

    do
    {
        printf("Ingrese la cantidad de clientes (max 5): ");
        scanf("%d", &cantidadClientes);

        if (cantidadClientes < 1 || cantidadClientes > 5)
        {
            printf("Error: debe ingresar un valor entre 1 y 5\n");
        }

    } while (cantidadClientes < 1 || cantidadClientes > 5);

    getchar(); // limpiar buffer (por el scanf anterior)

    Cliente *clientes;

    clientes = (Cliente *)malloc(cantidadClientes * sizeof(Cliente));

    if (clientes == NULL)
    {
        printf("Error al reservar memoria\n");
        return 1;
    }

    // ii) Solicitar al usuario la carga de los clientes creados dinámicamente en el paso anterior.
    for (int i = 0; i < cantidadClientes; i++)
    {
        char buffer[50];

        printf("\n--- Cliente %d ---\n", i + 1);

        // ID
        clientes[i].ClienteID = i + 1;

        // Nombre
        printf("Ingrese nombre: ");
        gets(buffer);

        // Reservar memoria exacta
        clientes[i].NombreCliente = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

        // Copiar
        strcpy(clientes[i].NombreCliente, buffer);

        // iii) A medida que se dé de alta cada cliente, Generar aleatoriamente la cantidad de
        // productos asociados al cliente y sus características.

        // Cantidad de productos (1 a 5)
        clientes[i].CantidadProductosAPedir = rand() % 5 + 1;

        // Reservar memoria para productos
        clientes[i].Productos = (Producto *)malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
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

    // v) Mostrar por pantalla todo lo cargado. Incluyendo un total a pagar por cliente
    // (sumatoria del costo de todos los productos)
    printf("\n===== LISTADO COMPLETO =====\n");

    for (int i = 0; i < cantidadClientes; i++)
    {

        printf("\nCliente %d\n", clientes[i].ClienteID);
        printf("Nombre: %s\n", clientes[i].NombreCliente);
        printf("Cantidad de productos a pedir: %d\n", clientes[i].CantidadProductosAPedir);

        float totalCliente = 0;

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {

            Producto p = clientes[i].Productos[j];

            printf("\n  Producto %d\n", p.ProductoID);
            printf("  Tipo: %s\n", p.TipoProducto);
            printf("  Cantidad: %d\n", p.Cantidad);
            printf("  Precio Unitario: %.2f\n", p.PrecioUnitario);

            float costo = calcularCostoTotalProducto(p);
            printf("  Costo: %.2f\n", costo);

            totalCliente += costo;
        }

        printf("\n>>> Total a pagar por cliente: %.2f\n", totalCliente);
    }

    // Liberación de memoria
    for (int i = 0; i < cantidadClientes; i++)
    {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);

    return 0;
}

// iv) Implemente una función que calcule el costo total de un producto. Esta función debe
// recibir como parámetro el producto y devolver el resultado de calcular la Cantidad por
// el PrecioUnitario.
float calcularCostoTotalProducto(Producto p)
{
    return p.Cantidad * p.PrecioUnitario;
}