/**
 * nomPrograma: openFileExcel-v0.cpp
 * descripcion: Abre un archivo de texto separados por comas,
 *              lo copia a vector de registros y lo muestra
 *             TAREA
 * 1. Analice, compile y ejecute luego analice los resultados.
 * 2. Comente en forma breve y adecuadamente.
 * 3. Que ensenanzas rescata de esta aplicacion.
 * 4. Puede mostrar la informacion sin necesidad de utilizar
 *    el vector de registros. Implemente y porque no se podria.
 *
 * autor: GASA
 * fecha: 23032020
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define 	MAXLINEA 	255
#define 	MAXCAMPO	   41
#define 	MAXVECTOR 	20

using namespace std;

typedef char 	str20[MAXCAMPO];
typedef char 	strLin[MAXLINEA];

struct ALUMNO{
	int icod;
	str20	snom;
	float fnota;
};

void crearVector(ALUMNO x[], int *dx);
void adicionaDatoVector(ALUMNO x[], int *dx, ALUMNO dato);
void mostrarVectorRegistros(ALUMNO x[], int dx);
void recuperar(ALUMNO x[], int *dx);

int main()
{
   int nalu;
   ALUMNO alu[MAXVECTOR];

   crearVector(alu,&nalu);
   mostrarVectorRegistros(alu, nalu);

   recuperar(alu, &nalu);
   mostrarVectorRegistros(alu, nalu);

	printf("\n");
   system("pause");
   return 0;
}

void recuperar(ALUMNO x[], int *dx)
{
	ALUMNO a;
	char 	*token;
	strLin linea;
	FILE *f;
	//system("cls");
	f=fopen("pruebaCsv.csv", "rt");
	if(f==NULL){
		cout<<"No se pudo abrir el Archivo de Entrada.\n";
	}
   else{
		cout<<"El archivo se abrio correctamente.\n";
   }

	fgets(linea,MAXLINEA,f);
	while (!feof(f)){
		token = strtok(linea,";");
      a.icod=atoi(token);

		token = strtok(NULL,";");
		strcpy(a.snom,token);

		token = strtok(NULL,";");
		a.fnota =atof(token);

		adicionaDatoVector(x, *&dx, a);

		fgets(linea,MAXLINEA,f);
	}
	fclose(f);
}

void crearVector(ALUMNO x[], int *dx)
{
   *dx=-1;
}

void adicionaDatoVector(ALUMNO x[], int *dx, ALUMNO dato)
{
   int n;
   if(*dx<0){
      x[0]=dato;
      *dx=1;
   }
   else{
      n=*dx;
      n=n+1;
      if(n<MAXVECTOR){
         x[*dx]=dato;
         *dx=n;
      }
      else{
         printf("Vector lleno...!\n");
      }
   }
}

void mostrarVectorRegistros(ALUMNO x[], int dx)
{
   int i;
   if(dx>0){
      for(i=0;i<dx;){
         printf("%d\t%-15s%10.1f\n", x[i].icod,x[i].snom,x[i].fnota);
         i=i+1;
      }
   }
   else{
      printf("Vector vaciooo...!\n");
   }
}

