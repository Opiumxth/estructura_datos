/*
* nomPrograma:
* descripcion:
*
*
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
#define  MAX 3
using namespace std;

//prototipos de funcion
void crearCola(int x[], int *frente, int *finale);
void encolar(int x[], int *frente, int *finale, int dato);
int decolar(int x[], int *frente, int *finale);


int main()
{
    int fte,fnal,dat;
    int cca[MAX];

    crearCola(cca, &fte, &fnal);
    encolar(cca, &fte, &fnal, 11);
    encolar(cca, &fte, &fnal, 22);
    encolar(cca, &fte, &fnal, 33);
    encolar(cca, &fte, &fnal, 44);

    printf("%d: decolado...\n", decolar(cca,&fte,&fnal));
    printf("%d: decolado...\n", decolar(cca,&fte,&fnal));
    printf("%d: decolado...\n", decolar(cca,&fte,&fnal));
    printf("%d: decolado...\n", decolar(cca,&fte,&fnal));


    system("pause");
    return 0;
}

//implmentacion prototipos de funcion
void crearCola(int x[], int *frente, int *finale)
{
    *frente=-1;
    *finale=-1;
}
void encolar(int x[], int *frente, int *finale, int dato)
{   printf("*frente: %d, *finale: %d\n", *frente, *finale);
    if(*finale==MAX-1 && *frente==0 || (*finale+1)==*frente){
        printf("Cola circular llena...\n");
    }
    else{
        if(*finale == MAX-1){
            *finale=0;
        }
        else{
            *finale=*finale+1;
        }
        x[*finale]=dato;
        if(*frente==-1){
            *frente = 0;
            *finale = 0;
        }
    }
}
int decolar(int x[], int *frente, int *finale)
{
    int dat=-1;
    if(*frente ==-1){
        printf("Cola circular vaciaaa...\n");
    }
    else{
        dat=x[*frente];
        if(*frente==*finale){
            *frente = -1;
            *finale = -1;
        }
        else{
            if(*frente== MAX-1){
                *frente = 0;
            }
            else{
                *frente=*frente+1;
            }
        }
    }
    return dat;
}
