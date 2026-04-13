/*
 * nomPrograma: tiempoMicroSegundos.cpp
 * descripcion:
 *
 *    gettimeofday() La función devuelve el tiempo de reloj de pared
 *    transcurrido desde la Época y lo almacena en el timeval
 *    estructura, expresada en segundos y microsegundos.
 *
 *    Se define en el <sys/time.h> archivo de encabezado y toma
 *    dos argumentos: el primer argumento es una referencia al timeval
 *    estructura, y el segundo argumento es un puntero nulo. los
 *    timeval estructura se declara de la siguiente manera por el
 *    <time.h> encabezamiento:
 *
 *          struct timeval {
 *             long tv_sec;    // seconds
 *             long tv_usec;   // microseconds
 *          };
 *    Vease programa.
 *
 * autor:
 * fecha:
 * version:
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <sys/time.h>   // gettimeofday()
#include <unistd.h>     // sleep()


using namespace std;

void operaTiempo();

int main()
{

   operaTiempo();

   system("pause");
   return(0);
}

void operaTiempo()
{
	struct timeval start, end;

	gettimeofday(&start, NULL);

	// do some stuff here
	sleep(5);

	gettimeofday(&end, NULL);

	long seconds = (end.tv_sec - start.tv_sec);
	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);

	printf("The elapsed time is %d seconds and %d micros\n", seconds, micros);
}
