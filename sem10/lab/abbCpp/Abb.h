#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

#include <iostream>

using namespace std;

template <class TD> class ABB;

template<class TD>
class Nodo {
   public:
   // Miembros de la clase nodo:
   TD dato;             // El dato a almacenar
   Nodo<TD> *izquierdo; // El puntero a la izquierda del árbol
   Nodo<TD> *derecho;   // El puntero a la derecha del árbol

   Nodo();
   //Nodo(const TD dat, Nodo<TD> *izq, Nodo<TD> *der);
   Nodo(const TD dat, Nodo<TD> *izq=NULL, Nodo<TD> *der=NULL) :
   dato(dat), izquierdo(izq), derecho(der) {}
   ~Nodo();
   friend class ABB<TD>; // Debe ser amiga de la clase lista para poder usar los nodos como parametros
   // de las funciones
};

template<class TD>
Nodo<TD>::Nodo()
{
   dato=NULL;
   izquierdo=NULL;
   derecho=NULL;
}
/*
template<class TD>
Nodo<TD>::Nodo(const TD dat, Nodo<TD> *izq, Nodo<TD> *der)
{
   dato=dat;
   izquierdo=izq;
   derecho=der;
}
*/
template<class TD>
Nodo<TD>::~Nodo()
{
   cout << "Nodo eliminado..."<<endl;
}

template<class TD>
class ABB {
   private:
   Nodo<TD> *raiz; // Declaración la raíz del árbol
   Nodo<TD> *actual; // Declaracion del nodo actual del arbol
   int contador; // Variable de tipo entero para contar la cantidad de nodos del árbol

   public:
   // Constructor de la clase
   //ABB() : raiz(NULL), actual(NULL) {}
   ABB();
   // Destructor de la clase
   //~ABB() { Podar(raiz); }
   ~ABB();
   // Inserción en un árbol ordenado:
   void Insertar(const TD dat);
   // Retorna true si el árbol está vacío, false en caso contrario:
   bool Vacio(Nodo<TD> *r) { return r==NULL; }
   // Retorna true si el nodo es hoja, false en caso contrario:
   bool EsHoja(Nodo<TD> *r) { return !r->derecho && !r->izquierdo; }
   // Cuenta el número de nodos del árbol y retorna dicho número:
   const int NumeroNodos();
   // Retorna el valor que contiene el nodo actual:
   TD &ValorActual() { return actual->dato; }
   // Mueve actual a la raíz:
   void Raiz() { actual = raiz; }
   // Recorre el árbol en InOrden
   void InOrden(void (*func)(TD&) , Nodo<TD> *nodo=NULL, bool r=true);
   // Recorre el árbol en PreOrden
   void PreOrden(void (*func)(TD&) , Nodo<TD> *nodo=NULL, bool r=true);
   // Recorre el árbol en PostOrden
   void PostOrden(void (*func)(TD&) , Nodo<TD> *nodo=NULL, bool r=true);
   // Muestra las hojas del árbol
   void MostrarHojas(void (*func)(TD&) , Nodo<TD> *nodo=NULL, bool r=true);
   // Muestra los nodos internos del árbol
   void MostrarInternos(void (*func)(TD&) , Nodo<TD> *nodo=NULL, bool r=true);

   private:
   // Función auxiliar para eliminar todos los nodos del árbol a partir de uno
   void Podar(Nodo<TD>* &);
   //Función auxiliar para contar la cantidad de nodos del árbol
   void auxContador(Nodo<TD>*);
};

template<class TD>
ABB<TD>::ABB(){
   raiz=NULL;
   actual=NULL;
}

template<class TD>
ABB<TD>::~ABB(){
   Podar(raiz);
}

template<class TD>
void ABB<TD>::Podar(Nodo<TD>* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

template<class TD>
void ABB<TD>::Insertar(const TD dat)
{
   Nodo<TD> *padre = NULL;
   actual = raiz;
   // Buscar el dato en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual)){
      padre = actual;
      if(dat >= actual->dato){
         actual = actual->derecho;
      }
      else{
         if(dat < actual->dato){
            actual = actual->izquierdo;
         }
      }
   }
   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)){
      return;
   }
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) {
      raiz = new Nodo<TD>(dat);
   }
   else{
      if(dat < padre->dato){ // Si dato menor que contine el nodo. inserta izq
         padre->izquierdo = new Nodo<TD>(dat);
      }
      // Si el dato es mayor que el que contiene el nodo padre, lo insertamos
      // en la rama derecha
      else{
         if(dat >= padre->dato){
            padre->derecho = new Nodo<TD>(dat);
         }
      }
   }
}

//**********************************************************************************************************************************//

/*
  Fecha de Creación: 13/Abril/2013
  Se recorre el árbol en PreOrden
  Durante el recorrido, se muestra el valor de cada nodo
*/
template<class TD>
void ABB<TD>::PreOrden(void (*func)(TD&), Nodo<TD> *nodo, bool r)
{
   if(r){
      nodo = raiz;
   }
   func(nodo->dato);
   if(nodo->izquierdo){
      PreOrden(func, nodo->izquierdo, false);
   }
   if(nodo->derecho) {
      PreOrden(func, nodo->derecho, false);
   }
}

//**********************************************************************************************************************************//
/*
 Fecha: 14/04/2013
 Recorrido de árbol en postorden.
 Durante el recorrido se muestra el valor de cada nodo
*/
template<class TD>
void ABB<TD>::PostOrden(void (*func)(TD&), Nodo<TD> *nodo, bool r)
{
   if(r){
      nodo = raiz;
   }  // Si r es true, el nodo es la raiz
   if(nodo->izquierdo){
      PostOrden(func, nodo->izquierdo, false);
   } // Se recorre la izquierda del nodo padre
   if(nodo->derecho){
      PostOrden(func, nodo->derecho, false);
   } // Se recorre la derecha del nodo padre
   func(nodo->dato);// Se muestra el valor del nodo
}

//**********************************************************************************************************************************//

/*
  Fecha de Creación: 14/04/2013
  Se recorre el árbol en InOrden
  Durante el recorrido, se muestra el valor de cada nodo
*/
template<class TD>
void ABB<TD>::InOrden(void (*func)(TD&) , Nodo<TD> *nodo, bool r)
{
   if(r){
      nodo = raiz;
   }  // Si r es true, el nodo es la raiz
   if(nodo->izquierdo){
      InOrden(func, nodo->izquierdo, false);
   }  // Se recorre la izquierda del nodo padre
   func(nodo->dato); // Se muestra el valor del nodo
   if(nodo->derecho){
      InOrden(func, nodo->derecho, false);
   }  // Se recorre la derecha del nodo padre
}

//**********************************************************************************************************************************//

/*
  Fecha de Creación: 14/Abril/2013
  Se recorre el árbol en preorden, la funcion func se encarga de mostrar el
  dato que contiene el nodo.
  Durante el recorrido se pregunta si el nodo es hoja.
  Si es hoja se muestra en la pantalla y se continua recorriendo el árbol
*/
template<class TD>
void ABB<TD>::MostrarHojas(void (*func)(TD&), Nodo<TD> *nodo, bool r)
{
   if(r){
      nodo = raiz;
   }  // Si r es true, el nodo es la raíz
   if (EsHoja(nodo)) {
      func(nodo->dato);
   } // Si el nodo es hoja, se muestra su valor
   if(nodo->izquierdo){
      MostrarHojas(func, nodo->izquierdo, false);
   }  // Se recorre a la izquierda del nodo padre
   if(nodo->derecho){
      MostrarHojas(func, nodo->derecho, false);
   }  // Se recorre a la derecha del nodo padre
}

//**********************************************************************************************************************************//

/*
   Fecha de Creación: 14/Abril/2013
   Se recorre el árbol en preorden, la funcion func se encarga de mostrar el
   dato que contiene el nodo.
   Durante el recorrido se pregunta si el nodo NO es hoja.
   De no ser hoja, se muestra en pantalla y se continua recorriendo el árbol
*/
template<class TD>
void ABB<TD>::MostrarInternos(void (*func)(TD&), Nodo<TD> *nodo, bool r)
{

   if(r){
      nodo = raiz;
   }  // Si r es true, el nodo es la raíz
   if(!EsHoja(nodo)) {
      func(nodo->dato);
   } // Si el nodo NO es hoja, se muestra su valo
   if(nodo->izquierdo){
      MostrarInternos(func, nodo->izquierdo, false);
   }  // Se recorre a la izquierda del nodo padre
   if(nodo->derecho){
      MostrarInternos(func, nodo->derecho, false);
   }  // Se recorre a la derecha del nodos padre
}

//**********************************************************************************************************************************//

/*
   Fecha de Creación: 13/Abril/2013
   Función para  Contar el número de nodos
   Es declarada como template para poder guardar cualquier tipo dato
   Entrada: no tiene entradas
   Salida: la cantidad de nodos que contiene el árbol.

*/

template<class TD>
const int ABB<TD>::NumeroNodos()
{
   contador = 0;
   if (raiz != NULL){ //Si se ha creado un árbol retorna la cantidad de nodos que contiene
      auxContador(raiz); // Función auxiliar de contador para realizar el conteo de los nodos
      return contador;  //retorna la cantidad de nodos que tiene el árbol
   }
   else{ //Si no se ha creado ningún árbol retorna q la cantidad de nodos es cero
      return 0;
   }
}

template<class TD>
void ABB<TD>::auxContador(Nodo<TD> *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo){
      auxContador(nodo->izquierdo);
   }  //recorrido por la izquierda
   if(nodo->derecho) {
      auxContador(nodo->derecho);
   } //recorrido por la derecha
}

//**********************************************************************************************************************************//
/*
  Fecha: 13/04/2013
  Función para mostrar el árbol.
*/
template <class TD>
void Mostrar(const TD dat)
{
   cout << dat << ","; //Imprime el dato y coloca una coma para separar cada dato.
}
#endif // ABB_H_INCLUDED
