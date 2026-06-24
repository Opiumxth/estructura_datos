# PRÁCTICA 11: ÁRBOLES BINARIOS DE BÚSQUEDA (ABB)

---

## Ejercicio 11.1 (Fácil) - Valor mínimo

**Enunciado:**
Escriba una función que encuentre el valor mínimo en un ABB (el nodo más a la izquierda).

**Solución en C/C++:**
```cpp
int minimo(NODO* raiz) {
    if (raiz == NULL) {
        cout << "Árbol vacío" << endl;
        return -1;
    }
    
    while (raiz->izq != NULL) {
        raiz = raiz->izq;
    }
    
    return raiz->info;
}
```

**Pseudocódigo:**
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

---

## Ejercicio 11.2 (Medio) - Construir ABB

**Enunciado:**
Inserte los valores 40, 30, 45, 27, 35, 60, 38 en un ABB vacío. Dibuje el árbol resultante.

**Solución:**
```
        40
       /  \
      30    45
     /       \
    27    35  60
          \
          38
```

---

## Ejercicio 11.3 (Medio) - Verificar si es ABB

**Enunciado:**
Escriba una función que verifique si un árbol binario es un ABB.

**Solución en C/C++:**
```cpp
bool esABB(NODO* raiz, int min, int max) {
    if (raiz == NULL) return true;
    
    if (raiz->info < min || raiz->info > max) {
        return false;
    }
    
    return esABB(raiz->izq, min, raiz->info - 1) && 
           esABB(raiz->der, raiz->info + 1, max);
}

bool esABB(NODO* raiz) {
    return esABB(raiz, INT_MIN, INT_MAX);
}
```

---

## Ejercicio 11.4 (Difícil) - Eliminar nodo con dos hijos

**Enunciado:**
Escriba la función de eliminación para un ABB, manejando específicamente el caso de un nodo con dos hijos.

**Solución en C/C++:**
```cpp
NODO* encontrarMinimo(NODO* raiz) {
    while (raiz->izq != NULL) {
        raiz = raiz->izq;
    }
    return raiz;
}

NODO* eliminar(NODO* raiz, int valor) {
    if (raiz == NULL) return raiz;
    
    if (valor < raiz->info) {
        raiz->izq = eliminar(raiz->izq, valor);
    } else if (valor > raiz->info) {
        raiz->der = eliminar(raiz->der, valor);
    } else {
        // Nodo con un hijo o sin hijos
        if (raiz->izq == NULL) {
            NODO* temp = raiz->der;
            delete raiz;
            return temp;
        } else if (raiz->der == NULL) {
            NODO* temp = raiz->izq;
            delete raiz;
            return temp;
        }
        
        // Nodo con dos hijos
        NODO* temp = encontrarMinimo(raiz->der);
        raiz->info = temp->info;
        raiz->der = eliminar(raiz->der, temp->info);
    }
    
    return raiz;
}
```

---

## Ejercicio 11.5 (Tipo examen) - Degeneración

**Enunciado:**
¿Qué pasa si insertamos 1, 2, 3, 4, 5 en ese orden en un ABB? Dibuje el árbol resultante.

**Solución:**
```
1
 \
  2
   \
    3
     \
      4
       \
        5
```

**Explicación:** El ABB degenera en una lista enlazada porque los datos vienen ordenados. La búsqueda se vuelve O(n) en lugar de O(log n). Solución: usar AVL.
