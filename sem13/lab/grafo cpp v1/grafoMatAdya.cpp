/*
* nomPrograma: matAdya.cpp
* descripcion: Operaciones Basicas de Grafo
*
* 0. Analice la estructura de la cola
* 1. Analice la estrucutura de grafo
*
* 2. Analice las operaciones basicas de la cola
*    - Analice su uso en el BFS
*    - Implemente otra version de grafo y reemplace la cola con su
*      propia libreria generica
* 3. Analice las operaciones DFS y BFS
*    - Analice el uso de la cola en el recorrido BFS
*    - Analice el recorrido  DFS recursivo
*    -  Implemente otra version de grafo e el recorrdio DFS no recursivo
*       utilizando una pila (libreria pila)
* 4. Proigrama principal
*    - Construya/dibuje el grafo dirigido y no dirigo
*    - Analice la creacion del grafo
*    - analice los recirridos
*    - Que deberia hacer para mostrar el grafo?
*    - Cuando emplearia la Matriz adyacencia en una implementacion de grafos?
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

#define NODOS 5

// --- Estructura de Cola Simple para el recorrido BFS ---
typedef struct {
    int items[NODOS];
    int frente;
    int finale;
} Cola;

// prototipos de funcion
Cola* crearCola();
int estaVacia(Cola* q);
void encolar(Cola* q, int valor);
int desencolar(Cola* q);
void imprimirNodo(int index);
void BFS(int matriz[NODOS][NODOS], int nodoInicio);
void DFSRecursivo(int matriz[NODOS][NODOS], int nodoActual, int visitados[NODOS]);
void DFS(int matriz[NODOS][NODOS], int nodoInicio);


int main()
{
    // --- 1. MATRIZ DEL GRAFO NO DIRIGIDO ---
    // Conexiones bidireccionales: A-B, A-C, B-D, B-E, C-E
    int grafoNoDirigido[NODOS][NODOS] = {
        {0, 1, 1, 0, 0}, // A -> Conecta con B(1), C(2)
        {1, 0, 0, 1, 1}, // B -> Conecta con A(0), D(3), E(4)
        {1, 0, 0, 0, 1}, // C -> Conecta con A(0), E(4)
        {0, 1, 0, 0, 0}, // D -> Conecta con B(1)
        {0, 1, 1, 0, 0}  // E -> Conecta con B(1), C(2)
    };

    // --- 2. MATRIZ DEL GRAFO DIRIGIDO ---
    // Conexiones unidireccionales: A->B, A->C, B->D, B->E, C->E, E->C
    int grafoDirigido[NODOS][NODOS] = {
        {0, 1, 1, 0, 0}, // A -> Apunta a B, C
        {0, 0, 0, 1, 1}, // B -> Apunta a D, E
        {0, 0, 0, 0, 1}, // C -> Apunta a E
        {0, 0, 0, 0, 0}, // D -> No apunta a nadie (Callejón sin salida)
        {0, 0, 1, 0, 0}  // E -> Apunta a C
    };

    printf("=== GRAFO NO DIRIGIDO (Desde A) ===\n");
    printf("Recorrido BFS: ");
    BFS(grafoNoDirigido, 0); // 0 representa el nodo 'A'
    printf("Recorrido DFS: ");
    DFS(grafoNoDirigido, 0);

    printf("\n=== GRAFO DIRIGIDO (Desde A) ===\n");
    printf("Recorrido BFS: ");
    BFS(grafoDirigido, 0);
    printf("Recorrido DFS: ");
    DFS(grafoDirigido, 0);

    printf("\n=== CASO ESPECIAL GRAFO DIRIGIDO (Desde D) ===\n");
    printf("Recorrido BFS: ");
    BFS(grafoDirigido, 3); // 3 representa el nodo 'D'


    //system("pause");
    return 0;
}



Cola* crearCola()
{
    Cola* q = (Cola*)malloc(sizeof(Cola));
    q->frente = -1;
    q->finale = -1;
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
    if (q->frente > q->finale) {
        q->frente = q->finale = -1;
    }
    return item;
}

// --- Función auxiliar para imprimir el nombre del nodo ---
void imprimirNodo(int index)
{
    printf("%c ", 'A' + index);
}

// --- Algoritmos de Recorrido ---

// Búsqueda en Anchura (BFS)
void BFS(int matriz[NODOS][NODOS], int nodoInicio)
{
    int visitados[NODOS] = {0};
    Cola* q = crearCola();

    visitados[nodoInicio] = 1;
    encolar(q, nodoInicio);

    while (!estaVacia(q)) {
        int nodoActual = desencolar(q);
        imprimirNodo(nodoActual);

        // Al revisar de 0 a NODOS-1, garantizamos el orden alfabético (A, B, C...)
        for (int i = 0; i < NODOS; i++) {
            if (matriz[nodoActual][i] == 1 && !visitados[i]) {
                visitados[i] = 1;
                encolar(q, i);
            }
        }
    }
    free(q);
    printf("\n");
}

// Función auxiliar recursiva para DFS
void DFSRecursivo(int matriz[NODOS][NODOS], int nodoActual, int visitados[NODOS])
{
    visitados[nodoActual] = 1;
    imprimirNodo(nodoActual);

    for (int i = 0; i < NODOS; i++) {
        if (matriz[nodoActual][i] == 1 && !visitados[i]) {
            DFSRecursivo(matriz, i, visitados);
        }
    }
}

// Búsqueda en Profundidad (DFS)
void DFS(int matriz[NODOS][NODOS], int nodoInicio)
{
    int visitados[NODOS] = {0};
    DFSRecursivo(matriz, nodoInicio, visitados);
    printf("\n");
}

