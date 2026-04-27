#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include "Nodo.h"

template <typename T>
class Lista {
private:
    Nodo<T>* primero;

public:
    Lista();  // Constructor
    ~Lista(); // Destructor

    void insertar(T valor);
    void mostrar();

    // Métodos de Persistencia
    void salvar(const std::string &nombreArchivo);
    void recuperar(const std::string &nombreArchivo);

    // agregado para persona
    friend std::ostream& operator<<(std::ostream& os, const Lista<T>& lista) {
        Nodo<T>* temp;
        temp = lista.primero;
        while (temp) {
            os << temp->dato << "\n";
            temp = temp->siguiente;
        }
        return os;
    }
};

// Necesario para plantillas
#include "Lista.cpp"

#endif
