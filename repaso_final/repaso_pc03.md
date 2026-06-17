# 📚 GUÍA INTENSIVA PC3 — ESTRUCTURA DE DATOS
> **PC3** | Sem 01 → Árboles | Pseudocódigo + C/C++
> Prof. Gilberto A. Salinas — UNMSM — Ciclo 2026-1

---

## Índice General

1. [Parte 1: Fundamentos (Punteros, Structs, Memoria Dinámica)](#parte-1-fundamentos)
2. [Parte 2: Listas Enlazadas](#parte-2-listas-enlazadas)
3. [Parte 3: Pilas y Colas](#parte-3-pilas-y-colas)
4. [Parte 4: Árboles](#parte-4-árboles)
5. [Integración de Conceptos](#integración-de-conceptos)
6. [Preparación PC3: Simulacro y Ejercicios](#preparación-pc3)
7. [Resúmenes y Hojas de Referencia](#resúmenes-y-hojas-de-referencia)
8. [Lo Más Probable que Pregunte el Profesor](#lo-más-probable-que-pregunte-el-profesor)

---

# PARTE 1: FUNDAMENTOS

## 1.1 Punteros

### Teoría

Un **puntero** es una variable que almacena la **dirección de memoria** de otro dato. No guarda el valor, sino *dónde* está el valor.

**¿Para qué sirve?**
- Crear estructuras dinámicas (listas, pilas, colas, árboles).
- Pasar datos grandes a funciones sin copiarlos.
- Reservar memoria en tiempo de ejecución (heap).

**¿Cómo funciona internamente?**
La RAM es una secuencia de celdas numeradas. Cada variable ocupa una dirección. Un puntero guarda ese número de dirección.

```
int x = 42;   →  dirección 0x1000, valor 42
int* p = &x;  →  p guarda 0x1000
*p = 100;     →  cambia el valor en 0x1000 → x ahora vale 100
```

**Operadores clave:**

| Operador | Pseudocódigo | C/C++ | Significado |
|----------|-------------|-------|-------------|
| Dirección de | `&var` | `&var` | "Dame la dirección de esta variable" |
| Desreferencia | `*ptr` | `*ptr` | "Dame el valor en esa dirección" |
| Acceso miembro | `nodo.dato` | `ptr->dato` | "Accede al campo mediante puntero" |

### Operaciones fundamentales

#### Declaración y uso básico

**Pseudocódigo:**
```
ENTERO x ← 42
ENTERO *p
p ← &x           // p apunta a x
ESCRIBIR(*p)      // muestra 42
*p ← 100          // x ahora vale 100
```

**C/C++:**
```cpp
int x = 42;
int *p;
p = &x;           // p apunta a x
printf("%d", *p); // muestra 42
*p = 100;         // x ahora vale 100
```

### Errores comunes
- `int* p; *p = 5;` → **CRASH** (puntero no inicializado)
- No liberar con `delete` → **memory leak**
- `delete` sin `new` → **CRASH**
- `p = nullptr; *p` → **CRASH**
- Doble liberación: `delete p; delete p;` → **CRASH**

---

## 1.2 Memoria Dinámica

### Teoría

**Memoria estática:** se reserva en compilación, tamaño fijo, vive en el STACK.
**Memoria dinámica:** se reserva en ejecución, tamaño variable, vive en el HEAP.

### Operaciones: Reservar y Liberar

**Pseudocódigo:**
```
NODO *p
p ← nuevoNodo()          // reserva memoria
p.valor ← dato
p.sgte ← NULL
liberaNodo(p)             // libera memoria
```

**C (malloc/free):**
```c
NODO *p;
p = (NODO*)malloc(sizeof(NODO));   // reserva
p->valor = dato;
p->sgte = NULL;
free(p);                            // libera
```

**C++ (new/delete):**
```cpp
NODO *p;
p = new NODO;              // reserva (más limpio)
p->valor = dato;
p->sgte = NULL;
delete p;                  // libera

// Para arreglos dinámicos:
int* arr = new int[10];
delete[] arr;              // liberar con delete[]
```

### Tabla de equivalencias Pseudocódigo ↔ C/C++

| Operación | Pseudocódigo | C | C++ |
|-----------|-------------|---|-----|
| Reservar nodo | `p ← nuevoNodo(cab1)` | `p = (NODO*)malloc(sizeof(NODO))` | `p = new NODO` |
| Liberar nodo | `liberaNodo(cab1, p)` | `free(p)` | `delete p` |
| Reservar arreglo | — | `p = (int*)malloc(n*sizeof(int))` | `p = new int[n]` |
| Liberar arreglo | — | `free(p)` | `delete[] p` |
| Redimensionar | — | `p = realloc(p, newSize)` | — (usar vector) |

---

## 1.3 Structs (Registros)

### Teoría

Un **struct** (registro) agrupa variables de **distintos tipos** bajo un mismo nombre. Es la forma de modelar entidades del mundo real.

### Declaración y Uso

**Pseudocódigo:**
```
REGISTRO ALUMNO
   ENTERO codigo
   CARACTER nombre[50]
   REAL promedio
FIN_REGISTRO
```

**C/C++:**
```cpp
struct ALUMNO {
    int codigo;
    char nombre[50];
    float promedio;
};
```

**Acceso a campos:**

| Situación | Pseudocódigo | C/C++ |
|-----------|-------------|-------|
| Variable directa | `alumno.codigo` | `alumno.codigo` |
| Mediante puntero | `p.codigo` | `p->codigo` |

### El Nodo: el struct más importante del curso

**Pseudocódigo:**
```
REGISTRO NODO
   TD valor
   NODO *sgte
FIN_REGISTRO
```

**C/C++:**
```cpp
typedef int TD;
struct NODO {
    TD valor;
    NODO *sgte;
};
```

> **Regla de oro:** Struct + Puntero = **Nodo**. Un Nodo autorreferenciado es el bloque de construcción de TODAS las estructuras dinámicas del curso.

### Nodo para lista doble

**Pseudocódigo:**
```
REGISTRO NODOD
   TD valor
   NODO *ante
   NODO *sgte
FIN_REGISTRO
```

**C/C++:**
```cpp
struct NODOD {
    TD valor;
    NODOD *ante;
    NODOD *sgte;
};
```

### Nodo para árbol binario

**Pseudocódigo:**
```
REGISTRO BNODO
   BNODO *hi      // hijo izquierdo
   TD info
   BNODO *hd      // hijo derecho
FIN_REGISTRO
```

**C/C++:**
```cpp
struct NODO {
    TD info;
    NODO *izq;
    NODO *der;
};
```

---

## Ejercicios Resueltos — Parte 1

### Ejercicio 1.1: Crear un nodo dinámico y mostrar su contenido

**Pseudocódigo:**
```
ACCION principal()
   NODO *p
   p ← new NODO
   p.valor ← 42
   p.sgte ← NULL
   ESCRIBIR("Valor: ", p.valor)
   ESCRIBIR("Siguiente: ", p.sgte)
   delete p
FIN_ACCION
```

**C/C++:**
```cpp
#include <stdio.h>
#include <stdlib.h>

typedef int TD;
struct NODO {
    TD valor;
    NODO *sgte;
};

int main() {
    NODO *p = new NODO;
    p->valor = 42;
    p->sgte = NULL;
    printf("Valor: %d\n", p->valor);
    printf("Siguiente: %p\n", (void*)p->sgte);
    delete p;
    return 0;
}
```

**Razonamiento:** Se reserva memoria dinámica para un nodo, se asignan valores a sus campos usando `->` (puntero a struct), y se libera la memoria al final.

### Ejercicio 1.2: Intercambiar valores de dos variables usando punteros

**Pseudocódigo:**
```
ACCION intercambiar(ENTERO *a, ENTERO *b)
   ENTERO temp
   temp ← *a
   *a ← *b
   *b ← temp
FIN_ACCION

ACCION principal()
   ENTERO x ← 10, y ← 20
   intercambiar(&x, &y)
   ESCRIBIR("x=", x, " y=", y)   // x=20, y=10
FIN_ACCION
```

**C/C++:**
```cpp
void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    intercambiar(&x, &y);
    printf("x=%d y=%d\n", x, y); // x=20 y=10
    return 0;
}
```

---

## Ejercicios para Practicar — Parte 1

**P1.1 (Pseudocódigo):** Escriba un procedimiento que reciba un puntero a un arreglo dinámico de enteros y su tamaño, y retorne la suma de todos los elementos.

**P1.2 (C/C++):** Implemente un programa que cree dinámicamente un arreglo de N enteros, los llene con valores leídos del usuario, muestre el promedio, y libere la memoria correctamente.

**P1.3 (Ambos):** Dado un struct `ALUMNO(codigo, nombre, nota)`, escriba primero en pseudocódigo y luego en C/C++ un subprograma que reciba un puntero a ALUMNO y modifique su nota.

<details>
<summary>🔑 Soluciones</summary>

**P1.1:**
```
ACCION sumaArreglo(ENTERO *arr, ENTERO n)
   ENTERO i, suma
   suma ← 0
   PARA i ← 0 HASTA n-1
      suma ← suma + arr[i]
      i ← i + 1
   FIN_PARA
   RETORNAR(suma)
FIN_ACCION
```

**P1.2:**
```cpp
#include <stdio.h>
int main() {
    int n;
    printf("Cantidad: "); scanf("%d", &n);
    int *arr = new int[n];
    float suma = 0;
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i); scanf("%d", &arr[i]);
        suma += arr[i];
    }
    printf("Promedio: %.2f\n", suma / n);
    delete[] arr;
    return 0;
}
```

**P1.3 Pseudocódigo:**
```
ACCION modificarNota(ALUMNO *alu, REAL nuevaNota)
   alu.nota ← nuevaNota
FIN_ACCION
```

**P1.3 C/C++:**
```cpp
void modificarNota(ALUMNO *alu, float nuevaNota) {
    alu->nota = nuevaNota;
}
```
</details>

---

# PARTE 2: LISTAS ENLAZADAS

## 2.1 Lista Enlazada Simple

### Teoría

Una **lista enlazada** es una colección de nodos donde cada nodo tiene un dato y un puntero al siguiente. Los nodos **NO** están contiguos en memoria.

```
cab → [5|→] → [3|→] → [8|NULL]
```

**Características (del material del profesor):**
- Son dinámicas: se crean y eliminan en tiempo de ejecución.
- Pueden expandirse y contraerse fácilmente.
- Se almacenan en posiciones de memoria NO contiguas.
- El acceso a los elementos es secuencial.

**Ventajas:** No necesita saber el número de elementos a almacenar; son flexibles.
**Desventajas:** Acceso secuencial; no son buenas para búsquedas en grandes cantidades de datos.

### Operaciones fundamentales

#### Crear lista vacía

**Pseudocódigo:**
```
ACCION crearLista(NODO cab)
   cab ← NULL
FIN_ACCION
```

**C/C++:**
```cpp
void crearLista(NODO **cab) {
    *cab = NULL;
}
```

#### Insertar al inicio — O(1)

**Pseudocódigo:**
```
ACCION insertarInicio(NODO cab, NODO cab1, TD dato)
   NODO p
   p ← nuevoNodo(cab1, dato)
   SI(p ≠ NULL)
      p.sgte ← cab
      cab ← p
   SINO
      ESCRIBIR("No hay espacio de memoria...")
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
void insertarInicio(NODO **cab, TD dato) {
    NODO *nuevo = new NODO;
    nuevo->valor = dato;
    nuevo->sgte = *cab;
    *cab = nuevo;
}
```

#### Insertar al final — O(n)

**Pseudocódigo:**
```
ACCION adicionaNodo(NODO cab, NODO cab1, TD dato)
   NODO p, q
   p ← nuevoNodo(cab1, dato)
   SI(p = NULL)
      ESCRIBIR("No hay espacio...")
   SINO
      SI(cab = NULL)
         cab ← p
      SINO
         q ← cab
         MIENTRAS(q.sgte ≠ NULL)
            q ← q.sgte
         FIN_MIENTRAS
         q.sgte ← p
      FIN_SI
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
void insertarFinal(NODO **cab, TD dato) {
    NODO *nuevo = new NODO;
    nuevo->valor = dato;
    nuevo->sgte = NULL;
    if (*cab == NULL) { *cab = nuevo; return; }
    NODO *temp = *cab;
    while (temp->sgte != NULL) temp = temp->sgte;
    temp->sgte = nuevo;
}
```

#### Eliminar al inicio — O(1)

**Pseudocódigo:**
```
ACCION eliminarInicio(NODO cab, NODO cab1)
   NODO p
   SI(cab = NULL)
      ESCRIBIR("Lista vacía")
   SINO
      p ← cab
      cab ← cab.sgte
      liberaNodo(cab1, p)
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
void eliminarInicio(NODO **cab) {
    if (*cab == NULL) { printf("Lista vacía\n"); return; }
    NODO *temp = *cab;
    *cab = (*cab)->sgte;
    delete temp;
}
```

#### Recorrer / Mostrar — O(n)

**Pseudocódigo:**
```
ACCION mostrarLista(NODO cab)
   NODO aux
   aux ← cab
   MIENTRAS(aux ≠ NULL)
      ESCRIBIR(aux.valor, " ")
      aux ← aux.sgte
   FIN_MIENTRAS
FIN_ACCION
```

**C/C++:**
```cpp
void mostrarLista(NODO *cab) {
    NODO *aux = cab;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->sgte;
    }
    printf("\n");
}
```

#### Buscar dato — O(n)

**Pseudocódigo:**
```
ACCION buscarDato(NODO cab, TD dato)
   NODO aux
   aux ← cab
   MIENTRAS(aux ≠ NULL Y aux.valor ≠ dato)
      aux ← aux.sgte
   FIN_MIENTRAS
   SI(aux = NULL)
      ESCRIBIR(dato, " no encontrado")
   SINO
      ESCRIBIR(dato, " encontrado")
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
NODO* buscarDato(NODO *cab, TD dato) {
    NODO *aux = cab;
    while (aux != NULL && aux->valor != dato)
        aux = aux->sgte;
    return aux; // NULL si no encontrado
}
```

---

## 2.2 Lista Enlazada Doble

### Teoría

Cada nodo tiene **dos** campos de enlace: uno al siguiente y otro al anterior. Permite recorrido en ambas direcciones.

```
NULL ← [←|5|→] ↔ [←|3|→] ↔ [←|8|→] → NULL
```

### Operaciones

#### Insertar al inicio (lista doble)

**Pseudocódigo:**
```
ACCION insertaNodoIni(NODOD cab, NODOD cab1, TD dato)
   NODOD p
   p ← nuevoNodo(cab1, dato)
   SI(p = NULL)
      ESCRIBIR("No hay espacio...")
      EXIT(0)
   SINO
      SI(cab = NULL)
         cab ← p
      SINO
         p.sgte ← cab
         cab.ante ← p
         cab ← p
      FIN_SI
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
void insertarInicioDoble(NODOD **cab, TD dato) {
    NODOD *p = new NODOD;
    p->valor = dato;
    p->ante = NULL;
    p->sgte = *cab;
    if (*cab != NULL) (*cab)->ante = p;
    *cab = p;
}
```

#### Insertar al final (lista doble)

**Pseudocódigo:**
```
ACCION insertaNodoFin(NODOD cab, NODOD cab1, TD dato)
   NODOD p, q
   p ← nuevoNodo(cab1, dato)
   SI(cab = NULL)
      cab ← p
   SINO
      q ← cab
      MIENTRAS(q.sgte ≠ NULL)
         q ← q.sgte
      FIN_MIENTRAS
      q.sgte ← p
      p.ante ← q
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
void insertarFinalDoble(NODOD **cab, TD dato) {
    NODOD *p = new NODOD;
    p->valor = dato; p->sgte = NULL; p->ante = NULL;
    if (*cab == NULL) { *cab = p; return; }
    NODOD *q = *cab;
    while (q->sgte != NULL) q = q->sgte;
    q->sgte = p;
    p->ante = q;
}
```

#### Eliminar inicio (lista doble)

**Pseudocódigo:**
```
ACCION eliminaInicio(NODOD cab, NODOD cab1)
   NODOD p
   p ← cab
   SI(p = NULL)
      ESCRIBIR("Lista vacía...")
   SINO
      cab ← cab.sgte
      cab.ante ← NULL
      liberaNodo(cab1, p)
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
void eliminarInicioDoble(NODOD **cab) {
    if (*cab == NULL) { printf("Lista vacía\n"); return; }
    NODOD *p = *cab;
    *cab = (*cab)->sgte;
    if (*cab != NULL) (*cab)->ante = NULL;
    delete p;
}
```

---

## Ejercicios Resueltos — Parte 2

### Ejercicio 2.1: Contar nodos de una lista simple

**Pseudocódigo:**
```
ACCION contarNodos(NODO cab)
   NODO aux
   ENTERO cont ← 0
   aux ← cab
   MIENTRAS(aux ≠ NULL)
      cont ← cont + 1
      aux ← aux.sgte
   FIN_MIENTRAS
   RETORNAR(cont)
FIN_ACCION
```

**C/C++:**
```cpp
int contarNodos(NODO *cab) {
    int cont = 0;
    NODO *aux = cab;
    while (aux != NULL) {
        cont++;
        aux = aux->sgte;
    }
    return cont;
}
```

### Ejercicio 2.2: Eliminar un nodo con valor dado en lista simple

**Pseudocódigo:**
```
ACCION eliminarDato(NODO cab, NODO cab1, TD dato)
   NODO aux, ante
   aux ← cab
   ante ← NULL
   // Caso 1: Nodo a eliminar es el primero
   SI(aux ≠ NULL Y aux.valor = dato)
      cab ← aux.sgte
      liberaNodo(cab1, aux)
   SINO
      // Buscar nodo y su anterior
      MIENTRAS(aux ≠ NULL Y aux.valor ≠ dato)
         ante ← aux
         aux ← aux.sgte
      FIN_MIENTRAS
      SI(aux = NULL)
         ESCRIBIR(dato, " no encontrado")
      SINO
         ante.sgte ← aux.sgte
         liberaNodo(cab1, aux)
      FIN_SI
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
void eliminarDato(NODO **cab, TD dato) {
    NODO *aux = *cab, *ante = NULL;
    // Caso 1: el primero
    if (aux != NULL && aux->valor == dato) {
        *cab = aux->sgte;
        delete aux;
        return;
    }
    // Buscar
    while (aux != NULL && aux->valor != dato) {
        ante = aux;
        aux = aux->sgte;
    }
    if (aux == NULL) { printf("No encontrado\n"); return; }
    ante->sgte = aux->sgte;
    delete aux;
}
```

---

## Ejercicios para Practicar — Parte 2

**P2.1 (Pseudocódigo):** Escriba un subprograma para invertir una lista enlazada simple.

**P2.2 (C/C++):** Implemente una función que inserte un nodo después de un nodo con valor dado.

**P2.3 (Ambos):** Implemente insertar un nodo en orden ascendente en una lista simple.

<details>
<summary>🔑 Soluciones</summary>

**P2.1:**
```
ACCION invertirLista(NODO cab)
   NODO ante, actual, sgte
   ante ← NULL
   actual ← cab
   MIENTRAS(actual ≠ NULL)
      sgte ← actual.sgte
      actual.sgte ← ante
      ante ← actual
      actual ← sgte
   FIN_MIENTRAS
   cab ← ante
FIN_ACCION
```

**P2.2:**
```cpp
void insertarDespuesDe(NODO *cab, TD valorBuscado, TD nuevoDato) {
    NODO *aux = cab;
    while (aux != NULL && aux->valor != valorBuscado)
        aux = aux->sgte;
    if (aux == NULL) { printf("No encontrado\n"); return; }
    NODO *nuevo = new NODO;
    nuevo->valor = nuevoDato;
    nuevo->sgte = aux->sgte;
    aux->sgte = nuevo;
}
```

**P2.3 Pseudocódigo:**
```
ACCION insertarOrdenado(NODO cab, TD dato)
   NODO p, aux, ante
   p ← new NODO
   p.valor ← dato
   p.sgte ← NULL
   SI(cab = NULL O dato ≤ cab.valor)
      p.sgte ← cab
      cab ← p
   SINO
      aux ← cab
      MIENTRAS(aux ≠ NULL Y aux.valor < dato)
         ante ← aux
         aux ← aux.sgte
      FIN_MIENTRAS
      ante.sgte ← p
      p.sgte ← aux
   FIN_SI
FIN_ACCION
```

**P2.3 C/C++:**
```cpp
void insertarOrdenado(NODO **cab, TD dato) {
    NODO *p = new NODO;
    p->valor = dato; p->sgte = NULL;
    if (*cab == NULL || dato <= (*cab)->valor) {
        p->sgte = *cab;
        *cab = p;
    } else {
        NODO *aux = *cab, *ante = NULL;
        while (aux != NULL && aux->valor < dato) {
            ante = aux; aux = aux->sgte;
        }
        ante->sgte = p;
        p->sgte = aux;
    }
}
```
</details>

---
