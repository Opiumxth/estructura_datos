/**
 *  Nombre Prog: ListaDinaSimpleCircular
 *  Descripcion:  Operaciones basicas de la lista circular simple
 *
 *             TAREA
 *    1. Analice el programa, luego compile, ejecute  y analice los resultados.
 *    2. Que diferncia hay entre entre borrar nodo y borrar lista.
 *    3. Implemente las operaciones insertar y eliminar antes y despues de un nodo dado,
 *        (eliminacion del primer y ultimo nodo tienen un tratamiento especial)
 *    4. Ordenar la lista  moviendo datos y moviendo nodos, tambien hay que tener presente el
 *       primer y ultimo nodo
 *    5. Implemente la lista con todas las operaciones anteriores en Lenguaje Java
 *    6. Defina el TAD para  la lista simple circular
 *
 *  Autor:  GASA
 *  Fecha:
 *
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct NODO {
   int valor;
   NODO *sgte;
};

void crearLista(NODO **cab);
void insertarNodo(NODO **cab, int dato);
void borrarNodo(NODO **cab, int dato);
void borrarLista(NODO **cab);
void mostrarLista(NODO *cab);

int main()
{
   NODO *a;
   crearLista(&a);
   insertarNodo(&a, 11);
   insertarNodo(&a, 22);
   insertarNodo(&a, 33);
   //insertarNodo(&a, 40);
   //insertarNodo(&a, 50);
   //mostrarLista(a);
   //borrarNodo(&a, 500);
   mostrarLista(a);
   //borrarNodo(&a, 60);
   //borrarNodo(&a, 50);
   //borrarNodo(&a, 10);
   //insertarNodo(&a, 90);
   //mostrarLista(a);
   //printf("Cab apunta al NODO de valor = %d\n\n", a->valor);
   //borrarLista(&A);
   system("PAUSE");
   return 0;
}
void crearLista(NODO **cab)
{
   *cab=NULL;
}
void insertarNodo(NODO **cab, int dato)
{
   NODO *p;
   // Creamos un nuevo nodo
   p = (NODO*)malloc(sizeof(NODO));

   p->valor = dato;
   p->sgte = NULL;
   // Si la lista está vacía
   if(*cab == NULL) {
      *cab = p;
   }
   else {
      p->sgte = (*cab)->sgte;
   }
   // Cerramos la lista circular
   (*cab)->sgte = p;
}

void mostrarLista(NODO *cab)
{
   //Analice el procedimiento mostrar lista.
   NODO *p;
   p = cab;
   if(p!=NULL) {
      printf("Lista = ");
      do {
         //printf("%d -> ", p->valor);
         p = p->sgte;
         printf("%d -> ", p->valor);
      } while(p != cab);
      printf("\n");
   }
   else {
      printf("Lista vaciaaaa...!\n");
   }
}

void borrarNodo(NODO **cab, int dato)
{
   NODO *p;
   p = *cab;
   // Hacer que cab apunte al nodo anterior al nodo de valor dato
   do {
      if((*cab)->sgte->valor != dato){
         *cab = (*cab)->sgte;
      }
   } while((*cab)->sgte->valor != dato && *cab != p);

   // Existe un nodo con el valor dato
   if((*cab)->sgte->valor == dato) {
      // Si la lista tiene un solo nodo
      if(*cab == (*cab)->sgte) {
         // borrar toda la lista
         free(*cab);
         *cab = NULL;
      }
      else {
         // Si lista tiene más de un nodo, borrar el nodo de valor dato
         p = (*cab)->sgte;
         (*cab)->sgte = p->sgte;
         free(p);
      }
      printf("El dato %d  SE HA ELIMINADO...!\n", dato);
   }
   else {
      printf("El dato %d NO ESTA en la lista...!\n", dato);
   }
}

void borrarLista(NODO **cab)
{
   NODO *p;
   // Mientras la lista tenga más de un nodo
   while((*cab)->sgte != *cab) {
      // borrar el nodo sgte al apuntado por lista
      p = (*cab)->sgte;
      (*cab)->sgte = p->sgte;
      free(p);
   }
   // Borrar el último nodo
   free(*cab);
   *cab = NULL;
}


