# SIMULACRO DE EXAMEN FINAL - ESTRUCTURAS DE DATOS

---

## Instrucciones

- **Tiempo:** 120 minutos
- **Formato:** Preguntas en pseudocódigo Y C/C++
- **Puntuación:** 100 puntos totales
- **Material:** No permitido

---

## SECCIÓN 1: TEORÍA (20 puntos)

### Pregunta 1 (5 puntos)
Explique la diferencia entre un ABB y un AVL. ¿Por qué un AVL garantiza O(log n) en todas las operaciones mientras que un ABB no?

### Pregunta 2 (5 puntos)
¿Qué es un árbol B y para qué tipo de aplicaciones se utiliza principalmente? Explique la propiedad que garantiza que todas las hojas estén al mismo nivel.

### Pregunta 3 (5 puntos)
Compare las estructuras de datos siguientes en términos de complejidad de búsqueda y uso de memoria: Arreglo, Lista Enlazada, ABB, Trie. ¿Cuándo conviene usar cada una?

### Pregunta 4 (5 puntos)
Explique el principio de compresión de Huffman. ¿Por qué los símbolos más frecuentes tienen códigos más cortos? ¿Qué propiedad garantiza que la compresión sea sin pérdida?

---

## SECCIÓN 2: PUNTEROS Y MEMORIA DINÁMICA (15 puntos)

### Pregunta 5 (8 puntos) - Pseudocódigo

Escriba en pseudocódigo una ACCIÓN que reciba un arreglo de enteros y su tamaño, e invierta el arreglo in-place usando aritmética de punteros (sin usar índices []). Use dos punteros: uno al inicio y otro al final.

### Pregunta 6 (7 puntos) - C/C++

Implemente en C/C++ una función `void duplicar(int* arr, int n)` que reciba un arreglo como puntero y duplique cada elemento in-place (sin crear otro arreglo). Asegúrese de manejar el caso de arreglo vacío.

---

## SECCIÓN 3: LISTAS ENLAZADAS (15 puntos)

### Pregunta 7 (8 puntos) - Pseudocódigo

Escriba en pseudocódigo una ACCION `insertarOrdenado` que inserte un valor en una lista enlazada simple manteniendo la lista ordenada de menor a mayor. Considere los casos: lista vacía, insertar al inicio, insertar en medio, insertar al final.

### Pregunta 8 (7 puntos) - C/C++

Implemente en C/C++ una función `void invertirLista(NODO** cab)` que invierta una lista enlazada simple in-place usando tres punteros: `anterior`, `actual`, `siguiente`.

---

## SECCIÓN 4: PILAS Y COLAS (10 puntos)

### Pregunta 9 (5 puntos) - Pseudocódigo

Escriba en pseudocódigo una ACCION que verifique si una cadena de paréntesis está balanceada. Use una pila. Por ejemplo: "(()())" está balanceada, "(()" no lo está.

### Pregunta 10 (5 puntos) - C/C++

Implemente en C/C++ una función `void enqueueCircular(COLA* c, int dato)` que inserte un elemento en una cola circular. Considere los casos: cola llena, cola vacía, insertar después del final.

---

## SECCIÓN 5: ÁRBOLES BINARIOS (20 puntos)

### Pregunta 11 (10 puntos) - Pseudocódigo

Dado el siguiente árbol binario:
```
        A
       / \
      B    C
          / \
         D   E
        / \ / \
       F  G I  J
```

a) Escriba los recorridos PreOrden, InOrden y PostOrden. (3 puntos)

b) Escriba en pseudocódigo una ACCION recursiva que cuente el número de hojas del árbol. (4 puntos)

c) Escriba en pseudocódigo una ACCION recursiva que calcule la altura del árbol. (3 puntos)

### Pregunta 12 (10 puntos) - C/C++

Implemente en C/C++ una función `int contarNodosInternos(NODO* raiz)` que cuente los nodos internos (no hojas) de un árbol binario. Un nodo es interno si tiene al menos un hijo.

---

## SECCIÓN 6: ABB (10 puntos)

### Pregunta 13 (10 puntos) - Ambos formatos

Inserte los valores 50, 25, 75, 10, 30, 60, 80, 5, 15 en un ABB vacío.

a) Dibuje el árbol resultante. (3 puntos)

b) Escriba los recorridos PreOrden, InOrden y PostOrden. (3 puntos)

c) Escriba primero en pseudocódigo y luego en C/C++ una función que encuentre el valor mínimo (el nodo más a la izquierda). (4 puntos)

---

## SECCIÓN 7: AVL (10 puntos)

### Pregunta 14 (10 puntos) - C/C++

Dado un árbol AVL, implemente en C/C++:

a) La función `int obtenerFE(NODO* n)` que calcula el Factor de Equilibrio. (3 puntos)

b) La función `NODO* rotarDerecha(NODO* y)` que realiza una rotación simple derecha. (4 puntos)

c) Explique cuándo se aplica una rotación LR (izquierda-derecha) en lugar de una rotación LL. (3 puntos)

---

## SOLUCIONES

### Sección 1: Teoría

**Pregunta 1:**
Un ABB es un árbol binario con propiedad de ordenamiento (izq < raíz ≤ der), pero puede degenerar en lista si los datos vienen ordenados, resultando en O(n) en el peor caso. Un AVL es un ABB autobalanceado que mantiene |FE| ≤ 1 para todos los nodos, garantizando que la altura sea O(log n) y por lo tanto todas las operaciones son O(log n) en el peor caso.

**Pregunta 2:**
Un árbol B es un árbol balanceado de búsqueda multi-vía diseñado para almacenamiento en disco. Cada nodo puede tener múltiples hijos (hasta m, donde m es el orden). Se usa en bases de datos y sistemas de archivos para minimizar el número de accesos a disco. La propiedad de dividir nodos cuando se desbordan y promover la mediana al padre garantiza que todas las hojas estén al mismo nivel.

**Pregunta 3:**
- **Arreglo:** Búsqueda O(1) por índice, O(n) lineal, O(n) espacio fijo. Conviene cuando se necesita acceso aleatorio rápido y el tamaño es conocido.
- **Lista Enlazada:** Búsqueda O(n), inserción O(1) al inicio, O(n) espacio dinámico. Conviene cuando el tamaño es desconocido y hay inserciones frecuentes al inicio.
- **ABB:** Búsqueda O(log n) promedio, O(n) peor caso, O(n) espacio. Conviene para búsqueda dinámica con inserciones frecuentes.
- **Trie:** Búsqueda O(L) donde L es longitud de palabra, O(n×L) espacio. Conviene para diccionarios, autocompletado, corrector ortográfico.

**Pregunta 4:**
El principio de Huffman es asignar códigos binarios más cortos a los símbolos más frecuentes y códigos más largos a los menos frecuentes. Esto minimiza la longitud total del mensaje codificado. Los símbolos más frecuentes tienen códigos más cortos porque aparecen más veces en el mensaje, por lo que ahorrar bits en ellos tiene mayor impacto. La propiedad de "prefijo libre" (ningún código es prefijo de otro) garantiza que la compresión sea sin pérdida, ya que permite decodificar unívocamente el mensaje original.

---

### Sección 2: Punteros y Memoria Dinámica

**Pregunta 5 - Pseudocódigo:**
```
ACCION invertirArreglo(ENTERO arr[], ENTERO n)
   ENTERO *pInicio, *pFinal, temp
   
   SI(n ≤ 1)
      RETORNAR
   FIN_SI
   
   pInicio ← arr
   pFinal ← arr + n - 1
   
   MIENTRAS(pInicio < pFinal)
      temp ← *pInicio
      *pInicio ← *pFinal
      *pFinal ← temp
      
      pInicio ← pInicio + 1
      pFinal ← pFinal - 1
   FIN_MIENTRAS
FIN_ACCION
```

**Pregunta 6 - C/C++:**
```cpp
void duplicar(int* arr, int n) {
    if (arr == NULL || n <= 0) {
        return;  // Arreglo vacío o inválido
    }
    
    for (int i = 0; i < n; i++) {
        *(arr + i) = *(arr + i) * 2;
    }
}
```

---

### Sección 3: Listas Enlazadas

**Pregunta 7 - Pseudocódigo:**
```
ACCION insertarOrdenado(NODO cab, NODO cab1, TD dato)
   NODO p, q, nuevo
   
   nuevo ← nuevoNodo(cab1, dato)
   SI(nuevo = NULL)
      RETORNAR
   FIN_SI
   
   SI(cab = NULL)
      cab ← nuevo
      RETORNAR
   FIN_SI
   
   SI(dato < cab.valor)
      nuevo.sgte ← cab
      cab ← nuevo
      RETORNAR
   FIN_SI
   
   q ← cab
   p ← cab.sgte
   MIENTRAS(p ≠ NULL Y p.valor < dato)
      q ← p
      p ← p.sgte
   FIN_MIENTRAS
   
   q.sgte ← nuevo
   nuevo.sgte ← p
FIN_ACCION
```

**Pregunta 8 - C/C++:**
```cpp
void invertirLista(NODO** cab) {
    NODO* anterior = NULL;
    NODO* actual = *cab;
    NODO* siguiente = NULL;
    
    while (actual != NULL) {
        siguiente = actual->sgte;
        actual->sgte = anterior;
        anterior = actual;
        actual = siguiente;
    }
    
    *cab = anterior;
}
```

---

### Sección 4: Pilas y Colas

**Pregunta 9 - Pseudocódigo:**
```
ACCION verificarBalance(CADENA s) RETORNA BOOLEANO
   PILA p
   ENTERO i, longitud
   CARACTER c, temp
   
   crearPila(p)
   longitud ← longitud(s)
   
   PARA i ← 0 HASTA longitud - 1
      c ← s[i]
      
      SI(c = '(')
         push(p, c)
      SINO
         SI(c = ')')
            SI(pilaVacia(p))
               RETORNAR(FALSO)
            FIN_SI
            
            pop(p, temp)
            
            SI(temp ≠ '(')
               RETORNAR(FALSO)
            FIN_SI
         FIN_SI
      FIN_SI
   FIN_PARA
   
   RETORNAR(pilaVacia(p))
FIN_ACCION
```

**Pregunta 10 - C/C++:**
```cpp
#define MAX 100

struct COLA {
    int datos[MAX];
    int frente;
    int final;
};

void enqueueCircular(COLA* c, int dato) {
    if ((c->final + 1) % MAX == c->frente) {
        printf("Cola llena\n");
        return;
    }
    
    if (c->frente == -1) {
        c->frente = c->final = 0;
    } else {
        c->final = (c->final + 1) % MAX;
    }
    
    c->datos[c->final] = dato;
}
```

---

### Sección 5: Árboles Binarios

**Pregunta 11a:**
- **PreOrden:** A, B, C, D, F, G, E, I, J
- **InOrden:** B, A, F, D, G, C, I, E, J
- **PostOrden:** B, F, G, D, I, J, E, C, A

**Pregunta 11b - Pseudocódigo:**
```
ACCION contarHojas(NODO raiz) RETORNA ENTERO
   SI(raiz = NULL)
      RETORNAR(0)
   FIN_SI
   
   SI(raiz.izq = NULL Y raiz.der = NULL)
      RETORNAR(1)
   FIN_SI
   
   RETORNAR(contarHojas(raiz.izq) + contarHojas(raiz.der))
FIN_ACCION
```

**Pregunta 11c - Pseudocódigo:**
```
ACCION altura(NODO raiz) RETORNA ENTERO
   SI(raiz = NULL)
      RETORNAR(-1)
   FIN_SI
   
   altIzq ← altura(raiz.izq)
   altDer ← altura(raiz.der)
   
   RETORNAR(1 + MAX(altIzq, altDer))
FIN_ACCION
```

**Pregunta 12 - C/C++:**
```cpp
int contarNodosInternos(NODO* raiz) {
    if (raiz == NULL) return 0;
    
    if (raiz->izq == NULL && raiz->der == NULL) {
        return 0;  // Es hoja
    }
    
    return 1 + contarNodosInternos(raiz->izq) + contarNodosInternos(raiz->der);
}
```

---

### Sección 6: ABB

**Pregunta 13a:**
```
        50
       /  \
      25   75
     / \   / \
    10 30 60 80
   / \
  5  15
```

**Pregunta 13b:**
- **PreOrden:** 50, 25, 10, 5, 15, 30, 75, 60, 80
- **InOrden:** 5, 10, 15, 25, 30, 50, 60, 75, 80
- **PostOrden:** 5, 15, 10, 30, 25, 60, 80, 75, 50

**Pregunta 13c - Pseudocódigo:**
```
ACCION minimo(NODO raiz) RETORNA TD
   SI(raiz = NULL)
      ESCRIBIR("Árbol vacío")
      RETORNAR
   FIN_SI
   
   MIENTRAS(raiz.izq ≠ NULL)
      raiz ← raiz.izq
   FIN_MIENTRAS
   
   RETORNAR(raiz.info)
FIN_ACCION
```

**Pregunta 13c - C/C++:**
```cpp
TD minimo(NODO* raiz) {
    if (raiz == NULL) {
        printf("Árbol vacío\n");
        return -1;
    }
    
    while (raiz->izq != NULL) {
        raiz = raiz->izq;
    }
    
    return raiz->info;
}
```

---

### Sección 7: AVL

**Pregunta 14a - C/C++:**
```cpp
int obtenerAltura(NODO *n) {
    if (n == NULL) return 0;
    return n->altura;
}

int obtenerFE(NODO *n) {
    if (n == NULL) return 0;
    return obtenerAltura(n->der) - obtenerAltura(n->izq);
}
```

**Pregunta 14b - C/C++:**
```cpp
NODO* rotarDerecha(NODO *y) {
    NODO *x = y->izq;
    NODO *T2 = x->der;
    
    // Rotación
    x->der = y;
    y->izq = T2;
    
    // Actualizar alturas
    y->altura = 1 + max(obtenerAltura(y->izq), obtenerAltura(y->der));
    x->altura = 1 + max(obtenerAltura(x->izq), obtenerAltura(x->der));
    
    return x;  // Nueva raíz
}
```

**Pregunta 14c:**
Se aplica una rotación LR (izquierda-derecha) cuando:
- El Factor de Equilibrio del nodo es < -1 (desbalanceado a la izquierda)
- El Factor de Equilibrio del hijo izquierdo es > 0 (el desbalanceo está en dirección opuesta)

En este caso, primero se hace una rotación izquierda en el hijo izquierdo, y luego una rotación derecha en el nodo. Esto es necesario cuando el nodo que causó el desbalanceo se insertó en el subárbol derecho del hijo izquierdo del nodo desbalanceado.
