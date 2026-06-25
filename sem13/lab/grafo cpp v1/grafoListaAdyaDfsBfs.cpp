/*
* nomPrograma: grafoListaAdyaDFSBfs.cpp
* descripcion: Operaciones de recorridos de grafos en lista de adyacencia
*
*                   TAREA
*   Implemente todo lo implementado y recomendado en los programas anteriores
*   de grafos en matriz y lista de adyacencia.
*   1. Implemente un grafo generico
*      - Implemente lista, cola, pila generica que debe utilizar como librerias
*        en el grafo generico
*      - Una vez implementados utilice como librerias Pila.h, Cola.h, Lista.h,
*        Grafo.h y SistemaGrafos.cpp sera el programa desde donde se opere
*        todo lo referido a grafos.
*   2. Tambien puden implementar en Java.
*   3. La implementacion requiere aplicar las buenas practicas.
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

// --- ESTRUCTURAS DEL GRAFO ---
typedef struct Nodo {
    int verticeDestino;
    struct Nodo* siguiente;
} Nodo;

typedef struct Lista {
    Nodo* cabeza;
} Lista;

typedef struct Grafo {
    int numVertices;
    int esDirigido;
    Lista* arregloListas;
} Grafo;

// --- ESTRUCTURA DE COLA PARA BFS ---
typedef struct {
    int items[NODOS];
    int frente;
    int finale;
} Cola;

//prototipos de funcion

// Operaciones de la cola
Cola* crearCola();
int estaVacia(Cola* q);
void encolar(Cola* q, int valor);
int desencolar(Cola* q);
// Operaciones de grafo
Nodo* crearNodo(int destino);
Grafo* crearGrafo(int numVertices, int esDirigido);
void insertarOrdenado(Lista* lista, int destino);
void agregarArista(Grafo* grafo, int origen, int destino);
void imprimirNodo(int index);
void BFS(Grafo* grafo, int nodoInicio);
void DFSRecursivo(Grafo* grafo, int nodoActual, int visitados[NODOS]);
void DFS(Grafo* grafo, int nodoInicio);
void liberarGrafo(Grafo* grafo);


// Programa principal
int main()
{
    // 0. Construya/dibuje los grafos en su cuaderno
    // 1. Grafo No Dirigido
    Grafo* gNoDirigido = crearGrafo(NODOS, 0);
    agregarArista(gNoDirigido, 0, 1); // A - B
    agregarArista(gNoDirigido, 0, 2); // A - C
    agregarArista(gNoDirigido, 1, 3); // B - D
    agregarArista(gNoDirigido, 1, 4); // B - E
    agregarArista(gNoDirigido, 2, 4); // C - E

    printf("=== RECORRIDOS EN GRAFO NO DIRIGIDO (Desde A) ===\n");
    printf("BFS: "); BFS(gNoDirigido, 0);
    printf("DFS: "); DFS(gNoDirigido, 0);

    // 2. Grafo Dirigido
    Grafo* gDirigido = crearGrafo(NODOS, 1);
    agregarArista(gDirigido, 0, 1); // A -> B
    agregarArista(gDirigido, 0, 2); // A -> C
    agregarArista(gDirigido, 1, 3); // B -> D
    agregarArista(gDirigido, 1, 4); // B -> E
    agregarArista(gDirigido, 2, 4); // C -> E
    agregarArista(gDirigido, 4, 2); // E -> C

    printf("\n=== RECORRIDOS EN GRAFO DIRIGIDO (Desde A) ===\n");
    printf("BFS: "); BFS(gDirigido, 0);
    printf("DFS: "); DFS(gDirigido, 0);

    liberarGrafo(gNoDirigido);
    liberarGrafo(gDirigido);

    //system("pause");
    return 0;
}

//Implementacion de prototipos de funcion

Cola* crearCola()
{
    Cola* q = (Cola*)malloc(sizeof(Cola));
    q->frente = -1; q->finale = -1;
    return q;
}

int estaVacia(Cola* q)
{
    return q->finale == -1;
}

void encolar(Cola* q, int valor)
{
    if (q->frente == -1) q->frente = 0;
    q->finale++;
    q->items[q->finale] = valor;
}

int desencolar(Cola* q)
{
    int item = q->items[q->frente];
    q->frente++;
    if (q->frente > q->finale) q->frente = q->finale = -1;
    return item;
}

// --- FUNCIONES DEL GRAFO ---
Nodo* crearNodo(int destino)
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->verticeDestino = destino;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

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

// Inserta de manera ordenada (menor a mayor) para garantizar el orden alfabético
void insertarOrdenado(Lista* lista, int destino)
{
    Nodo* nuevo = crearNodo(destino);
    if (lista->cabeza == NULL || lista->cabeza->verticeDestino > destino) {
        nuevo->siguiente = lista->cabeza;
        lista->cabeza = nuevo;
    } else {
        Nodo* actual = lista->cabeza;
        while (actual->siguiente != NULL && actual->siguiente->verticeDestino < destino) {
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }
}

void agregarArista(Grafo* grafo, int origen, int destino)
{
    insertarOrdenado(&(grafo->arregloListas[origen]), destino);
    if (!grafo->esDirigido) {
        insertarOrdenado(&(grafo->arregloListas[destino]), origen);
    }
}

void imprimirNodo(int index)
{
    printf("%c ", 'A' + index);
}

// --- RECORRIDO BFS (ANCHURA) ---
void BFS(Grafo* grafo, int nodoInicio)
{
    int visitados[NODOS] = {0};
    Cola* q = crearCola();

    visitados[nodoInicio] = 1;
    encolar(q, nodoInicio);

    while (!estaVacia(q)) {
        int nodoActual = desencolar(q);
        imprimirNodo(nodoActual);

        // Recorremos la lista enlazada de vecinos del nodo actual
        Nodo* vecino = grafo->arregloListas[nodoActual].cabeza;
        while (vecino != NULL) {
            int vDestino = vecino->verticeDestino;
            if (!visitados[vDestino]) {
                visitados[vDestino] = 1;
                encolar(q, vDestino);
            }
            vecino = vecino->siguiente;
        }
    }
    free(q);
    printf("\n");
}

// --- RECORRIDO DFS (PROFUNDIDAD) ---
void DFSRecursivo(Grafo* grafo, int nodoActual, int visitados[NODOS])
{
    visitados[nodoActual] = 1;
    imprimirNodo(nodoActual);

    Nodo* vecino = grafo->arregloListas[nodoActual].cabeza;
    while (vecino != NULL) {
        int vDestino = vecino->verticeDestino;
        if (!visitados[vDestino]) {
            DFSRecursivo(grafo, vDestino, visitados);
        }
        vecino = vecino->siguiente;
    }
}

void DFS(Grafo* grafo, int nodoInicio)
{
    int visitados[NODOS] = {0};
    DFSRecursivo(grafo, nodoInicio, visitados);
    printf("\n");
}

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

// --- PROGRAMA PRINCIPAL ---
