/*
 * nomPrograma: time3.cpp
 * descripcion: tiempo de ejecucion de una aplicacion.
 *
 *       Analice y aplique a la solucion del problemas.
 *       Investigue acerca del uso de Time sobre todas
 *    en las unidades adecuadas de la contabilizacion del tiempo.
 *
 * Author:
 * fecha:
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <time.h>

using namespace std;

int main()
{
   clock_t tini, tfin;
   int i;
   double secs;

   tini=clock();
   for(i=0;i<10000;){
      printf("hola ");
      i=i+1;
   }
   printf("\n");
   tfin=clock();

   secs=(double)(tfin-tini) / CLOCKS_PER_SEC;
   printf("%.16g segundos\n", secs);
   printf("%.16g milisegundos\n", secs * 1000.0);

   system("pause");
   return(0);
}

