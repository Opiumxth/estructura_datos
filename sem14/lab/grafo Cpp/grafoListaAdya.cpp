/**
 * nombreProg :grafoListaAdya.cpp
 * descripcion: Operaciones basicas de grafos
 *
 *                TAREA
 *    1. Analice, ejecute y comente cada una de los metodos y las instrucciones
 *    2. Elimine las variables globales (utilice parametros)
 *    3. Agregue la operacion recorrido en profundidad (dfs)
 *    4. Agregue la operacion recorrido en anchura (bfs)
 *    5. Agregue la operacion distancia mas corta para ir de una entrada a una salida
 *    6. Agregue las operaciones de salvar y recuperar.
 *    7. Investigue  acerca de las operaciones em grafos (Euler, Kruskal, Dijsktra,
 *       Prim, etc.)
 * autor: J. Fernandes
 * fecha:
 *
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

using namespace std;

struct arista {
    struct nodo *destino;//puntero al nodo de llegada
    struct arista *sgte;
};

struct nodo {
    char nombre;         //nombre  vertice o nodo
    struct nodo *sgte;
    struct arista *ady;  //puntero hacia la primera arista del nodo
};

typedef struct nodo *Tnodo;//  Tipo Nodo
typedef struct arista *Tarista; //Tipo Arista

Tnodo p;//puntero cabeza

void menu();
void insertarNodo();
void agregaArista(Tnodo &, Tnodo &, Tarista &);
void insertarArista();
void vaciarAristas(Tnodo &);
void eliminarNodo();
void eliminarArista();
void mostrarGrafo();
void mostrarAristas();

int main()
{
    menu();
    //system("pause");
    return(0);
}
void menu()
{
    p=NULL;
    int op;     // opcion del menu
    //system("color 0b");
    do {
        system("clear");
        cout<<"\n\tG R A F O S\n";
        cout<<"Operaciones basicas\n\n";
        cout<<" 0. SALIR" <<endl;
        cout<<" 1. Insertar nodo" <<endl;
        cout<<" 2. Insertar arista" <<endl;
        cout<<" 3. Eliminar nodo" <<endl;
        cout<<" 4. Eliminar arista" <<endl;
        cout<<" 5. Mostrar grafo" <<endl;
        cout<<" 6. Mostrar aristas de un nodo" <<endl;

        cout<<"\n Digite su opcion: ";
        cin>>op;
        switch(op) {
        case 0:
            cout << "El programado a terminado....\n\n";
            exit(0);
        case 1:
            insertarNodo();
            break;
        case 2:
            insertarArista();
            break;
        case 3:
            eliminarNodo();
            break;
        case 4:
            eliminarArista();
            break;
        case 5:
            mostrarGrafo();
            getchar();
            break;
        case 6:
            mostrarAristas();
            getchar();
            break;

        default:
            cout<<"Opcion na valida...!!!";
            break;
        }
        cout<<endl<<endl;
        //system("pause");
        //system("cls");
        system("clear");
    } while(op!=0);

}

/*                      INSERTAR NODO AL GRAFO
---------------------------------------------------------------------*/
void insertarNodo()
{
    Tnodo t,nuevo;
    nuevo=new struct nodo;
    cout <<"Ingrese nombre: ";
    cin  >> nuevo->nombre;
    nuevo->sgte =NULL;
    nuevo->ady=NULL;

    if(p==NULL) {  //Grafo vacio? cab=p: ir al final (ver else)
        p = nuevo;
        cout <<"Primer nodo...!!!";
    } else {
        t = p;
        //Recorre hasta el final lista de nodos
        while(t->sgte!=NULL) {
            t = t->sgte;
        }
        //Agrega un nuevo nodo al final de la lista
        t->sgte = nuevo;
        cout <<"Nodo ingresado...!!!";
    }
}

/*                      AGREGAR ARISTA
    funcion que utilizada para agregar la arista a dos nodos
---------------------------------------------------------------------*/
void agregaArista(Tnodo &aux, Tnodo &aux2, Tarista &nuevo)
{
    Tarista q;
    //Es primer arco?
    if(aux->ady==NULL) {
        aux->ady=nuevo;
        nuevo->destino=aux2;
        cout<<"Primera arista....!!!";
    }
    //Tiene nodos adyacentes, ===> ir al ultimo
    else {
        q=aux->ady;
        while(q->sgte!=NULL) {
            q=q->sgte;
        }
        nuevo->destino=aux2;
        q->sgte=nuevo;
        cout<<"Arista agregada...!!!";
    }
}
/*                      INSERTAR ARISTA
    funcion que busca las posiciones de memoria de los nodos
    y hace llamado a agregar_arista para insertar la arista
---------------------------------------------------------------------*/
void insertarArista()
{
    char ini, fin;
    //Crea un arco
    Tarista nuevo=new struct arista;
    //Nodo origen, nodo destino
    Tnodo aux, aux2;

    if(p==NULL) { // grafo vacio? salimos: continuamos
        cout<<"Grafo vaciooo...!!!";
        return;
    }
    nuevo->sgte=NULL;//arco apunta NULL
    cout <<"Ingrese nodo origen : ";
    cin  >>ini; //Nombre nodo origen
    cout <<"Ingrese nodo destino: ";
    cin  >>fin;//Nombre nodo destino
    aux=p;
    aux2=p;
    //Busca nodo deatino
    while(aux2!=NULL) {
        if(aux2->nombre==fin) {
            break;
        }
        aux2=aux2->sgte;
    }
    //Busca nodo origen, luega agrega arista
    while(aux!=NULL) {
        if(aux->nombre==ini) {
            agregaArista(aux,aux2, nuevo);
            return;
        }
        aux= aux->sgte;
    }
}

/*          FUNCION PARA BORRAR TODAS LAS ARISTAS DE UN NODO
    esta funcion es utilizada al borrar un nodo pues si tiene aristas
    es nesesario borrarlas tambien y dejar libre la memoria
---------------------------------------------------------------------*/
void vaciarAristas(Tnodo &aux)
{
    Tarista q, r;
    q=aux->ady;
    while(q->sgte!=NULL) {
        r=q;
        q=q->sgte;
        delete(r);
    }
}
/*                      ELIMINAR NODO
    funcion utilizada para eliminar un nodo del grafo
    pero para eso tambien tiene que eliminar sus aristas por lo cual
    llama a la funcion vaciar_aristas para borrarlas
---------------------------------------------------------------------*/
void eliminarNodo()
{
    char var;
    Tnodo aux,ant;
    aux=p;
    cout<<"Eliminar un nodo\n";
    if(p==NULL) {
        cout<<"Grafo vaciooo...!!!";
        return;
    }
    cout<<"Ingrese nombre: ";
    cin>>var;

    while(aux!=NULL) {
        if(aux->nombre==var) {
            if(aux->ady!=NULL) {
                vaciarAristas(aux);
            }

            if(aux==p) {
                p=p->sgte;
                delete(aux);
                cout<<"Nodo eliminado...!!!";
                return;
            } else {
                ant->sgte = aux->sgte;
                delete(aux);
                cout<<"Nodo eliminado...!!!";
                return;
            }
        } else {
            ant=aux;
            aux=aux->sgte;
        }
    }
}

/*                      ELIMINAR ARISTA
    funcion utilizada para eliminar una arista
---------------------------------------------------------------------*/
void eliminarArista()
{
    char ini, fin;
    Tnodo aux, aux2;
    Tarista q,r;
    cout<<"\n ELIMINAR ARISTA\n";
    cout<<"INGRESE NODO DE INICIO:";
    cin>>ini;
    cout<<"INGRESE NODO FINAL:";
    cin>>fin;
    aux=p;
    aux2=p;
    while(aux2!=NULL) {
        if(aux2->nombre==fin) {
            break;
        } else {
            aux2=aux2->sgte;
        }
    }
    while(aux!=NULL) {
        if(aux->nombre==ini) {
            q=aux->ady;
            while(q!=NULL) {
                if(q->destino==aux2) {
                    if(q==aux->ady) {
                        aux->ady=aux->ady->sgte;
                    } else {
                        r->sgte=q->sgte;
                    }
                    delete(q);
                    cout<<"ARISTA "<<aux->nombre<<"----->"<<aux2->nombre<<" ELIMINADA.....!!!!";
                    return;
                }
            }
            r=q;
            q=q->sgte;
        }
        aux= aux->sgte;
    }
}
/*                      MOSTRAR GRAFO
    funcion que imprime un grafo en su forma enlazada
---------------------------------------------------------------------*/
void mostrarGrafo()
{
    char c;
    Tnodo ptr;
    Tarista ar;
    ptr=p;
    system("clear");
    cout<<"\n\tG R A F O S\n";
    cout<<"Lista de Adyacencia\n\n";

    while(ptr!=NULL) {
        cout<<""<<ptr->nombre<<" ->";
        if(ptr->ady!=NULL) {
            ar=ptr->ady;
            while(ar!=NULL) {
                cout<<""<<ar->destino->nombre;
                ar=ar->sgte;
            }
        }
        ptr=ptr->sgte;
        cout<<endl;
    }
    getchar();
}

/*                      MOSTRAR ARISTAS
    funcion que muestra todas las aristas de un nodo seleccionado
---------------------------------------------------------------------*/
void mostrarAristas()
{
    Tnodo aux;
    Tarista ar;
    char var;
    cout<<"Mostrar aristas de un vertice\n";
    cout<<"Ingrese el vertice: ";
    cin>>var;
    aux = p;
    while(aux!=NULL) {
        if(aux->nombre == var) {
            if(aux->ady == NULL) {
                system("clear");
                cout<<"\n\tLISTA DE ADYACENCIA\n";
                cout<<"Aristas de un Vertice\n\n";
                cout<<"El vertice: " << var << " no tiene aristas...!!!!";
                return;
            }
            else {
                system("clear");
                cout<<"\n\tLISTA DE ADYACENCIA\n";
                cout<<"Aristas del Vertice: "<< var<<"\n\n";
                cout<<""<<aux->nombre<<"-> ";
                ar=aux->ady;
                while(ar!=NULL) {
                    cout<<ar->destino->nombre<<" ->";
                    ar=ar->sgte;
                }
                cout<<"NULL"<<endl;
                //return;
                getchar();
            }
            aux=aux->sgte;
        }
        else {
            aux=aux->sgte;
        }
    }
}
