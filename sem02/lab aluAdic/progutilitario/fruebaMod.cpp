/**
*  NombreProg : pruebaMod.cpp
*  Descripcion: Programa pruena los valores de MOD (%) resto.
*
*     Analice cada una de las instrucciones, que hace y como
*     puede reutilizarlo.
*
*  Autor:        GASA
*  Fecha:        Agosto 2007
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


using namespace std;

void operaMod();

int main()
{

	operaMod();
   system("PAUSE");
   return 0;
}

void operaMod()
{
   int i, n, v;
   printf(" MOD y resultados: 9999 MOD v  si  v = 1, 10 100, 1000\n\n");
   printf("Cuantos ---> ");
   scanf("%d", &n);
   for(i=1;i<=n;i++){
      printf("Ingrese el divisor ---> ");
      scanf("%d", &v);
      printf("9999 MOD %d = %d\n",v, 9999%v );
   }
   printf("\n\n");
	
}
