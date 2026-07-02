#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define MAX20 20
#define INF -1


// ======================================================
// ESTRUCTURAS DE DATOS  G R A F O S
// ------------------------------------------------------

/* Estructura Reto 1: Matriz de Adyacencia Estática */
typedef struct GraphMatrix{
    int matriz[MAX20][MAX20];
    int numVertices;
} GraphMatrix;

/* Estructuras Reto 2 y 3: Lista de Adyacencia Dinámica */
typedef struct Node {
    int targetVertex;
    struct Node* next;
} Node;

typedef struct GraphList{
    int numVertices;
    Node** adjLists; // Arreglo dinámico de punteros a Node
} GraphList;

// ======================================================
// PROTOTIPOS DE FUNCION DEL TAD
// ------------------------------------------------------

/* ---> RETO 1: GRAFO: Matriz de Adyacencia */
void createGraphMatrix(GraphMatrix *g);
void readGraphMatrix(GraphMatrix *g, int vertices);
void insertEdgeMatrix(GraphMatrix *g, int orig, int dest, int weight);
void showGraphMatrix(GraphMatrix *g);

/* ---> RETO 2: GRAFO: Lista de Adyacencia y Memoria dinamica*/
void createGraphList(GraphList *g);
GraphList* readGraphList(GraphList *g);
void insertEdgeList(GraphList *g, int orig, int dest);

void showGraphList(GraphList *g);
void freeGraphList(GraphList *g);

/* ---> RETO 3: Recorridos (DFS) */
void DFS(GraphList *g, int startVertex);
void recursiveDFS(GraphList *g, int startVertex, int* visited);

/* ---> RETO 4: Recorridos BFS Iterativo con stack/Queue NO SE PIDE*/

void line1();
void line2();

#endif
