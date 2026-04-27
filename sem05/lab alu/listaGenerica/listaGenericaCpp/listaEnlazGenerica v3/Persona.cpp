/*
* nomPrograma: Persona.cpp
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
#include "Persona.h"


using namespace std;

Persona::Persona() : dni(""), nombre(""), sueldo(0.0) {}

Persona::Persona(std::string dni, std::string nombre, double sueldo) {
    this->dni = dni;
    this->nombre = nombre;
    this->sueldo = sueldo;
}

// Implementación de sobrecarga operator<< del "toString"
std::ostream& operator<<(std::ostream& os, const Persona& p) {
    cout.width(8);
    cout.ios::setf(ios::right,ios::adjustfield);
    //cout.ios::setf(ios::left,ios::adjustfield);
    os << p.dni << " ";

    cout.width(12);
    cout.ios::setf(ios::left,ios::adjustfield);
    os <<p.nombre;

    cout.width(10);
    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);
    os << p.sueldo;
    return os;
}
