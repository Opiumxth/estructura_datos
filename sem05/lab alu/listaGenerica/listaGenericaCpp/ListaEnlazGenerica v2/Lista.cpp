/*
* nomPrograma: Lista.cpp
* descripcion: Implementacion de los metodos de la clase
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
#include <fstream>
#include <vector>
#include "Lista.h"

using namespace std;

// ... (Constructores e insertarFinal ya implementados antes) ...
// Constructor de Lista
template <typename T>
Lista<T>::Lista() : cabeza(nullptr), cola(nullptr) {}

// Destructor
template <typename T>
Lista<T>::~Lista() {
    while (cabeza) {
        Nodo<T>* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}
// Insertar al final
template <typename T>
void Lista<T>::insertarFinal(T valor) {
    Nodo<T>* nuevo = new Nodo<T>(valor);
    if (!cabeza) {
        cabeza = cola = nuevo;
    }
    else {
        cola->siguiente = nuevo;
        cola = nuevo;
    }
}
template <typename T>
void Lista<T>::mostrar() {
    // Y las consustebncias ?
    Nodo<T>* actual;
    actual = cabeza;
    while (actual != nullptr) {
        //std::cout << actual->dato << " -> "; // Que es ...?
        std::cout << actual->dato << endl;
        actual = actual->siguiente;
    }
    std::cout << "NULL" << std::endl; // Explique ... que es?
}


template <typename T>
void Lista<T>::guardarEnArchivo(const std::string& nombreArchivo) {
    Nodo<T>* temp;
    std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        return;   // Que significca...? El metodo no es funcion
    }

    temp = cabeza;
    while (temp) {
        // T debe tener el metodo serializar()
        archivo << temp->dato.serializar() << "\n";
        temp = temp->siguiente;
    }
    archivo.close();
}

template <typename T>
void Lista<T>::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::string linea;
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        return;
    }

    while (std::getline(archivo, linea)) {
        if (!linea.empty()) {
            // T debe tener el metodo estatico deserializar()
            insertarFinal(T::deserializar(linea));
        }
    }
    archivo.close();
}
