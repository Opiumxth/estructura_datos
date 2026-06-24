# PRÁCTICA 10: ÁRBOLES BINARIOS

---

## Ejercicio 10.1 (Fácil) - Contar hojas

**Enunciado:**
Escriba una función recursiva que cuente el número de hojas en un árbol binario.

**Solución en C/C++:**
```cpp
int contarHojas(NODO* raiz) {
    if (raiz == NULL) return 0;
    if (raiz->izq == NULL && raiz->der == NULL) return 1;
    return contarHojas(raiz->izq) + contarHojas(raiz->der);
}
```

**Pseudocódigo:**
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

---

## Ejercicio 10.2 (Medio) - Calcular altura

**Enunciado:**
Escriba una función recursiva que calcule la altura de un árbol binario.

**Solución en C/C++:**
```cpp
int altura(NODO* raiz) {
    if (raiz == NULL) return -1;
    int altIzq = altura(raiz->izq);
    int altDer = altura(raiz->der);
    return 1 + (altIzq > altDer ? altIzq : altDer);
}
```

**Pseudocódigo:**
```
ACCION altura(NODO raiz) RETORNA ENTERO
   ENTERO altIzq, altDer
   
   SI(raiz = NULL)
      RETORNAR(-1)
   FIN_SI
   
   altIzq ← altura(raiz.izq)
   altDer ← altura(raiz.der)
   
   RETORNAR(1 + MAX(altIzq, altDer))
FIN_ACCION
```

---

## Ejercicio 10.3 (Medio) - Recorridos desde secuencia

**Enunciado:**
Dado el árbol binario:
```
        A
       / \
      B    C
          / \
         D   E
```
Escriba los recorridos PreOrden, InOrden y PostOrden.

**Solución:**
- **PreOrden:** A, B, C, D, E
- **InOrden:** B, A, D, C, E
- **PostOrden:** B, D, E, C, A

---

## Ejercicio 10.4 (Difícil) - Contar nodos internos

**Enunciado:**
Escriba una función que cuente los nodos internos (no hojas) de un árbol binario.

**Solución en C/C++:**
```cpp
int contarNodosInternos(NODO* raiz) {
    if (raiz == NULL) return 0;
    if (raiz->izq == NULL && raiz->der == NULL) return 0;
    return 1 + contarNodosInternos(raiz->izq) + contarNodosInternos(raiz->der);
}
```

**Pseudocódigo:**
```
ACCION contarNodosInternos(NODO raiz) RETORNA ENTERO
   SI(raiz = NULL)
      RETORNAR(0)
   FIN_SI
   
   SI(raiz.izq = NULL Y raiz.der = NULL)
      RETORNAR(0)
   FIN_SI
   
   RETORNAR(1 + contarNodosInternos(raiz.izq) + contarNodosInternos(raiz.der))
FIN_ACCION
```

---

## Ejercicio 10.5 (Tipo examen) - Construir árbol desde recorridos

**Enunciado:**
Dado PreOrden: A, B, D, E, C, F y InOrden: D, B, E, A, C, F, dibuje el árbol.

**Solución:**
```
        A
       / \
      B   C
     / \   \
    D   E   F
```

**Razonamiento:**
- La raíz es A (primer elemento de PreOrden)
- En InOrden, D, B, E están a la izquierda de A
- C, F están a la derecha de A
- Repetir recursivamente para cada subárbol
