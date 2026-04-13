/**
*  NombreProg :  formatoCpp.cpp
*  Descripcion:  Programa muestra los diferentes tipos de formato de salida
*
*     Analice cada una de las instrucciones, que hace y como
*     puede reutilizarlo.
*
*  Autor:        GASA
*  Fecha:        Agosto 2007
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>


using namespace std;

void operaFormato();

int main()
{
	operaFormato();
   system("PAUSE");
   return (0);
}

void operaFormato()
{
	
	//Suitable for a check protected monetary field
	printf("Proteccion de cantidades monetarias\n\n");
	const float dollars = 1234.45;
	cout << '$';
	cout.fill('*'); cout.width(10); cout.precision(2);
	cout.setf(ios::fixed | ios:: showpoint);
	cout << dollars <<endl;

	//Alignments
	printf("Alineamiento\n\n");
	cout.width(10); cout.setf(ios::left,ios::adjustfield);
		cout << "test" <<endl;
	cout.width(10); cout.setf(ios::right,ios::adjustfield);
		 cout << "test" <<endl;
	cout.width(10); cout.setf(ios::internal,ios::adjustfield);
		 cout << "test" <<endl;
	cout.width(10); cout.setf(ios::left,ios::adjustfield);
		 cout << 1234 <<endl;
	cout.width(10); cout.setf(ios::right,ios::adjustfield);
		 cout << 1234 <<endl;
	cout.width(10); cout.setf(ios::internal,ios::adjustfield);
		 cout << 1234 <<endl;

	//Bases
	printf("Bases de numeracion\n\n");
	cout.fill(' ');
	cout.setf(ios::hex,ios::basefield);
                 cout << 1234 <<endl;
	cout.setf(ios::hex,ios::basefield); cout.setf(ios::uppercase);
                 cout << 1234 <<endl;
					cout.unsetf(ios::uppercase);
	cout.setf(ios::oct,ios::basefield);
                 cout << 1234 <<endl;
	cout.setf(ios::dec,ios::basefield);
                 cout << 1234 <<endl;
	cout.setf(ios::showbase);
	cout.setf(ios::hex,ios::basefield);
                 cout << 1234 <<endl;
	cout.setf(ios::hex,ios::basefield); cout.setf(ios::uppercase);
                 cout << 1234 <<endl;
					cout.unsetf(ios::uppercase);
	cout.setf(ios::oct,ios::basefield);
                 cout << 1234 <<endl;
	cout.setf(ios::dec,ios::basefield);
                 cout << 1234 <<endl;

	//Signs
	printf("Signos\n\n");
   cout.setf(ios::dec,ios::basefield); cout.setf(ios::showpos);
   cout << 1234 <<endl;
   cout.unsetf(ios::showpos);
	
}
