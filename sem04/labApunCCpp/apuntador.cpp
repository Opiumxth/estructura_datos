/*
* nomPrograma: apuntador.cpp
* descripcion: Tratamiento de apuntadores
*
*                   TAREA
* 0. Analice el codigo, luego compile, ejecute y analice la salida.
* 1. Analice el modulo APUNTADOES declaracion, direccion y desferencia
* 2. Analice el modulo Apuntadores multinivel:*, **, **
* 3. Implemente utilizando los operadores; cin y cout de C++
*
* autor:
* fecha:
* version1
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <String.h>

using namespace std;

void apuntador();
void apuntadorDeApuntadorC();
void apuntadorDeApuntadorC1();
void apuntadorDeApuntadorCpp();


int main()
{

    apuntador();
    apuntadorDeApuntadorC();
    //apuntadorDeApuntadorCpp();

    system("pause");
    return 0;
}
void apuntador()
{
    int *ap, a;
    a = 5;
    ap = &a;
    printf("\nAPUNTADORES: Declaracion, direccion y desreferencia\n\n");
    printf("a: %13d, *ap: %13d\n", a, *ap);
    printf("&a: %12p, &*ap: %12p, ap: %12p\n", &a, &ap,ap);
    *ap = 99;
    printf("a: %13d, *ap: %13d\n", a, *ap);
}

void apuntadorDeApuntadorC()
{
    // --- Nivel Básico: Puntero Simple (*) ---
    // Un puntero simple almacena la dirección de una variable normal.
    // Variable original

    printf("\nAPUNTADOR SIMPLE *: Declaracion, direccion y desreferencia\n\n");
    int va;
    int *ap1;
    va  = 50;
    ap1 = &va;

    printf("va : %13d, *ap1: %13d\n", va, *ap1);
    printf("&va: %13p, &*ap1: %12p, ap1: %12p\n", &va, &ap1, ap1);
    // Modificamos el valor va con el apuntador ap1*
    *ap1 = 150;
    printf("Se ha actualizado la variable va: 150\n");
    printf("va : %13d, *ap1: %13d\n", va, *ap1);

    printf("\nAPUNTADOR DOBLE **: Declaracion, direccion y desreferencia\n\n");
    int **ap2;
    ap2 = &ap1;

    printf("va : %13d, *ap1  : %13d\n", va, *ap1);
    printf("va : %13d, **ap2 : %13d\n", va, **ap2);
    printf("&va: %13p, &*ap1 : %12p, ap1: %12p\n", &va, &ap1, ap1);
    printf("&va: %13p, &**ap2: %12p, ap2: %12p\n", &va, &ap2, ap2);
    // Modificamos el valor va con el apuntador ap1*
    **ap2 = 250;
    printf("Se ha actualizado la variable va: 250\n");
    printf("va : %13d, **ap2 : %13d\n", va, **ap2);

    printf("\nAPUNTADOR DOBLE ***: Declaracion, direccion y desreferencia\n\n");
    int ***ap3;
    ap3 = &ap2;

    printf("va : %13d, *ap1   : %13d\n", va, *ap1);
    printf("va : %13d, **ap2  : %13d\n", va, **ap2);
    printf("va : %13d, ***ap3 : %13d\n", va, ***ap3);
    printf("&va: %13p, &*ap1  : %12p, ap1: %12p\n", &va, &ap1, ap1);
    printf("&va: %13p, &**ap2 : %12p, ap2: %12p\n", &va, &ap2, ap2);
    printf("&va: %13p, &***ap3: %12p, ap3: %12p\n", &va, &ap3, ap3);
    // Modificamos el valor va con el apuntador ap1*
    ***ap3 = 350;
    printf("Se ha actualizado la variable va: 350\n");
    printf("va : %13d, ***ap2 : %13d\n\n", va, ***ap3);
}

void apuntadorDeApuntadorC1()
{
    // --- Nivel Básico: Puntero Simple (*) ---
    // Un puntero simple almacena la dirección de una variable normal.
    // Variable original
    int var;
    int *ptr_basico;
    var = 50;
    ptr_basico = &var; // ptr_basico almacena la dirección de 'var'.
    //cout << "\n\n--- UTILIZANDO cin/cout de C++" << endl<<endl;;
    printf("\n\n--- UTILIZANDO cin/cout de C\n\n");
    //cout << "--- Nivel Basico (*) ---" <<endl;;
    printf("Apuntador Simple (*)\n\n");
    //cout << "Valor de var: " << var << endl;
    printf("Valor de var: %d\n", var);
    //cout << "Direccion de var: " << &var << endl;
    printf("Direccion de var: %p\n", &var);
    //cout << "Direccion almacenado en ptr_basico (direccion de var): " << ptr_basico << endl;
    printf("Direccion a0untado por ptr.basico (direccion var): %p\n", ptr_basico);
    //cout << "Valor apuntado por ptr_basico (*ptr_basico): " << *ptr_basico << endl;
    printf("Valor apuntado por ptr_basico (*ptr_basico): %d\n\n", *ptr_basico);
    // Modificar la variable original a través del puntero doble
    *ptr_basico = 150;
    //cout << "Nuevo valor de var despues de asignar *ptr_basico: 150, var: " << var << endl;
    printf("Nuevo valor, apuntado por *ptr_basico=150: %d\n\n", *ptr_basico);

    // --- Nivel Medio: Puntero Doble (**) ---
    // Un puntero doble almacena la dirección de otro puntero.
    int **ptr_medio;
    ptr_medio = &ptr_basico; // ptr_medio almacena la dirección de 'ptr_basico'.

    //cout << "--- Nivel Medio (**) ---" << endl;
    printf("Apuntador Doble (**)\n\n");
    //cout << "Valor de var: " << var << endl;
    printf("Valor de var: %d\n", var);
    //cout << "Direccion de ptr_basico: " << &ptr_basico << endl;
    printf("Direccion de ptr_basico: %p\n",&ptr_basico);
    //printf("Direccion de ptr_basico: %p\n",ptr_basico); // Que imprime ptr_basico?
    //cout << "Direccion almacenado en ptr_medio (direccion de ptr_basico): " << ptr_medio << endl;
    printf("Direccion almacenado en (direccion ptr_basico): %p\n", ptr_medio);
    //cout << "Direccion apuntado por ptr_medio (*ptr_medio, es decir, el valor de ptr_basico): " << *ptr_medio << endl;
    printf("Direccion apuntado en ptr_medio (*ptr_medio, o sea valor ptr_basico):%p\n", *ptr_medio);
    //cout << "Valor apuntado por **ptr_medio (**ptr_medio, es decir, el valor de var):" << **ptr_medio << endl;
    printf("Valor apuntado por **ptr_medio(**ptr_medio, o sea el valor de var): %d\n\n", **ptr_medio);

    // Modificar la variable original a través del puntero doble
    **ptr_medio = 250;
    //cout << "Nuevo valor de var despues de asignar **ptr_medio: 250, var: " << var << endl;
    printf("Nuevo valor, apuntado por **ptr_medio=250: %d\n\n", **ptr_medio);

    // --- Nivel Exigente: Puntero Triple (***) y uso avanzado ---
    // Un puntero triple almacena la dirección de un puntero doble.
    int ***ptr_triple;
    ptr_triple = &ptr_medio; // ptr_triple almacena la dirección de 'ptr_medio'.

    //cout << "--- Nivel Triple (***) ---" << endl;
    printf("Apuntador Doble (**)\n\n");
    //cout << "Valor de var: " << var << endl;
    printf("Valor de var: %d\n", var);
    //cout << "Direccion de ptr_medio: " << &ptr_medio << endl;
    printf("Direccion de ptr_medio %p\n",&ptr_medio);

    //cout << "Direccion almacenado en ptr_triple (direccion de ptr_medio): " << ptr_triple << endl;
    printf("Direccion almacenado en ptr_triple(direccion de ptr_medio): %p\n", &ptr_medio);
    //cout << "Valor apuntado por ***ptr_triple: " << ***ptr_triple << endl;
    printf("valor apuntado por ptr_triple: %d\n\n", ***ptr_triple);

        // Modificar la variable original a través del puntero doble
    ***ptr_triple = 350;
    //cout << "Nuevo valor de var despues de asignar ***ptr_triple: 350: " << var << endl;
    printf("Nuevo valor, apuntado por **ptr_triple=350: %d\n\n", ***ptr_triple);


}

void apuntadorDeApuntadorCpp()
{


      // Variable original
    int var = 100;

    // --- Nivel Básico: Puntero Simple (*) ---
    // Un puntero simple almacena la dirección de una variable normal.
    int *ptr_basico;
    ptr_basico = &var; // ptr_basico almacena la dirección de 'var'.

    cout << "\n\n--- UTILIZANDO scanf/printf de C" << endl<<endl;;
    printf("\n\n--- UTILIZANDO scanf/printf de C\n\n" );
    cout << "--- Nivel Basico (*) ---" << endl<<endl;;
    cout << "Valor de var: " << var << endl;
    cout << "Direccion de var: " << &var << endl;
    cout << "Valor almacenado en ptr_basico (direccion de var): " << ptr_basico << endl;
    cout << "Valor apuntado por ptr_basico (*ptr_basico): " << *ptr_basico << endl << endl;
    // --- Nivel Medio: Puntero Doble (**) ---
    // Un puntero doble almacena la dirección de otro puntero.
    int **ptr_medio;
    ptr_medio = &ptr_basico; // ptr_medio almacena la dirección de 'ptr_basico'.

    cout << "--- Nivel Medio (**) ---" << endl;
    cout << "Direccion de ptr_basico: " << &ptr_basico << endl;
    cout << "Valor almacenado en ptr_medio (direccion de ptr_basico): " << ptr_medio << endl;
    cout << "Valor apuntado por ptr_medio (*ptr_medio, es decir, el valor de ptr_basico): " << *ptr_medio << endl;
    cout << "Valor apuntado por **ptr_medio (**ptr_medio, es decir, el valor de var): " << **ptr_medio << endl << endl;

    // Modificar la variable original a través del puntero doble
    **ptr_medio = 250;
    cout << "Nuevo valor de var despues de usar **ptr_medio: " << var << endl << endl;
    // --- Nivel Exigente: Puntero Triple (***) y uso avanzado ---
    // Un puntero triple almacena la dirección de un puntero doble.
    int ***ptr_exigente;
    ptr_exigente = &ptr_medio; // ptr_exigente almacena la dirección de 'ptr_medio'.

    cout << "--- Nivel Exigente (***) ---" << endl;
    cout << "Direccion de ptr_medio: " << &ptr_medio << endl;
    cout << "Valor almacenado en ptr_exigente (direccion de ptr_medio): " << ptr_exigente << endl;
    cout << "Valor apuntado por ***ptr_exigente: " << ***ptr_exigente << endl << endl;

    // Uso avanzado: Paso por referencia de un puntero (común en listas enlazadas o manejo de memoria)
    // Función de ejemplo que no devuelve valor, pero modifica el puntero original.
    // void modificarPuntero(int **p) { *p = new int(500); } // Esto requeriría new y delete.
}
