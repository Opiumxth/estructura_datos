/*
 * nomPrograma: mainAbb.cpp
 * descripcion: Teste las operaciojes basicas del abb.
 *
 *          TAREA
 * 1. Analice, luego compile, ejecute y analice los redsultados
 * 2. Comrueb todas las operaciones.
 * 3. Implemente el abb para alumnos(codigo nombre y nota) y
 *    compruebe todas las operaciones.
 * 4. Implemente los metodos salvar y recuperar.
 *
 * autor:
 * fecha:
 * version 1
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Abb.h"

using namespace std;
//Instancia a la clase ABB, para poder utilizar las funciones que tiene la misma

ABB<int> ArbolEnteros;


void menu(); //Contiene todo el menu principal, en el cual se presentan las opciones del programa.
void Crear_Arbol(); //En esta función se invocan a las funciones respectivas para crear el árbol.
void Recorrer_arbol(); //Presenta las tres opciones de recorrer el árbol, PostOrden, InOrdeen, PreOrden.
void Inserta_Elementos_Automaticamente(); //Esta función crea un tamaño de nodoa aleatorios y una lista de numero aleatoria para insertar en el árbol.

//Función main, es la función principal del archivo, la cual llama al menú y se genera todo el programa.
int main()
{
   system("color 1F");
   menu();

   system("pause");
   return(0);
}


/**
*Entradas: No recibe ninguna entrada
*Salida: Como salida se obtiene todas las opciones del
 menú principal asi como la ejecución de cada opción que el ususario desee realizar.
*Restricciones: No se presenta ninguna restricción.
*/

void menu()
{
   int opc, numNodos;
   //ABB<int> ArbolEnteros;

   do{
      cout<<"\n"<<"\t\t\tARBOL BINARIO"<<endl;
      cout<<"\n"<<"\n0.SALIR.";
      cout<<"\n"<<"\n1.Crear arbol.";
      cout<<"\n"<<"\n2.Recorrer el arbol.";
      cout<<"\n"<<"\n3.Numero cd nodos del arbol.";
      cout<<"\n"<<"\n4.Numero de hojas del arbol.";
      cout<<"\n"<<"\n5.Numero de nodos internos del arbol.";
      cout<<"\n"<<"\nDigite su opcion ---> ";
      cin >> opc;
      switch(opc){
         case 0:
            exit(0);
         case 1:
            Crear_Arbol();
            break;
         case 2:
            Recorrer_arbol();
            break;
         case 3:
            numNodos=ArbolEnteros.NumeroNodos();
            if (numNodos==0) {
               cout <<"\n"<< "Arbol vacioooo...\n";
            }
            else {
               cout<<"\n"<<"Numero de nodos: "<< numNodos<<" Nodos";
               cout<<"\n";
            }
            break;
         case 4:
            numNodos = ArbolEnteros.NumeroNodos();
            if (numNodos==0) {
               cout <<"\n"<< "Arbol vacioooo...\n";
            }
            else {
               cout<<"\n"<<"Numero de Hojas: ";
               ArbolEnteros.MostrarHojas(Mostrar);
               cout<<"\n";
            }
            break;
         case 5:
            numNodos = ArbolEnteros.NumeroNodos();
            if (numNodos==0) {
               cout <<"\n"<< "Arbol vacioooo...\n";
            }
            else {
               cout<<"\n"<<"Numero de nodos internos: ";
               ArbolEnteros.MostrarInternos(Mostrar);
               cout<<"\n";
            }
            break;
         default:
            cout <<"Opcion invalidaaaa...\n";
      }
   }while(opc!=6);

   /*

   cout<<"\n"<<"==============================================================================="<<"\n";
   cout<<"\n"<<"                                     ARBOL BINARIO                             "<<"\n";
   cout<<"\n"<<"==============================================================================="<<"\n";
   cout<<"\n"<<"\n1.Crear arbol.";
   cout<<"\n"<<"\n2.Recorrer el arbol.";
   cout<<"\n"<<"\n3.Relizar conteo de los nodos del arbol.";
   cout<<"\n"<<"\n4.Visitar y Mostrar los nodos hojas del arbol.";
   cout<<"\n"<<"\n5.Visitar y Mostrar los nodos internos del arbol.";
   cout<<"\n"<<"\n6.Salir.";

   while
   char eleccion; //Declaración de la variable eleccion, de tipo char, en la cual se almacenará la opción que escogió  el usuario.
   while (true) { // Mientras la condición se cumpla se realizará indefinidamente, "while True".
      cout<<"\n"<<"\n"<<">>>>Estimado usuario digite el numero de la operacion a realizar: "; //Se le solicita al usuario ingresar el núero de la opció que quiere realizar.
      cin>>eleccion;
      system("cls"); //Se limpia la pantalla actual, para presentar la pantalla respectiva de acuerdo a lo elegido por el usuario.
      if (eleccion == '1') { //Opción 1
         system("cls"); //Se limpia la pantalla
         Crear_Arbol(); //Se llama y muestra en pantalla a la función Crear_Arbol.
      }
      else{
         if(eleccion == '2') { //Opción 2
            system("cls");  //Se limpia la pantalla
            Recorrer_arbol(); //Se llama y muestra en pantalla a la función Recorrer_arbol.
         }
         else{
            if (eleccion == '3') {
               //Opción 3
               cout<<"\n"<<"==============================================================================="<<"\n";
               cout<<"\n"<<"                                  CANTIDAD DE NODOS                            "<<"\n";
               cout<<"\n"<<"==============================================================================="<<"\n";
               int Cantidad_nodos = ArbolEnteros.NumeroNodos();
               /*
               if (Cantidad_nodos==0) {
                  cout <<"\n"<< "No se puede mostrar la cantidad de nodos, el arbol esta vacio";
               }
               else {
                  cout<<"\n"<<"La cantidad de nodos: "<< Cantidad_nodos<<" Nodos";
                  cout<<"\n";
               }
               menu();//Se llama al menú principal.


            }
            else{
               if (eleccion == '4') { //Opción 4
                  cout<<"\n"<<"==============================================================================="<<"\n";
                  cout<<"\n"<<"                               NODOS HOJAS DEL ARBOL                           "<<"\n";
                  cout<<"\n"<<"==============================================================================="<<"\n";
                  int Cantidad_nodos = ArbolEnteros.NumeroNodos();
                  if (Cantidad_nodos==0) {
                     cout <<"\n"<< " No hay nodos hojas para mostrar, debido a que el arbol esta vacio\n";
                  }
                  else {
                     cout<<"\n"<<"VISITAR NODOS HOJAS:."<<"\n";
                     cout<<"\n"<<"Los nodos hojas han sido visitados"<<"\n";
                     cout<<"\n"<<"MOSTRAR NODOS HOJAS:"<<"\n";
                     cout<<"\n"<<"Los nodos hojas del arbol son: "<<"\n";
                     cout<<"\n";
                     cout<<">>>";
                     ArbolEnteros.MostrarHojas(Mostrar);
                     cout<<"\n";
                  }
                  menu(); //Se llama al menú principal.


               }
               else {
                  if (eleccion == '5') { //Opción 5
                     cout<<"\n"<<"==============================================================================="<<"\n";
                     cout<<"\n"<<"                               NODOS INTERNOS DEL ARBOL                           "<<"\n";
                     cout<<"\n"<<"==============================================================================="<<"\n";
                     int Cantidad_nodos = ArbolEnteros.NumeroNodos();
                     if (Cantidad_nodos==0) {
                        cout <<"\n"<< " No hay nodos internos para mostrar, debido a que el arbol esta vacio\n";
                     }
                     else {
                        cout<<"\n"<<"VISITAR NODOS INTERNOS:"<<"\n";
                        cout<<"\n"<<"Los nodos internos han sido visitados"<<"\n";
                        cout<<"\n"<<"MOSTRAR NODOS INTERNOS:"<<"\n";
                        cout<<"\n"<<"Los nodos internos del arbol son: "<<"\n";
                        cout<<"\n";
                        cout<<">>> ";
                        ArbolEnteros.MostrarInternos(Mostrar);
                        cout<<"\n";
                     }
                     menu();   //Se llama al menú principal.
                  }
                  else {
                     if(eleccion == '6') { //Opción 6
                        exit(0); //Sale del programa
                     }
                     else {
                        cout<<"==============================================================================="<<"\n";
                        cout<<"\n"<<"             ESTIMADO USUARIO LA OPCION MARCADA ES INVALIDA                    "<<"\n";
                        cout<<"\n"<<"===============================================================================";
                        menu();
                     }
                  }
               }
            }
         }
      }
   }
   */
}

//**********************************************************************************************************************************//

/**
*Entradas: No recibe ninguna entrada
*Salida: Como salida se obtiene el recorrido del árbol de alguna de las tres formas PostOrden, InOrdeen, PreOrden, o si el ususario asi lo desea le muestra las tres formas a la vez. .
*Restricciones: No se presenta ninguna restricción.
*/

//Esta función presenta las tres opciones de recorrer el árbol, PostOrden, InOrdeen, PreOrden.
void Recorrer_arbol()
{
   /**
   *Estos tres cout, se encargan de mostrar el título de RECORRIDO DEL ARBOL.
   */
   cout<<"\n"<<"==============================================================================="<<"\n";
   cout<<"\n"<<"                                RECORRIDO DEL ARBOL                          "<<"\n";
   cout<<"\n"<<"==============================================================================="<<"\n";
   /**
   *Se asigna a la variable Cantidad_nodos el numero de nodos creados en el árbol, esto se logra llamando a la función
   *NumeroNodos previamnete ya establecida en la clase ABB.
   */
   int Cantidad_nodos = ArbolEnteros.NumeroNodos();
   /**
   *Mediante este bloque de desición se evalúa, si el árbol esta vacío, que retorne en pantalla al usuario
   *que no es posible realizar el recorrio pues el árbol está vació, o bien, si el árbol no se encuentra vacío que proceda a
   *la realización del recorrido.
   */
   if (Cantidad_nodos==0) {
   cout <<"\n"<< " No se puede mostrar el recorrido del arbol porque el mismo esta vacio.\n";
   menu(); //Se llama al menú principal.
   }
   else {
      char eleccion_ordenar;  //Declaración de la variable eleccion_ordenar, de tipo char, en la cual se almacenará la opción que escogió  el usuario para el recorrido del árbol.
      /**
      *Todos estos cout, tiene la funcionalidad de presentar la caratula de lasmopciones del recorrido de los arboles.
      */
      cout<<"\n"<<"1.Recorrido Arbol PreOrden.\n" ;
      cout<<"\n"<<"2.Recorrido Arbol InOrden.\n";
      cout<<"\n"<<"3.Recorrido Arbol PostOrden.\n" ;
      cout<<"\n"<<"4.Recorrido Arbol de las tres formas anterios.\n" ;
      cout<<"\n"<<"5.Regresar al menu.\n" ;
      cout<<"\n"<<"Estimado usuario digite el numero de la operacion que desea realizar.\n";
      cin>>eleccion_ordenar;


      if(eleccion_ordenar=='1') { //Opción 1  solamente muestra el RECORRIDO PREORDEN.
         /**
         *Estos tres cout, se encargan de mostrar el título de RECORRIDO PREORDEN.
         */
         system("cls");
         cout<<"\n"<<"==============================================================================="<<"\n";
         cout<<"\n"<<"                                RECORRIDO PREORDEN                          "<<"\n";
         cout<<"\n"<<"==============================================================================="<<"\n";
         ArbolEnteros.PreOrden(Mostrar); //Llama a la función PreOrden y a su vez muestra el resultado del recorrido.
         menu(); //Se llama al menú principal.
      }
      else{
         if(eleccion_ordenar=='2') { //Opción 2 solamente muestra el RECORRIDO PREORDEN.
            /**
            *Estos tres cout, se encargan de mostrar el título de RECORRIDO PREORDEN.
            */
            system("cls");
            cout<<"\n"<<"==============================================================================="<<"\n";
            cout<<"\n"<<"                                RECORRIDO INORDEN                         "<<"\n";
            cout<<"\n"<<"==============================================================================="<<"\n";
            ArbolEnteros.InOrden(Mostrar);//Se llama a la función InOrden y a su vez muestra el resultado del recorrido.
            menu();//Se llama al menú princiapl.
         }
         else{
            if(eleccion_ordenar=='3') { //Opción 3 solamente muestra el RECORRIDO POSTORDEN.
               /**
               *Estos tres cout, se encargan de mostrar el título de  RECORRIDO POSTORDEN.
               */
               system("cls");
               cout<<"\n"<<"==============================================================================="<<"\n";
               cout<<"\n"<<"                                RECORRIDO POSTORDEN                         "<<"\n";
               cout<<"\n"<<"==============================================================================="<<"\n";
               ArbolEnteros.PostOrden(Mostrar);//Se llama a la función PostOrden y a su vez muestra el resultado del recorrido.
               menu();//Se llama al menú princiapl.
            }
            else
               if(eleccion_ordenar=='4') {
                  //Opción 4 Muestra los tres tipos de recorrido

               /**
               *Estos tres cout, se encargan de mostrar el título de RECORRIDO PREORDEN.
               */
               system("cls");
               cout<<"\n"<<"==============================================================================="<<"\n";
               cout<<"\n"<<"                                RECORRIDO PREORDEN                          "<<"\n";
               cout<<"\n"<<"==============================================================================="<<"\n";
               ArbolEnteros.PreOrden(Mostrar); //Llama a la función PreOrden y a su vez muestra el resultado del recorrido.
               cout<<"\n";
               cout<<"\n";

               /**
               *Estos tres cout, se encargan de mostrar el título de RECORRIDO PREORDEN.
               */
               cout<<"\n"<<"==============================================================================="<<"\n";
               cout<<"\n"<<"                                RECORRIDO INORDEN                         "<<"\n";
               cout<<"\n"<<"==============================================================================="<<"\n";
               ArbolEnteros.InOrden(Mostrar);//Se llama a la función InOrden y a su vez muestra el resultado del recorrido.

               cout<<"\n";
               cout<<"\n";
               /**
               *Estos tres cout, se encargan de mostrar el título de  RECORRIDO POSTORDEN.
               */
               cout<<"\n"<<"==============================================================================="<<"\n";
               cout<<"\n"<<"                                RECORRIDO POSTORDEN                         "<<"\n";
               cout<<"\n"<<"==============================================================================="<<"\n";
               ArbolEnteros.PostOrden(Mostrar);//Se llama a la función PostOrden y a su vez muestra el resultado del recorrido.
               cout<<"\n";
               cout<<"\n";
               menu(); //Se llama al menú principal.
            }
            else{
               if(eleccion_ordenar=='5') { //Opción 5 Regresa al menú principal.
                  system("cls"); //Se limpia la pantalla.
                  menu();//Se llama al menú principal.
               }
               else {
                  system("cls");
                  cout<<"==============================================================================="<<"\n";
                  cout<<"\n"<<"             ESTIMADO USUARIO LA OPCION MARCADA ES INVALIDA                    "<<"\n";
                  cout<<"\n"<<"===============================================================================";
                  Recorrer_arbol();//Se llama al menú principal del recorrido de arboles.
               }
            }
         }

      }
   }
}


//**********************************************************************************************************************************//

/**
*Entradas: No recibe ninguna entrada
*Salida: Como salida se obtiene la creación del árbol con sus respectivos nodos.
*Restricciones: No se presenta ninguna restricción.
*/

//En esta función se invocan a las funciones respectivas para crear el árbol, además esta función presenta dos formas de crear el árbol.
void Crear_Arbol()
{
   ArbolEnteros.~ABB(); //Se llama al destructor para de la clase ABB para que destruya todos los valores y se generen de nuevo cada vez que se crea un árbol
   /**
   *Todos estos cout, tiene la funcionalidad de presentar la caratula del menú crear árbol.
   */
   cout<<"\n";
   cout<<"\n"<<"==============================================================================="<<"\n";
   cout<<"\n"<<"                                     CREAR ARBOL                               "<<"\n";
   cout<<"\n"<<"==============================================================================="<<"\n";
   cout<<"\n"<<"1.Crear arbol de forma manual.\n";
   cout<<"\n"<<"2.Crear arbol de forma automatica.\n" ;
   cout<<"\n"<<"3.Regresar al menu.\n" ;

   char eleccion;//Declaración de la variable eleccion, de tipo char, en la cual se almacenará la opción que escogió  el usuario.
   while (true) { // Mientras la condición se cumpla se realizará ndefinidamente, "while True"
      cout<<"\n"<<"\n"<<">>>>Estimado usuario digite el numero de la operacion a realizar: ";//Se le solicita al usuario ingresar el número de la opción que quiere realizar.
      cin>>eleccion;

      if (eleccion == '1') { //Opción 1. Mediante este if se evalúa la operación de creación de un árbol de forma manual.
         system("cls");//Se limpia la pantalla

         int n;  // numero de nodos del arbol
         int dato; // elemento a insertar en cada nodo
         /**
         *Estos tres cout, se encargan de mostrar el título de CREAR ARBOL MANUALMENTE.
         */
         cout<<"\n"<<"==============================================================================="<<"\n";
         cout<<"\n"<<"                                  CREAR ARBOL MANUALMENTE                      "<<"\n";
         cout<<"\n"<<"==============================================================================="<<"\n";
         cout << " Ingrese el numero de nodos deseados para el arbol:  ";//Se le solicita al ususario que ingrese cuantos nodos desea crear.
         cin >> n;
         cout << endl;
         /**
         Mediante este for se va solicitando al usuario los números que desea ingresar al árbol,
         *y el for es para solicitar la cantidad de números de acuerdo a la cantidad de nodos indicada previamente.
         */
         for(int i=0; i<n; i++) {
            cout << " Ingrese el numero " << i+1 << " : ";
            cin >> dato;
            ArbolEnteros.Insertar(dato); //Se va insertando a cada a lod nodos el némero que el usuario va digitando.
         }
         menu();

      }
      /**
      *Opción 2. Mediante este if se evalúa la operación de creación de un árbol de forma automática.
      *NOTA:
      *Llamecé automático a la forma que el programa genera de forma aleatoria, el tamaño del árbol y la lista de números.
      */
      else {
         if (eleccion == '2') {
            system("cls");
            /**
            *Estos tres cout, se encargan de mostrar el título de  CREAR ARBOL AUTOMATICAMENTE.
            */
            cout<<"\n"<<"==============================================================================="<<"\n";
            cout<<"\n"<<"                              CREAR ARBOL AUTOMATICAMENTE                     "<<"\n";
            cout<<"\n"<<"==============================================================================="<<"\n";
            Inserta_Elementos_Automaticamente(); //Se llama a la función Inserta_Elementos_Automaticamente la cual genera de forma aleatoria, el tamaño del árbol y la lista de números.
            menu();
         }
         else{
            if(eleccion == '3') { //Opció 3
               system("cls"); //Limpia la pantalla
               menu(); //Llama al menú principal
            }
            /**
            *Este else cumple la función de informarle al usuario que la opcion que ha marcado es incorrecta para que él mismo
            *marque de nuevo una opción válida.
            *NOTA:
            *    Llamece opción inválida al digitar un numero que no sea del 1 al 6 ó algúna letra o caracter.
            */
            else {
               cout<<"==============================================================================="<<"\n";
               cout<<"\n"<<"             ESTIMADO USUARIO LA OPCION MARCADA ES INVALIDA                    "<<"\n";
               cout<<"\n"<<"===============================================================================";
               system("cls");
               Crear_Arbol();//Se llama al menú principal.
            }
         }
      }
   }
}

//**********************************************************************************************************************************//
/**
*Fecha: 13/04/2013
*Hora: 5:00PM
*Entradas: No recibe ninguna entrada
*Salida: Como salida se obtiene el tamaño alaeatorio del árbol y los números aleatorios para dicho árbol.
*Restricciones: No se presenta ninguna restricción.
*/

//Esta función crea un tamaño de nodo aleatorios y una lista de números aleatoria para insertar en el árbol.
void Inserta_Elementos_Automaticamente()
{
   int tamano = rand() % 100; //Genera el número de nodos de forma aleatoria en un rango de 0 a 100.
   /**
   *Estos tres cout, se encargan de mostrar el título de  LISTA DE NUMEROS A INSERTAR EN EL ARBOL.
   */
   cout<<"\n"<<"==============================================================================="<<"\n";
   cout<<"\n"<<"                  LISTA DE NUMEROS A INSERTAR EN EL ARBOL                      "<<"\n";
   cout<<"\n"<<"==============================================================================="<<"\n";
   cout<<"\n";
   //Mediante este ciclo de for se genera de forma aleatoria los numeros a insertar en el árbol, el for es utilizado para generar la cantidad de nuemros de acuerdo al tmaño del árbol.
   for (int i = 0; i < tamano; i++) {
      int numero = rand() % 100;
      cout << numero << ",";
      ArbolEnteros.Insertar(numero);//Se insertan en cada nodo, cada número que s eva generando.
   }
}
