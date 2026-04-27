#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <fstream>
#include <vector>
#include "Nodo.h" // Asumiendo que Nodo estÃ¡ aquÃ­ o arriba

template <typename T>
class Lista {
    private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

    public:
    Lista();
    ~Lista();
    void insertarFinal(T valor);
    void mostrar();

    // Persistencia
    void guardarEnArchivo(const std::string& nombreArchivo);
    void cargarDesdeArchivo(const std::string& nombreArchivo);
    // Que hace este metodo??
    friend std::ostream& operator<<(std::ostream& os, const Lista<T>& lista) {
        Nodo<T>* temp = lista.cabeza;
        while (temp) {
            os << temp->dato << "\n";
            temp = temp->siguiente;
        }
        return os;
    }
};
// Obligatorio para Templates
#include "Lista.cpp"

#endif
