/*
* nomPrograma:
* descripcion:
*
*
*
* autor:
* fecha:
* version1
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>
#include "Nodo.h"
//#include "Persona.h"

using namespace std;

template <typename T>
Nodo<T>::Nodo(T valor) {
    this->dato = valor;
    this->siguiente = nullptr;
}
