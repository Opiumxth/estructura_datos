/*
* nomPrograma: grafoListaAdyaFile.cpp
* descripcion:
*
*
*    Analice el codigo, luego compile, ejecute y analice los resultados
*
* 0. Para cargar un grafo desde un archivo usando listas de adyacencia, el
*    formato adecuando es el archivo de texto, estructurado por lineas:
*    0.1 La primera indica numero de vertices y aristas
*    0.2 Las siguientes lineas contienen las conexiones:
*        - Vertice origen, vertice destino y peso.
* 1. El archivo de prueba es grafoDat.txt -crearo con el block de notas o
*    similar- que debe estar en la misma carpeta donde esta el programa.
*    1.1 Tambien se puede poner en una ruta distinta. Investigue como hacerlo.
* 2. Para tratamiento de files en C se utiliza fread() y fwrite() para datos
*    estructurados. Aqui lo ideal es utilizar fscanf() y fprintf()
*    investigue en la informacion que se ha dejado.
* 3. Tambien es importante liberar memoria por estar utilizando apuntadores y
*    malloc()
*
*
* autor:
* fecha:
* Version 1
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h> // libreria no standard
#include <string.h>

using namespace std;

// Nodo de la lista de adyacencia
struct Nodo {
    int destino;
    int peso;
    struct Nodo* siguiente;
};

// Lista de adyacencia (cabecera de cada vértice)
struct ListaAdyacencia {
    struct Nodo* cabeza;
};

// Estructura principal del Grafo
struct Grafo {
    int numVertices;
    struct ListaAdyacencia* arreglo;
};


struct Nodo* crearNodo(int destino, int peso);
struct Grafo* crearGrafo(int V);
void agregarArista(struct Grafo* grafo, int origen, int destino, int peso);
struct Grafo* cargarGrafoDesdeArchivo(const char* nombreArchivo);
void imprimirGrafo(struct Grafo* grafo);
void liberarGrafo(struct Grafo* grafo);


int main()
{
    // Llamamos a la función pasando el nombre de nuestro archivo de texto
    struct Grafo* grafo;
    grafo = cargarGrafoDesdeArchivo("grafoDat.txt");

    if (grafo != NULL) {
        imprimirGrafo(grafo);
        liberarGrafo(grafo); // Buenas prácticas: limpiar la memoria RAM
    }

    //system("pause");
    return 0;
}


// Función para crear un nuevo nodo en la lista
struct Nodo* crearNodo(int destino, int peso)
{
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->destino = destino;
    nuevoNodo->peso = peso;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para inicializar el grafo con V vértices
struct Grafo* crearGrafo(int V)
{
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->numVertices = V;

    // Crear un arreglo de listas de adyacencia
    grafo->arreglo = (struct ListaAdyacencia*)malloc(V * sizeof(struct ListaAdyacencia));

    // Inicializar cada cabeza como NULL (lista vacía)
    for (int i = 0; i < V; i++) {
        grafo->arreglo[i].cabeza = NULL;
    }
    return grafo;
}

// Función para agregar una arista (Grafo No Dirigido)
void agregarArista(struct Grafo* grafo, int origen, int destino, int peso)
{
    // Agregar arista desde origen a destino
    struct Nodo* nuevoNodo = crearNodo(destino, peso);
    nuevoNodo->siguiente = grafo->arreglo[origen].cabeza;
    grafo->arreglo[origen].cabeza = nuevoNodo;

    // Como es NO DIRIGIDO, agregamos también de destino a origen
    nuevoNodo = crearNodo(origen, peso);
    nuevoNodo->siguiente = grafo->arreglo[destino].cabeza;
    grafo->arreglo[destino].cabeza = nuevoNodo;
}

// Función para leer el archivo y construir el grafo
struct Grafo* cargarGrafoDesdeArchivo(const char* nombreArchivo)
{
    int vertices, aristas;
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo %s\n", nombreArchivo);
        return NULL;
    }

    //int vertices, aristas;
    // Leer la primera línea (Número de vértices y aristas)
    if (fscanf(archivo, "%d %d", &vertices, &aristas) != 2) {
        printf("Error al leer los encabezados del grafo.\n");
        fclose(archivo);
        return NULL;
    }

    // Crear la estructura base en memoria
    struct Grafo* grafo = crearGrafo(vertices);

    int origen, destino, peso;
    // Leer línea por línea cada arista restante hasta el fin del archivo (EOF)
    for (int i = 0; i < aristas; i++) {
        if (fscanf(archivo, "%d %d %d", &origen, &destino, &peso) == 3) {
            agregarArista(grafo, origen, destino, peso);
        }
    }

    fclose(archivo);
    printf("¡Grafo cargado exitosamente desde %s!\n\n", nombreArchivo);
    return grafo;
}

// Función para imprimir el grafo en consola
void imprimirGrafo(struct Grafo* grafo)
{
    for (int v = 0; v < grafo->numVertices; v++) {
        struct Nodo* temporal = grafo->arreglo[v].cabeza;
        printf("Vertice %d:", v);
        while (temporal) {
            printf(" -> (Destino: %d, Peso: %d)", temporal->destino, temporal->peso);
            temporal = temporal->siguiente;
        }
        printf("\n");
    }
}

// Función para liberar la memoria dinámica utilizada
void liberarGrafo(struct Grafo* grafo)
{
    if (grafo == NULL) {
        return;
    }

    for (int v = 0; v < grafo->numVertices; v++) {
        struct Nodo* actual = grafo->arreglo[v].cabeza;
        while (actual != NULL) {
            struct Nodo* siguiente = actual->siguiente;
            free(actual);
            actual = siguiente;
        }
    }
    free(grafo->arreglo);
    free(grafo);
}

/*
¡Grafo cargado exitosamente desde grafoDat.txt!

Vertice 0: -> (Destino: 3, Peso: 6) -> (Destino: 1, Peso: 2)
Vertice 1: -> (Destino: 4, Peso: 5) -> (Destino: 3, Peso: 8) -> (Destino: 2, Peso: 3) -> (Destino: 0, Peso: 2)
Vertice 2: -> (Destino: 4, Peso: 7) -> (Destino: 1, Peso: 3)
Vertice 3: -> (Destino: 4, Peso: 9) -> (Destino: 1, Peso: 8) -> (Destino: 0, Peso: 6)
Vertice 4: -> (Destino: 3, Peso: 9) -> (Destino: 2, Peso: 7) -> (Destino: 1, Peso: 5)

Process returned 0 (0x0)   execution time : 0.001 s
Press ENTER to continue.


*/
