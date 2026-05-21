/**
*  NombreProg :     PILAEstatReg01.cpp
*  Descripcion:     Operaciones basicas de una PILA en una implementacion estatica
*                   utilizando registros.
*
*         TAREA
*  1. Analice el codigo, luego compile, ejecute y analice los resultaos
*  2. Muestr los elemetos de la pila solo reutilizando los metodos de la pila..
*  3. Implemente una PILA estatica, sin utilizar registros y sin variables globales
*  4. Agregueun menu si cree conveniente.
*  5  Implemente el subprogrma para convertir una expresion infija en posfija
*     del libro de Estructura de datos de O Cairo
*
*  Autor: GASA
*  Fecha:
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define MAX  10
#define STR50  50
#define STR90  90

using namespace std;

typedef char TD;

struct PILA {
    TD v[MAX];
    int tope;
};
void crearPila(PILA *p);
void empilar(PILA *p, const TD dato);
TD depilar(PILA *p);
void eliminarPila(PILA *p);
TD visorPila(PILA p);
int pilaVacia(PILA p);
int pilaLlena(PILA p);
void esPalindromo();

void convetirPosfija(char einf[STR90]);
int prioridadOperador(char operad);
int prioridadEnPila(char operad);

int main()
{

    //esPalindromo();
    char ei1[]="x + z * w";
    //epos xzw " +
    char ei2[]="(x + z) * w / t^y - v";
    //epos:  xz+w*ty^/v-
    char ei3[]="x * (z + w)/(t - v)";

    convetirPosfija(ei2);

    printf("\n\t");
    system("PAUSE");
    return (0);
}

// Crea una PILA vacía */
void crearPila(PILA* p)
{
    p->tope = -1;
}

void empilar(PILA *p,const TD dato)
{
    if(pilaLlena(*p)) {//Porque con *p?
        printf("... PILA LLENA\n");
        return;
    }
    //else es correcto utilizarlo?
    p->tope=p->tope+1;
    p->v[p->tope] = dato;
}

TD depilar(PILA *p)
{
    TD aux;
    if (p->tope == -1) {
        printf(" ... Pila vacía\n");
        return(0);
    }
    aux = p->v[p->tope];

    // Actualiza tope */
    p->tope=p->tope-1;
    return (aux);
}

int pilaVacia(PILA p)
{
    return (p.tope == -1); //Que significa esto ?
}

int pilaLlena(PILA p)
{
    return p.tope == MAX-1;
}

void eliminarPila(PILA *p)
{
    p->tope = -1;
}
// Visualiza el elmento visible de la PILA: el primero*/
TD visorPila(PILA p )
{
    if (p.tope == -1) {
        printf("... PILA VACIA\n");
        system("pause");
        return(0);
    }
    return (p.v[p.tope]);
}

// Conversion expresion infija posfija
void convetirPosfija(char einf[STR90])
{
    int i,j, ls;

    char car,dato,opcima;
    char epos[STR50],vpi;
    PILA p;
    crearPila(&p);
    i=0, j=0;
    while(einf[i]!='\0'){   //2.
        car=einf[i];
        if(car=='('){       //2.1
            empilar(&p,car);
        }
        else{
            //2.1.1
            if(car==')'){
                //2.1.1.1
                //vpi=visorPila(p);
                while(visorPila(p) != '('){
                    dato=depilar(&p);
                    epos[j]=dato;
                    j=j+1;
                } //2.1.1.2
                depilar(&p);
            }
            else{
                // 2.1.1.3 si car es un operando
                if(car!='^'&&car!='/'&&car!='*'&&car!='+'&&car!='-'){
                    epos[j]=car;
                    j=j+1;
                }
                else{
                    // 2.1.1.3A
                    vpi=visorPila(p);
                    while(!pilaVacia(p) && (prioridadOperador(car) <= prioridadEnPila(vpi))){
                        dato=depilar(&p);
                        epos[j]=dato;
                        j=j+1;
                    } //2.1.1.3B
                    empilar(&p,car);
                }
            }
        }
        i=i+1;
    }
    while(!pilaVacia(p)){
        dato=depilar(&p);
        epos[j]=dato;
        j=j+1;
    }
    epos[j]='\0';
    printf("ExpPosfija: %s", epos);
}

int prioridadOperador(char operad)
{
    if (operad == '^') {
        return 4;
    }
    if (operad == '*' || operad == '/') {
        return 2;
    }
    if (operad == '+' || operad == '-') {
        return 1;
    }
    if (operad == '(' ) {
        return 5;
    }
    return 0;
}
int prioridadEnPila(char operad)
{
    if (operad == '^') {
        return 3;
    }
    if (operad == '*' || operad == '/') {
        return 2;
    }
    if (operad == '+' || operad == '-') {
        return 1;
    }
    if (operad == '(' ) {
        return 0;
    }
    return 0;
}
// Fin conversion expresion infija posfija

void esPalindromo()
{
    char cad[STR50], car;
    PILA p;
    int j, palin;
    j=0;
    palin = 1;

    crearPila(&p);
    printf("Dato del Tope ---> %c\n", visorPila(p));
    system("pause");
    // Lee la Cadena */
    do {
        system("cls");
        printf("\n\t\tCOMPROBAR SI ES PALINDROMO\n\n");
        printf("\tIngrese la Cadena ---> ");
        //for (j = 0; (Car = getchar())!='\n'; ) // ...?
        j=0;
        while((car=getchar())!='\n') {
            cad[j++] = car;
            empilar(&p,car);
        }
        cad[j] = '\0'; // Porque es necesario esto?
        j=0;
        while(palin && !pilaVacia(p)) {
            //Palin = Cad[j] == depilar(&p);// Que reemplazaria si utilizo esta?
            palin=cad[j];

            car=depilar(&p);
            if(palin==car) { //compara char con int ...?
                palin=1;
            }
            else {
                palin=0;
            }
            j=j+1;
        }

        eliminarPila(&p);
        if (palin) {
            printf("\n\tLa cadena - %s - es un PALINDROMO \n",cad);
        }
        else {
            printf("\n\tLa cadena - %s - no es un PALINDROMO \n",cad);
        }
        printf("\n\tOtra Cadena  S/N ? --->  ");
        //scanf("%c",&Car);
        scanf("%c%*c",&car); // Porque utiliza ademas %*c
    } while (tolower(car) == 's');
    //toupper(car)

}

