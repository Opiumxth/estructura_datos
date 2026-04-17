/*
* nomPrograma: metOrdenBucket.cpp
* descripcion: Metodo de ordenamiento
*
*               TAREA
*
*   0. Analice el codigo, luego compile, ejecute y analice los resultados
*      0.1 Que observaciones tienen a la aplicacion?
*   1. Analice el metodo insertarOrdenado(...) con el inserrtar ordenado
*      en vectores y vectores de registros del curso anterior.
*   2. Como aplicaria de forma de eficiente
*   3. Ivestigue las listas enlazadas en libros de texto Estructuras de datos
*      (seudcodigo) O. Cairo y Joyanes (lenguaje C)
*   4. Cual es la razon de utilizar struct Nodo* en las lineas 114 y 115
*      y solamente Nodo* en las lineas 35 y 40.
*   5. Que hace o para que se hace free(aux) en la linea 137.
*
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

// Nodo para la lista enlazada en cada balde
struct Nodo {
    float dato;
    Nodo *sgte;
};

void datosDePrueba();
void mostrarVector(float x[], int dx);
Nodo* insertarOrdenado(Nodo *cab, float valor);
void bucketSort(float x[], int dx);
float maximoElemento(float x[], int dx);

int main()
{

    datosDePrueba();

    //system("pause);
    return 0;
}

void datosDePrueba()
{
    int na;
    float a[] = {0.42, 0.32, 0.04, 0.33, 0.52, 0.37, 0.07, 0.51};
    na = sizeof(a) / sizeof(a[0]);

    mostrarVector(a,na);
    printf("MaxElemento: %.2f", maximoElemento(a, na));

    bucketSort(a, na);
    mostrarVector(a, na);

    printf("MaxElemento: %.2f", a[na-1]);

}

void mostrarVector(float x[], int dx)
{
    int i;
    float vi;
    if(dx>0) {
        printf("\nVector = {");
        for(i=0; i<dx;) {
            vi=x[i];
            printf("%.2f, ", vi);
            i=i+1;
        }
        printf("}\n");
    }
    else {
        printf("Vector vaciooo...\n");
    }
}


// Función para insertar y ordenar dentro del balde (Insertion Sort)
Nodo* insertarOrdenado(Nodo *cab, float valor)
{
    Nodo *nuevo, *actual;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->sgte = NULL;

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

void bucketSort(float x[], int dx)
{
    /// Cumple con las buenas practicas si o no?
    int i,indice, j;
    struct Nodo *aux;
    struct Nodo *baldes[dx];

    for (int i = 0; i < dx; i++) {
        baldes[i] = NULL;
    }

    // 1. Distribuir elementos en los baldes
    for (i = 0; i < dx; i++) {
        indice = dx * x[i]; // Determina el balde
        baldes[indice] = insertarOrdenado(baldes[indice], x[i]);
    }

    // 2. Concatenar los baldes de vuelta al arreglo original
    j = 0;
    for (i = 0; i < dx; i++) {
        struct Nodo* actual = baldes[i];
        while (actual != NULL) {
            x[j++] = actual->dato;
            aux = actual;
            actual = actual->sgte;
            free(aux); // Liberar memoria
        }
    }
}

// Función para encontrar el valor máximo en el arreglo
float maximoElemento(float x[], int dx)
{
    int i;
    float emax;
    emax= -1.0;
    if(dx > 0){
        emax = x[0];
        for (i = 0; i < dx; i++) {
            if (x[i] > emax) {
                emax = x[i];
            }
        }
        return emax;
    }
    else{
        printf("Vector vaciooo...\n");
        return(emax); //...y si emax=-5 ?
    }
}
