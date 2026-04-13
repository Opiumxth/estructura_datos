/*
 * nomPrograma: time1.cpp
 * descripcion: Calculo fecha y hora.
 *
 *       Analice y aplique a la solucion del problemas.
 *
 * Author: https://www.zator.com/Cpp/E5_5_1a.htm
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
   time_t tSac = time(NULL);  // instante actual

   struct tm* pt1 = localtime(&tSac);
   cout << "hh:mm:ss " << pt1->tm_hour << ":" << pt1->tm_min << ":"
                       << pt1->tm_sec << endl;
   printf("hh:mm:ss %d:%d:%d\n",pt1->tm_hour,pt1->tm_min,pt1->tm_sec);
   cout << "dd-mm-aaaa: " << pt1->tm_mday << "-" << pt1->tm_mon+1 << "-"
                          << pt1->tm_year+1900 << endl;
   printf("dd:mm:aaaa: %d/%d/%d\n",pt1->tm_mday,pt1->tm_mon,pt1->tm_year+1900);

   tm tm2 = *gmtime(&tSac);   // deferencia y asignación
   cout << "hh:mm:ss " << tm2.tm_hour << ":" << tm2.tm_min << ":"
                       << tm2.tm_sec << endl;
   cout << "dd-mm-aaaa: " << tm2.tm_mday << "-" << tm2.tm_mon+1 << "-"
        << tm2.tm_year+1900 << endl;

   system("pause");
   return(0);
}

