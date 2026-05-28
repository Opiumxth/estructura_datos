/*
 * nomPrograma: abinario.cpp
 * descripcion: operaci0nes basicas de arbol binario.
 *                  TAREA
 * 0. Analice el codigo, luego compile, ejecute y analice la salida.
 * 1. Analice los recorridos recursivos preorden, inorden y posorden.
 * 2. Implemente el recorrido anterior en la version iterativa.
 * 3. Analice la creacion del arbol binario siguiente:
 *
 *                              ARBOL BINARIO
 *                                    A
 *                                   / \
 *                                  /   \
 *                                 /     \
 *                                B       C
 *                                      /   \
 *                                     D     E
 *                                    / \   /  \
 *                                   F   G I    J
 * RECORRIDOS:
 * PreOrden: A B C D F G E I J
 * InOrden : B A F D G C I E J
 * PosOrden: B F G D I J E C A
 *
 * 4. Crear un arbol binario similar al anterior pero balanceado,
 *    muestre los recorridos. ¿Como implementaria los datos de prueba?
 * 5. Implemente el recorrido por niveles.
 * 6. Implemente el arbol binario en Java OO o sea clases Nodo,
 *    ArbolBinario con constructores, setters, getters, metodos con las
 *    operaciones basicas adecuadas de cada clase y TArbolBinario donde
 *    testee referenciando cada uno de los metodos adecuadamente.
 *
 *
 * autor:
 * fecha:
 * version 1.
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>
//#include <windows.h>

using namespace std;

typedef char TD;

struct NODO{
    TD info;
    NODO *izq;  // Izquierda
    NODO *der;  // Derecha
};

void insertarIzq(NODO*, TD dato);
void insertarDer(NODO*, TD dato);
void inOrden(NODO*);
void preOrden(NODO*);
void posOrden(NODO*);
void gotoxy(int x, int y);
void mostrarArbol(NODO*,int espacio);
void datosDePrueba(NODO **raiz);

int main()
{
    NODO *a1, *a2, *a3;

    datosDePrueba(&a1);

    printf("\n\nRecorrido PreOrden\n");
    preOrden(a1);
    printf("\n\nRecorrido InOrden\n");
    inOrden(a1);
    printf("\n\nRecorrido PosOrden\n");
    posOrden(a1);
    printf("\n\n");

    mostrarArbol(a1,0);
    printf("\n\n");

    //system("pause");
    return(0);
}

void datosDePrueba(NODO **raiz)
{
	NODO *a, *aux;
	a=new NODO;

	a->info='A';
	a->izq=NULL;
	a->der=NULL;

	insertarIzq(a,'B');
	insertarDer(a,'C');

	aux=a->der;
	insertarIzq(aux,'D');
	insertarDer(aux,'E');

	aux=a->der->izq;
	insertarIzq(aux,'F');
	insertarDer(aux,'G');

	aux=a->der->der;
	insertarIzq(aux,'I');
	insertarDer(aux,'J');

    *raiz=a;
}

void insertarIzq(NODO *p, TD dato)
{
	NODO *neo;
	neo=new NODO;
	neo->info=dato;
	neo->izq=NULL;
	neo->der=NULL;

	p->izq=neo;
}
void insertarDer(NODO *p, TD dato)
{
	NODO *neo;
	neo=new NODO;
	neo->info=dato;
	neo->izq=NULL;
	neo->der=NULL;

	p->der=neo;
}
void inOrden(NODO *raiz)
{
	if(raiz!=NULL){
		inOrden(raiz->izq);
		printf("%3c", raiz->info);
		inOrden(raiz->der);
	}
}
void preOrden(NODO *raiz)
{
	if(raiz!=NULL){
		printf("%3c", raiz->info);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}
void posOrden(NODO *raiz)
{
	if(raiz!=NULL){
		posOrden(raiz->izq);
		posOrden(raiz->der);
		printf("%3c", raiz->info);
	}
}

void mostrarArbol(NODO *raiz, int espacio)
{
    int i;
    if (raiz == NULL) {
        return;
    }
    espacio = espacio + 7;
    //espacio = espacio + 5;
    mostrarArbol(raiz->der, espacio);
    printf("\n");
    for (i = 10; i < espacio; i++) {
        printf(" ");
    }
    printf("%c\n", raiz->info);
    //printf("%d\n", raiz->info);
    mostrarArbol(raiz->izq, espacio);
}
