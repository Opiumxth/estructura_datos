/*
* nombrePrograma :
* descripPrograma:
*
*
*
* author: https://www.tutorialesprogramacionya.com/cya/detalleconcepto.php?punto=41&codigo=41&inicio=30
          https://titiushko.github.io/Tutoriales-Ya/www.tutorialesya.com.ar/cmasmasya/detalleconcepto76f4.html?punto=37&codigo=168&inicio=30
* fecha :
* Version 1
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define STR50 50

using namespace std;

//prototipos de funcion
struct NODO {
    char car;
    NODO *sgte;
};

void empilar(NODO **cab, char vcar);
char depilar(NODO **cab);
bool pilaVacia(NODO *cab);

void liberaMemoria(NODO **cab);
bool verificarExpresion(NODO **cab, char cad[]);

void cargarExpresion(char cad[]);

int main()
{
    char cad[STR50];
    NODO *p1;
    cargarExpresion(cad);
    printf("%s\n", cad);

    if (verificarExpresion(&p1, cad)) {
        printf("La expresion es correcta\n");
    }
    else {
        printf("La expresion no es correcta\n");
    }

    liberaMemoria(&p1);

    system("pause");
    return 0;
}

void empilar(NODO **cab, char vcar)
{
    NODO *neo;
    neo = (NODO*)malloc(sizeof(NODO));

    if(neo==NULL){
        printf("No hay espacio de memoria...\n");
    }
    else{
        neo->car = vcar;
        neo->sgte= NULL;

        if (*cab == NULL) {
            *cab = neo;
        }
        else {
            neo->sgte = *cab;
            *cab = neo;
        }
    }
}

char depilar(NODO **cab)
{
    char info;
    if (*cab != NULL) {
        info = (*cab)->car;
        NODO *p = *cab;
        *cab = (*cab)->sgte;
        free(p);
        return info;
    }
    else {
        return ' ';
    }
}

bool pilaVacia(NODO *cab)
{
    if (cab == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void liberaMemoria(NODO **cab)
{

    NODO *reco = *cab;
    NODO *bor;
    while (reco != NULL) {
        bor = reco;
        reco = reco->sgte;
        free(bor);
    }
    /*
    NODO *p, *q;
    p=cab;
    while(p!=NULL){
        q = p;
        p = p->sgte;
        free (q);
    }

    NODO *p;
    while(*cab!= NULL){
        p=*cab;
        *cab = (*cab)->sgte;
        free(p);
    }
    *cab=NULL;
    */
}

void cargarExpresion(char cad[])
{
    printf("Ingrese una expreion con (, {. o [ : ");
    gets(cad);
}

bool verificarExpresion(NODO **cab, char cad[])
{
    char car;
    int i;
    for (i=0; i<strlen(cad); i++) {
        if (cad[i]=='(' || cad[i]=='[' || cad[i]=='{') {
            empilar(&*cab, cad[i]);
        }
        else {
            if (cad[i]==')') {
                if (depilar(&*cab)!='(') {
                    return false;
                }
            }
            else {
                if (cad[i]==']') {
                    if (depilar(&*cab)!='[') {
                        return false;
                    }
                }
                else {
                    if (cad[i]=='}') {
                        if (depilar(&*cab)!='{') {
                            return false;
                        }
                    }
                }
            }
        }
    }

    if (pilaVacia(*cab)) {
        printf("true\n");
        return true;
    }
    else {
        printf("false\n");
        return false;
    }
}
