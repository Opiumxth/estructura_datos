/*
 * nomPrograma:aleatorio2.cpp
 * descripcion: Numeros seudo aleatoios.
 *
 *    Analice y alique.
 * Author: https://ehack.info/numeros-aleatorios-en-c/
 * fecha:
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main()
{
   int valor = 0;
   // rand() definiendo límite superior, el rango va de 0 a (Límite - 1)
   cout << "rand() definiendo limite superior, el rango va de 0 a (Limite-1)" << endl;
   valor=rand()%2;        // Obtiene valores entre 0 y 1
   cout << "rand() % 2: \t\t" << valor << endl;
   valor=rand()%10;       // Obtiene un número entre 0 y 9
   cout << "rand() % 10: \t\t" << valor << endl;
   valor=rand()%1500;     // Obtiene un número entre 0 y 1499
   cout << "rand() % 1500: \t\t" << valor << endl;
   valor=rand()%65536 ;   // Obtiene un número entre 0 y 65535
   cout << "rand() % 65536: \t" << valor << endl << endl;

   // rand() definiendo límite inferior, el rango va de
   // límite inferior a RAND_MAX* (*no del todo cierto, pero nos es útil así)
   cout << "rand() definiendo limite inferior" << endl;
   valor=10+rand();        // Número a partir de 10 hasta RAND_MAX*
   cout << "10 + rand(): \t\t" << valor << endl;
   valor=65000+rand();     // Número a partir de 65000 hasta RAND_MAX*
   cout << "65000 + rand(): \t" << valor << endl << endl;
   // rand() definiendo límite superior, e inferior
   // El compilador calcular el "límite superior real" sumando el límite superior
   // más el valor inicial
   cout << "rand() definiendo limite superior, e inferior" << endl;
   valor=1+rand()%100;     // Genera un valor entre 1 y 100
   cout << "1 + rand() % 100: \t" << valor << endl;
   valor=25+rand()%100;    // Genera un valor entre 25 y 124
   cout << "25 + rand() % 100: \t" << valor << endl;
   valor=rand()%51;        // Genera un valor entre 0 y 50
   cout << "rand() %51: \t\t" << valor << endl << endl;
   // rand() definiendo límite inferior y especificando el valor del límite superior
   // Observa que no dejamos al compilador calcular el lìmite superior "por su cuenta"
   cout << "rand() definiendo limite inferior y especificando el valor del limite superior" << endl;
   valor=10+rand()%(26-10);//Genera un valor entre 10 y 25
   cout << "10 + rand() % (26-10): \t" << valor << endl;
   valor=25+rand()%(100-25);//Genera un valor entre 25 y 100
   cout << "25 + rand() % (100-25): " << valor << endl;

   system("pause");
   return(0);
}

