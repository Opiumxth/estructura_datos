/*
 * nombreProg : listaDoble.cpp
 * descripcion: Operaciones basicas
 *
 *
 *	0.	Analice el codigo y comente las operaciones.
 * 1. Haga un esquema logico de la lista y en ella simule
 *    la insercion y eliminacion de nodos.
 *	2. Complete las operaciones basicas
 *
 * autor: GASA
 * fecha:
 *
 */


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;
struct NODO {
    int val;
    NODO *ante;
    NODO *sgte;
};

void crearLista(NODO **cab);
NODO* crearNodo(NODO **cab, int dato);
void insertarIni(NODO **cab, int dato);
void mostrarLista(NODO *cab);
void eliminarIni(NODO **cab);
void insertarDespues(NODO **cab, int dato, int pos);
void insertarAntes(NODO **cab, int dato, int pos);

int main()
{
    NODO *a, *b;
    crearLista(&a);
    crearLista(&b);
    insertarIni(&a, 11);
    insertarIni(&a, 22);
    insertarIni(&a, 33);
    mostrarLista(a);

    //eliminarIni(&a);
    //mostrarLista(a);
    insertarDespues(&a, 25, 3);
    mostrarLista(a);

    system("pause");
    return(0);
}

void crearLista(NODO **cab)
{
    *cab=NULL;
}
NODO* crearNodo(NODO **cab, int dato)
{
    NODO *p;
    p=NULL;
    p=(NODO*) malloc(sizeof(NODO));
    if(p!=NULL) {
        p->val=dato;
        p->sgte=NULL;
        p->ante=NULL;
        return(p);
    }
    else{
        printf("No hay espacio de memoria...\n");
        return(p);
    }
}
void insertarIni(NODO **cab, int dato)
{
    NODO *p;
    p=crearNodo(&*cab,dato);
    if(p==NULL){
        printf("No hay espacio de memoria...\n");
    }
    else{
        if(*cab==NULL) {
            *cab=p;
        }
        else {
            p->sgte=*cab;
            (*cab)->ante=p;
            *cab=p;
        }
    }

}
void mostrarLista(NODO *cab)
{
    NODO *p;
    p=cab;
    if(p==NULL) {
        printf("Lista vaciaaa...!\n\n");
    } else {
        printf("Lista = <");
        while(p!=NULL) {
            printf("%d, ", p->val);
            p=p->sgte;
        }
        printf(">\n\n");
    }
}

void eliminarIni(NODO **cab)
{
    NODO *p;
    p=*cab;
    if(p==NULL) {
        printf("Lista vaciaaa...!\n\n");
    }
    else {
        *cab=(*cab)->sgte;
        printf("%d ha sido eliminado ...!\n\n", p->val);
        free(p);
    }
}
void insertarDespues(NODO **cab, int dato, int pos)
{
    int ctdor;
    NODO *p, *actual, *q;
    p=(NODO*) malloc(sizeof(NODO));
    p->val=dato;
    p->sgte=NULL;
    p->ante=NULL;

    if(*cab==NULL) {
        if(pos==1) {
            *cab=p;
        }
        else {
            printf("%d: esa posicion no existe...!\n\n", pos);
        }
    }
    else {
        ctdor=0;
        actual=*cab;
        //while(actual!=NULL && ctdor<=pos) { // es solo < pos
        while(actual!=NULL && ctdor<pos) {
            actual=actual->sgte;
            ctdor=ctdor+1;
        }
        if(ctdor-1<=pos) {
            if(actual->sgte==NULL) {
                actual->sgte=p;
                p->ante=actual;
            }
            else {
                q=actual->sgte;
                actual->sgte=p;
                p->ante=actual;

                p->sgte=q;
                q->ante=p;
            }
        }
        else{
            printf("%d: posicion no existe...!\n\n", pos);
        }
    }
}
