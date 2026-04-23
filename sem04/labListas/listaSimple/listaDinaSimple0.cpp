/**
 *  Nombre Prog: ListaDinaSimple0.cpp
 *  Descripcion: Operaciones basicas de lista dinamica simple
 *
  *             TAREA
 *    1. Analice el programa, luego compile  ejecute y analice los resultados.
 *    2. Implemente borrar el primero nodo. Que diferencia hay entre borrar lista?
 *    3. Implemente las operaciones insertar y eliminar antes y despues de un nodo dado,
 *        la insercion y eliminacion en una lista ordenada.
  *       (eliminacion del primer y ultimo nodo tienen un tratamiento especial)
 *    4. Ordenar la lista  moviendo datos y moviendo nodos, tambien hay que tener presente el
 *        primer y ultimo nodo
 *    5. Defina el TAD para  la lista simple
 *    6. Implemente la lista con todas las operaciones anteriores en Lenguaje Java
 *
 *  autor: gasa
 *  Fecha: Septiembre 2010
 *
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

typedef int TD;

struct NODO {
   TD valor;
   NODO *sgte;
};

void crearLista(NODO **cab);
NODO* crearNodo(TD dato);
void insertarNodoIni(NODO **cab, int dato);
void mostrarLista(NODO *cab);
void adicionaNodo(NODO **cab, int dato);
int listaVacia(NODO *cab);
void eliminarListla(NODO **cab);

int main()
{
   NODO *la;
   crearLista(&la);
   string a="hola";
   cout << a << endl;
   /*
   ladicionaNodo(&la,5);
   ladicionaNodo(&la,10);
   ladicionaNodo(&la,20);
   */
   insertarNodoIni(&la, 11);
   insertarNodoIni(&la, 22);
   insertarNodoIni(&la, 33);
   insertarNodoIni(&la, 44);
   mostrarLista(la);
   //adicionaNodo(&la,50);
   //mostrarLista(la);
   /*
      eliminarNodo(&la, 10);
      mostrarLista(la);
      eliminarNodo(&la, 5);
      mostrarLista(la);
      eliminarNodo(&la, 55);
      mostrarLista(la);
      eliminarNodo(&la, 30);
      mostrarLista(la);
      eliminarNodo(&la, 40);

      mostrarLista(la);

      eliminarLista(&la);
   */
   system("pause");
   return 0;
}

void crearLista(NODO **cab)
{
   *cab=NULL;
}

NODO* crearNodo(TD dato)
{
   NODO *p;
   p=(NODO*)malloc(sizeof(NODO));
   if(p==NULL) {
      printf("No hay espacio de memoria....!\n");
      system("pause");
      //exit(0);
      return(p);
   } else {
      p->valor=dato;
      p->sgte=NULL;
      return(p);
   }
}

void insertarNodoAntes(NODO **cab, int dato, int x )
{

}
void eliminarNodoDato(NODO **cab, int dato)
{

}

void insertarNodoIni(NODO **cab, int dato )
{
   NODO *p;
   //p=(NODO*)malloc(sizeof(NODO));
   //p->valor=dato;
   p=crearNodo(dato);
   if(p==NULL) {
      printf("No hay espacio de memoria....!\n");
      system("pause");
      exit(0);
   } else {
      //Si lla listla estla vlacila
      if(*cab==NULL) {
         p->sgte=*cab;
         *cab=p;
      } else {
         p->sgte=*cab;
         *cab=p;
      }
   }
}

void adicionaNodo(NODO **cab, int dato)
{
   NODO *p, *q;
   p=crearNodo(dato);
   if(p==NULL) {
      printf("No hay espacio de memoria....!\n");
      system("pause");
      exit(0);
   } else {
      if(*cab==NULL) {
         p->sgte=*cab;
         *cab=p;
      }
      else {
         q=*cab;
         while(q->sgte!=NULL) {
            q=q->sgte;
         }
         q->sgte=p;
      }
   }
}

void mostrarLista(NODO *cab)
{
   NODO *p = cab;

   if(listaVacia(p)) {
      printf("Lista vacía\n");
   }
   else {
      printf("Lista = <");
      //while(p->sgte->sgte) {
      //while(p->sgte) {
      while(p) {
         printf("%d ->", p->valor);
         p = p->sgte;
      }
      printf(">\n");
   }
}

int listaVacia(NODO *cab)
{
   return (cab == NULL);
}

void eliminarLista(NODO **cab)
{
   NODO *p;
   //Porque utilizamos *clab
   while(*cab) {
      p = *cab;
      *cab = p->sgte;
      free(p);
   }
}


