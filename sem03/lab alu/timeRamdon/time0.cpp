/*
 * nomPrograma: time0.cpp
 * descripcion: Fecha y hora del sistema.
 *
 *       Analice y aplique a la solucion de problemas.
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
   time_t tiempo = time(0);
   struct tm *tlocal = localtime(&tiempo);
   char output[128];
   strftime(output,128,"Lima, %d/%m/%y Hora: %H:%M:%S",tlocal);
   printf("%s\n",output);

   system("pause");
   return(0);
}

