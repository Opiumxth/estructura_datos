/**
*  NombreProg :  avlCairo.cpp
*  Descripcion:  Arbol Binario Balanceado implementado con el pseudocodigo
*                 del texto de Osvaldo Cairo.
*           Tarea
*      Analice el codigo del libro Estructura de datos (Cairo)
*			Data: 86,65,40,87,93,...
*                    86
*                   /
*                 65    ------>     65          ------>        65
*                /                 /  \                       /   \
*              40                40    86                   40     87
*                                         \                       /  \
*                                          87                   86    93
*                                            \
*                                            93
*     Recorridos.
*     Preorden :  65,40,87,86,93
*     inorden  :  40,65,86,87,93
*     Postorden:  40,86,93,87,65
*
*     Ahora se desea adaptar dicha implementacion y soporte al tipo ALUMNO,
*     por ejemplo los datos:
*
*              086 DELPARISO VALE, Adan 16
*              065 DELPARISO ELAV, Eva 18
*              040 PROKOFIEV KOLOV, Vladimir 14
*              087 MAMAGNI VIALE, Valerina 14
*              093 ZEREP GRACIA, Aladino 12
*     Luego el recorrido preorden sera:
*
*              065 DELPARISO ELAV, Eva 18
*              040 PROKOFIEV KOLOV, Vladimir 14
*              087 MAMAGNI VIALE, Valerina 14
*              086 DELPARISO VALE, Adan 16
*              093 ZEREP GRACIA, Aladino 12
*     Si hacemos la busqueda del dato 87, la salida sera:
*
*              087 MAMAGNI VIALE, Valerina 14
*
*     Se ha presentado implementacion AVL para manejo de tipo enteros,
*     ahora se requiere adaptarlo a tipo de dato registro, para lo cual usted
*     debe analizar para determinar las variables, estructuras apropiadas,
*     metodos y los algoritmos utilizando la metodologia de programacion
*     modular, se pide:
*     1. Debe implementar una libreria.h con las operaciones basicas de una
*        estructura registro de su autoria con al menos 4 campos.
*     2. La presente aplicacion debe adaptarla al manejo del tipo de dato
*        registro del paso anterior, y poder realizar las operaciones
*        basicas de arbol AVL; para esto la presente implementacion
*        AVL debe recibir un vector de registros (al menos 10 registros) y
*        con estos elementos crear o cargar el AVL y asi pode realizar las
*        operaciones basicas de dicho arbol AVL.
*      3. Implemente salvar y recuperar el arbol avl.
*
*     La solucion debe implementarse utilizando la metologia de la programacion
*     modular, la salida debe presentarse debidamente formateada con las
*     cadenas justificadas al lado izquierdo y los numericos a la derecha,
*     con encabezados, lineas de apertura y de cierre (tablas); en el programa
*     prinncipal solo debe estar la llamada al metodo que resuelve
*     el problema.
*
*  Autor: CAIRO
*  Adaptado por: GASA
*	Fecha:
*
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

using namespace std;

typedef int TD;

struct NODO {
    TD info;
    NODO *izq;
    NODO *der;
    int FE;
};

void crearArbol(NODO **raiz);
void insercionBalanceado(NODO **raiz, bool *BO, int infor);
void busqueda(NODO *nodo,int infor);
void preOrden(NODO *);
void inOrden(NODO *);
void postOrden(NODO *);
void restructura1(NODO **raiz, bool *BO);
void restructura2(NODO **raiz, bool *BO);
void borra(NODO **aux1, NODO **otro1, bool *BO);
void eliminacionBalanceado(NODO **raiz, bool *BO, int infor);
void menu();

int main()
{
    menu();

    //system("pause");
    return(0);
}

void menu()
{
    int op, dato;
    NODO *ab1, *ab2, *ab3;
    bool inicio;
    do {
        system("cls");
        cout<<"\n\n\tARBOL BINARIO BALANCEADO \n";
        cout<<"\t(pseudocodigo [Cairo 1997])\n\n";
        cout<<"\t0. SALIR\n";
        cout<<"\t1. CrearArbol\n";
        cout<<"\t2. Insertar\n";
        cout<<"\t3. Buscar\n";
        cout<<"\t4. PreOrden\n";
        cout<<"\t5. InOrden\n";
        cout<<"\t6. PostOrden\n";
        cout<<"\t7. Eliminacion\n";
        printf("\n\tDigite su opcion ---> ");
        cin>>op;

        system("cls");
        switch(op) {
        case 0:
            exit(0);
        case 1:
            cout<< "\nRUTINA DE CREACION\n\n";
            crearArbol(&ab1);
            break;
        case 2:
            cout<<"\nRUTINA DE INSERCION\n\n";
            cout<<"\nIngrese dato a insertar: ";
            cin>>dato;
            inicio = false;
            insercionBalanceado(&ab1, &inicio, dato);
            break;

        case 3:
            cout<<"\nRUTINA DE BUSQUEDA\n\n";
            cout<<"\nIngrese dato a buscar: ";
            cin>>dato;
            busqueda(ab1, dato);
            break;
        case 4:
            printf("\nRECORRIDO PREORDEN\n\n");
            printf("\nPreOrden: ");
            preOrden(ab1);
            printf("\n\n");
            system("pause");
            break;
        case 5:
            printf("\nRECORRIDO INORDEN\n\n");
            printf("\nInOrden : ");
            inOrden(ab1);
            printf("\n\n");
            system("pause");
            break;
        case 6:
            printf("\nRECORRIDO POSTORDEN\n\n");
            printf("\nPostOrden: ");
            postOrden(ab1);
            printf("\n\n");
            system("pause");
            break;
        case 7:
            cout<< "\nRUTINA DE ELIMINACION\n\n";
            cout<< "\nIngrese dato a eliminar: ";
            cin>> dato;
            inicio = false;
            eliminacionBalanceado(&ab1, &inicio, dato);
            break;
        }
    } while(op!=0);
    //}while(op<0 || op>8);
}

void crearArbol(NODO **raiz)
{
    *raiz = NULL;
}
void insercionBalanceado(NODO **raiz, bool *BO, int infor)
{
    NODO *nodo, *nodo1, *nodo2;
    nodo = *raiz;
    if(nodo != NULL) {
        if( infor < nodo->info ) {
            insercionBalanceado(&(nodo->izq), BO, infor);
            if( *BO == true ) {
                switch(nodo->FE) {
                case 1:
                    nodo->FE = 0;
                    *BO = false;
                    break;
                case 0:
                    nodo->FE = -1;
                    break;
                case -1:
                    nodo1=nodo->izq;//reestructuracion del arbol
                    if (nodo1->FE <= 0) {
                        //Rotacion II
                        nodo->izq  = nodo1->der;
                        nodo1->der = nodo;
                        nodo->FE   = 0;
                        nodo       = nodo1;
                    } else {
                        //Rotacion ID
                        nodo2 = nodo1->der;
                        nodo->izq  = nodo2->der;
                        nodo2->der = nodo;
                        nodo1->der = nodo2->izq;
                        nodo2->izq = nodo1;
                        if (nodo2->FE == -1) {
                            nodo->FE = 1;
                        }

                        else {
                            nodo->FE = 0;
                        }

                        if (nodo2->FE == 1) {
                            nodo1->FE = -1;
                        }
                        else {
                            nodo1->FE = 0;
                        }
                        nodo = nodo2;
                    }
                    nodo->FE = 0;
                    *BO = false;
                    break;
                }
            }
        } else {
            if( infor > nodo->info ) {
                insercionBalanceado(&(nodo->der),BO,infor);
                if( *BO == true ) {
                    switch(nodo->FE) {
                    case -1:
                        nodo->FE=0;
                        *BO=false;
                        break;
                    case 0:
                        nodo->FE=1;
                        break;
                    case 1:
                        nodo1=nodo->der;//reestructuracion del arbol
                        if (nodo1->FE>=0) {
                            //Rotacion DD
                            nodo->der  = nodo1->izq;
                            nodo1->izq = nodo;
                            nodo->FE   = 0;
                            nodo = nodo1;
                        } else {
                            //Rotacion DI
                            nodo2 = nodo1->izq;
                            nodo->der  = nodo2->izq;
                            nodo2->izq = nodo;
                            nodo1->izq = nodo2->der;
                            nodo2->der = nodo1;

                            if (nodo2->FE == 1) {
                                nodo->FE = -1;
                            } else {
                                nodo->FE = 0;
                            }
                            if (nodo2->FE == -1) {
                                nodo1->FE = 1;
                            } else {
                                nodo1->FE = 0;
                            }
                            nodo = nodo2;
                        }
                        nodo->FE = 0;
                        *BO = false;
                        break;
                    }
                }
            } else {
                cout<<"\nEl nodo ya se encuentra en el arbol\n"<<endl;
                system("pause");
            }
        }
    } else {
        //NODO *otro;
        nodo = new(NODO);
        nodo->izq  = NULL;
        nodo->der  = NULL;
        nodo->info = infor;
        nodo->FE = 0;
        *BO = true;
    }
    *raiz=nodo;
}

void busqueda(NODO *nodo,int infor)
{
    if(nodo!=NULL) {
        if( infor < nodo->info ) {
            busqueda(nodo->izq, infor);
        }
        else {
            if( infor > nodo->info ) {
                busqueda(nodo->der, infor);
            }
            else {
                cout<<"\nEl nodo SI se encuentra en el arbol\n"<<endl;
                system("pause");
            }
        }
    } else {
        cout<<"\nEl nodo NO se encuentra en el arbol\n"<<endl;
        system("pause");
    }
}

void preOrden(NODO *nodo)
{
    if (nodo != NULL) {
        cout<< nodo->info<<", ";
        preOrden(nodo->izq);
        preOrden(nodo->der);
    }
}

void inOrden(NODO *nodo)
{
    if (nodo != NULL) {
        inOrden(nodo->izq);
        cout<< nodo->info<<", ";
        inOrden(nodo->der);
    }
}

void postOrden(NODO *nodo)
{
    if (nodo!=NULL) {
        postOrden(nodo->izq);
        postOrden(nodo->der);
        cout<< nodo->info<<", ";
    }
}
void restructura1(NODO **raiz, bool *BO)
{
    NODO *nodo, *nodo1, *nodo2;
    nodo =* raiz;
    if ( *BO == true ) {
        switch(nodo->FE) {
        case -1:
            nodo->FE = 0;
            break;
        case 0:
            nodo->FE = 1;
            *BO=false;
            break;
        case 1:
            //reestructuracion del arbol
            nodo1=nodo->der;
            if(nodo1->FE >= 0) {
                //rotacion DD
                nodo->der  = nodo1->izq;
                nodo1->izq = nodo;
                switch (nodo1->FE) {
                case 0:
                    nodo->FE  = 1;
                    nodo1->FE = -1;
                    *BO = false;
                    break;
                case 1:
                    nodo->FE  = 0;
                    nodo1->FE = 0;
                    *BO = false;
                    break;
                }
                nodo = nodo1;
            }
            else {
                //Rotacion DI
                nodo2 = nodo1->izq;
                nodo->der  = nodo2->izq;
                nodo2->izq = nodo;
                nodo1->izq = nodo2->der;
                nodo2->der = nodo1;

                if (nodo2->FE == 1) {
                    nodo->FE =- 1;
                }
                else {
                    nodo->FE = 0;
                }
                if (nodo2->FE ==- 1) {
                    nodo1->FE = 1;
                }
                else {
                    nodo1->FE = 0;
                }
                nodo = nodo2;
                nodo2->FE = 0;
            }
            break;
        }
    }
    *raiz=nodo;
}

void restructura2(NODO **raiz, bool *BO)
{
    NODO *nodo, *nodo1, *nodo2;
    nodo = *raiz;
    if (*BO == true) {
        switch(nodo->FE) {
        case 1:
            nodo->FE = 0;
            break;
        case 0:
            nodo->FE = -1;
            *BO = false;
            break;
        case -1:
            //reestructuracion del arbol
            nodo1 = nodo->izq;
            if(nodo1->FE <= 0) {
                //rotacion II
                nodo->izq = nodo1->der;
                nodo1->der = nodo;
                switch (nodo1->FE) {
                    case 0:
                        nodo->FE = -1;
                        nodo1->FE = 1;
                        *BO = false;
                        break;
                    case -1:
                        nodo->FE = 0;
                        nodo1->FE = 0;
                        *BO = false;
                        break;
                }
                nodo = nodo1;
            }
            else {
                //Rotacion ID
                nodo2=nodo1->der;
                nodo->izq  = nodo2->der;
                nodo2->der = nodo;
                nodo1->der = nodo2->izq;
                nodo2->izq = nodo1;

                if (nodo2->FE == -1) {
                    nodo->FE = 1;
                }

                else {
                    nodo->FE = 0;
                }

                if (nodo2->FE == 1) {
                    nodo1->FE = -1;
                }

                else {
                    nodo1->FE = 0;
                }
                nodo = nodo2;
                nodo2->FE = 0;
            }
            break;
        }
    }
    *raiz = nodo;
}

void borra(NODO **aux1, NODO **otro1, bool *BO)
{
    NODO *nodo, *aux, *otro;
    aux  = *aux1;
    otro = *otro1;
    if ( aux->der != NULL ) {
        borra(&(aux->der), &otro,BO);
        restructura2(&aux, BO);
    }
    else {
        otro->info = aux->info;
        aux = aux->izq;
        *BO = true;
    }
    *aux1  = aux;
    *otro1 = otro;
}

void eliminacionBalanceado(NODO **raiz, bool *BO, int infor)
{
    NODO *nodo, *otro;
    nodo = *raiz;
    if(nodo != NULL) {
        if( infor < nodo->info ) {
            eliminacionBalanceado(&(nodo->izq), BO, infor);
            restructura1(&nodo, BO);
        }
        else {
            if(infor > nodo->info ) {
                eliminacionBalanceado(&(nodo->der), BO, infor);
                restructura2(&nodo, BO);
            }
            else {
                otro = nodo;
                if (otro->der == NULL) {
                    nodo = otro->izq;
                    *BO  = true;
                }
                else {
                    if (otro->izq == NULL) {
                        nodo = otro->der;
                        *BO = true;
                    }
                    else {
                        borra(&(otro->izq), &otro,BO);
                        restructura1(&nodo, BO);
                        delete(otro);
                    }
                }
            }
        }
    }
    else {
        cout<<"\nEl nodo NO se encuentra en el arbol\n"<<endl;
        system("pause");
    }
    *raiz = nodo;
}
