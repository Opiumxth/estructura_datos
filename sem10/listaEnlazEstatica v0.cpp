/**
*  NombreProg : listaEnlazEstatica v0.cpp
*  Descripcion: Operaciones basicas de lista enlazada simple.
*
*           Implementacion de una lista enlazada en estructura estatic
*
*  La implementacion se basa:
*  a. Se crea un "espacio de memoria" para obtener los elementos (nodos) de la
*     lista, Cada nodo(val, sgte). Lista de nodos libres
*  b. El metodo crearElemento(...), provee nodos de la lista de nodos libres.
*     similar a malloc
*  c. El metodo liberaElemento(...), deveulve elementos a la lista de nodos
*     libres que los users de listas enlazadas eliminaron, similar a delete
*  d. Los uusers pueden crear las listas enlazadas que deseen
*  e. Analice la aplicacion para su mejor entendimiento .
*
*
*                           T A R E A
*
*	Debe aplicar conocimientos de operaciones basicas de vector de registros
*	aplicado a manejo espacio de memoria tratados y aplicados en el ultimo
*	laboratorio de la lista enlazada en seudocodigo.
*		Para la siguiente clase:
*		Analice, compile y ejecute; luego especifique las operaciones para
*	    determinar los parametros que se va utilizar como de insertarInicio()
*		y mostrarElementos() y todos los operaciones de la lista.
*   1. Elimine las variables globales de tal forma que tengamos un nuevo programa
*	   con subprogramas con paso de parametros SIN VARIABLES GLOBALES, y despues:
*   2. Implemente las SUBPROGRAMAS  buscar, contar, ordenar, insertar al final
*      insertar antes y despues de un elemento dado.

*
*  Autor: GASA
*  Fecha: version 0
*
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#define MAX 10

using namespace std;

typedef int TD;

// Para gestionar la direccion de elementos libres de lista enlazadas

struct NODO{
   TD  val;
   int sgte;
};
// Variables globales (debe eliminarlas)
int cab=-1, cab1;
NODO mem[MAX];

// Implementacion de los propotipos de funcion

// Inicializa  la memoria o la lista de nodos libres
void iniciaMem();

// Gestiona la lista de nodos libres
int crearElemento();

// Devuelve elemento a la lista de nodos libres (nodos eliminados)
void liberaElemento();

// Inserta un NODO al inicio de la lista de algun usuario
void insertarInicio(int dato);

// Inserta un NODO del inicio de la lista del usuario
void eliminarInicio(TD *dato);

// Muestra los elementos de la lista del usuario
void mostrarElementos();

// Mapea la "memoria" donde donde los users han creado listas enlazadas
void mostrarEstructura();


int main()
{
   int i;
   TD Num;
   iniciaMem();

   printf("\nLISTAS DE ELEMENTOS \n\n");
   printf("Rutina de Ingreso \n");
   //printf("Ingrese un dato entero ---> ");
   //scanf("%d",&Num);
   //InsertarInicio(L1, Num);
   insertarInicio(11);
   insertarInicio(22);
   insertarInicio(33);
   printf("\nRutina de Visualizacion \n");
   mostrarElementos();

   printf("\nRutina de Eliminacion \n");
   eliminarInicio(&Num);
   printf("\ndato eliminado :  %d \n\n", Num);
   mostrarEstructura();

   //system("PAUSE");
   return (0);
}


void iniciaMem()
{
   int i;
   cab1 =0; //Variable Global
   for(i=0;i<MAX-1;i++){
      mem[i].val = 0;
      mem[i].sgte = i+1;
   }
   mem[MAX-1].sgte = -1;
   for(i=0;i<MAX;i++){
      printf("\n %2d[%5d|%3d]\n", i, mem[i].val, mem[i].sgte);
   }
}
void mostrarEstructura()
{
   int i;
   printf("\n  MAPEO DE LA MEMORIA CON ELEMENTOS");
   for(i=0;i<MAX;i++){
      printf("\n %2d[%5d|%3d]\n", i, mem[i].val, mem[i].sgte);
   }
}

int crearElemento()
{
   int p;
   p = cab1;
   if(cab1 == -1){
      printf("No HAY ESPACIO en memoria\n\n");
      exit(1);
   }
   cab1 = mem[cab1].sgte;
   return(p);
}

void liberaElemento(int p)
{
   mem[p].sgte = cab1;
   cab1 = p;
}

void insertarInicio(int dato)
{
   int q;
   if(cab == -1){
      q = crearElemento();
      mem[q].val = dato;
      mem[q].sgte = -1;
      cab = q;
      printf("mem[q].val = %d\n", mem[q].val);
      printf("mem[q].sgte = %d\n", mem[q].sgte);
      printf("cabi = %d\n", cab);
   }
   else{
      q = crearElemento();
      mem[q].val = dato;
      mem[q].sgte = cab;
      cab = q;
      printf("Mem[Q].val = %d\n", mem[q].val);
      printf("Mem[Q].sgte = %d\n", mem[q].sgte);
      printf("cabs = %d\n", cab);
   }
}

void eliminarInicio(TD *dato)
{
   int q;
   if(cab == -1)
      printf("Lista VACIA \n\n");
   else{
      q = cab;
      *dato = mem[q].val;
      cab = mem[cab].sgte;
      liberaElemento(q);
   }
}

 void mostrarElementos()
{
   int q;
   TD dato;
   q = cab;
   while(q != -1){
      dato = mem[q].val;
      printf("%5d", dato);
      q = mem[q].sgte;
   }
}
