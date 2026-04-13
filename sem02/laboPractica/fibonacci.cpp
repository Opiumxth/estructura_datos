/*
   * nomPrograma:
   * descripcion:
   *
   *
   * author: FLORES HOYOS, Mathias Pavel Diego
   * fecha :
   */

// ══════════════════════════════════════════════════
//   BÚSQUEDA DE FIBONACCI EN C++
// ══════════════════════════════════════════════════

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ──────────────────────────────────────────────────
//   Función principal: Fibonacci Search
//   arr  → arreglo ordenado
//   n    → tamaño del arreglo
//   x    → elemento a buscar
//   ret  → índice encontrado, o -1 si no existe
// ──────────────────────────────────────────────────


// ──────────────────────────────────────────────────
//   Main: ejemplo de uso
// ──────────────────────────────────────────────────

int fibonacciSearch(int arr[], int n, int x);

int main() {
    int arr[] = { 10, 22, 35, 40, 45, 50, 80, 82, 99 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int objetivo = 45;

    int resultado = fibonacciSearch(arr, n, objetivo);

    if (resultado != -1)
        cout << "Elemento " << objetivo
             << " encontrado en el índice: "
             << resultado << endl;
    else
        cout << "Elemento no encontrado." << endl;

    return 0;
}

// Salida esperada:
// Elemento 45 encontrado en el índice: 4

int fibonacciSearch(int arr[], int n, int x) {

    // Generar números de Fibonacci hasta cubrir el arreglo
    int fibM2 = 0;   // Fib(k-2)
    int fibM1 = 1;   // Fib(k-1)
    int fibM  = 1;   // Fib(k)

    while (fibM < n) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM  = fibM2 + fibM1;
    }

    int offset = -1;  // Límite inferior del rango actual

    while (fibM > 1) {

        // Calcular índice seguro (no superar el límite del arreglo)
        int i = min(offset + fibM2, n - 1);

        if (arr[i] < x) {
            // El elemento está en la mitad derecha
            fibM  = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        }
        else if (arr[i] > x) {
            // El elemento está en la mitad izquierda
            fibM  = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        }
        else {
            return i;  // ¡Encontrado!
        }
    }

    // Verificar el último elemento restante
    if (fibM1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;  // No encontrado
}
