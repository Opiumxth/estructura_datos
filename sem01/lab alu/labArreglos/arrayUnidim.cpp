/*
 * nomPrograma: vector00.cpp
 * descripcion: Operaciones basicas.
 *             TAREA (Evaluacion continua)
 *       Los datos de prueba son: a[]= [4,1,9]
 *    1. Analice, ejecute y luego analice los resultados. Pruebe activando solo
 *       la operacion deseada.
 *    2. Comente brevemente en no mas 40 caracteres cada una de las intrucciones.
 *    3. La referencia o llamada insertarxPos(a,&na,4, 22) no inserta, corrija
 *       elm error.
 *    4. Con la experiencia anterior ahora implemente eliminarxPos()
 *    5. Implemente ordenarVector() veease la guia de labotarorio
 *    6. RETO: Implemente insertarxValor() vease la especificacion en la guia de
 *       lanoratorio. Si ha analizado bien y comprendido todo lo anterior,  esta
 *       es una operacion muy simple, requiere que el vector este ordenado y
 *       tambien de la operacion buscarDato() que retorna la posicion del dato
 *       a insertar en el vector.
 *
 *
 * autor: GASA
 * fecha:
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10

using namespace std;

void crearVector(int x[], int *dx);
void leerVector(int x[], int *dx);
void mostrarVector(int x[], int dx);
void ordenarVector(int x[], int dx);

void insertarxPos(int x[], int *dx, int posi, int dato);
// Prototipos de la tarea
void eliminarxPos(int x[], int *dx, int posi);
void insertarxValor(int x[], int *dx, int dato);
int buscarDato(int x[], int dx, int dato);

int main(){
   int a[MAX];
   int na, nb;
   crearVector(a, &na);
   leerVector(a, &na);
   mostrarVector(a, na);
   /* Prueba insertar por posicion */
   //insertarxPos(a,&na,0, 22);
   //insertarxPos(a,&na,1, 22);
   //insertarxPos(a,&na,3, 22);
   //insertarxPos(a,&na,4, 22);// Problemas, Porque no inserta?
   //insertarxPos(a,&na,5, 22);
   /* Prueba eliminar por posicion */
   //eliminarxPos(a,&na,0);
   //eliminarxPos(a,&na,1);
   //eliminarxPos(a,&na,2);
   //eliminarxPos(a,&na,3);
   //eliminarxPos(a,&na,4);
   ordenarVector(a, na);
   mostrarVector(a, na);

   system("pause");
   return(0);
}

void crearVector(int x[], int *dx)
{
   *dx=-1;
}
void leerVector(int x[], int *dx)
{
   int i, n, val;
   //RUTINA DE LECTURA
   scanf("%d", &n);
   if(n<MAX){
      for(i=0;i<n;){
         scanf("%d", &val);
         x[i]=val;
         i=i+1;
      }
      *dx=i;//Actualizac de la dimension
   }
   else{
      printf("Diemnsion fuera de RANGO ...");
   }
}
void mostrarVector(int x[], int dx){
   //RUTINA DE ESCRITURA
   int i, val;
   if(dx>0){
      printf("vector = < ");
      for(i=0;i<dx;){
         val=x[i];
         printf("%d ", val);
         i=i+1;
      }
      printf(">\n");
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}
void ordenarVector(int x[], int dx)
{
   int aux, i, j;
   if(dx>-1){
      for(i=0; i<dx-1; i++){
         for(j=i+1; j<dx; j++){
            if(x[i]>x[j]){
               aux=x[j];
               x[j]=x[i];
               x[i]=aux;
            }
            j=j+1;
         }
         i=i+1;
      }
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}

void insertarxPos(int x[], int *dx, int posi, int dato)
{
   int i, n;
   n = *dx;
   n = n + 1;//
   i = *dx;
   if(n<MAX){
      if(posi-1>-1 && posi-1<*dx){
         *dx=n;
         while(i>posi-1){
            x[i] = x[i-1];
            i = i-1;
         }
         x[posi-1]=dato;
         printf("\nDato %d  INSERTADO en posicion %d \n\n ", dato, posi);
         mostrarVector(x, *dx);
      }
      else{
         printf("La posicion %d no existe en el vector...\n", posi);
      }
   }
   else{
      printf("Dimension fuera de rango ...\n");
      system("pause");
   }
}
//Implementacion de la tarea y el reto
void eliminarxPos(int x[], int *dx, int posi)
{

}

void insertarxValor(int x[], int *dx, int dato)
{

}

int buscarDato(int x[], int dx, int dato)
{

}
