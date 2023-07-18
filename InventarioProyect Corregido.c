#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE_PRODUCTO 50

// Variables para almacenar los datos de los productos
char nombres[MAX_PRODUCTOS][MAX_NOMBRE_PRODUCTO];
int cantidades[MAX_PRODUCTOS];
float precios[MAX_PRODUCTOS];
int numProductos = 0;

// Función para ingresar un nuevo producto
void ingresarProducto() {
    char nuevoNombre[MAX_NOMBRE_PRODUCTO];
    int nuevaCantidad;
    float nuevoPrecio;

    printf("Ingresar nombre del producto: ");
    fflush(stdin);
    gets(nuevoNombre);
    fflush(stdin);
    printf("Ingresar cantidad: ");
    scanf("%d", &nuevaCantidad);
    printf("Ingresar precio: ");
    scanf("%f", &nuevoPrecio);

    strncpy(nombres[numProductos], nuevoNombre, MAX_NOMBRE_PRODUCTO - 1);
    nombres[numProductos][MAX_NOMBRE_PRODUCTO - 1] = '\0';
    cantidades[numProductos] = nuevaCantidad;
    precios[numProductos] = nuevoPrecio;

    numProductos++;

    printf("Producto ingresado exitosamente.\n");
}

// Función para editar un producto existente
void editarProducto() {
    int indice;
    printf("Ingrese el índice del producto a editar: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < numProductos) {
        printf("Editar nombre del producto: ");
        fflush(stdin);
        gets(nombres[indice]);
        fflush(stdin);
        printf("Editar cantidad: ");
        scanf("%d", &cantidades[indice]);
        printf("Editar precio: ");
        scanf("%f", &precios[indice]);

        printf("Producto editado exitosamente.\n");
    } else {
        printf("Índice inválido.\n");
    }
}

// Función para eliminar un producto existente
void eliminarProducto() {
    int indice;
    printf("Ingrese el índice del producto a eliminar: ");
    scanf("%d", &indice);

    if (indice >= 0 && indice < numProductos) {
        // Desplazar los productos restantes hacia atrás para llenar el espacio vacío
        for (int i = indice; i < numProductos - 1; i++) {
            strncpy(nombres[i], nombres[i + 1], MAX_NOMBRE_PRODUCTO);
            cantidades[i] = cantidades[i + 1];
            precios[i] = precios[i + 1];
        }

        numProductos--;

        printf("Producto eliminado exitosamente.\n");
    } else {
        printf("Índice inválido.\n");
    }
}

// Función para listar los productos ingresados
void listarProductos() {
    printf("----- Listado de productos -----\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Índice: %d\n", i);
        printf("Nombre: %s\n", nombres[i]);
        printf("Cantidad: %d\n", cantidades[i]);
        printf("Precio: %.2f\n", precios[i]);
        printf("-------------------\n");
    }
}

// Función para guardar los productos en un archivo
void guardarProductos(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fwrite(&numProductos, sizeof(int), 1, archivo);
    fwrite(nombres, sizeof(char[MAX_NOMBRE_PRODUCTO]), numProductos, archivo);
    fwrite(cantidades, sizeof(int), numProductos, archivo);
    fwrite(precios, sizeof(float), numProductos, archivo);

    fclose(archivo);

    printf("Productos guardados exitosamente.\n");
}

// Función para cargar los productos desde un archivo
int cargarProductos(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }

    fread(&numProductos, sizeof(int), 1, archivo);
    fread(nombres, sizeof(char[MAX_NOMBRE_PRODUCTO]), numProductos, archivo);
    fread(cantidades, sizeof(int), numProductos, archivo);
    fread(precios, sizeof(float), numProductos, archivo);

    fclose(archivo);

    printf("Productos cargados exitosamente.\n");
    return 1;
}

int main() {
    char user[40];
    char psswd[40];
    char admin[40] = "admin";
    char adminpsswd[40] = "Liz2021";
    char cajero[40] = "cajero";
    char cajeropsswd[40] = "Naty2016";

    int opcion;
    printf("-----Bienvenido al sistema de control de inventario----- \n \nPor favor ingresa tu usuario y contrasena \n");
    printf("Usuario:");
    gets(user);
    fflush(stdin);
    printf("Contrasena:");
    gets(psswd);
    fflush(stdin);

    //login con usuario y contraseña
    //login admin:
    if ((strcmp(user, admin) == 0) && (strcmp(psswd, adminpsswd) == 0)) {
        //menu de administrador:
        printf("\n*-*-*-*-* Bienvenido Administrador *-*-*-*-*\n");

        do {
            printf("\nSistema de Inventarios\n");
            printf("1. Ingresar producto\n");
            printf("2. Editar producto\n");
            printf("3. Eliminar producto\n");
            printf("4. Listar productos\n");
            printf("5. Guardar productos en archivo\n");
            printf("6. Cargar productos desde archivo\n");
            printf("7. Salir\n");
            printf("Ingrese una opcion: ");
            scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    ingresarProducto();
                    break;
                case 2:
                    editarProducto();
                    break;
                case 3:
                    eliminarProducto();
                    break;
                case 4:
                    listarProductos();
                    break;
                case 5: {
                    char nombreArchivo[50];
                    printf("Ingrese el nombre del archivo para guardar los productos: ");
                    scanf("%s", nombreArchivo);
                    printf("Para Visualizar los productos guardados nuevamente aplaste 6");
                    guardarProductos(nombreArchivo);
                    break;
                }
                case 6: {
                    char nombreArchivo[50];
                    printf("Ingrese el nombre del archivo para cargar los productos: ");
                    scanf("%s", nombreArchivo);
                    if (cargarProductos(nombreArchivo)) {
                        printf("Productos cargados exitosamente.\n");
                    }
                    break;
                }
                case 7:
                    printf("Saliendo del programa...\n");
                    break;
                default:
                    printf("Opción inválida.\n");
                    break;
            }
        } while (opcion != 7);
    }

        //login cajero:
    else if ((strcmp(user, cajero) == 0) && (strcmp(psswd, cajeropsswd) == 0)) {
        printf("\n*-*-*-*-* Bienvenido Cajero *-*-*-*-*\n");

        do {
            printf("\nSistema de Inventarios\n");
            printf("1. Ingresar producto\n");
            //esto no tiene el cajero: printf("2. Editar producto\n");
            printf("2. Eliminar producto\n");
            printf("3. Listar productos\n");
            //esto no tiene el cajero: printf("5. Guardar productos en archivo\n");
            //esto no tiene el cajero: printf("6. Cargar productos desde archivo\n");
            printf("4. Salir\n");
            printf("Ingrese una opcion: ");
            scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    ingresarProducto();
                    break;
                case 2:
                    eliminarProducto();
                    break;
                case 3:
                    listarProductos();
                    break;
                case 4:
                    printf("Saliendo del programa...\n");
                    break;
                default:
                    printf("Opción inválida.\n");
                    break;
            }

        } while (opcion != 4);
    }

        //en caso de no haber coincidencias:
    else {
        printf("CREDENCIALES INCORRECTAS!\nACCESO DENEGADO");
    }

    return 0;
}