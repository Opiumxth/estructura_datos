/*
* nomPrograma: maincc.cpp
* descripcion: Programa principal del Grafo
*
*                   PC04 GRAFOS Matriz y Lista Adyacencia
*                         Recorrido DFS Recursivo
*
* 0. Se tiene el "esqueleto" de la aplicacion Matriz y Lista de adyacencia.
* 1. Analice el TAD Grafo donde se declara las estructuras necesarias y la
*    especificacion de las operaciones.
* 2. Analice bien las implemntaciones de la matriz y de lista de adyacencia.
* 3. Analice bien las pautas que se dan.
* 4. Los RETOS valen 4 putos cada uno, el resto de puntanje se obtiene de las
*    deemas implementaciones para que la aplicacion funcione adecuandamente.,
*
*    IMPORTANTE:
*    Rotule adecuadamente la hoja cuadriculada de la PC04 Grafos, En el
*    debe construir/crear el grafo con minimo de 7 vertices  tanto para la matriz
*    como lista de adyacencia con la relaciones y pesos adecuados
*    MATRIZ DE AYACENCIA:
*    1. Dibuje el grafo con sus respectivas relaciones.
*    2. Dibuje la matriz de adyacencia
*    LISTA DE ADYACENCIA:
*    3. Dibuje el grafo con sus respectivas relaciones
*    4. Dibuje la Lista de ayacencia
*    5, Muestre el recorrido DFS del grafo
*
*    NO COPIE EL EJEMPLO que se da como salida de la aplicacion, Cree su
*    propio ejemplo que va a cargar a la aplicacion.
*    Cree una carpeta PC04 PaternoMaternoNombre, lo comprime y lo envia al
*    correo. La hoja cuadriculada contiene los datos solicitados de la
*    aplicacion de la PC04.
*
*
*
* autor: FLORES HOYOS, Mathias
* fecha: 02-07-2026
* Version 1
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h> // libreria no standard
#include <string.h>
#include "Grafo.h"
#include "grafocc.cpp"

using namespace std;

/*
int main()
{

    printf("---> LABORATORIO DE GRAFOS \n");
    // ======================================================
    // Prueba Reto 1: GRAFO: Matriz de Adyacencia
    // ------------------------------------------------------
    GraphMatrix gm1, gm2, gm3;
    createGraphMatrix(&gm1);


    insertEdgeMatrix(&gm1, 0, 1, 5);
    // ...

    // ======================================================
    // Prueba Reto 2 y 3: GRAFO: Lista de Adyacencia y DFS
    // ------------------------------------------------------

    GraphList *gl1, *gl2, *gl3;
    createGraphList(gl1);
    gl1 = readGraphList(gl1);
    if (gl1 != NULL) {
        // Construcción del grafo dirigido de prueba obligatoria
        insertEdgeList(gl1, 0, 1);
        // ...
        // Ejecución del recorrido
        printf("Recorrido en profunidad...\n");
        //DFS(gl1, 0);

        // Liberación absoluta de memoria
        freeGraphList(gl1);
    }


    //system("pause");
    return 0;
}
*/



// Solucion de la PC04

int main()
{
   printf("---> LABORATORIO DE GRAFOS\n");

   // MATRIZ DE ADYACENCIA

   GraphMatrix gm1;

   createGraphMatrix(&gm1);

   readGraphMatrix(&gm1);

   showGraphMatrix(&gm1);

   // Llenando con los valores
   // Revisar la hoja para ver el grafo con los pesos
   insertEdgeMatrix(&gm1,0,1,5);
   insertEdgeMatrix(&gm1,0,5,8);
   insertEdgeMatrix(&gm1,1,2,2);
   insertEdgeMatrix(&gm1,1,3,4);
   insertEdgeMatrix(&gm1,2,4,7);
   insertEdgeMatrix(&gm1,2,5,4);
   insertEdgeMatrix(&gm1,3,4,6);
   insertEdgeMatrix(&gm1,4,6,3);
   insertEdgeMatrix(&gm1,5,6,2);

   showGraphMatrix(&gm1);

   // LISTA DE ADYACENCIA

   GraphList *gl1;

   createGraphList(gl1);

   gl1 = readGraphList(gl1);

   // Monstrnado la lista vacia
   // showGraphList(gl1);

   if(gl1 != NULL)
   {
      insertEdgeList(gl1,0,1);
      insertEdgeList(gl1,0,5);
      insertEdgeList(gl1,1,2);
      insertEdgeList(gl1,1,3);
      insertEdgeList(gl1,2,4);
      insertEdgeList(gl1,2,5);
      insertEdgeList(gl1,3,4);
      insertEdgeList(gl1,4,6);
      insertEdgeList(gl1,5,6);

      showGraphList(gl1);

      printf("\nRecorrido DFS\n");

      // Hacemos el recorrido DFS desde el vertice 0
      DFS(gl1,0);

      // Para comparar se prueba pasandole el vertice 1
      // DFS(gl1,1);

      freeGraphList(gl1);
   }

   return 0;
}


/*
---> LABORATORIO DE GRAFOS

Numero vertices Matriz Adyacencia: 5

--- MATRIZ DE ADYACENCIA ---
       0   1   2   3   4

   0    0 INF INF INF INF
   1  INF   0 INF INF INF
   2  INF INF   0 INF INF
   3  INF INF INF   0 INF
   4  INF INF INF INF   0

--- MATRIZ DE ADYACENCIA ---
       0   1   2   3   4

   0    0   5 INF INF   8
   1  INF   0   2   6 INF
   2  INF INF   0 INF   1
   3  INF INF INF   0 INF
   4  INF INF INF INF   0

Numero vertices Lista Adyacencia:  6

========================================
 G R A F O S   Lista de Adyacencia
----------------------------------------
|  0|->  2-->  1--> NULL
|  1|->  3--> NULL
|  2|->  4--> NULL
|  3|->  5--> NULL
|  4|->  5--> NULL
|  5|-> NULL
----------------------------------------
Recorrido en profunidad...

Recorrido DFS desde vértice 0: 0 2 4 5 1 3

Se libero mmemoria de grafo lista.

Process returned 0 (0x0)   execution time : 7.151 s
Press ENTER to continue.

*/
