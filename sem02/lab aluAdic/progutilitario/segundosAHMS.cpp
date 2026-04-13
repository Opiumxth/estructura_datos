/*
 * nomPrograma:
 * descripcion:
 *
 *
 * Author:
 * fecha:
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
   int qs,ns,nm,nh;
   scanf("%d",&qs);
   nh=qs/3600;
   nm=(qs%3600)/60;
   ns=(qs%3600)%60;
   printf("%10d : horas\n", nh);
   printf("%10d : minutos\n", nm);
   printf("%10d : segundos\n", ns);
	
}
