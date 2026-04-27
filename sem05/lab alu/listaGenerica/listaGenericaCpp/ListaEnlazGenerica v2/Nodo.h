#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include <fstream>

template <typename T>
class Nodo
{
    public:
    T dato;
    Nodo<T>* siguiente;

    Nodo(T valor);
};
// Obligatorio para Templates
#include "Nodo.cpp"

#endif
