/*
 * nomPrograma:arrayUni.cpp
 * descripcion: Operaciones basicas de vector
 *					TAREA
 *	1. Analice, compile y ejecute
 *	2. Disene e implemente las operaciones buscar, ordenar,editar
 *		insertar por posicion, por valor, eliminar por posicion y por valor
 *	3. Implemente un progrma dado un valor entero diga si es el
 *		cuadrado de un numero o sino decir si el numero menor o mayor
 *		mas cercano al cuadrado de ese numero.
 *
 * autor:  GASA
 * fecha:
 *
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
void permuta(int x[], int dx, int ini);
void intercambia(int *p, int *q);


int main ()
{
   int a[MAX];
	int na,nd;
	//crearVector(d,&nd);
   int d[]={3,9,7, 10, 4, 78};
   nd=sizeof(d)/sizeof(int);

   //crearVector(d,&nd);
   //leerVector(a,&na);
   mostrarVector(d, nd);
   //mostrarVector(d, nd);
   //permuta(d, nd, 0);

   system("pause");
   return(0);
}
void crearVector(int x[], int *dx)
{
	*dx=-1;
}
void leerVector(int x[], int *dx)
{
	int i,n,val;
	scanf("%d", &n);
	if(n<MAX){
		for(i=0;i<n;){
			scanf("%d", &val);
			x[i]=val;
			i=i+1;
		}
		*dx=i;
	}
	else{
		printf("Dimension fuera de rango...!\n");
	}
}

void mostrarVector(int x[], int dx)
{
   int i, val;
   if(dx>0){
   	printf("vector = {");
      for(i=0;i<dx;){
         val=x[i];
         printf("%4d", val);
         i=i+1;
      }
      printf(" }\n\n");
   }
   else{
      printf("vector vaciooo...\n\n");
   }
}

void permuta(int x[], int dx, int ini)
{
   int i;
   if(dx>0){
	   if(ini==dx-1){
	      mostrarVector(x, dx);
	   }
	   else{
	      for(i=ini;i<dx;){
	         intercambia(&x[ini], &x[i]);
	         permuta(x, dx, ini+1);
	         intercambia(&x[ini], &x[i]);
	         i=i+1;
	      }
	   }
   }
	else{
      printf("vector vaciooo...\n\n");
   }
}
void intercambia(int *p, int *q)
{
   int aux;
   aux=*p;
   *p=*q;
   *q=aux;
}
