/*
 * nomPrograma: aletorio1.cpp
 * descripcion: genera numeros seudo aleatorios.
 *
 *       Mumero seudo Aleatorios en C
 *    nsa = rand()%2;     // obtiene numeros de 0 y 10
 *    nsa = rand()%11;    // obtiene numeros de 0 a 10
 *    nsa = rand()%1500;  // obtiene numeros de 0 a 1499
 *    nsa = 10+rand(); // obtiene numeros a partir de 10
 *    nsa = 80+rand(); // obtiene numeros ...?
 *    nsa = 1+rand()%100;  // obtiene numeros 1 a 100
 *    nsa = 15+rand()%100; // obtiene numeros 15 a 114
 *    nsa = rand()%(N+1);  // obtiene numeros de 0 a N
 *    nsa = rand()%11+20;             // obtiene numeros de 20 a 30
 *    nsa = rand()%(nmax-nmin)+nmin;  // obtiene numeros de nmin y nmax
 *    nsa = nmin+rand()%(nmax+1)-nmin;// ...?
 *
 * Author:
 * fecha:
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;

int main()
{

   srand((unsigned)time(NULL));
   //srand(time(NULL));
   int i, nmax,nmin, res,res1;
   nmin=1;
   nmax=6;
   for(i=1;i<=10;i++){
      res = (rand() % (nmax - nmin)) + nmin;
      printf("%d ",res);
   }
   printf("\n\n");
   for(i=1;i<=10;i++){
      res1 = rand()%(nmax-nmin+1)+nmin;
      printf("%d ",res1);
   }
   printf("\n\n");

   system("pause");
   return(0);
}

