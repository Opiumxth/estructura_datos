/*
 * nomPrograma:arrayBidim.cpp
 * descripcion: Operaciones basicas de arrglo cubico
 *					TAREA
 *	1. Analice, compile y ejecute
 *	2. Disene e implemente las operaciones buscar, ordenar,editar
 *		insertar por posicion, por valor, eliminar por posicion y por valor
 *
 *
 * autor:  GASA
 * fecha:
 *
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXI 10
#define MAXJ 10
#define MAXK 10

using namespace std;

void crearMatrizCubo(int x[][MAXJ][MAXK], int *dxi, int *dxj, int *dxk);
void leerMatrizCubo(int x[][MAXJ][MAXK], int *dxi, int *dxj, int *dxk);
void mostrarMatrizCubo(int x[][MAXJ][MAXK], int dxi, int dxj, int dxk);

int main ()
{
   int a[MAXI][MAXJ][MAXK];
	int nai,naj,nak;
   crearMatrizCubo(a,&nai,&naj,&nak);
   leerMatrizCubo(a,&nai,&naj,&nak);
   mostrarMatrizCubo(a,nai,naj,nak);

   system("pause");
   return(0);
}
void crearMatrizCubo(int x[][MAXJ][MAXK], int *dxi, int *dxj, int *dxk)
{
	*dxi=-1;
	*dxj=-1;
	*dxk=-1;
}

void leerMatrizCubo(int x[][MAXJ][MAXK], int *dxi, int *dxj, int *dxk)
{
	int i,j,k,ni,nj,nk,val;
	scanf("%d", &ni);
	scanf("%d", &nj);
	scanf("%d", &nk);
	if(ni<MAXI && nj<MAXJ && nk<MAXK){
		for(i=0;i<ni;){
			for(j=0;j<nj;){
				for(k=0;k<nk;){
					scanf("%d", &val);
					x[i][j][k]=val;
					k=k+1; 
				}
				j=j+1;
			}
			i=i+1;
		}
		*dxi=i;
		*dxj=j;
		*dxk=k;
	}
	else{
		printf("Dimension fuera de rango...!\n");
	}	
}

void mostrarMatrizCubo(int x[][MAXJ][MAXK], int dxi, int dxj, int dxk)
{
   int i,j,k,val;
   if(dxi>0 && dxj>0 && dxk>0){
   	printf("Matriz = {\n");
      for(i=0;i<dxi;){
	      for(j=0;j<dxj;){
		      for(k=0;k<dxk;){
	         	val=x[i][j][k];
	         	printf("%4d", val);
	         	k=k+1;
	      	}
	      	j=j+1;
      		printf("\n");
      	}
			i=i+1;
			printf("\n");
      }
      printf("}\n");
   }
   else{
      printf("Matriz vaciaaaa...\n\n");
   }
}

