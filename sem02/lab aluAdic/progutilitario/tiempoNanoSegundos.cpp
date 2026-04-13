/*
 * nomPrograma: tiempoNanoSegundos.cpp
 * descripcion: Detrermina tiempo de ejecucion
 *
 *    También podemos usar clock_gettime() función definida en <time.h>
 *    archivo de encabezado que admite una precisión de nanosegundos.
 *    Toma dos argumentos: el primer argumento es el tipo de reloj y el
 *    segundo argumento es un puntero al timespec estructura. los timespec
 *    La estructura es proporcionada por el <time.h> encabezado y se declara como:
 *
 *          struct timespec {
 *             time_t tv_sec;   // seconds
 *             long tv_nsec;    // nanoseconds
 *          };
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
#include <unistd.h> 	   // sleep()
#define BILLION  1000000000.0


using namespace std;
/*
struct timespec {
    time_t tv_sec;   // seconds
    long tv_nsec;    // nanoseconds
};
*/


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
