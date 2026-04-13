/**
*  NombreProg :  FormatoCC.cpp
*  Descripcion:  Programa muestra los diferentes tipos de formato de salida
*
*     Analice cada una de las instrucciones, que hace y como
*     puede reutilizarlo.
*
*  Autor:        GASA
*  Fecha:        Agosto 2007
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define PI  3.14159265


using namespace std;

void operaFormato();

int main()
{
	operaFormato();
   system("PAUSE");
   return 0;
}

void operaFormato()
{
   printf("Posiciones...\n");
   printf("|123456789012|\n\n");
   printf("|%10.5f|\n", PI);
   printf("|%-10.5f|\n", PI);
   printf("|%010.5f|\n", PI);
   printf("|%10.6f|\n", PI);
   long int A = 99999, B = 12345;
   printf("\nPosiciones...\n");
   printf("|123456789012|\n\n");
   printf("|%d|\n", B);
   printf("|%10d|\n", B);
   printf("|%010.5d|\n", B);
   printf("|%-10d|\n", B);
   printf("|%10Ld|\n", A);
   printf("\nPosiciones...\n");
   printf("|1234567890123456|\n\n");
   printf("|%s|\n", "!Hola Que Tal");
   printf("|%14s|\n", "!Hola Que Tal");
   printf("|%16.14s|\n", "!Hola Que Tal");
   printf("|%10.14s|\n", "!Hola Que Tal");
	
}
