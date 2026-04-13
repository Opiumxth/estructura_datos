/**
*  NombreProg :  MatDinamica.cpp
*  Descripcion:  Operaciones basicas de matriz dinamica
*  Autor:        GASA
*  Fecha:
*                TAREA:
*     En este caso la dimension de la Matriz, como en el caso del vector,
*     esto es, la dimension es el numero de filas y columnas ingresadas,
*     esto significa que no hay mas espacio en la matriz que el actual,
*     entonces:
*     - Analice, compile y ejecute. Luego implemente lo solicitado.
*     0. La solucion se hace utilizando los operadores new y delete de C++.
*        Implemente lo mismo pero utilizando las funciones predefinidas malloc()
*        y free() de C.como el caso de vectores
*        (Investigue acerca de apuntadores)
*     1. Como solucionar el problema si desea insertar filas o columnas a la matriz
*        si no hay mas espacion en la matriz
*        SOLUCION
*        Crea una funcion void redimensionarMatriz(...), esta funcion debe crear
*        una nueva matriz con dimension superior en filas o columnas,
*        segun sea el caso, copiar los elementos de la matriz anterior a la nueva
*        matriz, entonces ahora tendra una matriz con una fila o columna adicional,
*        segun sea el caso y ahora esta matriz sera la actual.
*        Tenga presente cuando desee hacer operaciones de insercion (insertar por
*        posicion, por valor o adicionar una fila o columna) antes de hacer esta
*        operacion, primero debe redimensionar la matriz llamando a la funcion
*        redimensionar.
*        Del mismo modo si tiene que eliminar una fila o columna, en este caso,
*        despues debe redimensionar la matriz no sumando sino restando la dimension.
*     2. Investigue sobre la funcion realloc() de C, es una funcion predefinida
*        de C parea el redimensionado y ahora implemente utilizando  esta funcion.
*
*     3. Implemente todas las operaciones basicas de matrices: (vease matrices)
*
*
*     Toda implemtacion debe ser estructurada y modular, esto es, utilizando funciones.
*
*     Entregar la siguiente clase.
*
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

void leerMatriz(int ***x, int *dxf, int *dxc);
void mostrarMatriz(int **X, int dxf, int dxc);
void eliminarMatriz(int **X, int dxf, int dxc);

int main()
{
   int **a, nfa, nca;
   leerMatriz(&a, &nfa, &nca);
   mostrarMatriz(&*a, nfa, nca);
   eliminarMatriz(&*a, nfa, nca);
   mostrarMatriz(&*a, nfa, nca);

   cout<<"\n\n";

   system("PAUSE");
   return(0);
}

void leerMatriz(int ***x, int *dxf, int *dxc)
{
   int fil, col, i, j;
   cout << "Ingrese DIMENSIONES [Fila, Columna] de la Matriz\n\n";
   cout << "NUMERO de FILAS ------> ";
   cin>>fil;
   cout << "NUMERO de COLUMNAS ---> ";
   cin>>col;
   //RUTINA DE ASIGNACION DE ESPACIO DE MEMORIA DE LA MATRIZ
   //Asignacion espacio de memoria para el ARRAY DE APUNTADORES
   *x = new int*[fil];
   if (*x == NULL){
      cout<<"No hay sufiente ESPACIO DE MEMORIA...\n"<<endl;
      system("pause");
      exit(1);
   }
   else{
      //Asignacion de espacio de memoria para cada fila
      for(i=0;i<fil;i++){
         (*x)[i] = new int [col];
         if ((*x)[i]==NULL){
            cout<<"No hay sufiente ESPACIO DE MEMORIA...\n";
            system("pause");
            exit(0);
         }
      }
      //RUTINA DE LECTURA DE LECTURA DE LA MATRIZ
      cout <<"\nIngrese los datos de la Matriz ...\n\n";
      for(i=0;i<fil;i++){
         //ANALICE EL FUNCIONAMIENTO
         for(j=0;j<col;j++){
            //printf("x[%d, %d] = ", i+1, j+1);
            //cin >>x[i][j]; // Esta forma Usual con indices
	         printf("(*(x+%d)+%d) = ", i+1, j+1);
            scanf("%d", *(*x+i)+j); // Ahora incrementando la posicion de memoria
         }
      }
      *dxf=fil;
      *dxc=col;
   }
}

void mostrarMatriz(int **x, int dxf, int dxc)
{
   int i, j;
   //RUTINA DE VISUALIZACION
   system("cls");
   if(*x==NULL){
      printf("La Matriz esta VACIA ...!\n\n");
   }
   else{
      cout <<"\nLos datos de la MATRIZ :\n\n";
      for(i=0;i<dxf;i++){
         for(j=0;j<dxc;j++){
            //*** ANALICE EL FUNCIONAMIENTO ***
            printf("%4d", x[i][j]); // Esta forma Usual con indices
            //printf("%4d", *(*(X+i)+j)); // Ahora incrementando la posicion de memoria
         }
         cout <<endl;
      }
   }
   //5
   system("PAUSE");
}

void eliminarMatriz(int **x, int dxf, int dxc)
{
   int i;
   //LIBERACION DEL ESPACIO DE MEMORIA QU NO SE USA
   //Se libera o borran las filas de la matriz
   system("cls");
   for(i=0;i<dxf;i++){
      delete [] x[i];
   }
   //Se Libera o borra el vector de punteros
   delete [] x;

   *x=NULL;
   cout <<"Se ELIMINO el espacio de memoria de la MATRIZ...!\n\n";
   system("PAUSE");
}
