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
#include <fstream>  // <--- ESTA ES LA QUE FALTA
#include "Lista.h"

using namespace std;

template <typename T>
Lista<T>::Lista() {
    this->primero = nullptr;
}

// Destructor: Importante para liberar la memoria dinámica
template <typename T>
Lista<T>::~Lista() {
    Nodo<T>* actual;
    actual = primero;
    while (actual != nullptr) {
        Nodo<T>* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

template <typename T>
void Lista<T>::insertar(T valor) {
    Nodo<T>* nuevo;
    nuevo = new Nodo<T>(valor);
    nuevo->siguiente = primero;
    primero = nuevo;
}

template <typename T>
void Lista<T>::mostrar() {
    Nodo<T>* actual;
    actual = primero;
    while (actual != nullptr) {
        //std::cout << actual->dato << " -> " << endl;
        std::cout << actual->dato << endl;
        actual = actual->siguiente;
    }
    std::cout << "NULL" << std::endl;
}

template <typename T>
void Lista<T>::salvar(const std::string &nombreArchivo) {
    Nodo<T>* actual;
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        actual = primero;
        while (actual != nullptr) {
            // Usamos los getters de Persona
            archivo << actual->dato.getDni() << " "
                    << actual->dato.getNombre() << " "
                    << actual->dato.getSueldo() << "\n";
            actual = actual->siguiente;
        }
        archivo.close();
    }
}

template <typename T>
void Lista<T>::recuperar(const std::string &nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::string dni, nombre;
    double sueldo;

    if (archivo.is_open()) {
        while (archivo >> dni >> nombre >> sueldo) {
            T temp(dni, nombre, sueldo);
            insertar(temp);
        }
        archivo.close();
    }
}
