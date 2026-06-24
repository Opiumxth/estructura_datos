# PRÁCTICA 03: MEMORIA DINÁMICA

---

## Ejercicio 3.1 (Fácil) - Reservar y liberar un entero

**Enunciado:**
Reserve memoria dinámicamente para un entero, asígnele un valor, imprímalo y luego libere la memoria.

**Solución en C/C++:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int* p = new int;
    *p = 42;
    
    cout << "Valor: " << *p << endl;
    
    delete p;
    p = nullptr;
    
    return 0;
}
```

**Pseudocódigo:**
```
ACCION ejercicio3()
   ENTERO p
   
   p ← reservar(ENTERO)
   *p ← 42
   
   ESCRIBIR("Valor: ", *p)
   
   liberar(p)
   p ← NULL
FIN_ACCION
```

---

## Ejercicio 3.2 (Medio) - Arreglo dinámico

**Enunciado:**
Solicite al usuario el tamaño de un arreglo, resérvelo dinámicamente, llénelo con valores y luego imprímalo. No olvide liberar la memoria.

**Solución en C/C++:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Tamaño del arreglo: ";
    cin >> n;
    
    int* arr = new int[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Valor " << i + 1 << ": ";
        cin >> arr[i];
    }
    
    cout << "Arreglo: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    arr = nullptr;
    
    return 0;
}
```

---

## Ejercicio 3.3 (Medio) - Redimensionar arreglo

**Enunciado:**
Escriba una función que reciba un arreglo dinámico y su tamaño, y cree un nuevo arreglo con el doble de tamaño, copiando los elementos del original.

**Solución en C/C++:**
```cpp
int* redimensionar(int* arr, int n) {
    int* nuevo = new int[n * 2];
    
    for (int i = 0; i < n; i++) {
        nuevo[i] = arr[i];
    }
    
    return nuevo;
}
```

**Pseudocódigo:**
```
ACCION redimensionar(ENTERO arr[], ENTERO n) RETORNA ENTERO[]
   ENTERO nuevo[n*2]
   ENTERO i
   
   PARA i ← 0 HASTA n - 1
      nuevo[i] ← arr[i]
   FIN_PARA
   
   RETORNAR(nuevo)
FIN_ACCION
```

---

## Ejercicio 3.4 (Difícil) - Matriz dinámica

**Enunciado:**
Reserve memoria dinámicamente para una matriz de m×n enteros, llénela con valores y luego imprímala. Libere toda la memoria correctamente.

**Solución en C/C++:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Filas: ";
    cin >> m;
    cout << "Columnas: ";
    cin >> n;
    
    // Reservar filas
    int** matriz = new int*[m];
    
    // Reservar columnas para cada fila
    for (int i = 0; i < m; i++) {
        matriz[i] = new int[n];
    }
    
    // Llenar matriz
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = i * n + j;
        }
    }
    
    // Imprimir matriz
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    
    // Liberar memoria
    for (int i = 0; i < m; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    
    return 0;
}
```

---

## Ejercicio 3.5 (Tipo examen) - Verificar memoria

**Enunciado:**
Escriba una función que verifique si la reserva de memoria fue exitosa antes de usar el puntero.

**Solución en C/C++:**
```cpp
int* reservarSeguro(int n) {
    int* arr = new int[n];
    
    if (arr == nullptr) {
        cout << "Error: no se pudo reservar memoria" << endl;
        return nullptr;
    }
    
    return arr;
}
```

**Pseudocódigo:**
```
ACCION reservarSeguro(ENTERO n) RETORNA ENTERO[]
   ENTERO arr[]
   
   arr ← reservar(n)
   
   SI(arr = NULL)
      ESCRIBIR("Error: no se pudo reservar memoria")
      RETORNAR(NULL)
   FIN_SI
   
   RETORNAR(arr)
FIN_ACCION
```
