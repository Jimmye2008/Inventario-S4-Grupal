#include <stdio.h>
#include <string.h>

int main() {
    char nombres[10][50];
    float precios[10];
    int cantidad = 0;
    int opcion;

    printf("--- REGISTRO DE INVENTARIO ---\n");
    
    do {
        cantidad = 0;
        printf("Cuantos productos desea registrar? (Entre 1 y 10): ");
        scanf("%d", &cantidad);
        
        while (getchar() != '\n');
        
        if (cantidad < 1 || cantidad > 10) {
            printf("Error: Ingrese un numero valido entre 1 y 10.\n\n");
        }
    } while (cantidad < 1 || cantidad > 10);

    for (int i = 0; i < cantidad; i++) {
        printf("\nProducto %d:\n", i + 1);
        printf("Nombre (sin espacios): ");
        scanf("%s", nombres[i]); 
        
        while (getchar() != '\n');
        
        int duplicado = 0;
        
        for (int j = 0; j < i; j++) {
            if (strcmp(nombres[i], nombres[j]) == 0) {
                printf("Error: El producto '%s' ya esta registrado. Ingrese otro.\n", nombres[i]);
                duplicado = 1;
                break;
            }
        }

        if (duplicado == 1) {
            i--;
            continue;
        }

        do {
            precios[i] = -1;
            printf("Precio: $");
            scanf("%f", &precios[i]);
            
            while (getchar() != '\n');
            
            if (precios[i] < 0) {
                printf("Error: El precio no puede ser negativo o invalido. Intente de nuevo.\n");
            }
        } while (precios[i] < 0);
    }

    do {
        printf("\n--- MENU DE FUNCIONES ---\n");
        printf("1- Calcular precio total del inventario\n");
        printf("2- Mostrar producto mas caro y mas barato\n");
        printf("3- Calcular precio promedio\n");
        printf("4- Buscar producto por nombre\n");
        printf("5- Salir\n");
        
        opcion = 0;
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        while (getchar() != '\n');

        switch(opcion) {
            case 1: {
                float total = 0;
                for (int i = 0; i < cantidad; i++) {
                    total += precios[i];
                }
                printf("\n> El precio total del inventario es: $%.2f\n", total);
                break;
            }
            case 2: {
                float maxPrecio = precios[0];
                float minPrecio = precios[0];
                int idxMax = 0, idxMin = 0;

                for (int i = 1; i < cantidad; i++) {
                    if (precios[i] > maxPrecio) {
                        maxPrecio = precios[i];
                        idxMax = i; 
                    }
                    if (precios[i] < minPrecio) {
                        minPrecio = precios[i];
                        idxMin = i; 
                    }
                }
                printf("\n> Producto mas caro: %s ($%.2f)\n", nombres[idxMax], maxPrecio);
                printf("> Producto mas barato: %s ($%.2f)\n", nombres[idxMin], minPrecio);
                break;
            }
            case 3: {
                float totalPromedio = 0;
                for (int i = 0; i < cantidad; i++) {
                    totalPromedio += precios[i];
                }
                printf("\n> El precio promedio de los productos es: $%.2f\n", totalPromedio / cantidad);
                break;
            }
            case 4: {
                char buscar[50];
                int encontrado = 0;
                printf("\nIngrese el nombre del producto a buscar: ");
                scanf("%s", buscar);
                
                while (getchar() != '\n');

                for (int i = 0; i < cantidad; i++) {
                    if (strcmp(nombres[i], buscar) == 0) {
                        printf("> Producto encontrado: %s - Precio: $%.2f\n", nombres[i], precios[i]);
                        encontrado = 1;
                        break;
                    }
                }
                if (encontrado == 0) {
                    printf("> Producto no encontrado en el inventario.\n");
                }
                break;
            }
            case 5:
                printf("\nFin del sistema.\n");
                break;
            default:
                printf("\n> Opcion no valida. Por favor, seleccione un numero del 1 al 5.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}