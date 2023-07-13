#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar los datos de un producto
typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

// Función para ingresar un nuevo producto
void ingresarProducto(Producto *productos, int *numProductos) {
    Producto nuevoProducto;
    printf("Ingresar nombre del producto: ");
    fflush(stdin);
	gets(nuevoProducto.nombre);
	fflush(stdin);
    printf("Ingresar cantidad: ");
    scanf("%d", &nuevoProducto.cantidad);
    printf("Ingresar precio: ");
    scanf("%f", &nuevoProducto.precio);
    
    productos[*numProductos] = nuevoProducto;
    (*numProductos)++;
    
    printf("Producto ingresado exitosamente.\n");
}

// Función para editar un producto existente
void editarProducto(Producto *productos, int numProductos) {
    int indice;
    printf("Ingrese el índice del producto a editar: ");
    scanf("%d", &indice);
    
    if (indice >= 0 && indice < numProductos) {
        printf("Editar nombre del producto: ");
        fflush(stdin);
        gets(productos[indice].nombre);
        fflush(stdin);
        printf("Editar cantidad: ");
        scanf("%d", &productos[indice].cantidad);
        printf("Editar precio: ");
        scanf("%f", &productos[indice].precio);
        
        printf("Producto editado exitosamente.\n");
    } else {
        printf("Índice inválido.\n");
    }
}

// Función para eliminar un producto existente
void eliminarProducto(Producto *productos, int *numProductos) {
    int indice;
    printf("Ingrese el índice del producto a eliminar: ");
    scanf("%d", &indice);
    
    if (indice >= 0 && indice < *numProductos) {
        // Desplazar los productos restantes hacia atrás para llenar el espacio vacío
        for (int i = indice; i < (*numProductos) - 1; i++) {
            productos[i] = productos[i + 1];
        }
        
        (*numProductos)--;
        
        printf("Producto eliminado exitosamente.\n");
    } else {
        printf("Índice inválido.\n");
    }
}

// Función para listar los productos ingresados
void listarProductos(Producto *productos, int numProductos) {
    printf("----- Listado de productos -----\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Índice: %d\n", i);
        printf("Nombre: %s\n", productos[i].nombre);
        printf("Cantidad: %d\n", productos[i].cantidad);
        printf("Precio: %.2f\n", productos[i].precio);
        printf("-------------------\n");
    }
}

// Función para guardar los productos en un archivo
void guardarProductos(Producto *productos, int numProductos, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    
    fwrite(&numProductos, sizeof(int), 1, archivo);
    fwrite(productos, sizeof(Producto), numProductos, archivo);
    
    fclose(archivo);
    
    printf("Productos guardados exitosamente.\n");
}

// Función para cargar los productos desde un archivo
int cargarProductos(Producto *productos, int *numProductos, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 0;
    }
    
    fread(numProductos, sizeof(int), 1, archivo);
    fread(productos, sizeof(Producto), *numProductos, archivo);
    
    fclose(archivo);
    
    printf("Productos cargados exitosamente.\n");
    return 1;
}

int main() {
    Producto productos[100];  // Arreglo para almacenar los productos
    int numProductos = 0;    // Variable para contar el número de productos
    char user[40];
	char psswd[40];
    char admin[40]="admin";
    char adminpsswd[40]="Liz2021";
    char cajero[40]="cajero";
    char cajeropsswd[40]="Naty2016";

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
    if((strcmp(user, admin)==0)&&(strcmp(psswd, adminpsswd)==0)){
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
                ingresarProducto(productos, &numProductos);
                break;
            case 2:
                editarProducto(productos, numProductos);
                break;
            case 3:
                eliminarProducto(productos, &numProductos);
                break;
            case 4:
                listarProductos(productos, numProductos);
                break;
            case 5: {
                char nombreArchivo[50];
                printf("Ingrese el nombre del archivo para guardar los productos: ");
                scanf("%s", nombreArchivo);
                printf("Para Visualizar los productos guardados nuevamente aplaste 6");
                guardarProductos(productos, numProductos, nombreArchivo);
                break;
            }
            case 6: {
                char nombreArchivo[50];
                printf("Ingrese el nombre del archivo para cargar los productos: ");
                scanf("%s", nombreArchivo);
                if (cargarProductos(productos, &numProductos, nombreArchivo)) {
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
if((strcmp(user, cajero)==0)&&(strcmp(psswd, cajeropsswd)==0)){
	
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
                ingresarProducto(productos, &numProductos);
                break;
            case 2:
                eliminarProducto(productos, &numProductos);
                break;
            case 3:
                listarProductos(productos, numProductos);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break; 
            default:
                printf("Opción inválida.\n");
                break;               
            }
        
    } while (opcion != 7);
    
    	
	}

//en caso de no haber coincidencias:
if((strcmp(user, cajero)!=0)||(strcmp(psswd, cajeropsswd)!=0)){
	printf("CREDENCIALES INCORRECTAS!\nACCESO DENEGADO");
}
if((strcmp(user, admin)!=0)||(strcmp(psswd, adminpsswd)!=0)){
	printf("CREDENCIALES INCORRECTAS!\nACCESO DENEGADO");
}
    return 0;	
}    

