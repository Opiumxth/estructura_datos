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
class Pila
{
private:
    class Nodo
    {
    public:
        char car;
        Nodo *sgte;
    };
    Nodo *cab;
public:
    Pila();
    ~Pila();
    void empilar(char x);
    char depilar();
    bool pilaVacia();
};

Pila::Pila()
{
    cab = NULL;
}
Pila::~Pila()
{
    Nodo *p, *q;
    p=cab;
    while(p!=NULL){
        q = p;
        p = p->sgte;
        delete q;
    }
}

void Pila::empilar(char vcar)//
{
    Nodo *neo;
    neo = new Nodo();
    if (neo==NULL){
        printf("Mo hay espacio de memoria\n");
    }
    else{
        neo->car=vcar;
        neo->sgte=NULL;
        if (cab == NULL) {
            cab = neo;
        }
        else {
            neo->sgte = cab;
            cab = neo;
        }
    }

}

char Pila::depilar()
{
    char ele;
    Nodo *p;

    if(cab!= NULL){
        ele=cab->car;
        p=cab;
        cab = cab->sgte;;
        delete p;
        return ele;
    }
    else {
        return ' ';
    }
}

bool Pila::pilaVacia()
{
    if (cab == NULL) {
        return true;
    }
    else {
        return false;
    }
}

class Expresion
{
    char cad[STR50];
    public:
    Expresion ();
    bool esCorrecto();
};

Expresion::Expresion()
{
    cout << "Ingrese una expreion con (, {. o [ : ";
    cin.getline(cad, STR50);
}

bool Expresion::esCorrecto()
{
    int i;
    Pila *pila1;
    pila1 = new Pila();
    for (i = 0; i < strlen(cad); i++) {
        if (cad[i] == '(' || cad[i] == '[' || cad[i] == '{') {
            pila1->empilar(cad[i]);
        }
        else {
            if (cad[i] == ')') {
                if (pila1->depilar() != '(') {
                    return false;
                }
            }
            else {
                if (cad[i] == ']') {
                    if (pila1->depilar() != '[') {
                        return false;
                    }
                }
                else {
                    if (cad[i] == '}') {
                        if (pila1->depilar() != '{') {
                            return false;
                        }
                    }
                }
            }
        }
    }
    if (pila1->pilaVacia()) {
        return true;
    }
    else {
        return false;
    }
}


int main()
{
    Expresion *exp1;
    exp1 = new Expresion();
    if (exp1->esCorrecto() == true) {
        cout << "La expresion esta correcta\n";
    }
    else {
        cout << "La expresion no esta correcta\n";
    }
    delete exp1;

    system("pause");
    return 0;
}


