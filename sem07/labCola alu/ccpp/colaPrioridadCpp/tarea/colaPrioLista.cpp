/*
* nomPrograma: colaPrioLista.cpp
* descripcion: operaciones basicas de cola prioridad dinamica
*               TAREA
*
*   Implemente las operaciones basicas de cola de prioridad dinamica:
*   encolar, decolar, colaVacia, colaLlena, visorCola
*
* author:
* fecha :
* Version 1
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

using namespace std;
struct NODO{
    char dato;
    int priori;
    nodo *sgte;
};
struct COLAP{
    NODO *frente;
    NODO *finale;
};

//prototipos de funcion
NODO *crearNodo(char x, int prio);
void encolar(COLAP *cx, char dato, int prio);



int main()
{


    system("pause");
    return 0;
}

//implmentacion prototipos de funcion
