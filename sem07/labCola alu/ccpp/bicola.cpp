/*
* nomPrograma: bicola.cpp
* descripcion: Operaciones basicas de una bicola
*
"                   TAREA
* 1. Analice el codigo, luego comile,ejecute y analice los resultados
* 2. Implemente en una nueva version agregue/actualice las siguietes
*    operaciones:
*    2.1 Las operaciones eliminar frente y final deben retornar dato
*        eliminado.
*    2.2 Las operaciones bicolaVacion, bicolaLlena y reutilice
*        adecuadamente.
*    2.3 Operaciones para ver los elementos del frente y final de la
*        bicola.
*    2.4 La operacion para determinar el numero de elementos de la
"        bicola
* 3. Implemente las operaciones basicas de la pila reutilizando solo
"    las operaciones de la bicola
*
*
*
* author: https://giltesa.com/2012/02/10/6x06-bicolas-en-lenguaje-c
* fecha :
* Version 1
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

using namespace std;

typedef int TD;
struct NODO{
	TD info;
	NODO *ante;
	NODO *sgte;
};
struct BICOLA{
	int nnodos;
	NODO *frente;
	NODO *finale;
};
//prototipos de funcion
void crearBicola(BICOLA **bcola);
void insertarFrente(BICOLA **bcola, TD dato);
void insertarFinale(BICOLA **bcola, TD dato);
TD eliminarFrente(BICOLA **bcola);
TD eliminarFinale(BICOLA **bcola);

void mostrarBicola(BICOLA **bcola );
void eliminarBicola(BICOLA **bcola );
void menu();

int main()
{
    menu();

    system("pause");
    return 0;
}

//implmentacion prototipos de funcion
void crearBicola(BICOLA **bcola)
{
	/*
	PRE: true/VERDAD
	POS: "No hay espacio en memoria" or bcola={}
	*/
	BICOLA *p;
	p = (BICOLA*) malloc(sizeof(BICOLA));

	p->nnodos  = 0;
	p->frente = NULL;
	p->finale = NULL;
    *bcola = p;
}
void insertarFrente(BICOLA **bcola, TD dato)
{
	/*
	PRE: bcola={} or bcola={e1,e2, ...,en}
	POS: bcola={dato} or bcola={dato,e1,e2, ..., en}
	*/
	NODO *p;
	p = (NODO*) malloc(sizeof(NODO));
	// Si la Bicola no tiene Nodos se inserta sin mas
	if( (*bcola)->frente == NULL ){
		p->info	= dato;
		p->ante	= NULL;
		p->sgte	= NULL;

		(*bcola)->frente	= p;
		(*bcola)->finale	= p;
	}
	else{
		p->info	= dato;
		p->ante	= NULL;
		p->sgte	= (*bcola)->frente;

		(*bcola)->frente->ante = p;
		(*bcola)->frente	= p;
	};

	(*bcola)->nnodos = (*bcola)->nnodos + 1;
}
void insertarFinale(BICOLA **bcola, TD dato)
{
	/*
	PRE: bcola={} or bcola={e1,e2, ...,en}
	POS: bcola={dato} or bcola={e1,e2, ..., en, dato}
	*/
	NODO *p;
	p = (NODO*) malloc(sizeof(NODO));

	// Si la Bicola no tiene Nodos se inserta sin mas
	if( (*bcola)->frente == NULL ){
		p->info	= dato;
		p->ante	= NULL;
		p->sgte	= NULL;

		(*bcola)->frente	= p;
		(*bcola)->finale	= p;
	}
	else{
		p->info	= dato;
		p->ante	= (*bcola)->finale;
		p->sgte = NULL;

		(*bcola)->finale->sgte= p;
		(*bcola)->finale	= p;
	};

	(*bcola)->nnodos = (*bcola)->nnodos + 1;
}

TD eliminarFrente(BICOLA **bcola)
{
	/*
	PRE: bcola={} or bcola={e1,e2, ...,en}
	POS: "Bicola vaciaaa.." or bcola={  e2, ..., en}
	*/
	TD dato=0;
	NODO *aBorrar;
	BICOLA *p;
	p=*bcola;
	// Si la Bicola esta vacía...
	if( (*bcola)->frente == NULL ){
		printf( "Bicola vacía...\n" );
		return dato;
	}
	else{
        if( (*bcola)->nnodos == 1 ){
            dato=(*bcola)->frente->info;
            free(*bcola);
            crearBicola(&*bcola);
            return dato;
        }
          // En caso contrario se elimina solo el primer Nodo:
        else {
            if( (*bcola)->nnodos > 1 ){
                aBorrar = (*bcola)->frente;
                dato=aBorrar->info;
                (*bcola)->frente->sgte->ante	= NULL;
                (*bcola)->frente	= (*bcola)->frente->sgte;
                free(aBorrar);

                (*bcola)->nnodos = (*bcola)->nnodos - 1;
                return dato;
            }
        }
    }
}

TD eliminarFinale(BICOLA **bcola)
{
	TD dato;
	NODO *aBorrar;
	BICOLA *p;
	p=*bcola;
	// Si la Bicola esta vacía...
	if( (*bcola)->frente == NULL ){
		printf( "Bicola vacía...\n" );
		return 0;
	}
	else{
        if( (*bcola)->nnodos == 1 ){
            dato=(*bcola)->frente->info;
            free(*bcola);
            crearBicola(&*bcola);
            return dato;
        }
          // En caso contrario se elimina solo el primer Nodo:
        else {
            if( (*bcola)->nnodos > 1 ){
                aBorrar = (*bcola)->finale;
                dato=aBorrar->info;
                (*bcola)->finale->ante->sgte	= NULL;
                (*bcola)->finale	= (*bcola)->finale->ante;
                free(aBorrar);

                (*bcola)->nnodos = (*bcola)->nnodos - 1;
                return dato;
            }
        }
	}
}
void mostrarBicola(BICOLA **bcola)
{
	/*
	PRE: cola={} or cola={e1,e2, ...,en}
	POS: "Cola vaciaaa..." or cola={e1,e2, ..., en}
	*/
	NODO *p;
    p=(*bcola)->frente;

	if( p == NULL ){
		printf( "Bicola vacia...\n" );
	}
 	else{
		printf( "Datos de la bicola: { " );
		while( p != NULL ){
			printf("%d, ", p->info);
			p = p->sgte;
		};

		printf( "}\n\n" );

	};
}
void eliminarBicola(BICOLA **bcola )
{
	/*
	PRE: cola={} or cola={e1,e2, ...,en}
	POS: "Bicola vaciaaa" or cola=NULL
	*/
	NODO *p, *q;
	p = (*bcola)->frente;

    if(p==NULL){
        printf( "Bicola vacía...\n" );
    }
    else{
        while(p != NULL ){
            q = p->sgte;
            printf("p->info %d\n", p->info);
            free(p);
            p = q;
        }
        crearBicola(&*bcola);
        printf( "Bicola eliminada...\n" );
    }
};

void menu()
{
	int eleccion, vdato;

	BICOLA *bcolaA;
	BICOLA *bcolaB;
	crearBicola(&bcolaA);

	enum OPCIONES{
	    salir,
        insertFrente,
        insertFinal,
        deleteFrente,
        deleteFinal,
        mostrar,
        deleteBicola,
    };
	OPCIONES opc;

	do{
        printf("\n\tOPERACIONES DE BICOLA\n\n");
        printf("0. SALIR\n");
        printf("1. Insertar al frente\n");
        printf("2. Insertar al final\n");
        printf("3. Eliminar al frente\n");
        printf("4. Eliminar al finale\n");
        printf("5. Mostrar bicola\n");
        printf("6. Eliminar la bicola\n\n");
        printf("Digite su opcion ---> ");
        scanf("%d", &opc);
        switch(opc){
            case salir:
                printf("Se acabo el boleto...\n\n");
                break;
            case insertFrente:
                printf("Dato a insertar ---> ");
                scanf("%d",&vdato);
                insertarFrente(&bcolaA, vdato);
                break;
            case insertFinal:
                printf("Dato a insertar ---> ");
                scanf("%d",&vdato);
                insertarFinale(&bcolaA, vdato);
                break;
            case deleteFrente:
                vdato=eliminarFrente(&bcolaA);
                if(vdato){
                    printf("%d: Decolado...\n", vdato);
                }
                else{
                    printf("%d: No existe...\n", vdato);
                }
                break;
            case mostrar:
                mostrarBicola(&bcolaA);
                break;
            case deleteFinal:
                vdato=eliminarFinale(&bcolaA);
                if(vdato){
                    printf("%d: Decolado...\n", vdato);
                }
                else{
                    printf("%d: No existe...\n", vdato);
                }
                break;
            case deleteBicola:
                eliminarBicola(&bcolaA);
                break;
            default:
                printf("%d:Opcion invalida...\n", opc);
        }
	}while(opc != salir);
}
