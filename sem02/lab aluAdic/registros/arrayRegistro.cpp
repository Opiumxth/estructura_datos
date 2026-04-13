/*
 * NombreProg : registroOperac.cpp
 * Descripcion: Operaciones basicas de  vector de registros
 *             TAREA
 *    0. Analice, compile y aplique
 *    1. Implemente las operaciones:,
 *       1.1 buscar, eliminar,ordenar (por codigo, por nombrem y por nota)
 *       1.2 Editar. debe crear un menu de la siguiente manera"
 *                         EDICION DE ALUMNO
 *
 *                      0. SALIR
 *                      1. Codigo   :  102
 *                      2. Nombre   :  eva
 *                      3. Nota     :  15.0
 *                      Digite su opcion --->
 *
 *       Suponiendo que ha optado por 2:
 *                      Ingrese el nuevo nomnbre: evita ENTER
 *       Ahora debe el menu actualizado:
 *                         EDICION DE ALUMNO
 *
 *                      0. SALIR
 *                      1. Codigo   :  102
 *                      2. Nombre   :  evita
 *                      3. Nota     :  15.0
 *                      Digite su opcion --->
 *       y asi hasta que se haya optado por SALIR,
 *
 *    2. Analice el codigo comentado  cual es la finalidad?
 *    3. Implemente  todas las operaciones basicas
 *
 * Autor:  GASA
 * Fecha:
 *
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

using namespace std;

const int MAX=10;
struct ALUMNO{
   int cod;
   char nom[40];
   float nota;
};

int Menu();
void crearVector(ALUMNO x[MAX], int *dx);
void leerVector(ALUMNO x[MAX], int *dx);
void mostrarVector(ALUMNO x[MAX], int dx);
void adicionaDato(ALUMNO x[MAX], int *dx, ALUMNO dato);

//void EliminarxVal(int x[Max], int Dim);
void encabezado1();
void encabezado2();
void raya2();
void raya1();

int main()
{
   int na, deno, nb;
   ALUMNO b[MAX];

   ALUMNO a[]={
      100,"Jorge",12,
      102,"EVANS-VECO, Eva",18,
      104,"ZELA-GATTI, Luis",5,
      108,"AREVALO-TORO, Alina",16,
      109,"BERNAOLA-CRUZSACO, Karenina",17,
   };

   na=(sizeof(a))/(sizeof(int)+40*sizeof(char)+sizeof(float));
   //printf("na= %d\n", na);
   printf("\nHola\n");

   mostrarVector(a, na);
   //ALUMNO b={140,"GONZALES AVA, Felix",12};
/*
   b.cod=112;
   strcpy(b.nom,"GONZALES AVA, Felix");
   b.nota=14.0;
   //printf("%d,%s,%f\n",b.cod,b.nom,b.nota);
   adicionaDato(a,&na,b);
   mostrarVector(a, na);

   crearVector(b, &nb);
   leerVector(b, &nb);
	mostrarVector(b, nb);
*/
   system("pause");
   return(0);
}

void crearVector(ALUMNO x[MAX], int *dx)
{
   *dx=-1;
}

void leerVector(ALUMNO x[MAX], int *dx)
{
   int i, n, val;

   printf("Numero de ALUMNOS ---> ");
   scanf("%d", &n);
   if(n < MAX){
      for(i=0;i<n;i++){
         system("cls");
         printf("\n\n\tRUTINA CAPTURA DE ALUMNOS\n\n ");
         printf("\tAlumno:  %d\n", i+1);;
         cout <<" Codigo ---> ";
         cin >>x[i].cod;
         cout <<" Nombre ---> ";
         cin >>x[i].nom;
         cout <<" Nota   ---> ";
         cin >>x[i].nota;
      }
      *dx = i;
   }
   else{
      printf(" %d dimension fuera de RANGO es mayor a Max = %d\n\n", n, MAX);
      system("pause");
      exit(1);
   }
}

void adicionaDato(ALUMNO x[MAX], int *dx, ALUMNO dato)
{
   int n;
   if(*dx<0){
      x[0]=dato;
      *dx=1;
      //printf("*x= %d\n");
   }
   else{
      n=*dx;
      n=n+1;
      if(n<MAX){
         //x[*dx]=dato;

         x[n-1].cod=dato.cod;
         strcpy(x[n-1].nom,dato.nom);
         x[n-1].nota=dato.nota;

         *dx=n;
      }
      else{
         printf("Vector llenooo...\n\n");
      }
   }
}
void mostrarVector(ALUMNO x[MAX], int dx)
{
   int i;
   system("cls");
   if(dx>0){
      encabezado2();
      for(i=0;i<dx;i++){
         printf("%3d\t%5d\t%-30s%10.1f\n",i+1,x[i].cod,x[i].nom,x[i].nota);
      }
      raya1();
      cout <<"\n\n";
      system("pause");
   }
   else{
      printf("Vector vaciooo...\n\n");
   }
}
void encabezado1()
{
   //system("cls");
   printf("\t\tREPORTE DE ALUMNOS\n\n");
   raya2();
   printf(" Numero\t CODIGO\tN o m b r e \t\t\tNOTA");
   raya1();
}
void encabezado2()
{
   //system("cls");
   char title[]="REPORTE DE ALUMNOS";
   char num[]="NUMERO";
   char cod[]="CODIGO";
   char nom[]="APELLIDOS, Nombres";
   char nota[]="NOTA";

   printf("\t\t%s\n\n",title);
   raya2();
   printf("%-6s\t%-12s%-32s%-5s\n",num,cod,nom,nota);
   raya1();
}
void raya2()
{
   printf("=========================================================\n");
}
void raya1()
{
   printf("---------------------------------------------------------\n");
}

