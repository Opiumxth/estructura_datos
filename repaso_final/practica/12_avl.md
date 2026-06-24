# PRÁCTICA 12: ÁRBOLES AVL

---

## Ejercicio 12.1 (Fácil) - Calcular Factor de Equilibrio

**Enunciado:**
Escriba una función que calcule el Factor de Equilibrio (FE) de un nodo AVL.

**Solución en C/C++:**
```cpp
int obtenerAltura(NODO* n) {
    if (n == NULL) return 0;
    return n->altura;
}

int obtenerFE(NODO* n) {
    if (n == NULL) return 0;
    return obtenerAltura(n->der) - obtenerAltura(n->izq);
}
```

**Pseudocódigo:**
```
ACCION obtenerAltura(NODO n) RETORNA ENTERO
   SI(n = NULL)
      RETORNAR(0)
   FIN_SI
   RETORNAR(n.altura)
FIN_ACCION

ACCION obtenerFE(NODO n) RETORNA ENTERO
   SI(n = NULL)
      RETORNAR(0)
   FIN_SI
   RETORNAR(obtenerAltura(n.der) - obtenerAltura(n.izq))
FIN_ACCION
```

---

## Ejercicio 12.2 (Medio) - Rotación derecha

**Enunciado:**
Implemente la rotación simple derecha (Caso LL).

**Solución en C/C++:**
```cpp
NODO* rotarDerecha(NODO* y) {
    NODO* x = y->izq;
    NODO* T2 = x->der;
    
    // Rotación
    x->der = y;
    y->izq = T2;
    
    // Actualizar alturas
    y->altura = 1 + max(obtenerAltura(y->izq), obtenerAltura(y->der));
    x->altura = 1 + max(obtenerAltura(x->izq), obtenerAltura(x->der));
    
    return x;  // Nueva raíz
}
```

**Pseudocódigo:**
```
ACCION rotarDerecha(NODO y) RETORNA NODO
   NODO x, T2
   
   x ← y.izq
   T2 ← x.der
   
   x.der ← y
   y.izq ← T2
   
   y.altura ← 1 + MAX(altura(y.izq), altura(y.der))
   x.altura ← 1 + MAX(altura(x.izq), altura(x.der))
   
   RETORNAR(x)
FIN_ACCION
```

---

## Ejercicio 12.3 (Medio) - Rotación izquierda

**Enunciado:**
Implemente la rotación simple izquierda (Caso RR).

**Solución en C/C++:**
```cpp
NODO* rotarIzquierda(NODO* x) {
    NODO* y = x->der;
    NODO* T2 = y->izq;
    
    // Rotación
    y->izq = x;
    x->der = T2;
    
    // Actualizar alturas
    x->altura = 1 + max(obtenerAltura(x->izq), obtenerAltura(x->der));
    y->altura = 1 + max(obtenerAltura(y->izq), obtenerAltura(y->der));
    
    return y;  // Nueva raíz
}
```

---

## Ejercicio 12.4 (Difícil) - Identificar tipo de rotación

**Enunciado:**
Dado un nodo AVL con FE = -2 y su hijo izquierdo tiene FE = 1, ¿qué rotación se necesita?

**Solución:**
Se necesita una rotación **LR (izquierda-derecha)**, que es una rotación doble:
1. Primero rotación izquierda en el hijo izquierdo
2. Luego rotación derecha en el nodo

**Por qué:** FE < -1 indica desbalanceo a la izquierda, pero FE del hijo > 0 indica que el desbalanceo está en dirección opuesta (derecha del hijo izquierdo).

---

## Ejercicio 12.5 (Tipo examen) - Inserción con rotación

**Enunciado:**
Inserte 10, 20, 30 en un AVL. Muestre las rotaciones necesarias.

**Solución:**
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

Rotación izquierda en 10 (Caso RR):
        20 (FE=0)
       /  \
      10   30
```
