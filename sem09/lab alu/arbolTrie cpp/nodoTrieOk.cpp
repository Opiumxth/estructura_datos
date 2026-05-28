/*
 * nomPrograma: nodoTrieOk.cpp
 * descripcion: Operaciones basicas de trie
 *          TAREA
 *    1. Analice y compile POO em C++ y como ejercicio paselo a Java
 *    2. El programa utiliza la colecion vector para simplificar la implemntacion
 *       vea las operaciones en http://www.cplusplus.com/reference/vector/vector/at/
 *    3. Complete el metodo elimina cadena
 *    4. Implemente la operacion editar y mostrar cadenas.
 *    5. Basado en esto implemente una aplicacion diccionario
 *    6. Ahora haga analisis comparativo con el programa trie en C++ que se
 *       le dio primero. Hay error de aplicacion de objetos y registros.
 *
 *    Investigue acerca de la clase vector y string, vector.size, string.length.
 *    Como sabran Java ha adoptado todo esto.
 * autor:
 * fecha:
 *
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Nodo {
   private:
      char mcar;
      bool mfin;
      vector<Nodo*> mhijos;

   public:
      //Los metodos implementados dentro de la clase se denominan
      // metodos en linea se supone que son mas veloces que los otros
      //Constructor en linea
      Nodo() {
         mcar = ' ';
         mfin = false;
      }
      //Destructor
      ~Nodo() {}
      char caracter() { return mcar; }
      void setCaracter(char car) { mcar = car; }
      bool finCadena() { return mfin; }
      void setFinCadena() {mfin = true; }
      Nodo* buscarHijos(char car);
      //Investuigue acerca de las operaciones de vector
      void adicionaHijos(Nodo* hijo) {
         mhijos.push_back(hijo); //adiciona al final del vector
      }
      vector<Nodo*> hijos() { return mhijos; }
};

class Trie {
   private:
      Nodo *raiz;
   public:
      Trie();
      ~Trie();
      void adicionaCad(string s);
      bool buscaCad(string s);
      void eliminaCad(string s);
};

Nodo* Nodo::buscarHijos(char car)
{
   Nodo* tmp;
   int i;
   for (i=0;i<mhijos.size(); i++){
      tmp = mhijos.at(i);//Que es y que hace at?:Devuelve elemento posicion i
      if(tmp->caracter()==car){
         return tmp;
      }
   }
   return NULL;
}

Trie::Trie()
{
   raiz=new Nodo();
}

Trie::~Trie()
{
   delete raiz;
}

void Trie::adicionaCad(string s)
{
   Nodo* p = raiz;
   int i;
   if(s.length()==0){
      p->setFinCadena(); // an empty word
      return;
   }
   for(i=0;i<s.length();i++){
      Nodo* hijo=p->buscarHijos(s[i]);
      if(hijo!=NULL){
         p=hijo;
      }
      else{
         Nodo* tmp=new Nodo();
         tmp->setCaracter(s[i]);
         p->adicionaHijos(tmp);
         p=tmp;
      }
      if(i==s.length()-1){
         p->setFinCadena();
      }
   }
}

bool Trie::buscaCad(string s)
{
   Nodo* p = raiz;
   Nodo* tmp;
   int i;
   while(p!=NULL){
      for(i=0;i<s.length();i++ ){
         //Nodo* tmp = p->buscarHijos(s[i]);
         tmp=p->buscarHijos(s[i]);
         if(tmp==NULL){
            return false;
         }
         p=tmp;
      }

      if(p->finCadena()){
         return true;
      }
      else{
         return false;
      }
   }
   return false;
}

int main()
{
   Trie* trie = new Trie();

   trie->adicionaCad("ganar");
   trie->adicionaCad("gancho");
   trie->adicionaCad("gandula");
   trie->adicionaCad("ganga");
   trie->adicionaCad("ganglio");
   //Tipo de dato cadena de C++ Vea la documentacion
   string c1 = "ganar";
   string c2 = "gancho";
   string c4 = "gango";
   string c5 = "ganglio";

   if ( trie->buscaCad("gandula")){
      cout << "Se encontro gandula" << endl;
   }
   else{
      cout << "No se encontro gandula \n";
   }

   if ( trie->buscaCad(c2)){
      cout << "Se encontro "<< c2<< endl;
   }
   else{
      cout << "No se encontro" << c2 <<"\n";
   }

   if ( trie->buscaCad(c4)){
      cout << "Se encontro "<< c4<< endl;
   }
   else{
      cout << "No se encontro " << c4 <<"\n";
   }

   delete trie;
   cout <<endl <<"El arbol trie ha sido destruido...! " <<endl <<endl;
   // Si tratan de buscar despues destruir el arbol trie. Que ocurre?
   system("pause");
   return(0);
}
