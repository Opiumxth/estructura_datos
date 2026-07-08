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
    printf("\tNumero vertices grafo:  ");
    scanf("%d", &nv);
    //if (g == NULL || vertices > MAX20 || vertices <= 0) {
    if (g == NULL || nv > MAX20 || nv <= 0) {
        //return;
        printf("%d: Numero de vertices fuera de rango...\n", nv);
    }
    else {
        // Inicializar la matriz.
        // Recuerda: la diagonal principal debe ser 0 (costo a sí mismo).
        // El resto de celdas deben inicializarse con la constante INF.

        g->numVertices = nv;
        for(i=0; i<nv; i=i+1) {
            for(j=0; j<nv; j=j+1) {
                if(i==j) {
                    g->matriz[i][j] = 0;
                }
                else {
                    g->matriz[i][j] = -1;
                }
            }
        }
    }
}
// Addiconar aristas al grafo
void insertEdgeMatrix(GraphMatrix* g, int orig, int dest, int weight)
{
    int i, j;
    if (g == NULL) {
        return;
    }
    // Validación de límites (Edge Cases)
    // insertar la arista ponderada.
    // Recuerda que este grafo debe ser NO DIRIGIDO (simétrico).


    if (orig < 0 || orig >= g->numVertices || dest < 0 || dest >= g->numVertices) {
        printf("Error: Índices de Matriz Adyac fuera de rango.\n");
        return;
    }
    else {
        // insertar la arista ponderada.
        // Recuerda que este grafo debe ser NO DIRIGIDO (simétrico).
        g->matriz[orig][dest] = weight;
        g->matriz[dest][orig] = weight;
    }
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
            //if (g->matriz[i][j] == INF) {
            if (g->matriz[i][j] == -1) {
                printf("%4s", inf);
            } else {
                printf("%4d", g->matriz[i][j]);
            }
        }
        printf("\n");
    }
}
void pausarConsola()
{
    // Limpia cualquier carácter sobrante en el buffer
    while (getchar() != '\n');
    printf("\n\tE N T E R  para continuar... ");
    // Pausa programa hasta presionar ENTER
    getchar();
}
void gestionGraphMatrix()
{
    system("clear");
    printf("\n****  LABORATORIO DE GRAFOS  ****\n");
    printf("\tMatriz Adyacencia\n\n");
    // ======================================================
    // Prueba Reto 1: GRAFO: Matriz de Adyacencia
    // ------------------------------------------------------
    GraphMatrix gm1, gm2, gm3;
    createGraphMatrix(&gm1);
    readGraphMatrix(&gm1);

    showGraphMatrix(&gm1);
    insertEdgeMatrix(&gm1, 0, 1, 5);
    insertEdgeMatrix(&gm1, 0, 4, 8);
    insertEdgeMatrix(&gm1, 1, 2, 2);
    insertEdgeMatrix(&gm1, 1, 3, 6);
    insertEdgeMatrix(&gm1, 2, 4, 1);

    showGraphMatrix(&gm1);
    pausarConsola();

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

    printf("\tNumero vertices grafo:  ");
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
        // Crear un arreglo de listas de adyacencia
        g->adjLists = (Node**)malloc(nv * sizeof(Node*));

        // Inicializar cada lista como vacía (NULL)
        for(i = 0; i < g->numVertices; i = i+1) {
            g->adjLists[i] = NULL;
        }

        return g;

    }
}
//Adicionar aristas al grafo
void insertEdgeList(GraphList *g, int orig, int dest)
{
    Node *neo;
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
        /*
        // Para grafo dirigido
        Node *neo = (Node*)malloc(sizeof(Node));
        neo->targetVertex = dest;
        neo->next = NULL;
        neo->next = g->adjLists[orig];
        g->adjLists[orig] = neo;
        */
        neo = createNode(dest);
        if(!listaLlena(neo)){
            neo->next = g->adjLists[orig];
            g->adjLists[orig] = neo;
        }
        else{
            printf("Lista llena...\n");
        }
    }
}

// Mostrar grafo

void showGraphList(GraphList *g)
{
    int i;
    Node *edg;
    printf("\n");
    line2();
    printf(" G R A F O S   Lista de Adyacencia..\n");
    line1();

    // Debe recorrer el vector de vertices que apuntan a nodos arista
    // y debe configurar la lista de adyacencia
    // No olvide las consistencias del caso
    i=0;
    if(g == NULL || g->numVertices < 0){
        printf ("Grafo vacioooo...\n");
        line1();
    }
    else{
        while(i < g->numVertices) {
            printf("|%3d|-> ", i);
            edg = g->adjLists[i];
            while(edg!=NULL) {
                printf("%2d--> ", edg->targetVertex);
                edg=edg->next;
            }
            cout<<"NULL"<<endl;
            i = i + 1;
        }
        line1();
    }
}

// Liberar memoria del grafo
GraphList* freeGraphList(GraphList *g)
{
    int i;
    Node *actual, *siguiente;
    if (g == NULL) {
        return NULL;
    }
    else {
        // Recorrer el arreglo g->adjLists.
        // Para cada posición, liberar iterativa o recursivamente todos
        // los nodos de la lista enlazada.
        // Finalmente, liberar el arreglo g->adjLists y la estructura principal g.


        for (i=0; i < g->numVertices; i=i+1) {
            actual = g->adjLists[i];
            while (actual != NULL) {
                siguiente = actual->next;
                free(actual);
                actual = siguiente;
            }
        }
        //Libera arreglo apuntadores y el grafo
        free(g->adjLists);
        free(g);
        printf("\nSe libero mmemoria de grafo lista.\n");
        return g;
    }
}
/*
void freeGraphList(GraphList **g)
{
    int i;
    Node *actual, *siguiente;
    if (*g == NULL) {
        return;
    }
    else {
        // Recorrer el arreglo g->adjLists.
        // Para cada posición, liberar iterativa o recursivamente todos
        // los nodos de la lista enlazada.
        // Finalmente, liberar el arreglo g->adjLists y la estructura principal g.


        for (i=0; i < (*g)->numVertices; i=i+1) {
            actual = (*g)->adjLists[i];
            while (actual != NULL) {
                siguiente = actual->next;
                free(actual);
                actual = siguiente;
            }
        }
        //Libera arreglo apuntadores y el grafo
        free((*g)->adjLists);
        free(*g);
        //*g = NULL;
        printf("\nSe libero mmemoria de grafo lista.\n");
    }
}
*/
Node* createNode(int ned)
{
    Node *aux;
    aux = (Node*)malloc(sizeof(Node));
    if(!listaLlena(aux)){
        aux->targetVertex = ned;
        aux->next = NULL;
        return aux;
    }
    else{
        return aux;
    }
}
void gestionGraphList()
{
    system("clear");
    printf("\n****  LABORATORIO DE GRAFOS  ****\n");
    printf("\t Lista Adyacencia\n\n");
    // ======================================================
    // Prueba Reto 2 y 3: GRAFO: Lista de Adyacencia y DFS
    // ------------------------------------------------------
    GraphList *gl1, *gl2, *gl3;
    createGraphList(gl1);
    gl1 = readGraphList(gl1);
    showGraphList(gl1);
    if (gl1 != NULL) {
        // Construcción del grafo dirigido de prueba obligatoria
        insertEdgeList(gl1, 0, 1);
        insertEdgeList(gl1, 0, 2);
        insertEdgeList(gl1, 1, 3);
        insertEdgeList(gl1, 2, 4);
        insertEdgeList(gl1, 3, 5);
        insertEdgeList(gl1, 4, 5);

        showGraphList(gl1);
        // Ejecución del recorrido
        printf("Recorrido en profunidad...\n");
        DFS(gl1, 0);

        // Liberación absoluta de memoria
        gl1 = freeGraphList(gl1);
        //freeGraphList(&gl1);
        showGraphList(gl1);
        pausarConsola();
    }
}

bool listaLlena(Node *nod)
{
    if(nod == NULL){
        return true;
    }
    else{
        return false;
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

    Node* temp = g->adjLists[vertex];
    while (temp != NULL) {
        int adjVertex = temp->targetVertex;
        if (visited[adjVertex] == 0) {
            recursiveDFS(g, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Función principal para iniciar el DFS
void DFS(GraphList* g, int startVertex)
{

    if (g == NULL || startVertex < 0 || startVertex >= g->numVertices) {
        return;
    }
    // Implementación del recorrido en profundidad recursivo.
    // 0. Crear lista/vector de visitados y despues liberar memoria
    // 1. Marcar startVertex como visitado (1).
    // 2. Imprimir el vértice actual para la traza.
    // 3. Obtener el primer vecino de la lista apuntada por g->adjLists[startVertex].
    // 4. Recorrer la lista enlazada de vecinos: si un vecino no ha sido visitado (0),
    //    llamar recursivamente a DFS pasándole ese vecino.



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



