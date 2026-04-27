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
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Persona.h"

using namespace std;

Persona::Persona(){
    nombre = "";
    sueldo = 0.0;
}
Persona::Persona(std::string n, double s) : nombre(n), sueldo(s) {}

std::string Persona::serializar() const {
    return nombre + "," + std::to_string(sueldo);
}

Persona Persona::deserializar(const std::string& linea) {
    std::stringstream ss(linea);
    std::string n, s_str; //Persona: nombre y sueldo

    std::getline(ss, n, ',');
    std::getline(ss, s_str, ',');

    return Persona(n, std::stod(s_str));
}

// Que hace este metodo...?
std::ostream& operator<<(std::ostream& os, const Persona& p) {
    // Que hacen las instrucciones con cout y que los de os?
    cout.width(12);
    cout.ios::setf(ios::left);
    os <<p.nombre;
    cout.width(10);
    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);
    os << p.sueldo;
    return os;
}
