/*
* nomPrograma:
* descripcion:
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

void crearVector(int **x, int *dx);
void llenarVector(int **x, int *dx);
void mostrarVector(int *x, int dx);
void eliminarPorPosicion(int **x, int *dx, int pos);

int main()
{
    int *a, *b, *c;
    int na, nb, nc;
    int posi;
    posi=1;

    crearVector(&a, &na);
    mostrarVector(a, na);
    crearVector(&b, &nb);
    mostrarVector(b, nb);

    llenarVector(&a, &na);
    mostrarVector(a, na);
    eliminarPorPosicion(&a,&na, posi);
    mostrarVector(a, na);


    //free(a); // Liberar memoria
    //free(b);


    system("pause");
    return 0;
}
// 1. Crear/Inicializar el vector
void crearVector(int **x, int *dx)
{
    *x  = NULL;
    *dx = -1;
}
/*
void crearVector(int **x, int *dx)
{
    int n;
    scanf("%d, &n");
    if(n>0){
        x = (int*)malloc(n*sizeof(int));
        *dx = n;
    }
    else{
        printf("dx: %d Dimension inadecuada", *dx);
    }
}
*/
// 2. Cargar elementos
void llenarVector(int **x, int *dx)
{
    int i,n,val;
    scanf("%d,", &n);
    if(n > 0) {
        *x = (int*)malloc(n*sizeof(int));
        for (i = 0; i < n; i++) {

            printf("x[%d]: ", i);
            //scanf("%d", &val);
            //*((*x)+i) = val;
            //scanf("%d", &((*x)[i]));
            scanf("%d", &(*x)[i]);
            //scanf("%d", &*((*x)+i));
            //scanf("%d", ((*x)+i));
            //scanf("%d", *(*x+i));
            //scanf("%d", &x[i]);
        }
        *dx = n;
    } else {
        printf("dx: %d. Dimension inadecuada\n", *dx);
    }
}


// 3. Mostrar elementos
void mostrarVector(int *x, int dx)
{
    int i;
    printf("dx: %d\n", dx);
    printf("Vector: {");
    if(dx > 0) {
        for (i = 0; i < dx; i++) {
            //printf("%d, ", x[i]);
            printf("%d, ", (x+i));
        }
    } else {
        printf("Vector vaciooo...");
    }
    printf("}\n");
}

// 4. Eliminar elemento
void eliminarPorPosicion(int **x, int *dx, int pos)
{
    int *a, i;
    a=(int*)malloc((*dx)*sizeof(int));
    //a = *x;
    printf("Hola... *dx: %d\n", *dx);
    for(int j=0;j<*dx;j++){
        printf("%d,", *(x+j));
    }

    if(*dx > 0) {
        if(pos<0 || pos >= *dx) {
            printf("%d: Posicion invalidaaaa...\n", *dx);
        }
        else {
            i=pos;
            for (i = pos; i < *dx - 1; i++){
            //while(i < *dx-1) {
                //a[i] = a[i + 1];
                *(x+i) = *(x+i+1);
                printf("Hola...: %d\n", i);
                //i=i+1;
            }
            *dx = *dx-1;
            for(int j=0;j<*dx;j++){
                printf("%d,", *(x+j));
            }
            printf("Hola...\n");
            *x = (int*)realloc(*x, (*dx)*sizeof(int));
            //*x = (int*)malloc((*dx)*sizeof(int));

            //a = (int*)realloc(a, (*dx)*sizeof(int));
            //*x = a;
        }
    }
    else {
        printf("Vector vaciooo...");
    }
}
/*
void eliminarPorPosicion(int *x, int *dx, int pos)
{
    int i;
    if(*dx > 0){
        if(pos<0 || pos >= *dx){
            printf("%d: Posicion invalidaaaa...\n", *dx);
        }
        else{
            i=pos;
            //for (i = pos; i < *dx - 1; i++)
            while(i < *dx-1){
                 x[i] = x[i + 1];
                 i=i+1;
            }
            *dx = *dx-1;
            x = (int*)realloc(x, (*dx)*sizeof(int));
        }
    }
    else{
        printf("Vector vaciooo...");
    }
}
*/
/*
int* eliminarElemento(int* v, int* n, int pos)
{
    if (pos < 0 || pos >= *n) {
        printf("Posición inválida\n");
        return v;
    }
    for (int i = pos; i < *n - 1; i++) {
        v[i] = v[i + 1]; // Desplazar elementos
    }
    (*n)--;
    v = (int*)realloc(v, (*n) * sizeof(int)); // Redimensionar
    return v;
}
*/
