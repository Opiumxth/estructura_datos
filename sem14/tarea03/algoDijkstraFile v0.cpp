/*
* nomPrograma: algoListaDijsktraFile.cpp
* descripcion:
*
*    Analice el codigo, luego compile, ejecute y analice los resultados
*
* 0. Las computadoras y los algoritmos como Dijkstra necesitan números
*    correlativos para indexar los arreglos y listas de adyacencia.
* 1. La estrategia consiste en asignar cada nombre de vertice/nodo a un
*    índice numérico único en ese instante mientras lees el archivo.
* 2. El formato del file sera:
*    2.1 La primera linea solo indica el numero de aristas que se van a leer
*    2.7 Nombre file: gciudades.txt
*            Lima Arequipa 10
*            Lima Ica 5
*            Cuzco Lima 8
*            Lima Puno 15
*            ...
* 3. Utilice el formato fscanf() se leen dos cadenas de texto consecutivas  y
*    y un entero  o sea: ("%s %s %d")
*    3.1 Al leer la primera cadena Lima lo almacena en la posicion 0 y retorna
*        el entero 0 (cero)
*    3.2 Cuando lee la siguiente linea o sea Lima, ya no lo almacena nuevamente,
*        simplemente retorna 0 (cero).
*    3.3 El algoritmo de Dijkstra procesa el grafo usando únicamente los
*        enteros 0, 1, 2...
*    3.4 Al momento de imprimir en pantalla, usamos nombreNodos[i] para
*        volver a mostrar el texto legible al usuario.
* 4. Elimine las variables globales nombreNodos(...), totalNodos y module
*    la aplicacion
*
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
#include <stdbool.h>
#define MAX50 50
#define STR30 30
#define INF 99999

using namespace std;

// Estructura del nodo para la lista de adyacencia
struct Nodo {
    int destinoId;
    int peso;
    struct Nodo* siguiente;
};

struct ListaAdyacencia {
    struct Nodo* cabeza;
};

// Diccionario para mapear nombres de texto a IDs numéricos
char nombresNodos[MAX50][STR30];
int totalNodos = 0;

int obtenerAsignarId(const char* nombre);
void agregarArista(struct ListaAdyacencia* grafo, int origen, int destino, int peso);
void dijkstra(struct ListaAdyacencia* grafo, int origenId);
void raya2();
void raya1();



// Función para obtener o asignar un ID numérico a un nombre de nodo
int obtenerAsignarId(const char* nombre)
{
    // Buscar si el nombre ya existe en nuestro "diccionario"
    for (int i = 0; i < totalNodos; i++) {        if (strcmp(nombresNodos[i], nombre) == 0) {
            return i; // Retorna el ID existente
        }
    }
    // Si no existe y hay espacio, lo agregamos
    if (totalNodos < MAX50) {
        strcpy(nombresNodos[totalNodos], nombre);
        return totalNodos++; // Retorna el nuevo ID asignado
    }
    return -1;
}

// Agregar arista a la lista de adyacencia (Grafo No Dirigido)
void agregarArista(struct ListaAdyacencia* grafo, int origen, int destino, int peso)
{
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->destinoId = destino;
    nuevo->peso = peso;
    nuevo->siguiente = grafo[origen].cabeza;
    grafo[origen].cabeza = nuevo;

    nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->destinoId = origen;
    nuevo->peso = peso;
    nuevo->siguiente = grafo[destino].cabeza;
    grafo[destino].cabeza = nuevo;
}

// ALGORITMO DE DIJKSTRA
void dijkstra(struct ListaAdyacencia* grafo, int origenId)
{
    int distancias[MAX50];
    bool visitados[MAX50];

    for (int i = 0; i < totalNodos; i++) {
        distancias[i] = INF;
        visitados[i] = false;
    }
    distancias[origenId] = 0;

    for (int count = 0; count < totalNodos - 1; count++) {
        // Encontrar el nodo con la distancia mínima no visitado
        int min = INF, u = -1;
        for (int v = 0; v < totalNodos; v++) {
            if (!visitados[v] && distancias[v] <= min) {
                min = distancias[v];
                u = v;
            }
        }

        if (u == -1) {
            break;
        }
        visitados[u] = true;

        // Actualizar distancias de los vecinos de 'u'
        struct Nodo* vecino = grafo[u].cabeza;
        while (vecino != NULL) {
            int v = vecino->destinoId;
            if (!visitados[v] && distancias[u] != INF && distancias[u] + vecino->peso < distancias[v]) {
                distancias[v] = distancias[u] + vecino->peso;
            }
            vecino = vecino->siguiente;
        }
    }

    // Imprimir resultados traduciendo los IDs de vuelta a los nombres originales
    printf("\n");
    raya2();
    printf("Rutas mas cortas desde: %s\n", nombresNodos[origenId]);
    raya1();
    for (int i = 0; i < totalNodos; i++) {
        if (distancias[i] == INF) {
            printf("Hacia %-12s ->   No alcanzable\n", nombresNodos[i]);
        } else {
            printf("Hacia %-12s ->   Costo: %d\n", nombresNodos[i], distancias[i]);
        }
    }
    raya1();
}

void raya1()
{
    int i, n=40;
    for(i=0;i<n; i=i+1){
        printf("-");
    }
    printf("\n");
}
void raya2()
{
    int i, n=40;
    for(i=0;i<n; i=i+1){
        printf("=");
    }
    printf("\n");
}

// Programa principal
// Aqui no debe haber implementaciones: module
int main()
{
    // Inicializar lista de adyacencia vacía
    struct ListaAdyacencia grafo[MAX50];
    for (int i = 0; i < MAX50; i++) {
        grafo[i].cabeza = NULL;
    }

    FILE* archivo = fopen("gciudades.txt", "r");
    if (!archivo) {
        printf("Error: No se pudo abrir ciudades.txt\n");
        return 1;
    }

    int numAristas;
    if (fscanf(archivo, "%d", &numAristas) != 1) {
        printf("Error al leer el numero de aristas.\n");
        fclose(archivo);
        return 1;
    }

    char origenTxt[STR30], destinoTxt[STR30];
    int peso;

    // Leer línea por línea usando %s %s %d
    for (int i = 0; i < numAristas; i++) {
        if (fscanf(archivo, "%s %s %d", origenTxt, destinoTxt, &peso) == 3) {
            // Pasamos las cadenas a enteros internos
            int u = obtenerAsignarId(origenTxt);
            int v = obtenerAsignarId(destinoTxt);
            agregarArista(grafo, u, v, peso);
        }
    }
    fclose(archivo);
    printf("Archivo cargado! Nodos detectados: %d\n\n", totalNodos);

    // Ejecutar Dijkstra desde "Lima" (siempre que exista en el archivo)
    int idInicio = obtenerAsignarId("Lima");
    if (idInicio != -1) {
        dijkstra(grafo, idInicio);
    }

    // Liberar memoria dinámica al salir
    for (int i = 0; i < totalNodos; i++) {
        struct Nodo* actual = grafo[i].cabeza;
        while (actual != NULL) {
            struct Nodo* sig = actual->siguiente;
            free(actual);
            actual = sig;
        }
    }


    //system("pause");
    return 0;
}
/*
//Salida del programa:
Archivo cargado! Nodos detectados: 5

Rutas mas cortas desde: Lima
-----------------------------------------
Hacia Lima         ->   Costo: 0
Hacia Cusco        ->   Costo: 5
Hacia Arequipa     ->   Costo: 8
Hacia Puno         ->   Costo: 10
Hacia Tacna        ->   Costo: 14
-----------------------------------------

Process returned 0 (0x0)   execution time : 0.001 s
Press ENTER to continue.

*/



