# TEMA 1: PUNTEROS

---

## 1. TEORÍA CLARA

### ¿Qué es un puntero?
Un puntero es una **variable que almacena una dirección de memoria**. No guarda un valor directamente, sino la "ubicación" donde vive otro dato.

### ¿Para qué sirve?
- **Estructuras dinámicas:** Sin punteros no existen nodos, y sin nodos no hay listas, pilas ni colas.
- **Paso por referencia:** Modificar variables de otra función sin copiarlas.
- **Arreglos dinámicos:** Crear arreglos cuyo tamaño se decide en ejecución.
- **Eficiencia:** Pasar un puntero (4-8 bytes) en lugar de copiar un struct de 200 bytes.

### ¿Cómo funciona internamente?
La RAM es una secuencia de celdas numeradas. Cada variable ocupa celdas a partir de cierta dirección.

```
Memoria:
Dirección  │ Valor
───────────┼──────
0x1000     │ 42       ← aquí vive x
0x1004     │ 0x1000   ← aquí vive p (guarda la dirección de x)
```

```cpp
int x = 42;     // x está en la dirección 0x1000
int* p = &x;    // p guarda 0x1000
*p = 100;       // escribe 100 en la dirección 0x1000 → ahora x vale 100
```

### Operadores clave

| Operador | Nombre | Qué hace | Ejemplo |
|----------|--------|----------|---------|
| `&var` | Dirección-de | Obtiene la dirección de una variable | `p = &x;` |
| `*ptr` | Desreferencia | Accede al valor en la dirección que guarda el puntero | `cout << *p;` |
| `->` | Flecha | Accede a un campo de un struct a través de un puntero | `ptr->dato` |

### Errores comunes

| Error | Qué pasa | Cómo evitarlo |
|-------|----------|---------------|
| `int* p; *p = 5;` | CRASH — puntero sin inicializar apunta a basura | Siempre inicializar: `int* p = nullptr;` o `p = &x;` |
| `delete p; *p = 3;` | Puntero colgante (dangling) — memoria ya liberada | Después de `delete`: `p = nullptr;` |
| `delete p; delete p;` | Doble liberación — comportamiento indefinido | Hacer `p = nullptr;` después del primer `delete` |
| `new int; /* sin delete */` | Memory leak — memoria perdida | Siempre emparejar `new` con `delete` |

---

## 2. EJEMPLOS RESUELTOS

### Ejemplo 1: Intercambiar dos valores usando punteros

**Enunciado:** Escriba una función que intercambie el valor de dos enteros usando punteros.

**Razonamiento:** Necesitamos que la función modifique las variables originales, no copias. Usamos punteros para acceder a las direcciones reales.

```cpp
#include <iostream>
using namespace std;

// Recibe las DIRECCIONES de a y b
void intercambiar(int* pa, int* pb) {
    int temp = *pa;   // temp = valor en la dirección pa
    *pa = *pb;        // pone el valor de pb en la dirección pa
    *pb = temp;       // pone temp en la dirección pb
}

int main() {
    int a = 10, b = 20;
    cout << "Antes: a=" << a << " b=" << b << endl;  // a=10 b=20
    
    intercambiar(&a, &b);  // pasamos las DIRECCIONES
    
    cout << "Después: a=" << a << " b=" << b << endl; // a=20 b=10
    return 0;
}
```

**Paso a paso en memoria:**
```
Inicio:    a(0x100)=10    b(0x104)=20    pa=0x100   pb=0x104
temp = *pa → temp = 10
*pa = *pb  → a = 20
*pb = temp → b = 10
Final:     a=20, b=10 ✓
```

### Ejemplo 2: Función que devuelve el mayor de un arreglo usando punteros

**Enunciado:** Usando aritmética de punteros, encuentre el mayor elemento de un arreglo.

```cpp
#include <iostream>
using namespace std;

int mayor(int* arr, int n) {
    int max = *arr;               // primer elemento
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > max) {   // arr+i avanza i posiciones
            max = *(arr + i);
        }
    }
    return max;
}

int main() {
    int datos[] = {3, 8, 1, 9, 4};
    cout << "Mayor: " << mayor(datos, 5) << endl;  // 9
    return 0;
}
```

**Clave:** `*(arr + i)` es equivalente a `arr[i]`. El compilador calcula la dirección real como `arr + i * sizeof(int)`.

---

## 3. EJERCICIOS PARA PRACTICAR

**Ejercicio 1.1 (Fácil):** Declare un puntero a `float`, asígnele la dirección de una variable, modifique el valor a través del puntero e imprima ambos (la variable y `*p`). Verifique que son iguales.

**Ejercicio 1.2 (Medio):** Escriba una función `void duplicar(int* arr, int n)` que reciba un arreglo como puntero y duplique cada elemento in-place (sin crear otro arreglo).

**Ejercicio 1.3 (Difícil):** Escriba una función `void invertir(int* arr, int n)` que invierta un arreglo usando solo aritmética de punteros (sin usar índices `[]`). Use dos punteros: uno al inicio y otro al final.

**Ejercicio 1.4 (Tipo examen):** ¿Qué imprime el siguiente código? Justifique paso a paso.
```cpp
int a = 5, b = 10;
int* p = &a;
int* q = &b;
*p = *q + 3;
q = p;
*q = *q * 2;
cout << a << " " << b << endl;
```

---

## 4. PATRONES DE EXAMEN

- **Traza de punteros:** Te dan código con punteros y preguntan qué imprime. → Dibuja las variables y flechas en papel.
- **Completar funciones:** Te dan una función con huecos que usa punteros. → Identifica si necesitas `&`, `*` o `->`.
- **Detectar errores:** Código con bugs de punteros. → Busca: sin inicializar, sin `delete`, doble `delete`, dereferenciar `nullptr`.
- **Truco rápido:** Cuando veas `**p` (doble puntero), piensa: "quieren modificar A DÓNDE apunta el puntero original" (se usa al pasar `cabeza` de una lista).

### Chuleta de repaso rápido
```
& = dirección de       * = valor en la dirección
new = reservar heap     delete = liberar heap
-> = acceso por puntero a struct     . = acceso directo
nullptr = puntero que no apunta a nada (seguro)
Doble puntero (**) = para modificar el puntero original desde una función
```
