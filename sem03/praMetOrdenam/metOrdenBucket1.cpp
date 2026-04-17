/*
* nomPrograma: metOrdenBucket1.cpp
* descripcion: Metodo de ordenamiento
*
*               TAREA
*
*   0. Analice el codigo, luego compile, ejecute y analice los resultados
*      0.1 Elimine el parametro maxValor de bucketSort(...), deberiqa queda
*      similar al primer ejemplo.
*   1. Analice el metodo insertarOrdenado(...) con el inserrtar ordenado
*      en vectores y vectores de registros del curso anterior.
*   2. Como aplicaria de forma de eficiente
*   3. Ivestigue las listas enlzadas en libros de texto Estructuras de datos
*      (seudcodigo) O. Cairo y Joyanes (lenguaje C)
*
*
* autor:
* Fecha:
* Version 1.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <stdlib.h>
#define MAX20 20

using namespace std;

struct Nodo {
    int dato;
    Nodo *sgte;
};

void datosDePrueba();
void mostrarVector(int x[], int dx);

Nodo* insertarOrdenado(Nodo *cab, int valor);
void bucketSort(int x[], int dx, int maxValor);


int main()
{

    datosDePrueba();

    //system("pause);
    return 0;
}

void datosDePrueba()
{
    int na, maxVal;
    maxVal=999;

    int a[] = {802, 15, 999, 45, 120, 300, 10, 550};
    na = sizeof(a) / sizeof(a[0]);

    mostrarVector(a,na);
    bucketSort(a, na, maxVal);
    mostrarVector(a, na);

}
void mostrarVector(int x[], int dx)
{
    int i, vi;

    if(dx>0) {
        printf("\nVector = {");
        for(i=0; i<dx;) {
            vi=x[i];
            printf("%d, ", vi);
            i=i+1;
        }
        printf("}\n");
    }
    else {
        printf("Vector vaciooo...\n");
    }
}

// Función para insertar ordenado en la lista enlazada del balde
Nodo* insertarOrdenado(Nodo *cab, int valor)
{
    Nodo *nuevo, *actual;

    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;

    // 1. Consistencia de lista vacia
    if (cab == NULL || valor < cab->dato) {
        nuevo->sgte = cab;
        return nuevo;
    }

    // 2. Busca la posicion adecuada y luego inserta el nodo
    actual = cab;
    while (actual->sgte != NULL && actual->sgte->dato < valor) {
        actual = actual->sgte;
    }

    nuevo->sgte = actual->sgte;
    actual->sgte = nuevo;
    return cab;
}

void bucketSort(int x[], int dx, int maxValor)
{
    /// Cumple con las buenas practicas si o no?
    int i, indice, k, numBaldes;
    Nodo *actual, *temp;

    // Se puede ajustar de acuerdo a necesidad
    numBaldes = 10;
    struct Nodo* baldes[numBaldes];

    for (i = 0; i < numBaldes; i++) {
        baldes[i] = NULL;
    }

    // 1. Distribuir elementos en los baldes
    for (i = 0; i < dx; i++) {
        // Fórmula para distribuir: (valor / (maxValor + 1)) * numBaldes
        int indice = (x[i] * numBaldes) / (maxValor + 1);
        baldes[indice] = insertarOrdenado(baldes[indice], x[i]);
    }

    // 2. Concatenar los baldes de vuelta al arreglo original
    k = 0;
    for (i = 0; i < numBaldes; i++) {
        actual = baldes[i];
        while (actual != NULL) {
            x[k++] = actual->dato;
            temp = actual;
            actual = actual->sgte;
            free(temp);
        }
    }
}





