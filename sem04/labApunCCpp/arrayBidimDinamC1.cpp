/*
* nomPrograma: arrayBidim1.cpp
* descripcion: Operaciones basicas
*
*
*
* autor:
* fecha:
* version1
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <String.h>

using namespace std;

void crearMatriz(int ***x, int dxf, int dxc);
void llenarMatriz(int **x, int dxf, int dxc);
void eliminarFila(int ***x, int *dxf);
void mostrarMatriz(int **x, int dxf, int dxc);

int main()
{
    int i;
    int **m1, m1f, m1c;
    int **m2, m2f, m2c;
    int **m3, m3f, m3c;
    m1f=3, m1c=0;

    printf("\nCreando y Llenando Matriz (m1f x m1c) \n");
    crearMatriz(&m1, m1f, m1c);
    llenarMatriz(m1, m1f, m1c);
    mostrarMatriz(m1, m1f, m1c);

    printf("\nEliminando última fila (realloc)\n");
    eliminarFila(&m1, &m1f);
    mostrarMatriz(m1, m1f, m1c);

    // Limpieza final
    for (i = 0; i < m1f; i++) {
        free(m1[i]);
    }
    free(m1);

    system("pause");
    return 0;
}

// Crear la matriz: Reserva memoria para filas y columnas
void crearMatriz(int ***x, int dxf, int dxc)
{
    int i;
    if(dxf>0 && dxc>0){
        *x = (int **)malloc(dxf * sizeof(int *));
        for (i = 0; i < dxf; i++) {
            (*x)[i] = (int *)malloc(dxc * sizeof(int));
        }
    }
    else{
        printf("dxf: %d, dxc: %d, Dimension inadecuada...\n",dxf, dxc);
    }

}

// Llenar la matriz con datos del usuario
void llenarMatriz(int **x, int dxf, int dxc)
{
    int i, j;
    if(dxf>0 && dxc>0){
        for (i = 0; i < dxf; i++) {
            for (j = 0; j < dxc; j++) {
                x[i][j] = i + j; // Operación básica de llenado
            }
        }
    }
    else{
        printf("dxf: %d, dxc: %d, Dimension inadecuada...\n",dxf, dxc);
    }
}

// Eliminar (Redimensionar): Quita la última fila usando realloc
void eliminarFila(int ***x, int *dxf)
{

    int **temp;
    if (*dxf <= 0) {
        return;
    }

    // 1. Liberar la memoria de la última fila primero
    free((*x)[*dxf - 1]);

    // 2. Redimensionar el arreglo de punteros
    //(*dxf)--;
    *dxf = *dxf-1;
    //int **temp = (int **)realloc(*x, (*dxf) * sizeof(int *));
    temp = (int **)realloc(*x, (*dxf)*sizeof(int *));

    if (temp != NULL || *dxf == 0) {
        *x = temp;
    }
}

// Mostrar matriz
void mostrarMatriz(int **x, int dxf, int dxc)
{
    int i,j,val;
    printf("Matriz = {\n");
    if(dxf>0 && dxc>0){
        for (i = 0; i < dxf; i++) {
            for (j = 0; j < dxc; j++) {
                val= x[i][j];
                printf("%4d ", val);
                //printf("%4d ", m[i][j]);
            }
            printf("\n");
        }
        printf("}\n");
    }
    else{
        printf("Matriz vaciaaa...\n");
    }

}
