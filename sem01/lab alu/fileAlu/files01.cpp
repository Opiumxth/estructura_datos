/*
 * nomPrograma: file01.cpp
 * descripcion: Operaciones basicas de files
 *
 *						OPERACIONES DE FILES
 *	0. Analice el el codigo, luego compile, ejecute
 *	   analice los resultados
 *	1. La operacion addFile() anade un registro cada vez
 *	   que se referencia o se llame.
 *	2. mostrarFile() recorre el file para mostrar cada
 *	   uno de los elementos. Debe formatear la salida de
 *	   los campos de registro.
 *	3. buscarPorCodigo() buscar un registro por codigo y muestra el registro,
 *	   mostrando un mensaje apropiado si esta o no esta.
 *	4. La eliminacion de un registro requiere utilizar un file temporal
 *     donde se copian todos los registros diferentes al que se desea elimianar.
 *	   Luego se elimina el file original y se renombra el file temporal.
 *	   Esta operacion (eliminacion fisica) de files es muy costosa, es mejor
 *     la eliminar logica.
 *	5. La operacion editar un registro, es modificar algunos de sus campos y
 *     es similar a la operacion eliminar.
 *	   Editar requiere utilizar una variable auxiliar de registro donde se hara
 *     la edicion de los campor que el usuario desea y cuando este seguro y
 *     conforme de los cambios, ejecutara la operacion salvar.
 *
 *									RUTINA DE EDICION
 *								0. SALIR
 *								1. Codigo	:	100
 *								2. Nombre	:	eva
 *								3. Codigo	:	14.5
 *
 *								Digite su opcion --->
 *
 *			Cuendo decida SALIR o terminado la edicion;
 *
 *								Desea salvar el registro S/N --->
 *
 *			Cuando confirme se salvara y se hara toda rutina,
 *			de lo contrario no se hara nada.

 *		6. Modular los encabezados para la salida de los registros
 *			del archivo
 *
 *							TAREA
 *			1. Analice la guia practica de files e implelente
 *				todas las operaciones restantesen un menu de opciones.
 *			2. Re escriba el ejercicion anterior pasado parametros de
 *				tipo FILE
 *
 * autor: GASA
 * fecha:
 * version 1
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
#include <string.h>
#define STR30 30

using namespace std;

//Prototipos de funcion
struct ALUMNO{
	int cod;
	char nombre[STR30];
	float nota;
};

void addFile();
void mostrarFile();
void buscarPorCodigo(int vcod);
void eliminarPorCodigo(int vcod);

//modulos auxiliares
ALUMNO leerAlumno();
void escribirAlumno(ALUMNO x);
void encabezado0();
void encabezado1();
void raya1();
void raya2();


int main()
{

	mostrarFile();
	//buscarPorCodigo(103);

   system("pause");
   return(0);
}

//Implementacion de los prototipos de funcion

void addFile()
{
	system("cls");
	ALUMNO alu;
	FILE *f;
   //Abre el archivo F para añadir
	f = fopen("alumnos.dat","a+");
   //Consistencia de exito de apertura del archivo
   if (f==NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }
   else{
		alu=leerAlumno();
		//fwrite(dato, tamanoBytes, numRegistros,varFile)
		fwrite(&alu, sizeof(alu), 1, f);
		//avisando usuario
		printf("Alumno salvado...\n\n");

		//cerramos f
		fclose(f);
   }
}

void mostrarFile()
{
	system("cls");
	int i=1;
	ALUMNO alu;
	FILE *f;
   //Abre el archivo F para lectura
	f = fopen("alumnos.dat","r");
   if (f==NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }
   else{
		encabezado1();
		fread(&alu, sizeof(alu),1,f);
		while(!feof(f)){
			printf("%4d",i);
			escribirAlumno(alu);
			fread(&alu, sizeof(alu),1,f);
			i=i+1;
		}
		raya1();
		fclose(f);
   }
}
void buscarPorCodigo(int vcod)
{
	system("cls");
	bool sw=false;
	ALUMNO alu;
	FILE *f;
   //Abre el archivo F para lectura
	f = fopen("alumnos.dat","r");
   if (f==NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }
   else{
		fread(&alu, sizeof(alu),1,f);
		while(!feof(f)&& !sw){
			if(vcod==alu.cod){
				escribirAlumno(alu);
				sw=true;
			}
			fread(&alu, sizeof(alu),1,f);
		}
		if(!sw){
			printf("%d, No hallado...\n",vcod);
		}
		fclose(f);
   }
}
void eliminarPorCodigo(int vcod)
{
	system("cls");
	bool sw=false;
	ALUMNO alu;
	FILE *f,*g;
	g = fopen("temporal.dat","w");//Abre para escritura
   if (g==NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }

	f = fopen("alumnos.dat","r");
   //Consistencia de exito de apertura del archivo
   if (f==NULL){
      printf("No se puede abrir el archivo\n");
      exit(1);
   }
   else{
		fread(&alu, sizeof(alu),1,f);
		while(!feof(f)){
			if(vcod!=alu.cod){
				fwrite(&alu, sizeof(alu),1,g);
				sw=true;
			}
			if(vcod==alu.cod){
				sw=true;
			}
			fread(&alu, sizeof(alu),1,f);
		}
		if(!sw){
			printf("%d, No hallado...\n",vcod);
		}
		else{
			remove("alumnos.dat");
			rename("temporaldat", "alumnos.dat");
			printf("%d, eliminado...\n",vcod);
		}
		fclose(f);
   }
}

//Implementacion de modulos auxiliares
ALUMNO leerAlumno()
{
    ALUMNO a;
    printf("\n\tCAPTURA DE ALUMNOS\n\n");
    // captura de campos de datos
    printf("Codigo ---> ");
    scanf("%d",&a.cod);
    fflush(stdin);
    printf("Nombre ---> ");
    cin.getline(a.nombre, STR30);
    printf("Nota -----> ");
    scanf("%f",&a.nota);
    fflush(stdin);
    return(a);
}
void escribirAlumno(ALUMNO x)
{
	printf("%6d %-12s %10.1f\n",x.cod,x.nombre,x.nota);
}

void encabezado0()
{
	char no[]="No";
	char cod[]="CODIGO";
	char nom[]="NOMBRE";
	char nota[]="NOTA";
	raya2();
	printf("%4s %5s %-17s %-10s\n",no,cod,nom,nota);
	raya1();
}
void encabezado1()
{
	printf("\n\tRELACION DE ALUMNOS\n\n");
	encabezado0();
}
void raya1()
{
	int i,n=35;
	for(i=0;i<n;){
		printf("-");
		i=i+1;
	}
	printf("\n");
}
void raya2()
{
	int i,n=35;
	for(i=0;i<n;){
		printf("=");
		i=i+1;
	}
	printf("\n");
}
