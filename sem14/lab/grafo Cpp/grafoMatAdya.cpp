/**
 * nombreProg :grafoMatAdya
 * descripcion: Operaciones basicas de grafos
 *
 *                TAREA
 *    1. Analice, ejecute y comente cada una de los metodos y las instrucciones
 *
 *
 * autor:
 * fecha:
 *
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

using namespace std;

class GrafoMatrizAdyacencia
{
	public:
		GrafoMatrizAdyacencia(int numeroVertices);
		~GrafoMatrizAdyacencia();

		void imprimematriz();
		void conectar(int i, int j);
		void desconectar(int i, int j);
		bool esConectado(int i, int j) const;

		void setPeso(int i, int j, float valor);
		float peso(int i, int j) const;

	private:
		int numVertices;
		float *matriz;
};


GrafoMatrizAdyacencia::GrafoMatrizAdyacencia(int numeroVertices)
	: numVertices(numeroVertices), matriz(0)
{
	matriz = new float[numVertices * numVertices];

	for(int i = 0; i < numVertices; i++) {
		for(int j = 0; j < numVertices; j++) {
			matriz[i + j * numVertices] = 0.0;
		}
	}
}

GrafoMatrizAdyacencia::~GrafoMatrizAdyacencia()
{
	delete matriz;
}

void GrafoMatrizAdyacencia::imprimematriz()
{
	for(int i = 0; i < numVertices; i++) {
		for(int j = 0; j < numVertices; j++) {
			cout << matriz[i + j * numVertices] << " ";
		}
              cout << endl;
	}
}

void GrafoMatrizAdyacencia::desconectar(int i, int j)
{
	if(((i >= 0) && (i < numVertices)) && ((j >= 0) && (i < numVertices))) {
		matriz[i + j * numVertices] = 0.0;
	}
}


void GrafoMatrizAdyacencia::conectar(int i, int j)
{
	if(((i >= 0) && (i < numVertices)) && ((j >= 0) && (i < numVertices))) {
		matriz[i + j * numVertices] = 1.0;
	}
}

bool GrafoMatrizAdyacencia::esConectado(int i, int j) const
{
	if(((i >= 0) && (i < numVertices)) && ((j >= 0) && (i < numVertices))) {
		if(matriz[i + j * numVertices] > 0.0)
			return true;
	}

	return false;

}

void GrafoMatrizAdyacencia::setPeso(int i, int j, float valor)
{
	if(((i >= 0) && (i < numVertices)) && ((j >= 0) && (i < numVertices))) {
		matriz[i + j * numVertices] = valor;
	}
}

float GrafoMatrizAdyacencia::peso(int i, int j) const
{
	if(((i >= 0) && (i < numVertices)) && ((j >= 0) && (i < numVertices))) {
		return matriz[i + j * numVertices];
	}

	return 0.0;
}

int main()
{
	GrafoMatrizAdyacencia G(3);
	G.conectar(0, 2);
	G.conectar(0, 1);
	G.conectar(1, 0);
	G.conectar(2, 0);

	cout << "El 0 con el 0 : " << G.esConectado(0, 0) << endl;
	cout << "El 0 con el 1 : " << G.esConectado(0, 1) << endl;
	cout << "El 0 con el 2 : " << G.esConectado(0, 2) << endl;
	cout << "El 1 con el 2 : " << G.esConectado(1, 2) << endl;

       G.imprimematriz();

	cout << "El 0 con el 2 Peso : " << G.peso(0, 2) << endl;

	G.setPeso(0, 2, 3.14);

	cout << "El cero con el 2 Peso : " << G.peso(0, 2) << endl;

	return 0;
}

