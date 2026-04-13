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
#include <string.h>

using namespace std;

int main()
{
    char s1[49] = "Esto es un ejemplo para usar la funcion strtok()";
    //char s2[4] = " \n\t";
    char s2[4] = "  ";
    char *ptr;

    printf( "s1=%s\n\n", s1 );

    ptr = strtok(s1, s2 ); // Primera llamada => Primer token
    //while( (ptr = strtok( NULL, s2 )) != NULL )  {
    while( ptr!= NULL )  {
        // Posteriores llamadas
        printf( "%s\n", ptr );
        ptr = strtok( NULL, s2 );
    }

   system("pause");
   return(0);
}

