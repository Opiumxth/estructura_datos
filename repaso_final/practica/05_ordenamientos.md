# PRÁCTICA 05: ORDENAMIENTOS

---

## Ejercicio 5.1 (Fácil) - Ordenamiento burbuja

**Enunciado:**
Implemente el algoritmo de ordenamiento burbuja para ordenar un arreglo de enteros en orden ascendente.

**Solución en C/C++:**
```cpp
#include <iostream>
using namespace std;

void burbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    burbuja(arr, n);
    
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Pseudocódigo:**
```
ACCION burbuja(ENTERO arr[], ENTERO n)
   ENTERO i, j, temp
   
   PARA i ← 0 HASTA n - 2
      PARA j ← 0 HASTA n - i - 2
         SI(arr[j] > arr[j + 1])
            temp ← arr[j]
            arr[j] ← arr[j + 1]
            arr[j + 1] ← temp
         FIN_SI
      FIN_PARA
   FIN_PARA
FIN_ACCION
```

---

## Ejercicio 5.2 (Medio) - Ordenamiento por selección

**Enunciado:**
Implemente el algoritmo de ordenamiento por selección.

**Solución en C/C++:**
```cpp
void seleccion(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}
```

**Pseudocódigo:**
```
ACCION seleccion(ENTERO arr[], ENTERO n)
   ENTERO i, j, minIdx, temp
   
   PARA i ← 0 HASTA n - 2
      minIdx ← i
      PARA j ← i + 1 HASTA n - 1
         SI(arr[j] < arr[minIdx])
            minIdx ← j
         FIN_SI
      FIN_PARA
      
      temp ← arr[i]
      arr[i] ← arr[minIdx]
      arr[minIdx] ← temp
   FIN_PARA
FIN_ACCION
```

---

## Ejercicio 5.3 (Medio) - Ordenamiento por inserción

**Enunciado:**
Implemente el algoritmo de ordenamiento por inserción.

**Solución en C/C++:**
```cpp
void insercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

**Pseudocódigo:**
```
ACCION insercion(ENTERO arr[], ENTERO n)
   ENTERO i, j, key
   
   PARA i ← 1 HASTA n - 1
      key ← arr[i]
      j ← i - 1
      
      MIENTRAS(j ≥ 0 Y arr[j] > key)
         arr[j + 1] ← arr[j]
         j ← j - 1
      FIN_MIENTRAS
      
      arr[j + 1] ← key
   FIN_PARA
FIN_ACCION
```

---

## Ejercicio 5.4 (Difícil) - Comparar algoritmos

**Enunciado:**
Implemente los tres algoritmos (burbuja, selección, inserción) y compare el número de comparaciones que realiza cada uno para el mismo arreglo.

**Solución en C/C++:**
```cpp
int burbujaConContador(int arr[], int n) {
    int comparaciones = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparaciones++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comparaciones;
}
```

---

## Ejercicio 5.5 (Tipo examen) - Ordenar strings

**Enunciado:**
Ordene un arreglo de cadenas de caracteres alfabéticamente usando burbuja.

**Solución en C/C++:**
```cpp
#include <iostream>
#include <cstring>
using namespace std;

void burbujaStrings(char arr[][50], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[50];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}
```
