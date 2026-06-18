/**
 * nomPrograma: openFileExcel-v1.cpp
 * descripcion: Abre un archivo de texto separados por comas,
 *              lo copia a vector de registros y lo muestra
 *             TAREA
 * 1. Analice, compile y ejecute luego analice los resultados.
 * 2. Comente en forma breve y adecuadamente.
 * 3. Que ensenanzas rescata de esta aplicacion.
 * 4. Suponga un archivo de 300 mil lineas, modique el mostrarVector,
 *    para que muestre por paginas y permita salir usuario cuando desea.
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

struct CodIndex{
	int icod;
	long dirlog;
};
struct ALUMNO{
	int icod;
	str20	snom;
	float fnota;
};

void crearVector(ALUMNO x[], int *dx);
void adicionaDatoVector(ALUMNO x[], int *dx, ALUMNO dato);
void mostrarVectorRegistros(ALUMNO x[], int dx);
void recuperar(FILE *fx, ALUMNO x[], int *dx);

void adicionaDatoFile(ALUMNO ax);
void mostrarFileAlu();

void adicionaDatoFileIndex();
void mostrarFileIndex();


void encabezado1();
void encabezado2();
void raya1();
void raya2();


int main()
{
   int nalu;
   ALUMNO a, alu[MAXVECTOR];

   FILE *fa;
   fa=fopen("pruebaCsv.csv", "rt");
	if(fa==NULL){
		cout<<"No se pudo abrir el Archivo de Entrada.\n";
	}
   else{
		cout<<"El archivo se abrio correctamente.\n";
   }

   crearVector(alu,&nalu);
   //mostrarVectorRegistros(alu, nalu);

   recuperar(fa, alu, &nalu);
   //mostrarVectorRegistros(alu, nalu);

    //adicionaDatoFile(a);
    //mostrarFileAlu();

    adicionaDatoFileIndex();
    mostrarFileIndex();


   fclose(fa);
	printf("\n");
   system("pause");
   return 0;
}

void recuperar(FILE *fa, ALUMNO x[], int *dx)
{
	ALUMNO a;
	char 	*token;
	strLin linea;

	//system("cls");

	fgets(linea,MAXLINEA,fa);
	while (!feof(fa)){
		token = strtok(linea,";");
        a.icod=atoi(token);

		token = strtok(NULL,";");
		strcpy(a.snom,token);

		token = strtok(NULL,";");
		a.fnota =atof(token);

		adicionaDatoVector(x, *&dx, a);
		adicionaDatoFile(a),

		fgets(linea,MAXLINEA,fa);
	}

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

 void adicionaDatoFile(ALUMNO ax)
 {
     FILE *f;
     f= fopen("alufile.dat", "a");
     if(f == NULL){
         printf("No se pudo ver el file...\n");
         exit(0);
     }
     fwrite(&ax, sizeof(ax),1,f);
     fclose(f);
 }


void mostrarVectorRegistros(ALUMNO x[], int dx)
{
   int i;
   if(dx>0){
      system("cls");
      encabezado1();
      encabezado2();
      for(i=0;i<dx;){
         printf("%3d%5d\t%-15s%10.1f\n",i+1, x[i].icod,x[i].snom,x[i].fnota);
         i=i+1;
      }
      raya1();
   }
   else{
      printf("Vector vaciooo...!\n");
   }
}

void mostrarFileAlu()
{
     int i=1;
     ALUMNO a;
     FILE *f;
     f= fopen("alufile.dat", "r");
     if(f == NULL){
         printf("No se pudo ver el file...\n");
         exit(0);
     }
     fread(&a, sizeof(a),1,f);
     while(!feof(f)){
         printf("%3d %5d\t%-15s%10.1f\n",i, a.icod,a.snom,a.fnota);
         fread(&a, sizeof(a),1,f);
         i = i+1;
     }
     fclose(f);
}

void adicionaDatoFileIndex()
{
     long  dl=0;
     CodIndex ai;

     ALUMNO a;
     FILE *f, *g;
     f= fopen("alufile.dat", "r");
     if(f == NULL){
         printf("No se pudo ver el file...\n");
         exit(0);
     }
     g= fopen("aluIndex.dat", "a");
     if(g == NULL){
         printf("No se pudo ver el file...\n");
         exit(0);
     }
     fread(&a, sizeof(a),1,f);
     while(!feof(f)){
         ai.icod = a.icod;
         ai.dirlog = dl;
         fwrite(&ai, sizeof(ai),1,g);
         fread(&a, sizeof(a),1,f);
         dl = dl+1;
     }
     fclose(f);
}

void mostrarFileIndex()
{
     int i=1;
     CodIndex ci;
     FILE *f;
     f= fopen("aluindex.dat", "r");
     if(f == NULL){
         printf("No se pudo ver el file...\n");
         exit(0);
     }
     fread(&ci, sizeof(ci),1,f);
     while(!feof(f)){
         printf("%8d %10d\n",ci.icod,ci.dirlog);
         fread(&ci, sizeof(ci),1,f);
         i = i+1;
     }
     fclose(f);
}

void encabezado1()
{
   char t10[]="RELACION DE ALUMNOS";
   char t11[]="Ordenado por codigo";
   printf("\t%-25s\n", t10);
   printf("\t%-25s\n", t11);
}
void encabezado2()
{
   char t20[]="No";
   char t21[]="CODIGO";
   char t22[]="NOMBRE";
   char t23[]="CALIFICACION";
   raya2();
   printf("%4s %-7s %-15s %15s\n",t20,t21,t22,t23);
   raya1();
}
void raya1()
{
   int ancho=45;
   char r10[]="-----------------------------------------------------------";
   printf("%.*s\n",ancho, r10);
}

void raya2()
{
   int ancho=45;
   char r20[]="===========================================================";
   printf("%.*s\n",ancho, r20);
}
