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

using namespace std;
struct Nodo{
    int elemento;
    Nodo *siguiente;
};
class CircularQueue
{
private :
    // Puntero frontal de cola
    Nodo* frente;

    // Puntero trasero de la cola
    Nodo* trasero;

public :
    // Constructor
    CircularQueue () : frontal ( NULL ) , posterior ( NULL ) {}

    // Poner en cola el nuevo elemento
    void enqueue ( int elemento ) ;

    // Sacar un elemento de la cola
    int desencolar () ;
    // Devuelve el elemento superior sin eliminarlo
    int vistazo () ;

    // Imprimir la cola
    void display ( string msg ) ;

    //Comprueba si la cola está vacía
    bool estáVacío () ;
} ;
// Poner en cola el nuevo elemento
void CircularQueue:: enqueue ( int elemento ) {
    // Paso 1. Crear el nuevo nodo
    Nodo* nodo = new Nodo () ;
    if ( nodo == NULL ) {
        cout << "Sistema sin memoria" << endl;
        devolver ;
    }
    nodo->elemento=elemento;

    // Paso 2. Conecte el nuevo nodo en el lado trasero
    if ( trasero == NULL ) {
        // Paso 2.A. Si la cola está vacía, configure el frente para que apunte al nuevo nodo.
        frente=nodo;
    } else {
        // Paso 2.B. De lo contrario, conecte el nuevo nodo después del trasero.
        trasero- > siguiente = nodo;
    }

    // Paso 3. Conecta el nuevo nodo al Frente y forma el círculo
    nodo-> siguiente=frente;

    // Paso 4. Cambia la parte trasera para apuntar al nuevo nodo
    parte trasera = nodo;
}
// Sacar un elemento de la cola
int CircularQueue:: sacar de la cola () {
    //Comprueba si la cola está vacía
    si ( frente == NULL ) {
        devuelve -1;
    }

    // Paso 1. Recuperar el elemento en Front
    int elemento = front- > elemento;

    // Paso 2. Recordar el nodo frontal en un puntero temporal
    Nodo* tmp = frente;

    // Paso 3. Desconectar el nodo frontal
    si ( front- > next == NULL ) {
        // Paso 3.A. Si el siguiente nodo no está disponible, configure Front y Rear para que apunten a NULL
        delantero = trasero = NULL ;
    } demás {
        // Paso 3.B. De lo contrario, cambie el Frente para apuntar al siguiente nodo
        // y vincular el Trasero para apuntar el nuevo nodo Delantero para formar un círculo.
        frente = frente- > siguiente;
        trasero- > siguiente = delantero;
    }

    // Paso 4: Eliminar el nodo almacenado en el puntero temporal
    eliminar tmp;

    elemento de retorno ;
}
// Devuelve el elemento superior sin eliminarlo
int CircularQueue:: peek () {
    if ( estáVacío ()) {
        devuelve -1;
    }
    retorna frontal- > elemento;
}
// Imprimir la cola
void CircularQueue:: mostrar ( cadena msg ) {
    cout << mensaje << fin;
    if ( estáVacío ()) {
        devolver ;
    }

    if ( delantero == trasero ) {
        cout << front-> elemento << " <-- delantero, trasero" << endl;

    } else {
        cout << front- > elemento << " <-- front" << endl;
        para ( Nodo* nodo=delantero-> siguiente; nodo != trasero; nodo = nodo- > siguiente ) {
            cout << nodo-> elemento << endl;
        }
        cout << trasero-> elemento << " <-- trasero" ;
    }

    if ( trasero-> siguiente == delantero ) {
        cout << " (vinculado al frente)" << endl;
    }
}
//Comprueba si la cola está vacía
bool CircularQueue:: estáVacía () {
    if ( frente == NULL ) {
        cout << "La cola está vacía" << endl;
        return verdadero ;
    }
    return falso ;
}
//La función principal para iniciar la ejecución
int main ()
{
    // Crear una cola
    Cola CircularQueue;

    // Empuja los elementos (10, 20, 30, 40 y 50)
    cola.enqueue ( 10 ) ;​
    cola.enqueue ( 20 ) ;​
    cola.enqueue ( 30 ) ;​
    cola.enqueue ( 40 ) ;​
    cola.enqueue ( 50 ) ;​
    cola.display ( "Cola después de insertar 10 20 30 40 y 50" ) ;

    // Obtener el elemento peek
    int elemento = cola.peek ( ) ;
    cout << "Elemento Peek devuelto " << elemento << endl;

    // Extrae los elementos de la cola
    elemento = cola.dequeue ( ) ;
    cout << "Elemento de cola devuelto " << elemento << endl;
    elemento = cola.dequeue ( ) ;
    cout << "Elemento de cola devuelto " << elemento << endl;
    cola.display ( "Cola después de eliminar dos elementos" ) ;
}

    system("pause");
    return 0;
}

//implmentacion prototipos de funcion
