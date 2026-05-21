/*
* nomPrograma:
* descripcion:
*
*
*
* author:
* fecha :
* Version 1
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "nodo.h"
#include "cola.h"
#include <iomanip>
#include <exception>

using namespace std;

//prototipos de funcion
void insert(int,int,Cola<int> *);
/* vacio displayC(<Arreglo de colas a mostrar>,<tamaño de arreglo de colas>) */
void displayC(Cola<int> *,int);
/* entero deleteItem(<Arreglo de colas a vaciar>,<tamaño de arreglo de colas>) */
int deleteItem(Cola<int> *,int);

int main(void){
	/* Crea un arreglo de colas, cada posicion es una prioridad */
	/* Maxima prioridad igual a longitud de arreglo menos uno */
	Cola<int> * cola = new Cola<int>[5];
	// Prueba de la funcion de insercion
	insert(3,4,cola);
	insert(2,4,cola);
	insert(3,0,cola);
	insert(5,2,cola);
	insert(7,1,cola);
	insert(1,3,cola);
	insert(8,2,cola);
	insert(9,1,cola);
	// Muestra la cola de prioridad actual
	displayC(cola,5);
	// extrae algunos elementos de la cola
	cout << "Extrayendo elemento: "<<deleteItem(cola,5)<<endl;
	cout << "Extrayendo elemento: "<<deleteItem(cola,5)<<endl;
	cout << "Extrayendo elemento: "<<deleteItem(cola,5)<<endl;
	cout << "Extrayendo elemento: "<<deleteItem(cola,5)<<endl;

    system("pause");
    return 0;
}

void insert(int data,int priori, Cola<int> * a ){
	// Si sale fuera de los limites genera una excepcion
	try{
		// Inserta el dato en la cola almacenada en la prioridad indicada
		a[priori].push(data);
	}catch(exception& e){
		cout << "OUT OF MEMORY: ";
	}
}

void displayC(Cola<int> * a, int Maxpriori ){
	// recorre toda el arreglo de colas
	for(int i = 0; i < Maxpriori; i++ ){
		// para cada cola almacenada llama a su respectivo metodo display
		a[i].display();
		// da un salto, esto permite separar por prioridad
		// y mostrar una prioridad por lina, si se elimina el salto
		// se mostrara una sola cadena, esto es opcional
		cout << endl;
	}
}

int deleteItem(Cola<int> * a, int Maxpriori ){
	int i = 0;
	// Mientras no se llegue al final del arreglo
	while(i < Maxpriori){
		// verifica si la prioridad mas alta esta vacia
		// si esta vacia entonces avanza a la siguiente
		// prioridad mas alta
		if(a[i].isEmpty()){
			i++;
		}else{
			// cuando la prioridad tenga elementos encolados
			// saca el elemento mas proximo de la cola y lo retorna
			// por lo tanto se detiene la ejecucion de la funcion
			return a[i].pop();
		}
	}
	// en caso que no encuentra elementos retorna -1 esto puede
	// servir para controlar excepciones
	return -1;
}
