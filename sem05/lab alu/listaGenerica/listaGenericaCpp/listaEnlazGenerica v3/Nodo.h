#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;

    Nodo(T valor); // Constructor
    ~Nodo();
};

// Necesario para plantillas
#include "Nodo.cpp"

#endif
