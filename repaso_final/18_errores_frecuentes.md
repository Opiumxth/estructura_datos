# ERRORES FRECUENTES - ESTRUCTURAS DE DATOS

---

## Punteros

### 1. Puntero sin inicializar

**Error:**
```cpp
int* p;
*p = 5;  // CRASH - apunta a basura
```

**Solución:**
```cpp
int* p = nullptr;  // o p = &x;
```

### 2. Doble liberación (double free)

**Error:**
```cpp
int* p = new int;
delete p;
delete p;  // Comportamiento indefinido
```

**Solución:**
```cpp
int* p = new int;
delete p;
p = nullptr;  // Prevenir doble delete
```

### 3. Memory leak

**Error:**
```cpp
int* p = new int;
*p = 10;
// sin delete → memoria perdida
```

**Solución:**
```cpp
int* p = new int;
*p = 10;
delete p;
p = nullptr;
```

### 4. Puntero colgante (dangling pointer)

**Error:**
```cpp
int* p = new int;
*p = 10;
delete p;
*p = 3;  // p apunta a memoria liberada
```

**Solución:**
```cpp
int* p = new int;
*p = 10;
delete p;
p = nullptr;  // p ya no apunta a nada válido
```

### 5. Confundir `*` con `&`

**Error:**
```cpp
int x = 10;
int* p = x;  // Error: asignando valor a puntero
```

**Solución:**
```cpp
int x = 10;
int* p = &x;  // Correcto: asignando dirección
```

---

## Memoria Dinámica

### 1. Olvidar liberar memoria

**Error:**
```cpp
void funcion() {
    int* arr = new int[100];
    // procesar arr
    // sin delete[] → memory leak
}
```

**Solución:**
```cpp
void funcion() {
    int* arr = new int[100];
    // procesar arr
    delete[] arr;
}
```

### 2. Usar `delete` en lugar de `delete[]` para arreglos

**Error:**
```cpp
int* arr = new int[100];
delete arr;  // Incorrecto para arreglos
```

**Solución:**
```cpp
int* arr = new int[100];
delete[] arr;  // Correcto para arreglos
```

### 3. No verificar si `new` falló

**Error:**
```cpp
int* p = new int[1000000000];  // Puede fallar
*p = 10;  // CRASH si new falló
```

**Solución:**
```cpp
int* p = new int[1000000000];
if (p == nullptr) {
    printf("Sin memoria\n");
    return;
}
*p = 10;
```

---

## Listas Enlazadas

### 1. Olvidar inicializar `sgte` a NULL

**Error:**
```cpp
NODO* nuevo = new NODO;
nuevo->valor = 10;
// olvidar nuevo->sgte = NULL
nuevo->sgte = cab;  // sgte tiene basura
```

**Solución:**
```cpp
NODO* nuevo = new NODO;
nuevo->valor = 10;
nuevo->sgte = NULL;  // OBLIGATORIO
nuevo->sgte = cab;
```

### 2. No usar doble puntero para modificar la cabeza

**Error:**
```cpp
void insertarInicio(NODO* cab, int dato) {
    NODO* nuevo = new NODO;
    nuevo->valor = dato;
    nuevo->sgte = cab;
    cab = nuevo;  // Solo modifica la copia local
}
```

**Solución:**
```cpp
void insertarInicio(NODO** cab, int dato) {
    NODO* nuevo = new NODO;
    nuevo->valor = dato;
    nuevo->sgte = *cab;
    *cab = nuevo;  // Modifica el puntero original
}
```

### 3. Olvidar caso de lista vacía

**Error:**
```cpp
void mostrar(NODO* cab) {
    NODO* temp = cab;
    while (temp->sgte != NULL) {  // Si cab es NULL, CRASH
        printf("%d ", temp->valor);
        temp = temp->sgte;
    }
}
```

**Solución:**
```cpp
void mostrar(NODO* cab) {
    if (cab == NULL) {
        printf("Lista vacía\n");
        return;
    }
    NODO* temp = cab;
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->sgte;
    }
}
```

### 4. Perder el puntero antes de liberar

**Error:**
```cpp
void liberarLista(NODO* cab) {
    while (cab != NULL) {
        cab = cab->sgte;  // Perdemos el puntero antes de delete
        delete cab;  // CRASH
    }
}
```

**Solución:**
```cpp
void liberarLista(NODO** cab) {
    NODO* temp;
    while (*cab != NULL) {
        temp = *cab;
        *cab = (*cab)->sgte;
        delete temp;
    }
}
```

---

## Pilas

### 1. Stack underflow (pop en pila vacía)

**Error:**
```cpp
int pop(NODO* pila) {
    if (pila == NULL) return -1;  // No maneja el error adecuadamente
    NODO* temp = pila;
    int valor = temp->valor;
    pila = pila->sgte;
    delete temp;
    return valor;
}
```

**Solución:**
```cpp
int pop(NODO** pila) {
    if (*pila == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    NODO* temp = *pila;
    int valor = temp->valor;
    *pila = (*pila)->sgte;
    delete temp;
    return valor;
}
```

### 2. No usar doble puntero

**Error:** Similar a listas, no usar `NODO**` para modificar la cabeza de la pila.

---

## Colas

### 1. Confundir frente y final

**Error:**
```cpp
void enqueue(NODO** frente, NODO** final, int dato) {
    NODO* nuevo = new NODO;
    nuevo->valor = dato;
    nuevo->sgte = NULL;
    
    if (*frente == NULL) {
        *frente = *final = nuevo;
    } else {
        (*frente)->sgte = nuevo;  // ERROR: debería ser final
        *final = nuevo;
    }
}
```

**Solución:**
```cpp
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
```

### 2. No actualizar ambos punteros cuando la cola queda vacía

**Error:**
```cpp
int dequeue(NODO** frente, NODO** final) {
    if (*frente == NULL) return -1;
    
    NODO* temp = *frente;
    int valor = temp->valor;
    *frente = (*frente)->sgte;
    delete temp;
    return valor;
    // Olvidar actualizar *final si la cola queda vacía
}
```

**Solución:**
```cpp
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

---

## Árboles Binarios

### 1. Olvidar caso base en recursión

**Error:**
```cpp
void preOrden(NODO* raiz) {
    printf("%c ", raiz->info);  // CRASH si raiz es NULL
    preOrden(raiz->izq);
    preOrden(raiz->der);
}
```

**Solución:**
```cpp
void preOrden(NODO* raiz) {
    if (raiz == NULL) return;  // Caso base
    printf("%c ", raiz->info);
    preOrden(raiz->izq);
    preOrden(raiz->der);
}
```

### 2. Confundir orden de recorridos

**Error:**
```cpp
// Quería InOrden pero escribió PreOrden
void inOrden(NODO* raiz) {
    if (raiz == NULL) return;
    printf("%c ", raiz->info);  // ERROR: debería ir en el medio
    inOrden(raiz->izq);
    inOrden(raiz->der);
}
```

**Solución:**
```cpp
void inOrden(NODO* raiz) {
    if (raiz == NULL) return;
    inOrden(raiz->izq);
    printf("%c ", raiz->info);  // Correcto: en el medio
    inOrden(raiz->der);
}
```

### 3. Altura incorrecta para árbol vacío

**Error:**
```cpp
int altura(NODO* raiz) {
    if (raiz == NULL) return 0;  // ERROR: debería ser -1
    return 1 + max(altura(raiz->izq), altura(raiz->der));
}
```

**Solución:**
```cpp
int altura(NODO* raiz) {
    if (raiz == NULL) return -1;  // Correcto: árbol vacío tiene altura -1
    return 1 + max(altura(raiz->izq), altura(raiz->der));
}
```

---

## ABB (Árboles Binarios de Búsqueda)

### 1. No usar doble puntero en inserción

**Error:**
```cpp
void insertar(NODO* raiz, int valor) {
    if (raiz == NULL) {
        raiz = new NODO;  // Solo modifica la copia local
        raiz->info = valor;
        raiz->izq = raiz->der = NULL;
    } else {
        if (valor < raiz->info) {
            insertar(raiz->izq, valor);
        } else {
            insertar(raiz->der, valor);
        }
    }
}
```

**Solución:**
```cpp
void insertar(NODO** raiz, int valor) {
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
```

### 2. Confundir propiedad de ordenamiento

**Error:**
```cpp
// Propiedad incorrecta: izq ≤ raíz < der
if (valor <= raiz->info) {
    insertar(raiz->izq, valor);
} else {
    insertar(raiz->der, valor);
}
```

**Solución:**
```cpp
// Propiedad correcta: izq < raíz ≤ der
if (valor < raiz->info) {
    insertar(raiz->izq, valor);
} else {
    insertar(raiz->der, valor);
}
```

### 3. Olvidar caso de dos hijos en eliminación

**Error:**
```cpp
NODO* eliminar(NODO* raiz, int valor) {
    if (raiz == NULL) return raiz;
    
    if (valor < raiz->info) {
        raiz->izq = eliminar(raiz->izq, valor);
    } else if (valor > raiz->info) {
        raiz->der = eliminar(raiz->der, valor);
    } else {
        // Encontrado
        if (raiz->izq == NULL) {
            NODO* temp = raiz->der;
            delete raiz;
            return temp;
        } else if (raiz->der == NULL) {
            NODO* temp = raiz->izq;
            delete raiz;
            return temp;
        }
        // OLVIDÓ CASO DE DOS HIJOS
    }
    return raiz;
}
```

**Solución:**
```cpp
NODO* eliminar(NODO* raiz, int valor) {
    if (raiz == NULL) return raiz;
    
    if (valor < raiz->info) {
        raiz->izq = eliminar(raiz->izq, valor);
    } else if (valor > raiz->info) {
        raiz->der = eliminar(raiz->der, valor);
    } else {
        // Encontrado
        if (raiz->izq == NULL) {
            NODO* temp = raiz->der;
            delete raiz;
            return temp;
        } else if (raiz->der == NULL) {
            NODO* temp = raiz->izq;
            delete raiz;
            return temp;
        }
        
        // Caso de dos hijos
        NODO* temp = encontrarMinimo(raiz->der);
        raiz->info = temp->info;
        raiz->der = eliminar(raiz->der, temp->info);
    }
    return raiz;
}
```

---

## AVL

### 1. No actualizar altura después de rotación

**Error:**
```cpp
NODO* rotarDerecha(NODO *y) {
    NODO *x = y->izq;
    NODO *T2 = x->der;
    
    x->der = y;
    y->izq = T2;
    
    // OLVIDÓ ACTUALIZAR ALTURAS
    return x;
}
```

**Solución:**
```cpp
NODO* rotarDerecha(NODO *y) {
    NODO *x = y->izq;
    NODO *T2 = x->der;
    
    x->der = y;
    y->izq = T2;
    
    // Actualizar alturas
    y->altura = 1 + max(obtenerAltura(y->izq), obtenerAltura(y->der));
    x->altura = 1 + max(obtenerAltura(x->izq), obtenerAltura(x->der));
    
    return x;
}
```

### 2. Confundir signo del Factor de Equilibrio

**Error:**
```cpp
int obtenerFE(NODO *n) {
    if (n == NULL) return 0;
    return obtenerAltura(n->izq) - obtenerAltura(n->der);  // ERROR: signo invertido
}
```

**Solución:**
```cpp
int obtenerFE(NODO *n) {
    if (n == NULL) return 0;
    return obtenerAltura(n->der) - obtenerAltura(n->izq);  // Correcto
}
```

### 3. No verificar FE del hijo para decidir rotación

**Error:**
```cpp
// Siempre hace rotación simple
if (fe < -1) {
    return rotarDerecha(nodo);
}
```

**Solución:**
```cpp
// Verifica FE del hijo para decidir simple vs doble
if (fe < -1 && valor < nodo->izq->dato) {
    return rotarDerecha(nodo);  // Simple LL
}
if (fe < -1 && valor > nodo->izq->dato) {
    nodo->izq = rotarIzquierda(nodo->izq);
    return rotarDerecha(nodo);  // Doble LR
}
```

---

## Archivos

### 1. Olvidar cerrar archivos

**Error:**
```cpp
FILE* f = fopen("datos.dat", "wb");
fwrite(&dato, sizeof(dato), 1, f);
// olvidar fclose(f)
```

**Solución:**
```cpp
FILE* f = fopen("datos.dat", "wb");
fwrite(&dato, sizeof(dato), 1, f);
fclose(f);  // OBLIGATORIO
```

### 2. No verificar si el archivo se abrió correctamente

**Error:**
```cpp
FILE* f = fopen("datos.dat", "rb");
fwrite(&dato, sizeof(dato), 1, f);  // CRASH si f es NULL
```

**Solución:**
```cpp
FILE* f = fopen("datos.dat", "rb");
if (f == NULL) {
    printf("Error al abrir archivo\n");
    return;
}
fwrite(&dato, sizeof(dato), 1, f);
fclose(f);
```

### 3. Confundir modo de apertura

**Error:**
```cpp
FILE* f = fopen("datos.dat", "r");  // Modo texto
fwrite(&dato, sizeof(dato), 1, f);  // Error: fwrite requiere modo binario
```

**Solución:**
```cpp
FILE* f = fopen("datos.dat", "wb");  // Modo binario correcto
fwrite(&dato, sizeof(dato), 1, f);
fclose(f);
```

---

## Ordenamiento

### 1. Error en condición de bucle (off-by-one)

**Error:**
```cpp
for (int i = 0; i <= n; i++) {  // Error: debería ser i < n
    // ...
}
```

**Solución:**
```cpp
for (int i = 0; i < n; i++) {  // Correcto
    // ...
}
```

### 2. No usar variable temporal en intercambio

**Error:**
```cpp
a = b;
b = a;  // a ya perdió su valor original
```

**Solución:**
```cpp
int temp = a;
a = b;
b = temp;
```

### 3. Confundir índices en QuickSort

**Error:**
```cpp
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {  // Error: debería ser j <= high-1
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}
```

**Solución:**
```cpp
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {  // Correcto
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}
```

---

## Consejos Generales

1. **Siempre inicializa punteros** a `nullptr` o a una dirección válida
2. **Siempre verifica NULL** antes de desreferenciar punteros
3. **Siempre usa doble puntero** (`NODO**`) cuando la función modifica la cabeza
4. **Siempre empareja `new` con `delete`** y `new[]` con `delete[]`
5. **Siempre cierra archivos** después de usarlos
6. **Siempre incluye caso base** en funciones recursivas
7. **Siempre actualiza alturas** en AVL después de rotaciones
8. **Siempre verifica casos especiales**: lista vacía, un solo nodo, etc.
9. **Dibuja las estructuras** en papel para entender el estado
10. **Usa el depurador** para seguir la ejecución paso a paso
