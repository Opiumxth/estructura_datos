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

int main()
{
   int v;
   FILE *f;
   f=fopen("f1.txt","rt");

   if(f==NULL){
      printf("No pudo abrir el file...\n");
      system("pause");
      exit(0);
   }
   fread(&v,sizeof(v),1,f);
   while(feof(f)){
      printf("%d ", v);
      fread(&v,sizeof(v),1,f);
   }

   system("pause");
   return(0);
}

