# TEMA 10: ÁRBOLES BINARIOS

---

## Objetivos

- Comprender la estructura fundamental de un árbol binario
- Dominar los recorridos recursivos (PreOrden, InOrden, PostOrden)
- Implementar operaciones básicas: insertar, buscar, contar nodos, calcular altura
- Entender la diferencia entre árbol binario general y ABB
- Aplicar árboles binarios a problemas prácticos

---

## Conceptos clave

- **Árbol binario:** Estructura donde cada nodo tiene máximo 2 hijos (izquierdo y derecho)
- **Raíz:** Nodo sin padre, punto de entrada del árbol
- **Hoja:** Nodo sin hijos (nodo terminal)
- **Altura:** Nivel máximo del árbol (número de aristas desde la raíz hasta la hoja más lejana)
- **Nivel:** Distancia desde la raíz (raíz = nivel 0)
- **Subárbol:** Porción del árbol que incluye un nodo y todos sus descendientes
- **Recorrido:** Proceso de visitar todos los nodos del árbol en un orden específico

---

## Explicación detallada

### ¿Qué es un árbol binario?

Un árbol binario es una estructura de datos jerárquica donde cada nodo puede tener:
- **0 hijos** (es una hoja)
- **1 hijo** (izquierdo o derecho)
- **2 hijos** (izquierdo y derecho)

A diferencia de las listas enlazadas (lineales), los árboles permiten representar relaciones jerárquicas y realizar búsquedas más eficientes.

### Estructura del nodo

```
REGISTRO NODO
   TD info        // dato almacenado
   NODO *izq      // puntero al hijo izquierdo
   NODO *der      // puntero al hijo derecho
FIN_REGISTRO
```

En C/C++:
```cpp
struct NODO {
    TD info;
    NODO *izq;
    NODO *der;
};
```

### Propiedades importantes

1. **Árbol vacío:** `raiz == NULL`
2. **Árbol con un solo nodo:** `raiz->izq == NULL` y `raiz->der == NULL`
3. **Número máximo de nodos en nivel n:** 2ⁿ
4. **Número máximo de nodos en árbol de altura h:** 2^(h+1) - 1
5. **Árbol completo:** Todos los niveles están llenos excepto quizás el último, lleno de izquierda a derecha
6. **Árbol perfecto:** Todos los niveles están completamente llenos

---

## Recorridos de árboles binarios

### PreOrden (RID - Raíz, Izquierda, Derecha)

Visita: Raíz → Subárbol izquierdo → Subárbol derecho

**Pseudocódigo:**
```
ACCION preOrden(NODO raiz)
   SI(raiz ≠ NULL)
      ESCRIBIR(raiz.info)
      preOrden(raiz.izq)
      preOrden(raiz.der)
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
void preOrden(NODO *raiz) {
    if (raiz != NULL) {
        printf("%c ", raiz->info);
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}
```

### InOrden (IRD - Izquierda, Raíz, Derecha)

Visita: Subárbol izquierdo → Raíz → Subárbol derecho

**Pseudocódigo:**
```
ACCION inOrden(NODO raiz)
   SI(raiz ≠ NULL)
      inOrden(raiz.izq)
      ESCRIBIR(raiz.info)
      inOrden(raiz.der)
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
void inOrden(NODO *raiz) {
    if (raiz != NULL) {
        inOrden(raiz->izq);
        printf("%c ", raiz->info);
        inOrden(raiz->der);
    }
}
```

### PostOrden (IDR - Izquierda, Derecha, Raíz)

Visita: Subárbol izquierdo → Subárbol derecho → Raíz

**Pseudocódigo:**
```
ACCION postOrden(NODO raiz)
   SI(raiz ≠ NULL)
      postOrden(raiz.izq)
      postOrden(raiz.der)
      ESCRIBIR(raiz.info)
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
void postOrden(NODO *raiz) {
    if (raiz != NULL) {
        postOrden(raiz->izq);
        postOrden(raiz->der);
        printf("%c ", raiz->info);
    }
}
```

---

## Ejemplos

### Ejemplo 1: Construir y recorrer un árbol binario

**Árbol a construir:**
```
        A
       / \
      B    C
          / \
         D   E
        / \ / \
       F  G I  J
```

**Pseudocódigo - Construcción:**
```
ACCION datosDePrueba(NODO cab, NODO cab1)
   NODO a, aux
   a ← nuevoNodo(cab1, 'A')
   
   insertarIzq(a, cab1, 'B')
   insertarDer(a, cab1, 'C')
   
   aux ← a.der
   insertarIzq(aux, cab1, 'D')
   insertarDer(aux, cab1, 'E')
   
   aux ← a.der.izq
   insertarIzq(aux, cab1, 'F')
   insertarDer(aux, cab1, 'G')
   
   aux ← a.der.der
   insertarIzq(aux, cab1, 'I')
   insertarDer(aux, cab1, 'J')
   
   cab ← a
FIN_ACCION
```

**C/C++ - Construcción:**
```cpp
void datosDePrueba(NODO **raiz) {
    NODO *a = new NODO;
    a->info = 'A';
    a->izq = NULL;
    a->der = NULL;
    
    insertarIzq(a, 'B');
    insertarDer(a, 'C');
    
    NODO *aux = a->der;
    insertarIzq(aux, 'D');
    insertarDer(aux, 'E');
    
    aux = a->der->izq;
    insertarIzq(aux, 'F');
    insertarDer(aux, 'G');
    
    aux = a->der->der;
    insertarIzq(aux, 'I');
    insertarDer(aux, 'J');
    
    *raiz = a;
}

void insertarIzq(NODO *p, TD dato) {
    NODO *neo = new NODO;
    neo->info = dato;
    neo->izq = NULL;
    neo->der = NULL;
    p->izq = neo;
}

void insertarDer(NODO *p, TD dato) {
    NODO *neo = new NODO;
    neo->info = dato;
    neo->izq = NULL;
    neo->der = NULL;
    p->der = neo;
}
```

**Recorridos resultantes:**
- **PreOrden:** A, B, C, D, F, G, E, I, J
- **InOrden:** B, A, F, D, G, C, I, E, J
- **PostOrden:** B, F, G, D, I, J, E, C, A

---

## Operaciones básicas

### Contar nodos

**Pseudocódigo:**
```
ACCION contarNodos(NODO raiz) RETORNA entero
   SI(raiz = NULL)
      RETORNAR(0)
   FIN_SI
   RETORNAR(1 + contarNodos(raiz.izq) + contarNodos(raiz.der))
FIN_ACCION
```

**C/C++:**
```cpp
int contarNodos(NODO *raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNodos(raiz->izq) + contarNodos(raiz->der);
}
```

### Contar hojas

**Pseudocódigo:**
```
ACCION contarHojas(NODO raiz) RETORNA entero
   SI(raiz = NULL)
      RETORNAR(0)
   FIN_SI
   SI(raiz.izq = NULL Y raiz.der = NULL)
      RETORNAR(1)  // es hoja
   FIN_SI
   RETORNAR(contarHojas(raiz.izq) + contarHojas(raiz.der))
FIN_ACCION
```

**C/C++:**
```cpp
int contarHojas(NODO *raiz) {
    if (raiz == NULL) return 0;
    if (raiz->izq == NULL && raiz->der == NULL) return 1;
    return contarHojas(raiz->izq) + contarHojas(raiz->der);
}
```

### Calcular altura

**Pseudocódigo:**
```
ACCION altura(NODO raiz) RETORNA entero
   SI(raiz = NULL)
      RETORNAR(-1)  // árbol vacío tiene altura -1
   FIN_SI
   altIzq ← altura(raiz.izq)
   altDer ← altura(raiz.der)
   RETORNAR(1 + MAX(altIzq, altDer))
FIN_ACCION
```

**C/C++:**
```cpp
int altura(NODO *raiz) {
    if (raiz == NULL) return -1;
    int altIzq = altura(raiz->izq);
    int altDer = altura(raiz->der);
    return 1 + (altIzq > altDer ? altIzq : altDer);
}
```

### Buscar un valor

**Pseudocódigo:**
```
ACCION buscar(NODO raiz, TD valor) RETORNA NODO
   SI(raiz = NULL)
      RETORNAR(NULL)
   FIN_SI
   SI(raiz.info = valor)
      RETORNAR(raiz)
   SINO
      resultado ← buscar(raiz.izq, valor)
      SI(resultado ≠ NULL)
         RETORNAR(resultado)
      FIN_SI
      RETORNAR(buscar(raiz.der, valor))
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
NODO* buscar(NODO *raiz, TD valor) {
    if (raiz == NULL) return NULL;
    if (raiz->info == valor) return raiz;
    
    NODO *resultado = buscar(raiz->izq, valor);
    if (resultado != NULL) return resultado;
    
    return buscar(raiz->der, valor);
}
```

---

## Casos típicos de examen

### Caso 1: Dibujar árbol desde recorridos

**Pregunta:** Dado el PreOrden: A, B, D, E, C, F y el InOrden: D, B, E, A, F, C, dibuje el árbol.

**Solución:**
1. La raíz es A (primer elemento de PreOrden)
2. En InOrden, todo a la izquierda de A (D, B, E) es el subárbol izquierdo
3. Todo a la derecha de A (F, C) es el subárbol derecho
4. Repetir recursivamente

**Árbol resultante:**
```
        A
       / \
      B   C
     / \  /
    D  E F
```

### Caso 2: Calcular altura y número de nodos

**Pregunta:** Para el árbol anterior, calcule:
- Número de nodos
- Número de hojas
- Altura del árbol

**Solución:**
- Nodos: 6 (A, B, C, D, E, F)
- Hojas: 3 (D, E, F)
- Altura: 2 (A→B→D o A→C→F)

### Caso 3: Completar código recursivo

**Pregunta:** Complete la función que cuenta nodos internos (no hojas).

**Solución:**
```cpp
int contarNodosInternos(NODO *raiz) {
    if (raiz == NULL) return 0;
    if (raiz->izq == NULL && raiz->der == NULL) return 0; // es hoja
    return 1 + contarNodosInternos(raiz->izq) + contarNodosInternos(raiz->der);
}
```

---

## Errores frecuentes

| Error | Qué pasa | Cómo evitarlo |
|-------|----------|---------------|
| Olvidar caso base `if (raiz == NULL)` | Stack overflow o acceso inválido | Siempre verificar NULL primero |
| Confundir orden de recorridos | Resultados incorrectos | Memorizar: Pre=RID, In=IRD, Post=IDR |
| No inicializar punteros a NULL | Comportamiento indefinido | Siempre: `nuevo->izq = NULL; nuevo->der = NULL;` |
| Usar altura = 0 para árbol vacío | Cálculos incorrectos | Árbol vacío tiene altura -1 |
| Confundir nivel con altura | Respuestas incorrectas en examen | Nivel: distancia desde raíz. Altura: máxima distancia desde raíz |

---

## Preguntas de recuperación activa

1. ¿Por qué el recorrido InOrden de un ABB produce los datos ordenados?
2. ¿Cuál es la diferencia entre un árbol binario completo y un árbol binario perfecto?
3. ¿Por qué todos los recorridos recursivos necesitan un caso base?
4. ¿En qué situación usarías PostOrden en lugar de PreOrden?
5. ¿Cuál es la complejidad temporal de buscar en un árbol binario desbalanceado?
6. ¿Por qué la altura de un árbol vacío es -1 y no 0?
7. ¿Cómo se calcula el número máximo de nodos en un árbol de altura h?
8. ¿Qué ventaja tiene un árbol sobre una lista enlazada?

---

## Autoevaluación

### Nivel 1 (Básico)
1. Defina qué es un árbol binario.
2. Escriba el pseudocódigo de PreOrden.
3. ¿Cuántos hijos máximo puede tener un nodo en un árbol binario?

### Nivel 2 (Intermedio)
1. Dado un árbol, escriba sus tres recorridos.
2. Implemente la función para contar hojas en C/C++.
3. Explique la diferencia entre nivel y altura.

### Nivel 3 (Avanzado)
1. Construya un árbol dado PreOrden e InOrden.
2. Implemente una función que determine si dos árboles son idénticos.
3. Explique por qué la búsqueda en un árbol binario puede ser O(n) en el peor caso.

---

## Resumen de una página

**Árbol binario:** Estructura jerárquica donde cada nodo tiene máximo 2 hijos.

**Estructura del nodo:**
```cpp
struct NODO {
    TD info;
    NODO *izq;
    NODO *der;
};
```

**Recorridos (5 líneas cada uno):**
- PreOrden (RID): visita raíz, luego izq, luego der
- InOrden (IRD): visita izq, luego raíz, luego der
- PostOrden (IDR): visita izq, luego der, luego raíz

**Operaciones clave:**
- Contar nodos: `1 + contar(izq) + contar(der)`
- Contar hojas: `if (izq==NULL && der==NULL) return 1`
- Altura: `1 + max(alt(izq), alt(der))`, árbol vacío = -1
- Buscar: búsqueda recursiva en ambos subárboles

**Propiedades:**
- Máx nodos en nivel n: 2ⁿ
- Máx nodos en árbol altura h: 2^(h+1) - 1
- Árbol completo: todos los niveles llenos excepto último (izquierda a derecha)
- Árbol perfecto: todos los niveles completamente llenos

**Errores comunes:**
- Olvidar caso base `if (raiz == NULL)`
- Confundir orden de recorridos
- No inicializar punteros a NULL

**Complejidad:**
- Búsqueda: O(n) peor caso (árbol degenerado)
- Recorridos: O(n) siempre
- Inserción: O(n) si no es ABB
