/*
 * nomPrograma: time2.cpp
 * descripcion: Calculo de fecha y hora
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
   char* dS[7]= {"Domingo","Lunes","Martes","Miercoles",
      "Jueves","Viernes","Sabado"
   };
   time_t tSac = time(NULL);       // instante actual
   struct tm* tmP = localtime(&tSac);

   cout << "hh:mm:ss  : " << tmP->tm_hour << ":" << tmP->tm_min << ":"
        << tmP->tm_sec << endl;
   printf("HORA hh:mm:ss   : %d:%d:%d\n",tmP->tm_hour,tmP->tm_min,tmP->tm_sec);
   cout << "dd-mm-aaaa: " << tmP->tm_mday << "-" << tmP->tm_mon+1 << "-"
        << tmP->tm_year+1900 << endl;
   printf("FECHA dd/mm/aaaa: %d/%d/%d\n",tmP->tm_mday,tmP->tm_mon+1,tmP->tm_year+1900);
   cout << "Dia de semana: " << dS[tmP->tm_wday] << endl;
   cout << "Dia del año: " << tmP->tm_yday << endl;
   cout << "Horario de verano: " << (tmP->tm_isdst ? "Si" : "No") << endl;



   system("pause");
   return(0);
}

