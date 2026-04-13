/*
   * nomPrograma:
   * descripcion:
   *
   *
   * author: FLORES HOYOS, Mathias Pavel Diego
   * fecha :
   */
// ============================================================
//   BÚSQUEDA FIBONACCI - MENÚ INTERACTIVO
//   Compilar: g++ -std=c++17 -o fibonacci_menu fibonacci_menu.cpp
// ============================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// ────────────────────────────────────────────────
//   UTILIDADES
// ────────────────────────────────────────────────

void pausar() {
    cout << "\n  Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int leerEntero(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
        cout << "  [!] Entrada invalida. Intenta de nuevo.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// ────────────────────────────────────────────────
//   GESTIÓN DEL ARREGLO
// ────────────────────────────────────────────────

void agregarElemento(vector<int>& arr) {
    int val = leerEntero("  Ingresa el valor a agregar: ");
    arr.push_back(val);
    sort(arr.begin(), arr.end()); // Mantener ordenado para Fibonacci Search
    cout << "  [✓] Elemento " << val << " agregado y arreglo reordenado.\n";
}

void eliminarElemento(vector<int>& arr) {
    if (arr.empty()) {
        cout << "  [!] El arreglo esta vacio.\n";
        return;
    }
    int val = leerEntero("  Ingresa el valor a eliminar: ");
    auto it = find(arr.begin(), arr.end(), val);
    if (it != arr.end()) {
        arr.erase(it);
        cout << "  [✓] Elemento " << val << " eliminado.\n";
    } else {
        cout << "  [!] El elemento " << val << " no existe en el arreglo.\n";
    }
}

void mostrarElementos(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "  [!] El arreglo esta vacio.\n";
        return;
    }
    cout << "\n  Arreglo (" << arr.size() << " elementos):\n";
    cout << "  Indice: ";
    for (int i = 0; i < (int)arr.size(); i++)
        cout << "[" << i << "] \t";
    cout << "\n  Valor:  ";
    for (int v : arr)
        cout << " " << v << "  \t";
    cout << "\n";
}

void limpiarArreglo(vector<int>& arr) {
    if (arr.empty()) {
        cout << "  [!] El arreglo ya esta vacio.\n";
        return;
    }
    char confirm;
    cout << "  ¿Seguro que deseas limpiar todo el arreglo? (s/n): ";
    cin >> confirm;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (confirm == 's' || confirm == 'S') {
        arr.clear();
        cout << "  [✓] Arreglo limpiado.\n";
    } else {
        cout << "  Operacion cancelada.\n";
    }
}

// ────────────────────────────────────────────────
//   BÚSQUEDA DE FIBONACCI
// ────────────────────────────────────────────────

int busquedaFibonacci(const vector<int>& arr, int x) {
    int n = arr.size();

    int fibM2 = 0; // Fib(k-2)
    int fibM1 = 1; // Fib(k-1)
    int fibM  = 1; // Fib(k)

    while (fibM < n) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM  = fibM2 + fibM1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibM2, n - 1);

        if (arr[i] < x) {
            fibM  = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        } else if (arr[i] > x) {
            fibM  = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        } else {
            return i;
        }
    }

    if (fibM1 && offset + 1 < n && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

void buscarElemento(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "  [!] El arreglo esta vacio. Agrega elementos primero.\n";
        return;
    }
    int val = leerEntero("  Ingresa el valor a buscar: ");
    int idx  = busquedaFibonacci(arr, val);
    if (idx != -1)
        cout << "  [✓] Elemento " << val << " encontrado en el indice [" << idx << "].\n";
    else
        cout << "  [✗] Elemento " << val << " NO encontrado en el arreglo.\n";
}

// ────────────────────────────────────────────────
//   MENÚ
// ────────────────────────────────────────────────

void mostrarMenu() {
   system("clear");
    cout << "\n";
    cout << "  ╔══════════════════════════════════════╗\n";
    cout << "  ║    BUSQUEDA DE FIBONACCI EN C++      ║\n";
    cout << "  ╠══════════════════════════════════════╣\n";
    cout << "  ║  1. Agregar elemento                 ║\n";
    cout << "  ║  2. Eliminar elemento                ║\n";
    cout << "  ║  3. Mostrar elementos                ║\n";
    cout << "  ║  4. Buscar elemento (Fibonacci)      ║\n";
    cout << "  ║  5. Limpiar arreglo                  ║\n";
    cout << "  ║  0. Salir                            ║\n";
    cout << "  ╚══════════════════════════════════════╝\n";
}

// ────────────────────────────────────────────────
//   MAIN
// ────────────────────────────────────────────────

int main() {
    vector<int> arr;
    int opcion;

    do {
        mostrarMenu();
        opcion = leerEntero("  Opcion: ");

        switch (opcion) {
            case 1: agregarElemento(arr);  break;
            case 2: eliminarElemento(arr); break;
            case 3: mostrarElementos(arr); break;
            case 4: buscarElemento(arr);   break;
            case 5: limpiarArreglo(arr);   break;
            case 0: cout << "  Hasta luego!\n"; break;
            default: cout << "  [!] Opcion invalida.\n"; break;
        }
      if(opcion != 0){
        printf("\nPresione ENTER para continuar...");
        getchar(); // limpia \n de scanf
        getchar(); // espera enter
      }
    } while (opcion != 0);

    return 0;
}
