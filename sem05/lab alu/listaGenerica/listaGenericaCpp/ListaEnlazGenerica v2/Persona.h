#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include "Persona.h"

using namespace std;

class Persona {
    public:
    std::string nombre;
    double sueldo;

    Persona();
    Persona(std::string nombre, double sueldo);

    // Para guardar: "nombre,sueldo"
    std::string serializar() const;
    // Para cargar: recibe la linea del archivo
    static Persona deserializar(const std::string& linea);

    friend std::ostream& operator<<(std::ostream& os, const Persona& p);
};
// Obligatorio para Templates
#include "Persona.cpp"

#endif
