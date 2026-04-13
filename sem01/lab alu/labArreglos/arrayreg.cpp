/*
 * nomPrograma: arrayReg.cpp
 * descripcion: operaciones basica de arreglos
 *
 *                   Tarea
 *    Implmente las operaciones basicas de un vector de registros
 *
 * autor:
 * fecha:
 * version 1.
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 4
#define STR15 15

struct ALUMNO {
    int codAlu;
    char nombre[STR15];
    int prac[MAX];
    char valido; // S: valido, N: no valido
    long nreg;
};

void crearVector(ALUMNO x[], int *dx);
void leerVector(ALUMNO x[], int *dx);
void escribirAlumno(ALUMNO reg);
void leerAlumno(ALUMNO *reg);
void mostrarVector(ALUMNO x[], int *dx);
void buscarAluPorCodigo(ALUMNO x[], int dx, int cod);
void ordenarAluPorCodigo(ALUMNO x[], int dx);
void ordenarAluPorNombre(ALUMNO x[], int dx);

void insertarAluPorPosicion(ALUMNO x[], int dx, int pos);
void insertarAluPorPosicion(ALUMNO x[], int dx, int pos);//Vector ordenado

int main()
{

   //Solo llamadas a metodos

   system("pause");
   return(0);
}

// Muestra un menú con las opciones disponibles y captura una opción del usuario
