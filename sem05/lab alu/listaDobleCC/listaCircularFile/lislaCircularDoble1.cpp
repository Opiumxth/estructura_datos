/*
 * nombreProg : listaCircularDoble1.cpp
 * descripcion: Operaciones basicas de una lista doble circular
 *              con apuntador al inicio y al final de la lista.
*
 *    0. Se adjunta el file de prueba  con la cual podemos recuperar
 *       los elementos de la lista.
 *    1. Analice porque en el main solo estan activas las lineas
 *       58/60, 65 y 74/75.
 *    2. ¿que debe hacer para agregar elementos a la lista y salvarlas?
 *    3. Implemente un metodo de menu de opciones para el manejo de
 *       la lista.
 *
 *                      PL04 previa
 *    1. Analice para determinar el funcionamiento.
 *    2. Comente las estructuras de control indicando la razon de
 *       cada una de ellas.
 *    3. Agregue la operacion eliminar (3p)
 *             TAREA
 *    4. Implemente el mismo programa de listas dobles circular
 *       pero solo con el apuntador a inicio (un solo apuntador al menor)(6p)
 *    5. Implemente el mismo programa anterior pero ahora agregando
 *       la estructura (6p):
 *             struct LISTA{
 *                NODO *ini;
 *                NODO *fin;
 *             };
 *             TAREA domiciliaria posible pregunta de examen
 *    7. Crear una libreria del programa anterior
 *    8. Implemente las operaciones de pila y Cola  utilizando esta libreria.
 *
 * autor: GASA
 * fecha: 20012020
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

void crearLista(NODO **cabi, NODO **cabu);
void insertarInicio(NODO **cabi, NODO **cabu, int dato);
void insertarOrdenado(NODO **cabi, NODO **cabu, int dato);
void mostrarLista(NODO *cabi);
void mostrarLista1(NODO *cabu);

void salvarLista(NODO *cabi);
void recuperarLista(NODO **cabi, NODO **cabu);

int main()
{
    NODO *ai, *au;
    int v;
    crearLista(&ai, &au);
    //insertarInicio(&ai, &au, 11);
    //insertarInicio(&ai, &au, 22);
    //insertarInicio(&ai, &au, 33);
    //salvarLista(ai);
    recuperarLista(&ai, &au);
    /*
    insertarOrdenado(&ai, &au, 11);
    insertarOrdenado(&ai, &au, 2);
    insertarOrdenado(&ai, &au, 33);
    insertarOrdenado(&ai, &au, 15);
    insertarOrdenado(&ai, &au, -5);
    insertarOrdenado(&ai, &au, 100);
    */
    mostrarLista(ai);
    mostrarLista1(au);

    system("pause");
    return(0);
}
void crearLista(NODO **cabi, NODO **cabu)
{
    *cabi=NULL;
    *cabu=NULL;
}

void insertarInicio(NODO **cabi, NODO **cabu, int dato)
{
    NODO *neo;
    neo=(NODO*) malloc(sizeof(NODO));
    neo->val=dato;
    neo->ante=NULL;
    neo->sgte=NULL;

    if(*cabi==NULL) {
        *cabi=neo;
        *cabu=neo;
        neo->sgte=neo;
        neo->ante=neo;
    } else {
        neo->ante=(*cabu);
        (*cabu)->sgte=neo;
        neo->sgte=(*cabi);
        (*cabi)->ante=neo;
        *cabi=neo;
    }
}

void insertarOrdenado(NODO **cabi, NODO **cabu, int dato)
{
    NODO *neo, *p;
    neo=(NODO*) malloc(sizeof(NODO));
    neo->val=dato;
    neo->ante=NULL;
    neo->sgte=NULL;

    if(*cabi==NULL) {
        *cabi=neo;
        *cabu=neo;
        neo->sgte=neo;
        neo->ante=neo;
    } else {
        p=*cabi;
        if(dato < p->val) {
            (*cabu)->sgte=neo;
            neo->ante=(*cabu);
            neo->sgte=(*cabi);
            (*cabi)->ante=neo;
            *cabi=neo;
        } else {
            while(p->sgte!=*cabi && dato>=p->sgte->val) {
                p=p->sgte;
            }
            if(p==*cabu) {
                neo->sgte=(*cabu)->sgte;
                (*cabi)->ante=neo;
                (*cabu)->sgte=neo;
                neo->ante=*cabu;
                *cabu=neo;
            } else {
                neo->sgte=p->sgte;
                p->sgte=neo;
                neo->ante=p;
                neo->sgte->ante=neo;
            }
        }
    }
}
void mostrarLista(NODO *cabi)
{
    NODO *p;
    p=cabi;
    if(p != NULL) {
        printf("Lista = < ");
        do {
            printf("%d ", p->val);
            p=p->sgte;
        } while(p!=cabi);
        printf(" >\n\n");

    } else {
        printf("Lista vaciaaaa,..\n");
    }

}

void mostrarLista1(NODO *cabu)
{
    NODO *p;
    p=cabu;
    if (p != NULL) {
        printf("Lista = < ");
        do {
            printf("%d ", p->val);
            p=p->ante;
        } while(p!=cabu);
        printf(" >\n\n");
    }
    else{
        printf("Lista vaciaaaa...\n");
    }
}

void salvarLista(NODO *cabi)
{
    NODO *p;
    FILE *f;
    int v;
    f=fopen("lista.txt", "a+");
    if(f==NULL) {
        printf("No se pudo abrir el file...\n");
        exit(0);
    }

    p=cabi;
    if(p != NULL){
        do {
            v=p->val;
            fwrite(&v,sizeof(v),1,f);
            p=p->sgte;
        } while(p!=cabi);
        fclose(f);
        printf("La lista ha sido salvada... >\n\n");
    }
    else{
        printf("Lista vaciaaa...\n");
    }
}
void recuperarLista(NODO **cabi, NODO **cabu)
{
    FILE *f;
    int v;
    f=fopen("lista.txt", "r");
    if(f==NULL) {
        printf("No se pudo abrir el file...\n");
        exit(0);
    }
    fread(&v,sizeof(v),1,f);
    while(!feof(f)) {
        insertarInicio(*&cabi,*&cabu,v);
        fread(&v,sizeof(v),1,f);
    }
    fclose(f);
    printf("La lista ha sido recuperada... \n\n");
}
