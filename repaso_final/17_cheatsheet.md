# CHEATSHEET - ESTRUCTURAS DE DATOS

## Complejidades Big-O

### Estructuras de Datos

| Estructura | Acceso | Inserción | Eliminación | Búsqueda | Espacio |
|------------|--------|-----------|-------------|----------|---------|
| **Arreglo** | O(1) | O(n) | O(n) | O(n) / O(log n)* | O(n) fijo |
| **Lista Simple** | O(n) | O(1) inicio | O(1) inicio | O(n) | O(n) dinámico |
| **Lista Doble** | O(n) | O(1) inicio | O(1) inicio | O(n) | O(n) dinámico |
| **Pila** | O(1)† | O(1) | O(1) | O(n) | O(n) |
| **Cola** | O(1)†† | O(1) | O(1) | O(n) | O(n) |
| **ABB** | O(log n)‡ | O(log n)‡ | O(log n)‡ | O(log n)‡ | O(n) |
| **AVL** | O(log n) | O(log n) | O(log n) | O(log n) | O(n) |
| **Árbol B** | O(log_m n) | O(log_m n) | O(log_m n) | O(log_m n) | O(n) |
| **Trie** | O(L) | O(L) | O(L) | O(L) | O(n×L) |

```
* O(log n) solo si está ordenado (Búsqueda Binaria)
† Solo acceso al tope
†† Solo acceso al frente
‡ Promedio. Peor caso O(n) si el árbol está degenerado.
L = longitud de la palabra/cadena
m = orden del árbol B
```

### Algoritmos de Ordenamiento

| Algoritmo | Mejor | Promedio | Peor | Estable | Espacio |
|-----------|-------|----------|------|---------|---------|
| **Burbuja** | O(n) | O(n²) | O(n²) | Sí | O(1) |
| **Selección** | O(n²) | O(n²) | O(n²) | No | O(1) |
| **Inserción** | O(n) | O(n²) | O(n²) | Sí | O(1) |
| **QuickSort** | O(n log n) | O(n log n) | O(n²) | No | O(log n) |
| **MergeSort** | O(n log n) | O(n log n) | O(n log n) | Sí | O(n) |
| **HeapSort** | O(n log n) | O(n log n) | O(n log n) | No | O(1) |

### Algoritmos de Búsqueda

| Algoritmo | Complejidad | Requisito |
|-----------|-------------|-----------|
| **Lineal** | O(n) | Ninguno |
| **Binaria** | O(log n) | Datos ordenados |

### Jerarquía de Eficiencia

```
O(1)  <  O(log n)  <  O(n)  <  O(n log n)  <  O(n²)  <  O(2ⁿ)  <  O(n!)
 │          │          │           │             │
const.   binaria    lineal     merge/quick    burbuja
                                             selección
                                             inserción
```

---

## Operaciones por Estructura

### Punteros

```cpp
int x = 42;
int* p = &x;        // p guarda dirección de x
*p = 100;           // modifica x a través de p
```

**Operadores:**
- `&var` - dirección de
- `*ptr` - desreferencia
- `->` - acceso a campo de struct por puntero

**Errores comunes:**
- Puntero sin inicializar → CRASH
- Doble delete → comportamiento indefinido
- Memory leak → sin delete después de new

### Structs

```cpp
struct ALUMNO {
    int codigo;
    char nombre[50];
    float nota;
};

ALUMNO a;
a.codigo = 12345;
strcpy(a.nombre, "Juan");
a.nota = 15.5;
```

### Memoria Dinámica

```cpp
// C
int* p = (int*)malloc(sizeof(int));
*p = 10;
free(p);

// C++
int* p = new int;
*p = 10;
delete p;

// Arreglos dinámicos
int* arr = new int[n];
delete[] arr;
```

### Listas Enlazadas

```cpp
struct NODO {
    int valor;
    NODO* sgte;
};

// Insertar al inicio - O(1)
void insertarInicio(NODO** cab, int dato) {
    NODO* nuevo = new NODO;
    nuevo->valor = dato;
    nuevo->sgte = *cab;
    *cab = nuevo;
}

// Insertar al final - O(n)
void insertarFinal(NODO** cab, int dato) {
    NODO* nuevo = new NODO;
    nuevo->valor = dato;
    nuevo->sgte = NULL;
    
    if (*cab == NULL) {
        *cab = nuevo;
        return;
    }
    
    NODO* temp = *cab;
    while (temp->sgte != NULL) {
        temp = temp->sgte;
    }
    temp->sgte = nuevo;
}
```

### Pilas (LIFO)

```cpp
// Push - O(1)
void push(NODO** pila, int dato) {
    NODO* nuevo = new NODO;
    nuevo->valor = dato;
    nuevo->sgte = *pila;
    *pila = nuevo;
}

// Pop - O(1)
int pop(NODO** pila) {
    if (*pila == NULL) return -1;
    
    NODO* temp = *pila;
    int valor = temp->valor;
    *pila = (*pila)->sgte;
    delete temp;
    return valor;
}
```

### Colas (FIFO)

```cpp
// Enqueue - O(1)
void enqueue(NODO** frente, NODO** final, int dato) {
    NODO* nuevo = new NODO;
    nuevo->valor = dato;
    nuevo->sgte = NULL;
    
    if (*final == NULL) {
        *frente = *final = nuevo;
    } else {
        (*final)->sgte = nuevo;
        *final = nuevo;
    }
}

// Dequeue - O(1)
int dequeue(NODO** frente, NODO** final) {
    if (*frente == NULL) return -1;
    
    NODO* temp = *frente;
    int valor = temp->valor;
    *frente = (*frente)->sgte;
    
    if (*frente == NULL) {
        *final = NULL;
    }
    
    delete temp;
    return valor;
}
```

### Árboles Binarios

```cpp
struct NODO {
    TD info;
    NODO *izq;
    NODO *der;
};

// Recorridos (5 líneas cada uno)
void preOrden(NODO *raiz) {
    if (raiz != NULL) {
        printf("%c ", raiz->info);
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}

void inOrden(NODO *raiz) {
    if (raiz != NULL) {
        inOrden(raiz->izq);
        printf("%c ", raiz->info);
        inOrden(raiz->der);
    }
}

void postOrden(NODO *raiz) {
    if (raiz != NULL) {
        postOrden(raiz->izq);
        postOrden(raiz->der);
        printf("%c ", raiz->info);
    }
}
```

### ABB (Árbol Binario de Búsqueda)

```cpp
// Propiedad: izq < raíz ≤ der

// Inserción
void insertar(NODO **raiz, int valor) {
    if (*raiz == NULL) {
        *raiz = new NODO;
        (*raiz)->info = valor;
        (*raiz)->izq = (*raiz)->der = NULL;
    } else {
        if (valor < (*raiz)->info) {
            insertar(&(*raiz)->izq, valor);
        } else {
            insertar(&(*raiz)->der, valor);
        }
    }
}

// Búsqueda
NODO* buscar(NODO *raiz, int valor) {
    if (raiz == NULL) return NULL;
    if (valor == raiz->info) return raiz;
    
    if (valor < raiz->info) {
        return buscar(raiz->izq, valor);
    } else {
        return buscar(raiz->der, valor);
    }
}
```

### AVL

```cpp
struct NODO {
    int dato;
    NODO *izq;
    NODO *der;
    int altura;  // ← campo adicional
};

// Factor de Equilibrio
int obtenerFE(NODO *n) {
    if (n == NULL) return 0;
    return obtenerAltura(n->der) - obtenerAltura(n->izq);
}

// Rotación derecha (Caso LL)
NODO* rotarDerecha(NODO *y) {
    NODO *x = y->izq;
    NODO *T2 = x->der;
    
    x->der = y;
    y->izq = T2;
    
    y->altura = 1 + max(obtenerAltura(y->izq), obtenerAltura(y->der));
    x->altura = 1 + max(obtenerAltura(x->izq), obtenerAltura(x->der));
    
    return x;
}

// Rotación izquierda (Caso RR)
NODO* rotarIzquierda(NODO *x) {
    NODO *y = x->der;
    NODO *T2 = y->izq;
    
    y->izq = x;
    x->der = T2;
    
    x->altura = 1 + max(obtenerAltura(x->izq), obtenerAltura(x->der));
    y->altura = 1 + max(obtenerAltura(y->izq), obtenerAltura(y->der));
    
    return y;
}
```

---

## Fórmulas Clave

### Ordenamiento
- **Comparaciones Burbuja/Selección (peor caso):** n(n-1)/2
- **Comparaciones Búsqueda Binaria:** ⌊log₂(n)⌋ + 1

### Colas Circulares
- **Avanzar frente:** (frente + 1) % MAX
- **Avanzar final:** (final + 1) % MAX

### Árboles
- **Máx nodos en nivel n:** 2ⁿ
- **Máx nodos en árbol altura h:** 2^(h+1) - 1
- **Árbol vacío:** altura = -1
- **Factor de Equilibrio AVL:** FE = altura(der) - altura(izq)

### Archivos
- **sizeof(struct):** Bytes que ocupa un struct (para archivos binarios)

---

## Equivalencias Pseudocódigo ↔ C/C++

| Pseudocódigo | C/C++ |
|-------------|-------|
| `REGISTRO NODO` | `struct NODO {` |
| `FIN_REGISTRO` | `};` |
| `ACCION nombre(params)` | `void nombre(params) {` |
| `FIN_ACCION` | `}` |
| `RETORNAR(valor)` | `return valor;` |
| `p ← nuevoNodo(cab1, dato)` | `p = new NODO;` o `(NODO*)malloc(sizeof(NODO))` |
| `liberaNodo(cab1, p)` | `delete p;` o `free(p);` |
| `p.sgte ← cab` | `p->sgte = cab;` |
| `SI(cond) ... FIN_SI` | `if(cond) { ... }` |
| `MIENTRAS(cond) ... FIN_MIENTRAS` | `while(cond) { ... }` |
| `PARA i ← 0 HASTA n-1` | `for(int i=0; i<n; i++)` |
| `ESCRIBIR(...)` | `printf(...)` o `cout << ...` |
| `LEER(var)` | `scanf(...)` o `cin >> var` |

---

## Términos que DEBES Memorizar

| Término | Definición |
|---------|-----------|
| **Puntero** | Variable que almacena una dirección de memoria |
| **Struct** | Tipo de dato que agrupa variables de distintos tipos |
| **LIFO** | Last In, First Out → Pila |
| **FIFO** | First In, First Out → Cola |
| **TAD** | Tipo Abstracto de Dato: define QUÉ hace sin decir CÓMO |
| **Nodo** | Struct con dato + puntero al siguiente |
| **Memory leak** | Memoria reservada que nunca se libera |
| **Dangling pointer** | Puntero que apunta a memoria ya liberada |
| **Stack overflow** | Push en pila llena |
| **Stack underflow** | Pop en pila vacía |
| **Raíz** | Nodo sin padre en un árbol |
| **Hoja** | Nodo sin hijos (nodo terminal) |
| **Altura** | Nivel máximo del árbol |
| **ABB** | Árbol Binario de Búsqueda: izq < raíz ≤ der |
| **PreOrden** | Recorrido: Raíz, Izq, Der |
| **InOrden** | Recorrido: Izq, Raíz, Der (ordenado en ABB) |
| **PostOrden** | Recorrido: Izq, Der, Raíz |
| **AVL** | Árbol binario autobalanceado (|FE| ≤ 1) |
| **FE** | Factor de Equilibrio: altura(der) - altura(izq) |
| **Trie** | Árbol para almacenamiento eficiente de cadenas |
| **Huffman** | Árbol para compresión sin pérdida |

---

## Cuándo Usar Cada Estructura

| Necesidad | Estructura | Por qué |
|-----------|-----------|---------|
| Acceso por índice | Arreglo | O(1) directo |
| Tamaño desconocido + inserciones frecuentes | Lista | Dinámico, O(1) al inicio |
| Deshacer/rehacer, recursión, paréntesis | Pila | LIFO natural |
| Turnos, orden de llegada, BFS | Cola | FIFO natural |
| Datos ordenados + búsqueda rápida | Arreglo ordenado | Búsqueda binaria O(log n) |
| Búsqueda dinámica + inserción frecuente | ABB | O(log n) búsqueda e inserción |
| Búsqueda garantizada O(log n) | AVL | Siempre balanceado |
| Grandes volúmenes en disco | Árbol B | Minimiza accesos a disco |
| Diccionarios, autocompletado | Trie | Búsqueda O(longitud_palabra) |
| Compresión de datos | Huffman | Códigos de longitud variable |

---

## Patrones de Examen

### Punteros
- **Traza de punteros:** Dibuja variables y flechas en papel
- **Completar funciones:** Identifica si necesitas `&`, `*` o `->`
- **Detectar errores:** Busca: sin inicializar, sin `delete`, doble `delete`

### Listas
- **Implementar operación:** Manejar caso vacío, primer nodo, caso general
- **Traza de operaciones:** Dibuja la lista paso a paso
- **Doble puntero:** `NODO**` cuando la función modifica la cabeza

### Árboles
- **Recorridos:** Pre(RID), In(IRD), Post(IDR)
- **Construir ABB:** Menor va izquierda, mayor/igual va derecha
- **ABB vs AVL:** AVL garantiza O(log n), ABB puede degenerar
- **Rotaciones AVL:** LL (rotar derecha), RR (rotar izquierda), LR (izq+der), RL (der+izq)

### Ordenamiento
- **Burbuja:** O(n²), simple pero ineficiente
- **Selección:** O(n²), siempre n(n-1)/2 comparaciones
- **Inserción:** O(n²), eficiente para datos casi ordenados
- **QuickSort:** O(n log n) promedio, O(n²) peor caso
- **MergeSort:** O(n log n) siempre, estable

---

## Valores de Referencia

| n | O(log n) | O(n) | O(n log n) | O(n²) |
|---|----------|------|------------|-------|
| 10 | 3 | 10 | 33 | 100 |
| 100 | 7 | 100 | 664 | 10,000 |
| 1,000 | 10 | 1,000 | 9,966 | 1,000,000 |
| 1,000,000 | 20 | 1M | 20M | 1 billón |

---

## Funciones C/C++ del Curso

| Operación | C (estilo profesor) | C++ |
|----------|-------------------|-----|
| Reservar memoria | `(TIPO*)malloc(sizeof(TIPO))` | `new TIPO` |
| Liberar memoria | `free(p)` | `delete p` / `delete[] p` |
| Abrir archivo | `fopen("nombre", "modo")` | `ofstream f("nombre")` |
| Escribir binario | `fwrite(&dato, sizeof, n, f)` | `f.write((char*)&dato, sizeof)` |
| Leer binario | `fread(&dato, sizeof, 1, f)` | `f.read((char*)&dato, sizeof)` |
| Cerrar archivo | `fclose(f)` | `f.close()` |
| Imprimir | `printf(...)` | `cout << ...` |
| Leer entrada | `scanf(...)` | `cin >> var` |
