#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

class Persona {
private:
    std::string dni;
    std::string nombre;
    double sueldo;

public:
    Persona(); // Requerido para templates y persistencia
    Persona(std::string dni, std::string nombre, double sueldo);

    // Getters para salvar/recuperar
    std::string getDni() const {
        return dni;
    }
    std::string getNombre() const {
        return nombre;
    }
    double getSueldo() const {
        return sueldo;
    }

    // Sobrecarga similar a toString() de Java
    friend std::ostream& operator<<(std::ostream& os, const Persona& p);
};

#include "Persona.cpp"

#endif
