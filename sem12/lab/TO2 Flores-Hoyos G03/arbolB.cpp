/**
*  nomPrograma: arbolBLab.cpp
*  Descripcion: Arbol B adaptado para trabajar con archivo de indices
*
*  Base: arbolBLab.cpp del profesor. Se conserva la estructura
*  del nodo, insertar, buscar y eliminar. La unica adaptacion real es que
*  la clave del arbol ahora es un CodIndex (idPedido + dirLog) en vez de
*  un entero suelto, para poder ubicar el registro real en el .dat.
*
*  Flujo: regVentasProd.csv -> vector de registros -> regVentasProd.dat
*         y fileIndices.dat -> Arbol B (cargado desde el indice) ->
*         busqueda por arbol (fseek directo) vs busqueda secuencial.
*
*  autor: Flores Hoyos, MAthias (adaptado)
*  fecha: 2026
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <chrono>

#define m 5

using namespace std;

//----------------------------------------
// Registro de venta (campos del CSV)
struct RegVentaProd {
   char   idCliente[12];
   char   zona[40];
   char   pais[40];
   char   tipoProducto[40];
   int    idPedido;
   int    unidades;
   double precioUnitario;
   double costeUnitario;
   double importeVentaTotal;
   double importeCosteTotal;
};

// Registro de indice: clave de busqueda + direccion logica en el .dat
struct CodIndex {
   int  idPedido;
   long dirLog;
};

bool operator<(const CodIndex& a, const CodIndex& b)  { return a.idPedido <  b.idPedido; }
bool operator==(const CodIndex& a, const CodIndex& b) { return a.idPedido == b.idPedido; }

//----------------------------------------
// El arbol B trabaja unicamente con registros indice (CodIndex)
typedef CodIndex tipoClave;

typedef struct pagina {
   tipoClave claves[m];
   struct pagina *ramas[m];
   int cuenta;
} Pagina;

//----------------------------------------
// ---- Nucleo del Arbol B (igual al laboratorio del profesor) ----
void crearArbolB(Pagina **raiz);
Pagina *buscar(Pagina *actual, tipoClave cl, int *k);
void insertar(Pagina **raiz, tipoClave cl);
void eliminar(Pagina **raiz, tipoClave cl);

int nodoLLeno(Pagina* actual);
int nodoSemiVacio(Pagina* actual);
void escribeNodo(Pagina* actual);

int buscarNodo(Pagina* actual, tipoClave cl, int* k);
void empujar(Pagina* actual, tipoClave cl, int* subeArriba, tipoClave* mediana, Pagina** nuevo);
void meterHoja(Pagina* actual, tipoClave cl, Pagina* rd, int k);
void dividirNodo(Pagina* actual, tipoClave cl, Pagina* rd, int k, tipoClave* mediana, Pagina** nuevo);
void eliminarRegistro(Pagina* actual, tipoClave cl, int* encontrado);
void quitar(Pagina* actual, int k);
void sucesor(Pagina* actual, int k);
void restablecer(Pagina* actual, int k);
void moverDrcha(Pagina* actual, int k);
void moverIzqda(Pagina* actual, int k);
void combina(Pagina* actual, int k);
void listarCreciente(Pagina* actual);

// ---- Salvar / Recuperar el arbol ----
void salvarNodo(Pagina* actual, FILE* f);
void Salvar(Pagina* raiz, const char* archivo);
void Recuperar(Pagina** raiz, const char* archivo);

// ---- CSV / archivos de datos e indices ----
void quitarSalto(char* s);
bool parsearLinea(char* linea, RegVentaProd& r);
void leerCSV(const char* archivo, vector<RegVentaProd>& regs);
void mostrarRegistros(const vector<RegVentaProd>& regs);
void mostrarRegistro(const RegVentaProd& r);
void crearDatVentas(const vector<RegVentaProd>& regs, const char* archivo);
void crearFileIndices(const vector<RegVentaProd>& regs, const char* archivo);
void construirArbolDesdeIndice(Pagina** raiz, const char* archivo);

// ---- Busquedas y comparacion ----
void buscarPorArbolMenu(Pagina* raiz, const char* datFile);
void buscarSecuencialMenu(const char* datFile);
void compararBusquedas(Pagina* raiz, const char* datFile);

void menu();

int main()
{
   menu();
   return 0;
}

//============================================================
//  NUCLEO DEL ARBOL B (adaptado del laboratorio del profesor)
//============================================================
void crearArbolB(Pagina **raiz)
{
   *raiz = NULL;
}

Pagina* buscar(Pagina* actual, tipoClave cl, int* indice)
{
   if (actual == NULL) {
      return NULL;
   } else {
      int esta = buscarNodo(actual, cl, indice);
      if (esta)
      { return actual; }
      else
      { return buscar(actual->ramas[*indice], cl, indice); }
   }
}

void insertar(Pagina **raiz, tipoClave cl)
{
   int subeArriba;
   tipoClave mediana;
   Pagina *p, *nd;

   empujar(*raiz, cl, &subeArriba, &mediana, &nd);

   if (subeArriba) {
      p = (Pagina*) malloc(sizeof(Pagina));
      p->cuenta = 1;
      p->claves[1] = mediana;
      p->ramas[0] = *raiz;
      p->ramas[1] = nd;
      *raiz = p;
   }
}

void eliminar(Pagina **raiz, tipoClave cl)
{
   int encontrado;

   eliminarRegistro(*raiz, cl, &encontrado);
   if (encontrado) {
      printf("Clave %d eliminada\n", cl.idPedido);
      if ((*raiz)->cuenta == 0) {
         Pagina* p = *raiz;
         *raiz = (*raiz)->ramas[0];
         free(p);
      }
   } else
   { puts("La clave no se encuentra en el arbol\n"); }
}

int nodoLLeno(Pagina* actual)
{
   return (actual->cuenta == m - 1);
}

int nodoSemiVacio(Pagina* actual)
{
   return (actual->cuenta < m / 2);
}

void escribeNodo(Pagina* actual)
{
   int k;
   printf("\n Nodo: ");
   for (k = 1; k <= actual->cuenta; k++)
   { printf(" %d ", actual->claves[k].idPedido); }
   printf("\n");
}

int buscarNodo(Pagina* actual, tipoClave cl, int* k)
{
   int encontrado;

   if (cl < actual->claves[1]) {
      encontrado = 0;
      *k = 0;
   } else {
      *k = actual->cuenta;
      while ((cl < actual->claves[*k]) && (*k > 1))
      { (*k)--; }
      encontrado = (cl == actual->claves[*k]);
   }
   return encontrado;
}

void empujar(Pagina* actual, tipoClave cl, int* subeArriba, tipoClave* mediana, Pagina** nuevo)
{
   int k;

   if (actual == NULL) {
      *subeArriba = 1;
      *mediana = cl;
      *nuevo = NULL;
   } else {
      int esta = buscarNodo(actual, cl, &k);

      if (esta) {
         puts("\nClave duplicada");
         *subeArriba = 0;
         return;
      }

      empujar(actual->ramas[k], cl, subeArriba, mediana, nuevo);

      if (*subeArriba) {
         if (nodoLLeno(actual))
         { dividirNodo(actual, *mediana, *nuevo, k, mediana, nuevo); }
         else {
            *subeArriba = 0;
            meterHoja(actual, *mediana, *nuevo, k);
         }
      }
   }
}

void meterHoja(Pagina* actual, tipoClave cl, Pagina* rd, int k)
{
   int i;
   for (i = actual->cuenta; i >= k + 1; i--) {
      actual->claves[i + 1] = actual->claves[i];
      actual->ramas[i + 1] = actual->ramas[i];
   }
   actual->claves[k + 1] = cl;
   actual->ramas[i + 1] = rd;
   actual->cuenta++;
}

void dividirNodo(Pagina* actual, tipoClave cl, Pagina* rd, int k, tipoClave* mediana, Pagina** nuevo)
{
   int i, posMdna;

   posMdna = (k <= m / 2) ? m / 2 : m / 2 + 1;

   (*nuevo) = (Pagina*) malloc(sizeof(Pagina));
   for (i = posMdna + 1; i < m; i++) {
      (*nuevo)->claves[i - posMdna] = actual->claves[i];
      (*nuevo)->ramas[i - posMdna] = actual->ramas[i];
   }
   (*nuevo)->cuenta = (m - 1) - posMdna;
   actual->cuenta = posMdna;

   if (k <= m / 2)
   { meterHoja(actual, cl, rd, k); }
   else
   { meterHoja(*nuevo, cl, rd, k - posMdna); }

   *mediana = actual->claves[actual->cuenta];
   (*nuevo)->ramas[0] = actual->ramas[actual->cuenta];
   actual->cuenta--;
}

void eliminarRegistro(Pagina* actual, tipoClave cl, int* encontrado)
{
   int k;

   if (actual != NULL) {
      *encontrado = buscarNodo(actual, cl, &k);
      if (*encontrado) {
         if (actual->ramas[k - 1] == NULL)
         { quitar(actual, k); }
         else {
            sucesor(actual, k);
            eliminarRegistro(actual->ramas[k], actual->claves[k], encontrado);
         }
      } else {
         eliminarRegistro(actual->ramas[k], cl, encontrado);
      }

      if (actual->ramas[k] != NULL)
         if (actual->ramas[k]->cuenta < m / 2)
         { restablecer(actual, k); }
   } else
   { *encontrado = 0; }
}

void quitar(Pagina* actual, int k)
{
   int j;
   for (j = k + 1; j <= actual->cuenta; j++) {
      actual->claves[j - 1] = actual->claves[j];
      actual->ramas[j - 1] = actual->ramas[j];
   }
   actual->cuenta--;
}

void sucesor(Pagina* actual, int k)
{
   Pagina* q = actual->ramas[k];
   while (q->ramas[0] != NULL)
   { q = q->ramas[0]; }
   actual->claves[k] = q->claves[1];
}

void restablecer(Pagina* actual, int k)
{
   if (k > 0)
      if (actual->ramas[k - 1]->cuenta > m / 2)
      { moverDrcha(actual, k); }
      else
      { combina(actual, k); }
   else
      if (actual->ramas[1]->cuenta > m / 2)
      { moverIzqda(actual, 1); }
      else
      { combina(actual, 1); }
}

void moverDrcha(Pagina* actual, int k)
{
   int j;
   Pagina* nodoProblema = actual->ramas[k];
   Pagina* nodoIzqdo = actual->ramas[k - 1];

   for (j = nodoProblema->cuenta; j >= 1; j--) {
      nodoProblema->claves[j + 1] = nodoProblema->claves[j];
      nodoProblema->ramas[j + 1] = nodoProblema->ramas[j];
   }
   nodoProblema->cuenta++;
   nodoProblema->ramas[1] = nodoProblema->ramas[0];
   nodoProblema->claves[1] = actual->claves[k];

   actual->claves[k] = nodoIzqdo->claves[nodoIzqdo->cuenta];
   nodoProblema->ramas[0] = nodoIzqdo->ramas[nodoIzqdo->cuenta];
   nodoIzqdo->cuenta--;
}

void moverIzqda(Pagina* actual, int k)
{
   int j;
   Pagina* nodoProblema = actual->ramas[k - 1];
   Pagina* nodoDrcho = actual->ramas[k];

   nodoProblema->cuenta++;
   nodoProblema->claves[nodoProblema->cuenta] = actual->claves[k];
   nodoProblema->ramas[nodoProblema->cuenta] = nodoDrcho->ramas[0];

   actual->claves[k] = nodoDrcho->claves[1];
   nodoDrcho->ramas[1] = nodoDrcho->ramas[0];
   nodoDrcho->cuenta--;

   for (j = 1; j <= nodoDrcho->cuenta; j++) {
      nodoDrcho->claves[j] = nodoDrcho->claves[j + 1];
      nodoDrcho->ramas[j] = nodoDrcho->ramas[j + 1];
   }
}

void combina(Pagina* actual, int k)
{
   int j;
   Pagina* q = actual->ramas[k];
   Pagina* nodoIzqdo = actual->ramas[k - 1];

   nodoIzqdo->cuenta++;
   nodoIzqdo->claves[nodoIzqdo->cuenta] = actual->claves[k];
   nodoIzqdo->ramas[nodoIzqdo->cuenta] = q->ramas[0];

   for (j = 1; j <= q->cuenta; j++) {
      nodoIzqdo->cuenta++;
      nodoIzqdo->claves[nodoIzqdo->cuenta] = q->claves[j];
      nodoIzqdo->ramas[nodoIzqdo->cuenta] = q->ramas[j];
   }

   for (j = k; j <= actual->cuenta - 1; j++) {
      actual->claves[j] = actual->claves[j + 1];
      actual->ramas[j] = actual->ramas[j + 1];
   }
   actual->cuenta--;

   free(q);
}

void listarCreciente(Pagina* actual)
{
   if (actual != NULL) {
      int j;
      listarCreciente(actual->ramas[0]);
      for (j = 1; j <= actual->cuenta; j++) {
         printf("%d(%ld) \t", actual->claves[j].idPedido, actual->claves[j].dirLog);
         listarCreciente(actual->ramas[j]);
      }
   }
}

//============================================================
//  SALVAR / RECUPERAR ARBOL
//============================================================
void salvarNodo(Pagina* actual, FILE* f)
{
   if (actual != NULL) {
      salvarNodo(actual->ramas[0], f);
      for (int j = 1; j <= actual->cuenta; j++) {
         fwrite(&actual->claves[j], sizeof(CodIndex), 1, f);
         salvarNodo(actual->ramas[j], f);
      }
   }
}

void Salvar(Pagina* raiz, const char* archivo)
{
   FILE* f = fopen(archivo, "wb");
   if (!f) { printf("No se pudo crear %s\n", archivo); return; }
   salvarNodo(raiz, f);
   fclose(f);
   printf("Arbol salvado en %s\n", archivo);
}

void Recuperar(Pagina** raiz, const char* archivo)
{
   FILE* f = fopen(archivo, "rb");
   if (!f) { printf("No existe %s\n", archivo); return; }

   crearArbolB(raiz);
   CodIndex ci;
   int n = 0;
   while (fread(&ci, sizeof(CodIndex), 1, f) == 1) {
      insertar(raiz, ci);
      n++;
   }
   fclose(f);
   printf("Arbol recuperado desde %s (%d claves)\n", archivo, n);
}

//============================================================
//  CSV -> VECTOR -> .dat / fileIndices.dat
//============================================================
void quitarSalto(char* s)
{
   size_t l = strlen(s);
   while (l > 0 && (s[l - 1] == '\n' || s[l - 1] == '\r'))
   { s[--l] = '\0'; }
}

bool parsearLinea(char* linea, RegVentaProd& r)
{
   char* token = strtok(linea, ",");
   if (!token) return false;
   strncpy(r.idCliente, token, sizeof(r.idCliente) - 1); r.idCliente[sizeof(r.idCliente) - 1] = 0;

   token = strtok(NULL, ","); if (!token) return false;
   strncpy(r.zona, token, sizeof(r.zona) - 1); r.zona[sizeof(r.zona) - 1] = 0;

   token = strtok(NULL, ","); if (!token) return false;
   strncpy(r.pais, token, sizeof(r.pais) - 1); r.pais[sizeof(r.pais) - 1] = 0;

   token = strtok(NULL, ","); if (!token) return false;
   strncpy(r.tipoProducto, token, sizeof(r.tipoProducto) - 1); r.tipoProducto[sizeof(r.tipoProducto) - 1] = 0;

   token = strtok(NULL, ","); if (!token) return false;
   r.idPedido = atoi(token);

   token = strtok(NULL, ","); if (!token) return false;
   r.unidades = atoi(token);

   token = strtok(NULL, ","); if (!token) return false;
   r.precioUnitario = atof(token);

   token = strtok(NULL, ","); if (!token) return false;
   r.costeUnitario = atof(token);

   token = strtok(NULL, ","); if (!token) return false;
   r.importeVentaTotal = atof(token);

   token = strtok(NULL, ","); if (!token) return false;
   r.importeCosteTotal = atof(token);

   return true;
}

void leerCSV(const char* archivo, vector<RegVentaProd>& regs)
{
   FILE* f = fopen(archivo, "rt");
   if (!f) { printf("No se pudo abrir %s\n", archivo); return; }

   char linea[512];
   fgets(linea, sizeof(linea), f); // descarta encabezado

   regs.clear();
   while (fgets(linea, sizeof(linea), f)) {
      quitarSalto(linea);
      if (strlen(linea) == 0) continue;
      RegVentaProd r;
      if (parsearLinea(linea, r)) regs.push_back(r);
   }
   fclose(f);
   printf("%zu registros leidos de %s\n", regs.size(), archivo);
}

void mostrarRegistro(const RegVentaProd& r)
{
   printf("------------------------------------------------------\n");
   printf("ID Pedido        : %d\n", r.idPedido);
   printf("ID Cliente       : %s\n", r.idCliente);
   printf("Zona             : %s\n", r.zona);
   printf("Pais             : %s\n", r.pais);
   printf("Tipo de producto : %s\n", r.tipoProducto);
   printf("Unidades         : %d\n", r.unidades);
   printf("Precio Unitario  : %.2f\n", r.precioUnitario);
   printf("Coste Unitario   : %.2f\n", r.costeUnitario);
   printf("Importe Venta    : %.2f\n", r.importeVentaTotal);
   printf("Importe Coste    : %.2f\n", r.importeCosteTotal);
   printf("------------------------------------------------------\n");
}

void mostrarRegistros(const vector<RegVentaProd>& regs)
{
   if (regs.empty()) { printf("Vector vacio. Importe el CSV primero.\n"); return; }

   printf("%5s %-12s %-12s %-20s %-10s %10s\n",
          "N", "ID Pedido", "ID Cliente", "Pais", "Unidades", "Importe");
   for (size_t i = 0; i < regs.size(); i++) {
      printf("%5zu %-12d %-12s %-20s %-10d %10.2f\n",
             i + 1, regs[i].idPedido, regs[i].idCliente, regs[i].pais,
             regs[i].unidades, regs[i].importeVentaTotal);
   }
   printf("Total: %zu registros\n", regs.size());
}

void crearDatVentas(const vector<RegVentaProd>& regs, const char* archivo)
{
   if (regs.empty()) { printf("Vector vacio. Importe el CSV primero.\n"); return; }

   FILE* f = fopen(archivo, "wb");
   if (!f) { printf("No se pudo crear %s\n", archivo); return; }

   for (size_t i = 0; i < regs.size(); i++)
   { fwrite(&regs[i], sizeof(RegVentaProd), 1, f); }

   fclose(f);
   printf("%s creado con %zu registros\n", archivo, regs.size());
}

void crearFileIndices(const vector<RegVentaProd>& regs, const char* archivo)
{
   if (regs.empty()) { printf("Vector vacio. Importe el CSV primero.\n"); return; }

   FILE* f = fopen(archivo, "wb");
   if (!f) { printf("No se pudo crear %s\n", archivo); return; }

   CodIndex ci;
   for (size_t i = 0; i < regs.size(); i++) {
      ci.idPedido = regs[i].idPedido;
      ci.dirLog = (long) i;
      fwrite(&ci, sizeof(CodIndex), 1, f);
   }

   fclose(f);
   printf("%s creado con %zu indices\n", archivo, regs.size());
}

void construirArbolDesdeIndice(Pagina** raiz, const char* archivo)
{
   FILE* f = fopen(archivo, "rb");
   if (!f) { printf("No se pudo abrir %s. Cree el archivo de indices primero.\n", archivo); return; }

   crearArbolB(raiz);
   CodIndex ci;
   int n = 0;
   while (fread(&ci, sizeof(CodIndex), 1, f) == 1) {
      insertar(raiz, ci);
      n++;
   }
   fclose(f);
   printf("Arbol B construido con %d claves desde %s\n", n, archivo);
}

//============================================================
//  BUSQUEDAS Y COMPARACION DE TIEMPOS
//============================================================
void buscarPorArbolMenu(Pagina* raiz, const char* datFile)
{
   int idPedido;
   printf("ID Pedido a buscar: ");
   scanf("%d", &idPedido);

   CodIndex clave; clave.idPedido = idPedido; clave.dirLog = 0;
   int pos;

   auto t0 = chrono::high_resolution_clock::now();

   Pagina* nodo = buscar(raiz, clave, &pos);
   RegVentaProd r;
   bool ok = false;

   if (nodo != NULL) {
      long dirLog = nodo->claves[pos].dirLog;
      FILE* f = fopen(datFile, "rb");
      if (f) {
         fseek(f, dirLog * sizeof(RegVentaProd), SEEK_SET);
         ok = (fread(&r, sizeof(RegVentaProd), 1, f) == 1);
         fclose(f);
      }
   }

   auto t1 = chrono::high_resolution_clock::now();
   double us = chrono::duration<double, micro>(t1 - t0).count();

   if (ok) {
      printf("\nEncontrado por Arbol B en %.3f us (acceso directo)\n", us);
      mostrarRegistro(r);
   } else {
      printf("\nID Pedido %d no encontrado. Tiempo: %.3f us\n", idPedido, us);
   }
}

void buscarSecuencialMenu(const char* datFile)
{
   int idPedido;
   printf("ID Pedido a buscar: ");
   scanf("%d", &idPedido);

   FILE* f = fopen(datFile, "rb");
   if (!f) { printf("No se pudo abrir %s\n", datFile); return; }

   RegVentaProd r;
   long comparaciones = 0;
   bool ok = false;

   auto t0 = chrono::high_resolution_clock::now();
   while (fread(&r, sizeof(RegVentaProd), 1, f) == 1) {
      comparaciones++;
      if (r.idPedido == idPedido) { ok = true; break; }
   }
   auto t1 = chrono::high_resolution_clock::now();
   fclose(f);

   double us = chrono::duration<double, micro>(t1 - t0).count();

   if (ok) {
      printf("\nEncontrado por busqueda secuencial en %.3f us (%ld comparaciones)\n", us, comparaciones);
      mostrarRegistro(r);
   } else {
      printf("\nID Pedido %d no encontrado tras %ld comparaciones. Tiempo: %.3f us\n",
             idPedido, comparaciones, us);
   }
}

void compararBusquedas(Pagina* raiz, const char* datFile)
{
   int idPedido;
   printf("ID Pedido a comparar: ");
   scanf("%d", &idPedido);

   // --- Arbol B + acceso directo ---
   CodIndex clave; clave.idPedido = idPedido; clave.dirLog = 0;
   int pos;
   auto t0 = chrono::high_resolution_clock::now();
   Pagina* nodo = buscar(raiz, clave, &pos);
   RegVentaProd rArbol;
   bool okArbol = false;
   if (nodo != NULL) {
      long dirLog = nodo->claves[pos].dirLog;
      FILE* f = fopen(datFile, "rb");
      if (f) {
         fseek(f, dirLog * sizeof(RegVentaProd), SEEK_SET);
         okArbol = (fread(&rArbol, sizeof(RegVentaProd), 1, f) == 1);
         fclose(f);
      }
   }
   auto t1 = chrono::high_resolution_clock::now();
   double usArbol = chrono::duration<double, micro>(t1 - t0).count();

   // --- Busqueda secuencial ---
   FILE* f2 = fopen(datFile, "rb");
   RegVentaProd rSeq;
   long comparaciones = 0;
   bool okSeq = false;
   auto t2 = chrono::high_resolution_clock::now();
   if (f2) {
      while (fread(&rSeq, sizeof(RegVentaProd), 1, f2) == 1) {
         comparaciones++;
         if (rSeq.idPedido == idPedido) { okSeq = true; break; }
      }
      fclose(f2);
   }
   auto t3 = chrono::high_resolution_clock::now();
   double usSeq = chrono::duration<double, micro>(t3 - t2).count();

   printf("\n================ COMPARACION DE BUSQUEDAS ================\n");
   printf("%-20s %-12s %15s\n", "Metodo", "Encontrado", "Tiempo (us)");
   printf("%-20s %-12s %15.3f\n", "Arbol B (fseek)", okArbol ? "Si" : "No", usArbol);
   printf("%-20s %-12s %15.3f\n", "Secuencial", okSeq ? "Si" : "No", usSeq);
   printf("Comparaciones en busqueda secuencial: %ld\n", comparaciones);
   printf("=============================================================\n");

   if (okArbol) mostrarRegistro(rArbol);
}

//============================================================
//  MENU
//============================================================
void menu()
{
   Pagina* arbol;
   crearArbolB(&arbol);

   vector<RegVentaProd> regs;
   const char* csvFile   = "regVentasProd.csv";
   const char* datFile   = "regVentasProd.dat";
   const char* idxFile   = "fileIndices.dat";
   const char* treeFile  = "arbolBGuardado.dat";

   int opcion;
   do {
      puts("\n\t\tT A R E A   0 2  -  A R B O L   B   E   I N D I C E S\n");
      puts("\t1.  Importar CSV");
      puts("\t2.  Mostrar registros");
      puts("\t3.  Crear regVentasProd.dat");
      puts("\t4.  Crear fileIndices.dat");
      puts("\t5.  Construir Arbol B");
      puts("\t6.  Buscar mediante Arbol B");
      puts("\t7.  Buscar secuencialmente");
      puts("\t8.  Comparar tiempos");
      puts("\t9.  Salvar Arbol");
      puts("\t10. Recuperar Arbol");
      puts("\t0.  Salir");
      printf("\n\tOpcion ---> ");
      scanf("%d", &opcion);

      switch (opcion) {
         case 1:  leerCSV(csvFile, regs); break;
         case 2:  mostrarRegistros(regs); break;
         case 3:  crearDatVentas(regs, datFile); break;
         case 4:  crearFileIndices(regs, idxFile); break;
         case 5:  construirArbolDesdeIndice(&arbol, idxFile); break;
         case 6:  buscarPorArbolMenu(arbol, datFile); break;
         case 7:  buscarSecuencialMenu(datFile); break;
         case 8:  compararBusquedas(arbol, datFile); break;
         case 9:  Salvar(arbol, treeFile); break;
         case 10: Recuperar(&arbol, treeFile); break;
         case 0:  break;
         default: printf("Opcion invalida\n");
      }
   } while (opcion != 0);
}