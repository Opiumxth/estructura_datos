/*
* nomPrograma: grafocc.cpp
* descripcion: opraciones basicas de grafo matriz de adyacencia
*
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
#include "Grafo.h"

using namespace std;

// ======================================================
// RETO 1: GRAFO: MATRIZ DE ADYACENCIA ESTÁTICA
// ------------------------------------------------------
// Crear Grafo matriz
void createGraphMatrix(GraphMatrix *g)
{
    //g = NULL; // Porque si,  no?
    g->numVertices = -1;
}
// Leer los elementos de la matriz
void readGraphMatrix(GraphMatrix *g)
{
    int i, j, nv;
    printf("\nNumero vertices Matriz Adyacencia: ");
    scanf("%d", &nv);
    //if (g == NULL || vertices > MAX20 || vertices <= 0) {
    if (g == NULL || nv > MAX20 || nv <= 0) {
        printf("%d: Numero de vertices fuera de rango...\n", nv);
        return;
    }
    else {
        // Inicializar la matriz.
        // Recuerda: la diagonal principal debe ser 0 (costo a sí mismo).
        // El resto de celdas deben inicializarse con la constante INF.
      g->numVertices = nv;

        for(i=0;i<nv;i++)
        {
            for(j=0;j<nv;j++)
            {
                if(i==j)
                    g->matriz[i][j]=0;
                else
                    g->matriz[i][j]=INF;
            }
        }

    }
}

// Addiconar aristas al grafo
void insertEdgeMatrix(GraphMatrix* g, int orig, int dest, int weight)
{
    if (g == NULL) {
        return;
    }
    // Validar los límites aristas/Edges
    // insertar la arista ponderada.
    // Recuerda que este grafo debe ser NO DIRIGIDO (simétrico).

   if(orig < 0 || orig >= g->numVertices) return;
   if(dest < 0 || dest >= g->numVertices) return;
    g->matriz[orig][dest] = weight;
    g->matriz[dest][orig] = weight;
 }

// Mostrar matriz de adyaencia
void showGraphMatrix(GraphMatrix* g)
{
    int i, j;
    char inf[] = "INF";
    char spc[] = " ";
    if (g == NULL) {
        return;
    }
    printf("\n--- MATRIZ DE ADYACENCIA ---\n");
    printf("%4s", spc);
    for (i = 0; i < g->numVertices; i++) {
        printf("%4d", i);
    }
    printf("\n\n");

    for (i = 0; i < g->numVertices; i++) {
        printf("%4d ", i);
        for (j = 0; j < g->numVertices; j++) {
            if (g->matriz[i][j] == -1) {
                printf("%4s", inf);
            } else {
                printf("%4d", g->matriz[i][j]);
            }
        }
        printf("\n");
    }
}

// ======================================================
// RETO 2: GRAFO: LISTA DE ADYACENCIA DINÁMICA
// ------------------------------------------------------

//Crear grafo
void createGraphList(GraphList *g)
{
    g = NULL;
}

//Leer elementos para el grafo
GraphList* readGraphList(GraphList *g)
{
    int i, nv;

    printf("\nNumero vertices Lista Adyacencia:  ");
    scanf("%d", &nv);

    if (nv <= 0) {
        return NULL;
    }
    else {
        // Asignar memoria para la estructura principal GraphList g
        // Asignar numero de vertices al grafo
        // Crear un arreglo de listas de adyacencia
        // Iniciliar cada elementos de la lista como vacia o sea ?

        g = (GraphList*)malloc(sizeof(GraphList));
        g->numVertices = nv;

        g->adjLists = (Node**)malloc(nv * sizeof(Node*));

        for(i = 0; i < nv; i++)
        {
            g->adjLists[i] = NULL;
        }

        return g;


    }
}

//Adicionar aristas al grafo
void insertEdgeList(GraphList *g, int orig, int dest)
{
    if (g == NULL) {
        return;
    }
    if (orig < 0 || orig >= g->numVertices || dest < 0 || dest >= g->numVertices) {
        return;
    }
    else {
        // Caso Grafo no dirigido
        // Crear el metodo crearNodo(). Referencia y asignar vertice orgen
        // Insertar el nodo AL INICIO de la lista enlazada apuntada por
        // g->adjLists[destino] (Costo O(1)).
        // Caso Grafo dirigido ?

        /*
        // Para grafo no dirigido
        Node *neo = (Node*)malloc(sizeof(Node));
        neo->targetVertex = orig;
        neo->next = NULL;
        neo->next = g->adjLists[dest];
        g->adjLists[dest] = neo;
        */

        // Para grafo dirigido
        Node *neo = (Node*)malloc(sizeof(Node));
        neo->targetVertex = dest;
        neo->next = g->adjLists[orig];
        g->adjLists[orig] = neo;

    }
}

// Mostrar grafo
void showGraphList(GraphList *g)
{
    int i;
    Node *edg;
    printf("\n");
    line2();
    printf(" G R A F O S   Lista de Adyacencia\n");
    line1();

    // Debe recorrer el vector de vertices que apuntan a nodos arista
    // y debe configurar la lista de adyacencia
    // No olvide las consistencias del caso

   if (g == NULL) return;
   // Ahora mostramos el grafo con el formato |Vertice|->
   for(i = 0; i < g->numVertices; i++){
      printf("|%3d|-> ", i);

      edg = g->adjLists[i];

      while(edg != NULL){
         printf("%3d--> ", edg->targetVertex);
         edg = edg->next;
      }
      printf("NULL\n");
   }
   line1();
}

// Liberar memoria del grafo
void freeGraphList(GraphList *g)
{
    int i;
    Node *actual, *siguiente;
    if (g == NULL) {
        return;
    }
    else {
        // Recorrer el arreglo g->adjLists.
        // Para cada posición, liberar iterativa o recursivamente todos
        // los nodos de la lista enlazada.
        // Finalmente, liberar el arreglo g->adjLists y la estructura principal g.

      for(i = 0; i < g->numVertices; i++){
         actual = g->adjLists[i];
         // Se libera uno por uno usando free
         while(actual != NULL){
            siguiente = actual->next;
            free(actual);
            actual = siguiente;
         }
      }
      free(g->adjLists);
      free(g);

      printf("\nSe libero la memoria del grafo lista.\n");
   }
}

// ======================================================
// RETO 3: RECORRIDOS (DFS) Recursivo
// ------------------------------------------------------

// 3. RECORRIDO DFS (Función Auxiliar Recursiva)
void recursiveDFS(GraphList *g, int vertex, int *visited)
{
    // Implementación del recorrido en profundidad recursivo.
    // 1. Marcar startVertex como visitado (1).
    // 2. Imprimir el vértice actual para la traza.
    // 3. Obtener el primer vecino de la lista apuntada por g->adjLists[startVertex].
    // 4. Recorrer la lista enlazada de vecinos: si un vecino no ha sido visitado (0),
    //    llamar recursivamente a DFS pasándole ese vecino.
   visited[vertex] = 1;

   printf("%d ", vertex);
   Node *aux = g->adjLists[vertex];

   while(aux != NULL){
      if(!visited[aux->targetVertex]){
         recursiveDFS(g, aux->targetVertex, visited);
      }
      aux = aux->next;
   }

}

// Función principal para iniciar el DFS
void DFS(GraphList* g, int startVertex)
{

    if (g == NULL || startVertex < 0 || startVertex >= g->numVertices) {
        return;
    }

    printf("\nRecorrido DFS desde vértice %d: ", startVertex);
    int* visited = (int*)calloc(g->numVertices, sizeof(int));

    recursiveDFS(g, startVertex, visited);

    printf("\n");
    free(visited);
}

void line1()
{
    int i, n=40;
    for(i=0;i<n; i=i+1){
        printf("-");
    }
    printf("\n");
}

void line2()
{
    int i, n=40;
    for(i=0;i<n; i=i+1){
        printf("=");
    }
    printf("\n");
}
