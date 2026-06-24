# TEMA 12: ÁRBOLES AVL

---

## Objetivos

- Comprender el problema del desbalanceo en ABB
- Dominar el cálculo del Factor de Equilibrio (FE)
- Implementar las 4 rotaciones: LL, RR, LR, RL
- Entender cuándo y cómo aplicar cada rotación
- Analizar la complejidad de operaciones en AVL

---

## Conceptos clave

- **Árbol AVL:** Árbol binario de búsqueda autobalanceado
- **Factor de Equilibrio (FE):** FE = altura(der) - altura(izq)
- **Balanceado:** |FE| ≤ 1 para todos los nodos
- **Rotación simple:** Reestructuración cuando el desbalanceo está en una sola dirección (LL o RR)
- **Rotación doble:** Reestructuración cuando el desbalanceo está en direcciones opuestas (LR o RL)
- **Altura:** Número de aristas desde el nodo hasta la hoja más lejana

---

## Explicación detallada

### ¿Qué es un árbol AVL?

Un árbol AVL (Adelson-Velsky y Landis) es un ABB que **siempre mantiene el balance** después de cada inserción o eliminación. Esto garantiza que la altura sea O(log n), asegurando búsquedas eficientes.

**Propiedad AVL:** Para todo nodo, |altura(der) - altura(izq)| ≤ 1

### El problema de los ABB desbalanceados

```
ABB desbalanceado (degenerado):
1
 \
  2
   \
    3
     \
      4
       \
        5

Altura = 4, n = 5
Búsqueda = O(n) ❌
```

```
AVL balanceado:
        3
       / \
      2   4
     /     \
    1       5

Altura = 2, n = 5
Búsqueda = O(log n) ✓
```

### Factor de Equilibrio (FE)

**Fórmula:** FE = altura(subárbol derecho) - altura(subárbol izquierdo)

**Interpretación:**
- FE = 0: subárboles de igual altura
- FE = 1: subárbol derecho es 1 nivel más alto
- FE = -1: subárbol izquierdo es 1 nivel más alto
- FE = 2: desbalanceado a la derecha (necesita rotación izquierda)
- FE = -2: desbalanceado a la izquierda (necesita rotación derecha)

### Estructura del nodo AVL

```
REGISTRO NODO
   TD info
   NODO *izq
   NODO *der
   ENTERO altura
FIN_REGISTRO
```

En C/C++:
```cpp
struct NODO {
    int dato;
    NODO *izq;
    NODO *der;
    int altura;
};
```

---

## Rotaciones AVL

### Rotación Simple Derecha (Caso LL)

**Cuándo aplicar:** FE < -1 y FE del hijo izquierdo ≤ 0

```
ANTES (desbalanceado a izquierda):
    y
   /
  x
 /
T2

DESPUÉS (rotación derecha):
  x
   \
    y
   /
  T2
```

**Pseudocódigo:**
```
ACCION rotarDerecha(NODO y) RETORNA NODO
   NODO x, T2
   x ← y.izq
   T2 ← x.der
   
   // Reasignación de punteros
   x.der ← y
   y.izq ← T2
   
   // Actualización de alturas
   y.altura ← 1 + MAX(altura(y.izq), altura(y.der))
   x.altura ← 1 + MAX(altura(x.izq), altura(x.der))
   
   RETORNAR(x)
FIN_ACCION
```

**C/C++:**
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

### Rotación Simple Izquierda (Caso RR)

**Cuándo aplicar:** FE > 1 y FE del hijo derecho ≥ 0

```
ANTES (desbalanceado a derecha):
  x
   \
    y
     \
      T2

DESPUÉS (rotación izquierda):
    y
   /
  x
   \
    T2
```

**Pseudocódigo:**
```
ACCION rotarIzquierda(NODO x) RETORNA NODO
   NODO y, T2
   y ← x.der
   T2 ← y.izq
   
   // Reasignación de punteros
   y.izq ← x
   x.der ← T2
   
   // Actualización de alturas
   x.altura ← 1 + MAX(altura(x.izq), altura(x.der))
   y.altura ← 1 + MAX(altura(y.izq), altura(y.der))
   
   RETORNAR(y)
FIN_ACCION
```

**C/C++:**
```cpp
NODO* rotarIzquierda(NODO *x) {
    NODO *y = x->der;
    NODO *T2 = y->izq;
    
    // Rotación
    y->izq = x;
    x->der = T2;
    
    // Actualizar alturas
    x->altura = 1 + max(obtenerAltura(x->izq), obtenerAltura(x->der));
    y->altura = 1 + max(obtenerAltura(y->izq), obtenerAltura(y->der));
    
    return y;  // Nueva raíz
}
```

### Rotación Doble Izquierda-Derecha (Caso LR)

**Cuándo aplicar:** FE < -1 y FE del hijo izquierdo > 0

```
ANTES:
    z
   /
  y
   \
    x

PASO 1 (rotar izquierda en y):
    z
   /
  x
 /
y

PASO 2 (rotar derecha en z):
  x
 / \
y   z
```

**Pseudocódigo:**
```
ACCION insertar(NODO nodo, TD valor) RETORNA NODO
   // Inserción normal de ABB
   SI(nodo = NULL)
      RETORNAR(nuevoNodo(valor))
   FIN_SI
   
   SI(valor < nodo.info)
      nodo.izq ← insertar(nodo.izq, valor)
   SINO
      nodo.der ← insertar(nodo.der, valor)
   FIN_SI
   
   // Actualizar altura
   nodo.altura ← 1 + MAX(altura(nodo.izq), altura(nodo.der))
   
   // Calcular FE y balancear
   fe ← obtenerFE(nodo)
   
   // Caso LL
   SI(fe < -1 Y valor < nodo.izq.info)
      RETORNAR(rotarDerecha(nodo))
   FIN_SI
   
   // Caso RR
   SI(fe > 1 Y valor > nodo.der.info)
      RETORNAR(rotarIzquierda(nodo))
   FIN_SI
   
   // Caso LR
   SI(fe < -1 Y valor > nodo.izq.info)
      nodo.izq ← rotarIzquierda(nodo.izq)
      RETORNAR(rotarDerecha(nodo))
   FIN_SI
   
   // Caso RL
   SI(fe > 1 Y valor < nodo.der.info)
      nodo.der ← rotarDerecha(nodo.der)
      RETORNAR(rotarIzquierda(nodo))
   FIN_SI
   
   RETORNAR(nodo)
FIN_ACCION
```

**C/C++:**
```cpp
NODO* insertar(NODO *nodo, int valor) {
    // Inserción normal de ABB
    if (nodo == NULL) {
        return crearNodo(valor);
    }
    
    if (valor < nodo->dato) {
        nodo->izq = insertar(nodo->izq, valor);
    } else if (valor > nodo->dato) {
        nodo->der = insertar(nodo->der, valor);
    } else {
        return nodo;  // Valores duplicados no permitidos
    }
    
    // Actualizar altura
    nodo->altura = 1 + max(obtenerAltura(nodo->izq), obtenerAltura(nodo->der));
    
    // Calcular FE y balancear
    int fe = obtenerFE(nodo);
    
    // Caso LL
    if (fe < -1 && valor < nodo->izq->dato) {
        return rotarDerecha(nodo);
    }
    
    // Caso RR
    if (fe > 1 && valor > nodo->der->dato) {
        return rotarIzquierda(nodo);
    }
    
    // Caso LR
    if (fe < -1 && valor > nodo->izq->dato) {
        nodo->izq = rotarIzquierda(nodo->izq);
        return rotarDerecha(nodo);
    }
    
    // Caso RL
    if (fe > 1 && valor < nodo->der->dato) {
        nodo->der = rotarDerecha(nodo->der);
        return rotarIzquierda(nodo);
    }
    
    return nodo;
}
```

### Rotación Doble Derecha-Izquierda (Caso RL)

**Cuándo aplicar:** FE > 1 y FE del hijo derecho < 0

```
ANTES:
  z
   \
    y
   /
  x

PASO 1 (rotar derecha en y):
  z
   \
    x
     \
      y

PASO 2 (rotar izquierda en z):
    x
   / \
  z   y
```

---

## Funciones auxiliares

### Obtener altura

```cpp
int obtenerAltura(NODO *n) {
    if (n == NULL) return 0;
    return n->altura;
}
```

### Obtener Factor de Equilibrio

```cpp
int obtenerFE(NODO *n) {
    if (n == NULL) return 0;
    return obtenerAltura(n->der) - obtenerAltura(n->izq);
}
```

### Máximo de dos números

```cpp
int max(int a, int b) {
    return (a > b) ? a : b;
}
```

---

## Ejemplos

### Ejemplo 1: Inserción que requiere rotación simple (RR)

**Secuencia:** 10, 20, 30

```
Insertar 10:    10 (FE=0)

Insertar 20:    10 (FE=1)
                \
                 20 (FE=0)

Insertar 30:    10 (FE=2) ← DESBALANCEADO
                \
                 20 (FE=1)
                  \
                   30 (FE=0)

Rotación izquierda en 10:
        20 (FE=0)
       /  \
      10   30
```

### Ejemplo 2: Inserción que requiere rotación doble (LR)

**Secuencia:** 30, 10, 20

```
Insertar 30:    30 (FE=0)

Insertar 10:    30 (FE=-1)
               /
              10 (FE=0)

Insertar 20:    30 (FE=-2) ← DESBALANCEADO
               /
              10 (FE=1)
               \
                20 (FE=0)

Rotación izquierda en 10:
    30 (FE=-2)
   /
  20 (FE=0)
 /
10 (FE=0)

Rotación derecha en 30:
    20 (FE=0)
   /  \
  10   30
```

### Ejemplo 3: Inserción compleja con múltiples rotaciones

**Secuencia:** 40, 20, 10, 25, 30, 22, 50

```
Paso a paso:

40:          40 (FE=0)

40,20:       40 (FE=1)
             /
            20 (FE=0)

40,20,10:    20 (FE=0) ← rotación derecha
            /  \
          10   40

40,20,10,25: 20 (FE=0)
             /  \
           10   40
               /
              25 (FE=0)

40,20,10,25,30: 20 (FE=1)
                /  \
              10   40
                  /
                25 (FE=1)
                 \
                  30 (FE=0)

40,20,10,25,30,22: 20 (FE=1)
                  /  \
                10   30 (FE=0)
                    /  \
                  25   40
                  /
                22 (FE=0)

40,20,10,25,30,22,50: 30 (FE=0)
                     /    \
                   20      40
                  /  \       \
                10   25       50
                    /
                  22
```

---

## Casos típicos de examen

### Caso 1: Identificar tipo de rotación

**Pregunta:** Dado el siguiente árbol AVL desbalanceado, ¿qué rotación se necesita?
```
    30 (FE=2)
      \
       40 (FE=1)
         \
          50 (FE=0)
```

**Solución:** Rotación simple izquierda (Caso RR). FE > 1 y FE del hijo derecho ≥ 0.

### Caso 2: Completar código de rotación

**Pregunta:** Complete la función de rotación derecha.

**Solución:**
```cpp
NODO* rotarDerecha(NODO *y) {
    NODO *x = y->izq;
    NODO *T2 = x->der;
    
    x->der = y;
    y->izq = T2;
    
    y->altura = 1 + max(obtenerAltura(y->izq), obtenerAltura(y->der));
    x->altura = 1 + max(obtenerAltura(x->izq), obtenerAltura(x->der));
    
    return x;
}
```

### Caso 3: Calcular FE de todos los nodos

**Pregunta:** Calcule el Factor de Equilibrio de cada nodo.
```
        20
       /  \
      10   30
     / \
    5   15
```

**Solución:**
- Nodo 5: FE = 0 - 0 = 0
- Nodo 15: FE = 0 - 0 = 0
- Nodo 10: FE = 0 - 0 = 0
- Nodo 30: FE = 0 - 0 = 0
- Nodo 20: FE = 1 - 1 = 0

**Árbol balanceado.**

---

## Errores frecuentes

| Error | Qué pasa | Cómo evitarlo |
|-------|----------|---------------|
| No actualizar altura después de rotación | FE incorrecto en siguientes operaciones | Siempre actualizar altura de ambos nodos rotados |
| Confundir signo de FE | Rotación incorrecta | Memorizar: FE = alt(der) - alt(izq) |
| Olvidar caso de rotación doble | Árbol sigue desbalanceado | Verificar FE del hijo para decidir simple vs doble |
- No verificar FE del hijo | Rotación simple cuando se necesita doble | Siempre verificar FE del hijo antes de rotar |
- Rotar en el nodo incorrecto | Árbol corrupto | Rotar en el primer nodo desbalanceado desde la hoja hacia arriba |

---

## Preguntas de recuperación activa

1. ¿Por qué un AVL garantiza O(log n) en todas las operaciones?
2. ¿Cuál es la diferencia entre rotación simple y rotación doble?
3. ¿Cómo se calcula el Factor de Equilibrio?
4. ¿En qué caso se aplica una rotación LR vs LL?
5. ¿Por qué es necesario actualizar la altura después de cada rotación?
6. ¿Qué pasa si insertamos valores ordenados en un AVL vs un ABB?
7. ¿Cuál es la máxima altura posible de un AVL con n nodos?
8. ¿Por qué AVL es más complejo que ABB pero más eficiente?

---

## Autoevaluación

### Nivel 1 (Básico)
1. Defina qué es un árbol AVL.
2. Escriba la fórmula del Factor de Equilibrio.
3. ¿Qué significa que |FE| ≤ 1?

### Nivel 2 (Intermedio)
1. Dibuje las 4 rotaciones AVL (LL, RR, LR, RL).
2. Implemente la función para obtener el FE en C/C++.
3. Explique cuándo se necesita rotación simple vs doble.

### Nivel 3 (Avanzado)
1. Construya un AVL insertando: 10, 20, 30, 40, 50, 25. Muestre todas las rotaciones.
2. Implemente la eliminación en AVL con rebalanceo.
3. Demuestre que la altura de un AVL con n nodos es O(log n).

---

## Resumen de una página

**AVL:** ABB autobalanceado que garantiza |FE| ≤ 1 para todos los nodos.

**Factor de Equilibrio:** FE = altura(der) - altura(izq)
- |FE| ≤ 1: balanceado
- FE = 2: desbalanceado a derecha (rotar izquierda)
- FE = -2: desbalanceado a izquierda (rotar derecha)

**4 Casos de rotación:**
- **LL (FE < -1, FE hijo ≤ 0):** rotación derecha simple
- **RR (FE > 1, FE hijo ≥ 0):** rotación izquierda simple
- **LR (FE < -1, FE hijo > 0):** rotación izquierda en hijo, luego derecha
- **RL (FE > 1, FE hijo < 0):** rotación derecha en hijo, luego izquierda

**Estructura del nodo:**
```cpp
struct NODO {
    int dato;
    NODO *izq;
    NODO *der;
    int altura;  // ← campo adicional
};
```

**Operaciones:**
- Inserción: O(log n) + rebalanceo
- Búsqueda: O(log n) garantizado
- Eliminación: O(log n) + rebalanceo

**Ventaja sobre ABB:** Garantiza O(log n) en peor caso.
**Desventaja:** Mayor complejidad de implementación.

**Errores comunes:**
- No actualizar altura después de rotación
- Confundir signo de FE
- Olvidar rotaciones dobles
