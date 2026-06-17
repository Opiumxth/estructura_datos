# TEMA 7: LISTAS ENLAZADAS (SIMPLE)

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
| Búsqueda binaria | ✅ Posible | ❌ Imposible |

### Estructura del nodo (estilo del curso)

```cpp
typedef int TD;

struct NODO {
    TD valor;
    NODO* sgte;
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

// Insertar al final — O(n)
void insertarFinal(NODO** cab, TD dato) {
    NODO* nuevo = crearNodo(dato);
    if (nuevo == NULL) return;
    
    if (*cab == NULL) {       // lista vacía
        *cab = nuevo;
        return;
    }
    
    NODO* temp = *cab;
    while (temp->sgte != NULL) {   // avanzar hasta el último
        temp = temp->sgte;
    }
    temp->sgte = nuevo;            // el último ahora apunta al nuevo
}

// Eliminar al inicio — O(1)
void eliminarInicio(NODO** cab) {
    if (*cab == NULL) {
        printf("Lista vacía!\n");
        return;
    }
    NODO* temp = *cab;       // guardar referencia al primero
    *cab = (*cab)->sgte;     // cabeza avanza al segundo
    printf("Eliminado: %d\n", temp->valor);
    free(temp);              // liberar el antiguo primero
}

// Mostrar lista — O(n)
void mostrar(NODO* cab) {
    if (cab == NULL) {
        printf("Lista vacía\n");
        return;
    }
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

## 3. EJERCICIOS PARA PRACTICAR

**Ejercicio 7.1 (Fácil):** Escriba una función `int contarNodos(NODO* cab)` que devuelva cuántos nodos tiene la lista.

**Ejercicio 7.2 (Fácil):** Escriba una función `TD sumarValores(NODO* cab)` que sume todos los valores de la lista y devuelva el total.

**Ejercicio 7.3 (Medio):** Escriba una función `void insertarOrdenado(NODO** cab, TD dato)` que inserte un nuevo nodo de forma que la lista se mantenga ordenada de menor a mayor.

**Ejercicio 7.4 (Medio):** Dada una lista de structs `Alumno` (código, nombre, nota), escriba una función que muestre solo los alumnos con nota >= 14 y devuelva cuántos son.

**Ejercicio 7.5 (Difícil):** Escriba una función `void invertirLista(NODO** cab)` que invierta la lista in-place (sin crear una nueva). Use 3 punteros: `anterior`, `actual`, `siguiente`.

**Ejercicio 7.6 (Tipo examen):** Dada una lista enlazada de enteros, escriba una función que separe los pares en una lista y los impares en otra lista. La lista original debe quedar vacía.

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
