/*
 * nombreProg :
 * descripcion:
 *
 *
 * autor:
 * fecha:
 *
 */


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void operaSegundos();

int main()
{
   operaSegundos();

   system("pause");
   return(0);
}

void operaSegundos()
{
   //Numero de segundos por minuto, hora, dia y semanas
   int min=60;
   int hor=60*min;
   int dia=24*hor;
   int sem=7*dia;
   int nseg=694863;
   //scanf("%d", &nseg);
   printf("Numero semanas : %d\n", nseg/sem);
   printf("Numero dias    : %d\n", (nseg%sem)/dia);
   printf("Numero horas   : %d\n", ((nseg%sem)%dia)/hor);
   printf("Numero segundos: %d\n", (((nseg%sem)%dia)%hor)%min);
	
}
