/**
*  NombreProg :     PilaEstatVector.cpp
*  Descripcion:     Pila estatica de enteros
*
*           TAREA
*
*  1. Analice el codigo, luego compile, ejecute y analice los resultados
*  2. Implemente la operacion visorPila(...) que permita ver el valor del tope
*  3. Operaciones de Conversion Infijo/posfijo/prefijo
*  4. Implementa la operacion visualizar los elmentos de la pila.
*  4. Evaluacion de expresion prefijo/posfijo debe implementarse usando
*     ver Cairo 2014: expresiones Infija/Posfija
*     compilacion separada.
*
*  Autor: GASA
*  Fecha:
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 3

using namespace std;

typedef int TD;

void crearPila(int *tope);
void empilar(TD PILA[], int *tope, TD dato);
TD depilar(TD PILA[], int *tope);
bool pilaVacia(int *tope);
bool pilaLlena(int *tope);


int main()
{
   TD p1[MAX];
   int top=-1;
   //RUTINA DE CREACION DE LA PILA
   crearPila(&top);
   //RUTINA DE EMPILAR
   empilar(p1, &top, 10);
   empilar(p1, &top, 20);
   empilar(p1, &top, 30);
   empilar(p1, &top, 40);
   //RUTINA DEPILAR
   printf("%d, ", depilar(p1, &top));
   printf("%d, ", depilar(p1, &top));
   printf("%d, ", depilar(p1, &top));
   printf("%d  ", depilar(p1, &top));
   printf("%d  ", depilar(p1, &top));
   printf("\n\n");

   system("pause");
   return (0);
}

void crearPila(int *tope)
{
   *tope = -1;
}

void empilar(TD PILA[], int *tope,  TD dato)
{
   int n;
   n=*tope; // Porque se utiliza variable auxiliar?
   n=n+1;
   if(!pilaLlena(&n)){
      PILA[n] = dato;
      *tope = n;
   }
   else{
      printf("\n\n...Pila LLENA\n\n");
   }
}

TD depilar(TD PILA[], int *tope)
{
   TD dato;
   if(pilaVacia(&*tope)==false){ // ¿porque utiliza &*?
      dato = PILA[*tope];
      *tope = *tope -1;
      return(dato);
   }
   else{
      printf("\n\n...Pila VACIA\n\n");
      return(0);
   }
}

bool pilaVacia(int *tope)
{
   if(*tope < 0){
      return(true);
   }
   else{
      return(false);
   }
}

bool pilaLlena(int *tope)
{
   printf("Tope = %d\n", *tope);
   if(*tope > MAX-1){
      return(true);
   }
   else{
      return(false);
   }
}
