/*
* nomPrograma: prioridadListas.cpp
* descripcion: operaciones basicas
*           TAREA
*
*      Implementa las operaciones de una cola de prioridad
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
    int info;
    NODO *sgte;
};
struct COLAP{
    int prio;
    NODO *nsgte;
    COLAP *psgte;
};

//prototipos de funcion

int main()
{


    system("pause");
    return 0;
}

//implmentacion prototipos de funcion
