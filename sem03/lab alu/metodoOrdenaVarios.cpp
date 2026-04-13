/*
* nombrePrograma : metodosOrdenaVarios.cpp
* descripPrograma: Metodos de ordenamiento varios
*
*       Metodos de ordenamiento varios
*      Anaalice el codigo, luego compile, ejecute y analice los resultados
*
* author:
* fecha :
* Version 1
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>

using namespace std;

//prototipos de funcion
void mostrarVector(int x[], int dx);
void ordenaBurbuja(int x[], int dx);

void seleccion(int x[], int dx);
void insercion(int x[], int dx);

void intercambia(int *x, int *y);
void datosDePrueba();

int main()
{

    datosDePrueba();

    //system("pause");
    cin.get();
    return 0;
}

void datosDePrueba()
{
    int dat,na;
    int a[]= {26,47,55,123,222,69,885,12,19,96,101,117};
    na=sizeof(a)/sizeof(a[0]);

    mostrarVector(a, na);

    ordenaBurbuja(a, na);
    //seleccion(a, na);
    //insercion(a, na);

    mostrarVector(a, na);
}
void mostrarVector(int x[], int dx)
{
    int i, vi;
    if(dx>0) {
        printf("\nVector={");
        for(i=0; i<dx;) {
            vi=x[i];
            printf("%5d", vi);
            i=i+1;
        }
        printf("}\n");
    }
    else {
        printf("Vector vaciooo...\n");
    }
}

void ordenaBurbuja(int x[], int dx)
{
    int i, j;
    if(dx>0){
        for (i = 0; i < dx - 1; ++i) {
            for (j = 0; j < dx - i - 1; ++j) {
                if (x[j] > x[j + 1]) {
                    // Intercambiar los elementos
                    int temp = x[j];
                    x[j] = x[j + 1];
                    x[j + 1] = temp;
                }
            }
        }
    }
    else{
        printf("Vector vzciooo...\n");
    }

}

void seleccion(int x[], int dx)
{
    int i,j, minIndex;
    if(dx>0){
        for (i = 0; i < dx - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < dx; ++j) {
                if (x[j] < x[minIndex]) {
                    minIndex = j;
                }
            }
            intercambia(&x[i], &x[minIndex]);
        }
    }
    else{
        printf("Vector vzciooo...\n");
    }
}

void insercion(int x[], int dx)
{
    int i, j, val;
    if(dx>0){
        for (i = 1; i < dx; ++i) {
            val = x[i];
            j = i - 1;

            while (j >= 0 && x[j] > val) {
                x[j + 1] = x[j];
                j = j - 1;
            }
            x[j + 1] = val;
        }
    }
    else{
        printf("Vector vaciooo...\n");
    }
}

void intercambia(int *x, int *y)
{
    int tmp;
    tmp=*x;
    *x=*y;
    *y=tmp;
}
