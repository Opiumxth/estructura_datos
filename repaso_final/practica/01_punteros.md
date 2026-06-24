# PRÁCTICA 01: PUNTEROS

---

## Ejercicio 1.1 (Fácil) - Declaración y uso básico

**Enunciado:**
Declare un puntero a `float`, asígnele la dirección de una variable `float`, modifique el valor a través del puntero e imprima tanto la variable original como el valor desreferenciado del puntero. Verifique que ambos valores sean iguales.

**Solución en C/C++:**
```cpp
#include <iostream>
using namespace std;

int main() {
    float numero = 3.14f;
    float* ptr = &numero;
    
    cout << "Valor original: " << numero << endl;
    cout << "Valor a través de puntero: " << *ptr << endl;
    
    // Modificar a través del puntero
    *ptr = 6.28f;
    
    cout << "Después de modificar:" << endl;
    cout << "Valor original: " << numero << endl;
    cout << "Valor a través de puntero: " << *ptr << endl;
    
    return 0;
}
```

**Pseudocódigo:**
```
ACCION ejercicio1()
   REAL numero
   REAL ptr
   
   numero ← 3.14
   ptr ← direccion(numero)
   
   ESCRIBIR("Valor original: ", numero)
   ESCRIBIR("Valor a través de puntero: ", *ptr)
   
   *ptr ← 6.28
   
   ESCRIBIR("Después de modificar:")
   ESCRIBIR("Valor original: ", numero)
   ESCRIBIR("Valor a través de puntero: ", *ptr)
FIN_ACCION
```

---

## Ejercicio 1.2 (Medio) - Intercambio con punteros

**Enunciado:**
Escriba una función que intercambie el valor de dos variables enteras usando punteros. La función debe recibir las direcciones de las variables.

**Solución en C/C++:**
```cpp
#include <iostream>
using namespace std;

void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    
    cout << "Antes: x = " << x << ", y = " << y << endl;
    intercambiar(&x, &y);
    cout << "Después: x = " << x << ", y = " << y << endl;
    
    return 0;
}
```

**Pseudocódigo:**
```
ACCION intercambiar(ENTERO a, ENTERO b)
   ENTERO temp
   
   temp ← *a
   *a ← *b
   *b ← temp
FIN_ACCION
```

---

## Ejercicio 1.3 (Medio) - Aritmética de punteros

**Enunciado:**
Escriba una función que reciba un arreglo de enteros y su tamaño, y use aritmética de punteros para encontrar el valor máximo del arreglo. No use índices con corchetes `[]`.

**Solución en C/C++:**
```cpp
#include <iostream>
using namespace std;

int maximo(int* arr, int n) {
    if (n <= 0) return 0;
    
    int max = *arr;  // Primer elemento
    
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    
    return max;
}

int main() {
    int datos[] = {3, 8, 1, 9, 4, 2, 7};
    int n = sizeof(datos) / sizeof(datos[0]);
    
    cout << "Máximo: " << maximo(datos, n) << endl;
    
    return 0;
}
```

**Pseudocódigo:**
```
ACCION maximo(ENTERO arr[], ENTERO n) RETORNA ENTERO
   ENTERO max, i
   
   SI(n ≤ 0)
      RETORNAR(0)
   FIN_SI
   
   max ← *arr
   
   PARA i ← 1 HASTA n - 1
      SI(*(arr + i) > max)
         max ← *(arr + i)
      FIN_SI
   FIN_PARA
   
   RETORNAR(max)
FIN_ACCION
```

---

## Ejercicio 1.4 (Difícil) - Inversión de arreglo

**Enunciado:**
Escriba una función que invierta un arreglo in-place usando dos punteros: uno al inicio y otro al final. Use aritmética de punteros, no índices.

**Solución en C/C++:**
```cpp
#include <iostream>
using namespace std;

void invertir(int* arr, int n) {
    if (n <= 1) return;
    
    int* inicio = arr;
    int* final = arr + n - 1;
    
    while (inicio < final) {
        int temp = *inicio;
        *inicio = *final;
        *final = temp;
        
        inicio++;
        final--;
    }
}

void imprimir(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int datos[] = {1, 2, 3, 4, 5};
    int n = sizeof(datos) / sizeof(datos[0]);
    
    cout << "Original: ";
    imprimir(datos, n);
    
    invertir(datos, n);
    
    cout << "Invertido: ";
    imprimir(datos, n);
    
    return 0;
}
```

**Pseudocódigo:**
```
ACCION invertir(ENTERO arr[], ENTERO n)
   ENTERO *inicio, *final, temp
   
   SI(n ≤ 1)
      RETORNAR
   FIN_SI
   
   inicio ← arr
   final ← arr + n - 1
   
   MIENTRAS(inicio < final)
      temp ← *inicio
      *inicio ← *final
      *final ← temp
      
      inicio ← inicio + 1
      final ← final - 1
   FIN_MIENTRAS
FIN_ACCION
```

---

## Ejercicio 1.5 (Tipo examen) - Traza de punteros

**Enunciado:**
¿Qué imprime el siguiente código? Justifique paso a paso.

```cpp
int a = 5, b = 10;
int* p = &a;
int* q = &b;
*p = *q + 3;
q = p;
*q = *q * 2;
cout << a << " " << b << endl;
```

**Solución:**
```
Estado inicial:
  a = 5, b = 10
  p → a, q → b

*p = *q + 3:
  *p = 10 + 3 = 13
  a = 13

q = p:
  q ahora también apunta a a

*q = *q * 2:
  *q = 13 * 2 = 26
  a = 26 (ambos p y q apuntan a a)

Resultado: a = 26, b = 10
Imprime: "26 10"
```

---

## Ejercicio 1.6 (Avanzado) - Suma de elementos con punteros

**Enunciado:**
Escriba una función que sume todos los elementos de un arreglo usando aritmética de punteros. Implemente tanto en pseudocódigo como en C/C++.

**Solución en C/C++:**
```cpp
int suma(int* arr, int n) {
    if (arr == NULL || n <= 0) return 0;
    
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += *(arr + i);
    }
    return total;
}
```

**Pseudocódigo:**
```
ACCION suma(ENTERO arr[], ENTERO n) RETORNA ENTERO
   ENTERO total, i
   
   SI(arr = NULL O n ≤ 0)
      RETORNAR(0)
   FIN_SI
   
   total ← 0
   PARA i ← 0 HASTA n - 1
      total ← total + *(arr + i)
   FIN_PARA
   
   RETORNAR(total)
FIN_ACCION
```
