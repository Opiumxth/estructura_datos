/*
   * nomPrograma:
   * descripcion:
   *
   *
   * author: FLORES HOYOS, Mathias Pavel Diego
   * fecha :
   */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR30 30

using namespace std;

//Prototipos de funcion
struct ALUMNO{
	int cod;
	char nombre[STR30];
	float nota;
};

void addFile(FILE *f);
void mostrarFile(FILE *f);
void buscarPorCodigo(FILE *f, int vcod);
void eliminarPorCodigo(FILE *f, int vcod);

//modulos auxiliares
ALUMNO leerAlumno();
void escribirAlumno(ALUMNO x);
void encabezado0();
void encabezado1();
void raya1();
void raya2();


int main()
{
	int opc, codigo;

	do{
      system("clear");
		printf("\n\tMENU\n");
		printf("\n1. Agregar");
		printf("\n2. Mostrar");
		printf("\n3. Buscar");
		printf("\n4. Eliminar");
		printf("\n0. Salir");
		printf("\nOpcion: ");
		scanf("%d",&opc);

		switch(opc){
			case 1:{
				FILE *f = fopen("alumnos.dat","ab+");
				addFile(f);
				fclose(f);
				break;
			}
			case 2:{
				FILE *f = fopen("alumnos.dat","rb");
				mostrarFile(f);
				fclose(f);
				break;
			}
			case 3:{
				printf("Codigo: ");
				scanf("%d",&codigo);
				FILE *f = fopen("alumnos.dat","rb");
				buscarPorCodigo(f,codigo);
				fclose(f);
				break;
			}
			case 4:{
				printf("Codigo: ");
				scanf("%d",&codigo);
				FILE *f = fopen("alumnos.dat","rb");
				eliminarPorCodigo(f,codigo);
				fclose(f);
				break;
        }
    }

    if(opc != 0){
        printf("\nPresione ENTER para continuar...");
        getchar(); // limpia \n de scanf
        getchar(); // espera enter
    }

}while(opc!=0);

   return(0);
}

//Implementacion de los prototipos de funcion

void addFile(FILE *f)
{
	ALUMNO alu;

   if (f==NULL){
      perror("Error fopen");
      exit(1);
   }
   else{
		alu=leerAlumno();
		fwrite(&alu, sizeof(alu), 1, f);
		printf("Alumno salvado...\n\n");
   }
}

void mostrarFile(FILE *f)
{
	int i=1;
	ALUMNO alu;

   if (f==NULL){
      perror("Error fopen");
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
   }
}

void buscarPorCodigo(FILE *f, int vcod)
{
	bool sw=false;
	ALUMNO alu;

   if (f==NULL){
      perror("Error fopen");
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
   }
}

void eliminarPorCodigo(FILE *f, int vcod)
{
	bool sw=false;
	ALUMNO alu;
	FILE *g;
	g = fopen("temporal.dat","wb");

   if (g==NULL){
      perror("Error fopen temporal");
      exit(1);
   }

   if (f==NULL){
      perror("Error fopen original");
      exit(1);
   }
   else{
		fread(&alu, sizeof(alu),1,f);
		while(!feof(f)){
			if(vcod!=alu.cod){
				fwrite(&alu, sizeof(alu),1,g);
			}
			else{
				sw=true;
			}
			fread(&alu, sizeof(alu),1,f);
		}

		fclose(f);
		fclose(g);

		if(!sw){
			printf("%d, No hallado...\n",vcod);
			remove("temporal.dat"); // limpiar basura
		}
		else{
			remove("alumnos.dat");

			if(rename("temporal.dat", "alumnos.dat") != 0){
				perror("Error en rename");
			}
			else{
				printf("%d, eliminado...\n",vcod);
			}
		}
   }
}

//Implementacion de modulos auxiliares
ALUMNO leerAlumno()
{
    ALUMNO a;
    printf("\n\tCAPTURA DE ALUMNOS\n\n");
    printf("Codigo ---> ");
    scanf("%d",&a.cod);

    printf("Nombre ---> ");
    cin.ignore();
    cin.getline(a.nombre, STR30);

    printf("Nota -----> ");
    scanf("%f",&a.nota);

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
