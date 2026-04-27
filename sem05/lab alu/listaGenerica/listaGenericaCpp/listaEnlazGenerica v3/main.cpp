#include <iostream>
#include <fstream>
#include "Lista.h"
#include "Persona.h"

using namespace std;

int main()
{
    Lista<Persona> nomina;

    // Crear y insertar
    Persona p1("123", "Juan", 1500.50);
    Persona p2("456", "Maria", 2200.00);

    nomina.insertar(p1);
    nomina.insertar(p2);

    std::cout << "Lista Original (Usa el << sobrecargado):" << std::endl;
    nomina.mostrar();

    // Persistencia
    nomina.salvar("personas.txt");
    std::cout << "\nDatos guardados. Limpiando y recuperando..." << std::endl;

    Lista<Persona> nuevaLista;
    nuevaLista.recuperar("personas.txt");
    nuevaLista.mostrar();

    /*
    // Datos Prueba sin Persona
    // Lista de Enteros
    Lista<int> listaEnteros;
    listaEnteros.insertar(10);
    listaEnteros.insertar(20);
    listaEnteros.insertar(30);

    std::cout << "Lista de enteros: ";
    listaEnteros.mostrar();

    // Lista de Strings
    Lista<std::string> listaStrings;
    listaStrings.insertar("Mundo");
    listaStrings.insertar("Hola");

    std::cout << "Lista de strings: ";
    listaStrings.mostrar();

    // El destructor se llama automáticamente al salir del scope
    */
    return 0;
}
