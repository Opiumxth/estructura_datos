/*
* nomPrograma: arbolAVLc.cpp
* descripcion: operaciones basicas
*
*               TAREA

* 0. Analice el codigo, luego compile, ejecute y analice los resultados
* 1. Analice las rotaciones simples que se realicen
* 2. Analice las rotaciones dobles derecha y las condicones para realizar las
*    simples de acuerdo al valor FE negativo o positivo  de los subnodos
* 3. Analice las rotaciones dobles izquierda y las condicones para realizar las
*    simples de acuerdo al valor FE negativo o positivo  de los subnodos
*    3.1 El FE = Altura sai - altura sad y no FE = Altura sad - altura sai
* 4. Suponga que se debe imprimir el valor del dato eliminado, que debe hacer
*    para imprimir dicho dato.
* 5. La aplicacion esta implementado con funciones, implementee la aplicacion
*    con procedimientos, todos deben ser retorno void execepto el crearNodo().
*
*
* autor:
* fecha:
* Version 1
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h> // libreria no standard
#include <string.h>

using namespace std;

typedef struct Nodo {
    int dato;
    struct Nodo *izq;
    struct Nodo *der;
    int altura;
} Nodo;

void crearArbol(Nodo **cab);
Nodo* crearNodo(int dato);

Nodo* rotarDerecha(Nodo *y);
Nodo* rotarIzquierda(Nodo *x);

Nodo* insertar(Nodo* nodo, int dato);
Nodo* eliminarNodo(Nodo* raiz, int dato);
Nodo* nodoValorMinimo(Nodo* nodo);


int max(int a, int b);
int obtenerAltura(Nodo *n);
int obtenerFE(Nodo *n);

void preOrden(Nodo *raiz);
void inOrden(Nodo *raiz);
void posOrden(Nodo *raiz);
void mostrarArbol(Nodo *raiz, int espacio);


int main()
{

    //Nodo *raiz = NULL;
    Nodo *raiz;
    crearArbol(&raiz);
    // Insertar valores que fuercen rotaciones
    int valores[] = {10, 20, 30, 40, 50, 25};
    for(int i=0; i < 6; i++) {
        raiz = insertar(raiz, valores[i]);
    }
    printf("PreOrden: ");
    preOrden(raiz);
    printf("\nInOrden : ");
    inOrden(raiz);
    printf("\nPosOrden: ");
    posOrden(raiz);

    printf("\nArbol AVL tras inserciones:\n");
    mostrarArbol(raiz, 0);

    printf("\n--- Eliminando el 30 ---\n");
    raiz = eliminarNodo(raiz, 30);
    mostrarArbol(raiz, 0);



    //system("pause");
    return 0;
}

void crearArbol(Nodo **cab)
{
    *cab = NULL;
}

Nodo* crearNodo(int dato)
{
    Nodo* nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    nuevo->altura = 1;
    return nuevo;
}

// --- ROTACIONES SIMPLES ---
Nodo* rotarDerecha(Nodo *y)
{
    Nodo *x, *T2;
    x  = y->izq;    // x es el hijo izquierdo de y
    T2 = x->der;    // T2 es el subárbol derecho de x (puede ser NULL)

    // REASIGNACIÓN DE PUNTEROS
    x->der = y;     // y baja y se convierte en hijo derecho de x
    y->izq = T2;    // El subárbol T2 se "muda" a la izquierda de y
    // Actualización de alturas
    y->altura = max(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;
    x->altura = max(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;
    return x;
}

Nodo* rotarIzquierda(Nodo *x)
{
    Nodo *y, *T2;
    y  = x->der;
    T2 = y->izq;
    y->izq = x;
    x->der = T2;

    x->altura = max(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;
    y->altura = max(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;
    return y;
}

// --- ROTACIONES COMPUESTAS (Reutilizando simples) ---
Nodo* insertar(Nodo* nodo, int dato)
{
    if (nodo == NULL) {
        return crearNodo(dato);
    }

    if (dato < nodo->dato) {
        nodo->izq = insertar(nodo->izq, dato);
    }
    else{
        if (dato > nodo->dato) {
            nodo->der = insertar(nodo->der, dato);
        }
        else {
            return nodo;
        }
    }

    nodo->altura = 1 + max(obtenerAltura(nodo->izq), obtenerAltura(nodo->der));
    int fe = obtenerFE(nodo);

    // Caso Simple Izquierda (LL)
    if (fe < -1 && dato < nodo->izq->dato) {
        return rotarDerecha(nodo);
    }

    // Caso Simple Derecha (RR)
    if (fe > 1 && dato > nodo->der->dato) {
        return rotarIzquierda(nodo);
    }

    // Caso Compuesto Izquierda-Derecha (LR)
    if (fe < -1 && dato > nodo->izq->dato) {
        nodo->izq = rotarIzquierda(nodo->izq); // Rotación simple previa
        return rotarDerecha(nodo);             // Rotación simple final
    }

    // Caso Compuesto Derecha-Izquierda (RL)
    if (fe > 1 && dato < nodo->der->dato) {
        nodo->der = rotarDerecha(nodo->der);   // Rotación simple previa
        return rotarIzquierda(nodo);           // Rotación simple final
    }

    return nodo;
}

Nodo* eliminarNodo(Nodo* raiz, int dato)
{
    if (raiz == NULL) {
        return raiz;
    }

    // 1. ELIMINACIÓN ESTÁNDAR DE BST
    if (dato < raiz->dato) {
        raiz->izq = eliminarNodo(raiz->izq, dato);
    }
    else{
        if (dato > raiz->dato) {
            raiz->der = eliminarNodo(raiz->der, dato);
        }
        else {
            // Nodo con un solo hijo o ninguno
            if ((raiz->izq == NULL) || (raiz->der == NULL)) {
                Nodo *temp = raiz->izq ? raiz->izq : raiz->der;
                if (temp == NULL) { // Caso sin hijos
                    temp = raiz;
                    raiz = NULL;
                }
                else { // Caso con un hijo
                    *raiz = *temp;
                }
                free(temp);
            }
            else {
                // Nodo con dos hijos: obtener sucesor en orden
                Nodo* temp = nodoValorMinimo(raiz->der);
                raiz->dato = temp->dato;
                raiz->der = eliminarNodo(raiz->der, temp->dato);
            }
        }
    }

    if (raiz == NULL) {
        return raiz;
    }

    // 2. ACTUALIZAR ALTURA
    raiz->altura = 1 + max(obtenerAltura(raiz->izq), obtenerAltura(raiz->der));

    // 3. REBALANCEO
    int fe = obtenerFE(raiz);

    // Caso LL
    if (fe < -1 && obtenerFE(raiz->izq) <= 0) {
        return rotarDerecha(raiz);
    }

    // Caso LR
    if (fe < -1 && obtenerFE(raiz->izq) > 0) {
        raiz->izq = rotarIzquierda(raiz->izq);
        return rotarDerecha(raiz);
    }

    // Caso RR
    if (fe > 1 && obtenerFE(raiz->der) >= 0) {
        return rotarIzquierda(raiz);
    }

    // Caso RL
    if (fe > 1 && obtenerFE(raiz->der) < 0) {
        raiz->der = rotarDerecha(raiz->der);
        return rotarIzquierda(raiz);
    }

    return raiz;
}

// Función auxiliar para encontrar el nodo con el valor mínimo (sucesor en orden)
Nodo* nodoValorMinimo(Nodo* nodo)
{
    Nodo* actual = nodo;
    while (actual->izq != NULL) {
        actual = actual->izq;
    }
    return actual;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int obtenerAltura(Nodo *n)
{
    return (n == NULL) ? 0 : n->altura;
}

int obtenerFE(Nodo *n)
{
    return (n == NULL) ? 0 : obtenerAltura(n->der) - obtenerAltura(n->izq);
}


//Recorridos
void preOrden(Nodo *raiz)
{
    if(raiz != NULL){
        printf("%d ", raiz->dato);
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}

void inOrden(Nodo *raiz)
{
    if(raiz != NULL){
        inOrden(raiz->izq);
        printf("%d ", raiz->dato);
        inOrden(raiz->der);
    }
}

void posOrden(Nodo *raiz)
{
    if(raiz != NULL){
        posOrden(raiz->izq);
        posOrden(raiz->der);
        printf("%d ", raiz->dato);
    }
}

void mostrarArbol(Nodo *raiz, int espacio)
{
    int INCREMENTO = 10;
    if (raiz == NULL) {
        return;
    }

    espacio += INCREMENTO;

    // Procesar hijo derecho primero (aparecerá arriba)
    mostrarArbol(raiz->der, espacio);

    printf("\n");
    for (int i = INCREMENTO; i < espacio; i++) {
        printf(" ");
    }
    printf("%d(h:%d)\n", raiz->dato, raiz->altura);

    // Procesar hijo izquierdo (aparecerá abajo)
    mostrarArbol(raiz->izq, espacio);
}

