/*
* nomPrograma: maincc.cpp
* descripcion: Programa principal del Grafo
*
*        SOLUCION PC04 GRAFOS Matriz y Lista Adyacencia
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
* autor: GASA
* fecha:
* Version 1
        - Analice la solucion
        - Analice los metodos freeGraphList funcion y procedimiento
        - Module los encabezados y lineas
        - Re implemente todo utilizando procedimientos o sea (**)
        - Implemente una aplicacion utilizando sus propias librerias: Lista.h
          Pila.h, Cola.h, Avl.h, ArbolB.h, Grafo.h, Trie.h, Hash.h
          - Crear una aplicacion conversion de expresiones matematicas infijas
            a posfijas o prefijas
          - Implementar una AplicacionDiccionario
          - Implemente una aplicacion que solucione problemas utilizando los
            algoritmos de Grafos

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h> // libreria no standard
#include <string.h>
#include "Grafo.h"
#include "grafocc.cpp"

using namespace std;

int main()
{

    gestionGraphMatrix();
    gestionGraphList();

    //system("pause");
    return 0;
}

