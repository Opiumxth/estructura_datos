/*
* nombrePrograma : busquedaInterpOtros
* descripPrograma: Metodoso de busqueda busqueda varios
*
*       Metodos de busqueda varios
*      Anaalice el codigo, luego compile, ejecute y analice los resultados
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

using namespace std;

//prototipos de funcion
void mostrarVector(int x[], int dx);
int busquedaSecuencial(int x[], int dx, int dato);
int busquedaBinaria(int x[], int dx, int dato);
int busquedaInterpolcion(int x[], int dx, int dato);

int main()
{
    int dat,na, val;
    int a[]= {5,12,19,26,47,55,69,88,96,101,117,123,222};
    na=sizeof(a)/sizeof(a[0]);

    mostrarVector(a, na);
    dat=123;
    //val=busquedaSecuencial(a,na,dat);
    val=busquedaBinaria(a,na,dat);
    //val=busquedaInterpolcion(a,na,dat);

    if(val>=0) {
        printf("%d: Encontrado\n", dat);
    }
    else {
        printf("%d: NO Encontrado\n", dat);
    }

    system("pause");
    return 0;
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
int busquedaSecuencial(int x[], int dx, int dato)
{
    int i, vi;
    if(dx>0) {
        while(i<dx) {
            vi=x[i];
            if(vi==dato) {
                return(i);
            }
            i=i+1;
        }
        return -1;
    }
    else {
        printf("Vector vaciooo...\n");
        return -1;
    }
}
int busquedaBinaria(int x[], int dx, int dato)
{
    int lo, hi, mid;
    hi = dx-1;
    lo = 0;
    if(dx>0){
        while (lo <= hi) {
            mid = (hi + lo)/2;
            if (x[mid] == dato) {
                return mid;
            }
            else {
                if (dato < x[mid]) {
                    hi=mid-1;
                }
                else {
                    lo=mid+1;
                }
            }
        }
        return -1;
    }
    else {
        printf("Vector vaciooo...\n");
        return -1;
    }
}
int busquedaInterpolcion(int x[], int dx, int dato)
{
    int lo, hi, mid;
    lo = 0;
    hi = dx - 1;
    if(dx>0){
        while ((x[hi] != x[lo]) && (dato >= x[lo]) && (dato <= x[hi])) {
            mid = lo + ((dato - x[lo]) * (hi - lo) / (x[hi] - x[lo]));

            if (x[mid] < dato) {
                lo = mid + 1;
            }
            else {
                if (dato < x[mid]) {
                    hi = mid - 1;
                }
                else {
                    return mid;
                }
            }
        }
        if (dato == x[lo]) {
            return lo;
        }
        else {
            return -1;
        }
    }
    else {
        printf("Vector vaciooo...\n");
        return -1;
    }
}
