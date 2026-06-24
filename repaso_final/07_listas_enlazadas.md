# TEMA 7: LISTAS ENLAZADAS (SIMPLE Y DOBLE)

---

## 1. TEORÍA CLARA

### ¿Qué es?
Una colección de **nodos** donde cada nodo contiene un dato y un puntero al siguiente. Los nodos NO están contiguos en memoria; están conectados por punteros.

```
cabeza → [5|→] → [3|→] → [8|NULL]
```

### ¿Para qué sirve?
- **Tamaño dinámico:** Crece y se reduce según se necesite (a diferencia del arreglo).
- **Inserción/eliminación al inicio en O(1):** No necesita desplazar elementos.
- **Base para pilas y colas:** Una pila es una lista que solo opera en un extremo; una cola opera en dos.

### Arreglo vs Lista Enlazada

| Aspecto | Arreglo | Lista Enlazada |
|---------|---------|----------------|
| Acceso al elemento i | **O(1)** directo | O(n) recorrer |
| Insertar al inicio | O(n) desplazar | **O(1)** |
| Insertar al final | O(1) si hay espacio | O(n) recorrer |
| Tamaño | Fijo (estático) | Dinámico |
| Memoria extra | Ninguna | Un puntero por nodo |
| Búsqueda binaria | Posible | No Imposible |

### Estructura del nodo (estilo del curso)

**Pseudocódigo:**
```
Definición Tipo ENTERO TD
REGISTRO NODO
   TD valor
   NODO sgte
FIN_REGISTRO

NODO cab, p, q
```

**C/C++:**
```cpp
typedef int TD;
struct NODO {
    TD valor;
    NODO* sgte;
};
NODO *cab, *p, *q;
```

### Nodo para lista doble

**Pseudocódigo:**
```
REGISTRO NODOD
   TD valor
   NODO ante
   NODO sgte
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

### Operaciones fundamentales

| Operación | Complejidad | ¿Por qué? |
|-----------|-------------|-----------|
| Crear lista | O(1) | Solo poner `cab = NULL` |
| Insertar al inicio | **O(1)** | Solo ajustar 2 punteros |
| Insertar al final | O(n) | Recorrer hasta el último |
| Eliminar al inicio | **O(1)** | Mover cabeza y borrar |
| Eliminar al final | O(n) | Recorrer hasta el penúltimo |
| Buscar | O(n) | Recorrer nodo por nodo |
| Mostrar | O(n) | Recorrer completa |

### ¿Por qué `NODO** cab` (doble puntero)?
Cuando una función necesita **modificar** a dónde apunta la cabeza (ej: insertar al inicio), necesita la DIRECCIÓN del puntero cabeza, no una copia. Por eso se pasa `&cab` y la función recibe `NODO** cab`.

```
Sin doble puntero: la función recibe una COPIA del puntero → cambios se pierden
Con doble puntero: la función recibe la DIRECCIÓN del puntero → cambios permanecen
```

### Errores comunes
- No inicializar `nuevo->sgte = NULL` → al recorrer el while se pasa de largo
- No guardar referencia antes de eliminar: `temp = cab; cab = cab->sgte; delete temp;` (en ese orden)
- Acceder a `p->sgte` cuando `p` es NULL → CRASH
- No hacer `delete`/`free` al eliminar nodos → memory leak
- Olvidar actualizar `*cab` al insertar/eliminar al inicio

---

## 2. EJEMPLOS RESUELTOS

### Ejemplo 1: Lista completa con insertar, mostrar y eliminar

**Enunciado:** Implemente una lista simple con insertar al inicio, insertar al final, mostrar y eliminar al inicio. Estilo del profesor Salinas.

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

typedef int TD;

struct NODO {
    TD valor;
    NODO* sgte;
};
```
**Pseudocódigo — Crear lista e insertar al inicio:**
```
ACCION crearLista(NODO cab)
   cab ← NULL
FIN_ACCION

ACCION crearNodo(NODO cab1, TD dato)
   NODO p
   p ← nuevoNodo(cab1)
   SI(p ≠ NULL)
      p.valor ← dato
      p.sgte ← NULL
      RETORNAR(p)
   SINO
      ESCRIBIR("No hay espacio...")
      RETORNAR(NULL)
   FIN_SI
FIN_ACCION

ACCION insertarInicio(NODO cab, NODO cab1, TD dato)
   NODO p
   p ← crearNodo(cab1, dato)
   SI(p ≠ NULL)
      p.sgte ← cab
      cab ← p
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
// Crear lista vacía
void crearLista(NODO** cab) {
    *cab = NULL;
}

// Crear un nodo nuevo
NODO* crearNodo(TD dato) {
    NODO* p = (NODO*)malloc(sizeof(NODO));
    if (p == NULL) {
        printf("Sin memoria!\n");
        return NULL;
    }
    p->valor = dato;
    p->sgte = NULL;     // ← OBLIGATORIO
    return p;
}

// Insertar al inicio — O(1)
void insertarInicio(NODO** cab, TD dato) {
    NODO* nuevo = crearNodo(dato);
    if (nuevo == NULL) return;
    nuevo->sgte = *cab;   // nuevo apunta al antiguo primero
    *cab = nuevo;          // cabeza ahora es el nuevo
}
```

**Cómo traducir:** En pseudocódigo `p.sgte ← cab` equivale a `p->sgte = *cab` en C/C++. El pseudocódigo usa `.` siempre; C/C++ usa `->` con punteros.

**Pseudocódigo — Insertar al final:**
```
ACCION insertarFinal(NODO cab, NODO cab1, TD dato)
   NODO p, q
   p ← crearNodo(cab1, dato)
   SI(p ≠ NULL)
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
// Insertar al final — O(n)
void insertarFinal(NODO** cab, TD dato) {
    NODO* nuevo = crearNodo(dato);
    if (nuevo == NULL) return;
    if (*cab == NULL) { *cab = nuevo; return; }
    NODO* temp = *cab;
    while (temp->sgte != NULL) temp = temp->sgte;
    temp->sgte = nuevo;
}
```

**Pseudocódigo — Eliminar inicio y mostrar:**
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

ACCION mostrarLista(NODO cab)
   NODO aux
   aux ← cab
   SI(aux = NULL)
      ESCRIBIR("Lista vacía")
   SINO
      MIENTRAS(aux ≠ NULL)
         ESCRIBIR(aux.valor, " ")
         aux ← aux.sgte
      FIN_MIENTRAS
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
void eliminarInicio(NODO** cab) {
    if (*cab == NULL) { printf("Lista vacía!\n"); return; }
    NODO* temp = *cab;
    *cab = (*cab)->sgte;
    printf("Eliminado: %d\n", temp->valor);
    free(temp);
}

void mostrar(NODO* cab) {
    if (cab == NULL) { printf("Lista vacía\n"); return; }
    NODO* temp = cab;
    printf("Lista = {");
    while (temp != NULL) {
        printf("%d", temp->valor);
        if (temp->sgte != NULL) printf(" -> ");
        temp = temp->sgte;
    }
    printf("}\n");
}
// Liberar toda la lista
void liberarLista(NODO** cab) {
    NODO* temp;
    while (*cab != NULL) {
        temp = *cab;
        *cab = (*cab)->sgte;
        free(temp);
    }
}

int main() {
    NODO* lista;
    crearLista(&lista);
    
    insertarInicio(&lista, 10);
    insertarInicio(&lista, 20);
    insertarInicio(&lista, 30);
    insertarFinal(&lista, 5);
    
    mostrar(lista);
    // Lista = {30 -> 20 -> 10 -> 5}
    
    eliminarInicio(&lista);
    mostrar(lista);
    // Eliminado: 30
    // Lista = {20 -> 10 -> 5}
    
    liberarLista(&lista);
    return 0;
}
```

### Ejemplo 2: Buscar y eliminar un nodo con valor específico

**Enunciado:** Eliminar el nodo que contiene un valor dado, manejando los 3 casos: inicio, medio, final.

```cpp
void eliminarDato(NODO** cab, TD dato) {
    if (*cab == NULL) {
        printf("Lista vacía\n");
        return;
    }
    
    // Caso 1: el dato está en el primer nodo
    if ((*cab)->valor == dato) {
        NODO* temp = *cab;
        *cab = (*cab)->sgte;
        free(temp);
        printf("Eliminado: %d\n", dato);
        return;
    }
    
    // Caso 2 y 3: buscar en el resto
    NODO* anterior = *cab;
    NODO* actual = (*cab)->sgte;
    
    while (actual != NULL && actual->valor != dato) {
        anterior = actual;
        actual = actual->sgte;
    }
    
    if (actual == NULL) {
        printf("%d no encontrado\n", dato);
        return;
    }
    
    // Enlazar anterior con el siguiente de actual (salta el nodo)
    anterior->sgte = actual->sgte;
    free(actual);
    printf("Eliminado: %d\n", dato);
}
```

**Los 3 casos visualizados:**
```
Caso 1 - Eliminar al inicio (dato=30):
  ANTES:  cab → [30|→] → [20|→] → [10|NULL]
  DESPUÉS: cab → [20|→] → [10|NULL]       (free del 30)

Caso 2 - Eliminar en el medio (dato=20):
  ANTES:  cab → [30|→] → [20|→] → [10|NULL]
  DESPUÉS: cab → [30|→] → [10|NULL]       (free del 20)

Caso 3 - Eliminar al final (dato=10):
  ANTES:  cab → [30|→] → [20|→] → [10|NULL]
  DESPUÉS: cab → [30|→] → [20|NULL]       (free del 10)
```

---


## Preguntas de recuperación

1. ¿Por qué las listas enlazadas son necesarias cuando no conocemos el tamaño de los datos en tiempo de compilación?
2. ¿Cuál es la diferencia entre una lista simple y una lista doblemente enlazada y cuándo se usa cada una?
3. ¿Qué problema resuelve el uso de listas enlazadas en comparación con arreglos?
4. ¿Cómo se relaciona el concepto de puntero con la navegación en una lista enlazada?
5. ¿Qué ocurriría si pierdes la referencia al primer nodo de una lista?
6. ¿Cuándo conviene usar una lista circular en lugar de una lista lineal?
7. ¿Cómo se relacionan las listas enlazadas con la memoria dinámica?
8. ¿Qué ventajas y desventajas tiene una lista enlazada respecto a un arreglo?

## 3. EJERCICIOS PARA PRACTICAR

**Ejercicio 7.1 (Pseudocódigo):** Escriba en pseudocódigo una ACCION `contarNodos` que cuente los nodos de la lista.

**Ejercicio 7.2 (C/C++):** Implemente `TD sumarValores(NODO* cab)` que sume todos los valores de la lista.

**Ejercicio 7.3 (Ambos):** Escriba primero en pseudocódigo y luego en C/C++ `insertarOrdenado` que inserte manteniendo la lista ordenada de menor a mayor.

**Ejercicio 7.4 (Pseudocódigo → C/C++):** Dada una lista de structs `Alumno`, escriba primero en pseudocódigo y luego traduzca a C/C++ una función que muestre solo los alumnos con nota >= 14.

**Ejercicio 7.5 (C/C++):** Escriba `void invertirLista(NODO** cab)` que invierta la lista in-place con 3 punteros: `anterior`, `actual`, `siguiente`.

**Ejercicio 7.6 (Tipo examen — Ambos):** Dada una lista enlazada de enteros, escriba una función que separe pares en una lista e impares en otra. Resuelva en pseudocódigo y luego en C/C++.

### Listas Dobles — Operaciones clave

**Pseudocódigo — Insertar inicio en lista doble:**
```
ACCION insertaNodoIni(NODOD cab, NODOD cab1, TD dato)
   NODOD p
   p ← nuevoNodo(cab1, dato)
   SI(p = NULL)
      ESCRIBIR("No hay espacio...")
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
void insertarInicioDoble(NODOD** cab, TD dato) {
    NODOD* p = new NODOD;
    p->valor = dato;
    p->ante = NULL;
    p->sgte = *cab;
    if (*cab != NULL) (*cab)->ante = p;
    *cab = p;
}
```

---

## 4. PATRONES DE EXAMEN

- **Implementar operación:** Te piden insertar/eliminar/buscar en una lista. → Siempre manejar caso lista vacía, caso primer nodo, caso general.
- **Traza de operaciones:** Te dan una secuencia de operaciones y preguntan cómo queda la lista. → Dibuja la lista paso a paso.
- **Comparar con arreglo:** Pregunta teórica frecuente. → Lista: dinámica, O(1) insertar inicio, O(n) acceso. Arreglo: fijo, O(1) acceso, O(n) insertar inicio.
- **Doble puntero:** Si te preguntan por qué se usa `NODO**` → Porque necesitas modificar el puntero original (la cabeza).
- **Truco:** En examen, siempre dibuja el estado de la lista antes y después de cada operación. Los errores en listas son casi siempre errores de "a dónde apunta este puntero".

### Chuleta de repaso rápido
```
NODO = { valor, NODO* sgte }
crearLista:      *cab = NULL
crearNodo:       malloc + valor + sgte=NULL
insertarInicio:  nuevo->sgte = *cab; *cab = nuevo;    O(1)
insertarFinal:   while(temp->sgte!=NULL) avanzar      O(n)
eliminarInicio:  temp=*cab; *cab=(*cab)->sgte; free    O(1)
eliminarDato:    buscar con anterior/actual; enlazar   O(n)
mostrar:         while(temp!=NULL) imprimir, avanzar   O(n)

SIEMPRE: nuevo->sgte = NULL al crear
SIEMPRE: guardar temp antes de free
SIEMPRE: verificar if(*cab == NULL) para lista vacía
Doble puntero (**) cuando la función modifica la cabeza
```
