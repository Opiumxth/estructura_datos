/*
* nomPrograma: grafoListaAdya.cpp
* descripcion: Operaciones basicas de grafos en lista adyacencia para
#         grafo dirigiidos y no dirigos
*
* 0. Analice las estructuras de la lista adyacencia
*    - La estructura del nodo
*    - La estructura de la lista de adyacencia
*    - La estructura del grafo
* 1. Creacion del de los elementos del grafo
*    - crear nodo
*    - crear el grafo
*    - agregar arista
* 2. Calculo del grado y densidad
*    - contar aristas
*    - Calcula el grado de los nodos
*    - Calcula la densidad de para estos grafos.
* 3. Eliminacion de grafo
* 4. Programa principal
*    - Construya/dibuje el grafo en su cuaderno
*    - Construccion del grafo  no dirigdo  y dirigdo
*      - Creacion de nos del grafo
*      - Creacionb de las aristas del grafo
*      - analizar grafo
*      - Eliminacion/liberacion de memoria del grafo
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
#define NODOS 5
using namespace std;



// Estructura para un nodo de la lista de adyacencia
typedef struct Nodo {
    int verticeDestino;
    struct Nodo* siguiente;
} Nodo;

// Estructura para la lista de adyacencia (cabecera)
typedef struct Lista {
    Nodo* cabeza;
} Lista;

// Estructura que representa el Grafo completo
typedef struct Grafo {
    int numVertices;
    int esDirigido;
    Lista* arregloListas;
} Grafo;

//Prototipos de funcion
Nodo* crearNodo(int destino);
Grafo* crearGrafo(int numVertices, int esDirigido);
void agregarArista(Grafo* grafo, int origen, int destino);
int contarAristas(Grafo* grafo);
void analizarGrafo(Grafo* grafo, const char* nombreGrafo);
void liberarGrafo(Grafo* grafo);
void mostrarGrafo(Grafo* grafo, int esDirigido, int nver);
//void mostrarGrafoD(Grafo* grafo);

int main()
{
    // --- 1. CONSTRUCCIÓN DEL GRAFO NO DIRIGIDO ---
    // Datos originales: A-B, A-C, B-D, B-E, C-E (5 aristas únicas)
    Grafo* gNoDirigido = crearGrafo(NODOS, 0); // 0 = No dirigido
    agregarArista(gNoDirigido, 0, 1); // A - B
    agregarArista(gNoDirigido, 0, 2); // A - C
    agregarArista(gNoDirigido, 1, 3); // B - D
    agregarArista(gNoDirigido, 1, 4); // B - E
    agregarArista(gNoDirigido, 2, 4); // C - E

    analizarGrafo(gNoDirigido, "GRAFO NO DIRIGIDO");


    mostrarGrafo(gNoDirigido, gNoDirigido->esDirigido, NODOS);
    printf("\n");


    // --- 2. CONSTRUCCIÓN DEL GRAFO DIRIGIDO ---
    // Datos originales: A->B, A->C, B->D, B->E, C->E, E->C (6 aristas dirigidas)
    Grafo* gDirigido = crearGrafo(NODOS, 1); // 1 = Dirigido
    agregarArista(gDirigido, 0, 1); // A -> B
    agregarArista(gDirigido, 0, 2); // A -> C
    agregarArista(gDirigido, 1, 3); // B -> D
    agregarArista(gDirigido, 1, 4); // B -> E
    agregarArista(gDirigido, 2, 4); // C -> E
    agregarArista(gDirigido, 4, 2); // E -> C

    analizarGrafo(gDirigido, "GRAFO DIRIGIDO");

    // Liberación de recursos
    liberarGrafo(gNoDirigido);
    liberarGrafo(gDirigido);


    //system("pause");
    return 0;
}



// Función para crear un nuevo nodo de la lista
Nodo* crearNodo(int destino)
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->verticeDestino = destino;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para inicializar un grafo de tamaño V
Grafo* crearGrafo(int numVertices, int esDirigido)
{
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = numVertices;
    grafo->esDirigido = esDirigido;

    grafo->arregloListas = (Lista*)malloc(numVertices * sizeof(Lista));

    for (int i = 0; i < numVertices; i++) {
        grafo->arregloListas[i].cabeza = NULL;
    }
    return grafo;
}

// Función para insertar una arista respetando el orden alfabético al insertar al final o de forma ordenada
void agregarArista(Grafo* grafo, int origen, int destino)
{
    Nodo* nuevoNodo = crearNodo(destino);

    // Insertar al inicio de la lista del vértice origen
    nuevoNodo->siguiente = grafo->arregloListas[origen].cabeza;
    grafo->arregloListas[origen].cabeza = nuevoNodo;

    // Si el grafo es NO dirigido, agregamos el camino de regreso (destino -> origen)
    if (!grafo->esDirigido) {
        nuevoNodo = crearNodo(origen);
        nuevoNodo->siguiente = grafo->arregloListas[destino].cabeza;
        grafo->arregloListas[destino].cabeza = nuevoNodo;
    }
}

// Función para contar el total de aristas reales recorriendo las listas
int contarAristas(Grafo* grafo)
{
    int total = 0;
    for (int i = 0; i < grafo->numVertices; i++) {
        Nodo* actual = grafo->arregloListas[i].cabeza;
        while (actual != NULL) {
            total++;
            actual = actual->siguiente;
        }
    }
    // Si no es dirigido, cada arista física está duplicada en memoria (A->B y B->A)
    return (grafo->esDirigido) ? total : (total / 2);
}

// Función para analizar grados y densidades
void analizarGrafo(Grafo* grafo, const char* nombreGrafo)
{
    printf("=== ANALISIS DE: %s ===\n", nombreGrafo);

    int v = grafo->numVertices;
    int e = contarAristas(grafo);

    if (!grafo->esDirigido) {
        // Cálculo de Grados para Grafo No Dirigido
        for (int i = 0; i < v; i++) {
            int grado = 0;
            Nodo* actual = grafo->arregloListas[i].cabeza;
            while (actual != NULL) {
                grado++;
                actual = actual->siguiente;
            }
            printf("Nodo %c: Grado = %d\n", 'A' + i, grado);
        }
        // Densidad No Dirigida
        double densidad = (2.0 * e) / (v * (v - 1));
        printf("Aristas Unicas (E): %d | Densidad: %.2f (%.1f%%)\n\n", e, densidad, densidad * 100);
    }
    else {
        // Cálculo de Grados para Grafo Dirigido (In-degree y Out-degree)
        int gradosEntrada[NODOS] = {0};

        // Primero calculamos los grados de entrada barriendo todo el grafo
        for (int i = 0; i < v; i++) {
            Nodo* actual = grafo->arregloListas[i].cabeza;
            while (actual != NULL) {
                gradosEntrada[actual->verticeDestino]++;
                actual = actual->siguiente;
            }
        }

        // Mostramos Grados de Salida (tamaño de la lista propia) y de Entrada
        for (int i = 0; i < v; i++) {
            int gradoSalida = 0;
            Nodo* actual = grafo->arregloListas[i].cabeza;
            while (actual != NULL) {
                gradoSalida++;
                actual = actual->siguiente;
            }
            printf("Nodo %c: Grado Entrada (In) = %d | Grado Salida (Out) = %d | Total = %d\n",
                   'A' + i, gradosEntrada[i], gradoSalida, gradosEntrada[i] + gradoSalida);
        }
        // Densidad Dirigida
        double densidad = (double)e / (v * (v - 1));
        printf("Aristas Dirigidas (E): %d | Densidad: %.2f (%.1f%%)\n\n", e, densidad, densidad * 100);
    }
}

// Función para liberar la memoria dinámica asignada
void liberarGrafo(Grafo* grafo)
{
    for (int i = 0; i < grafo->numVertices; i++) {
        Nodo* actual = grafo->arregloListas[i].cabeza;
        while (actual != NULL) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            free(temp);
        }
    }
    free(grafo->arregloListas);
    free(grafo);
}

void mostrarGrafo(Grafo* grafo, int esDirigido, int nver)
{
    // Inicializando a NULL
  /*  for (int i = 0; i < nver; i++) {
        grafo->arregloListas[i].cabeza = NULL;
        printf("%3c|", 'A' + i);
    }
*/

    if (!grafo->esDirigido) {
        for (int i = 0; i < nver; i++) {
            Nodo* actual = grafo->arregloListas[i].cabeza;
            printf("%3c ->", 'A' + i);
            while (actual != NULL) {
                printf("%2c - ", 'A' + actual->verticeDestino);
                actual = actual->siguiente;
            }
            printf("NULL");
            printf("\n");
        }
    }

}
