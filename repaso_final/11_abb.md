# TEMA 11: ÁRBOLES BINARIOS DE BÚSQUEDA (ABB)

---

## Objetivos

- Comprender la propiedad de ordenamiento de los ABB
- Dominar las operaciones de inserción, búsqueda y eliminación
- Entender los tres casos de eliminación en ABB
- Analizar la complejidad temporal de las operaciones
- Reconocer cuándo un ABB degenera en lista

---

## Conceptos clave

- **ABB (Árbol Binario de Búsqueda):** Árbol binario con propiedad de ordenamiento
- **Propiedad ABB:** Para todo nodo: subárbol izquierdo < raíz ≤ subárbol derecho
- **InOrden ordenado:** El recorrido InOrden de un ABB produce los datos en orden ascendente
- **Degeneración:** ABB que se convierte en lista (peor caso de rendimiento)
- **Predecesor:** Mayor elemento del subárbol izquierdo
- **Sucesor:** Menor elemento del subárbol derecho

---

## Explicación detallada

### ¿Qué es un ABB?

Un Árbol Binario de Búsqueda es un árbol binario con una propiedad especial de ordenamiento:

**Para cada nodo:**
- Todos los valores en el subárbol izquierdo son **menores** que el valor del nodo
- Todos los valores en el subárbol derecho son **mayores o iguales** que el valor del nodo

Esta propiedad permite búsquedas eficientes: en cada paso, eliminamos la mitad del árbol restante.

### Estructura del nodo ABB

```
REGISTRO NODO
   TD info
   NODO *izq
   NODO *der
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

### Propiedad de ordenamiento

```
        40
       /  \
      30    45
     /       \
    27        60
   /  \      /
  15  35    50

Subárbol izquierdo de 40: todos < 40
Subárbol derecho de 40: todos ≥ 40
```

---

## Operaciones en ABB

### Inserción

**Algoritmo:**
1. Si el árbol está vacío, crear nodo raíz
2. Si el valor a insertar es menor que la raíz, ir al subárbol izquierdo
3. Si el valor es mayor o igual, ir al subárbol derecho
4. Repetir hasta encontrar un lugar vacío (NULL)

**Pseudocódigo:**
```
ACCION insertar(NODO cab, NODO cab1, TD valor)
   SI(cab = NULL)
      cab ← nuevoNodo(cab1, valor)
   SINO
      SI(valor < cab.info)
         insertar(cab.izq, cab1, valor)
      SINO
         insertar(cab.der, cab1, valor)
      FIN_SI
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
void insertar(NODO **raiz, TD valor) {
    if (*raiz == NULL) {
        *raiz = new NODO;
        (*raiz)->info = valor;
        (*raiz)->izq = NULL;
        (*raiz)->der = NULL;
    } else {
        if (valor < (*raiz)->info) {
            insertar(&(*raiz)->izq, valor);
        } else {
            insertar(&(*raiz)->der, valor);
        }
    }
}
```

### Búsqueda

**Algoritmo:**
1. Si el árbol está vacío, el valor no existe
2. Si el valor es igual a la raíz, encontrado
3. Si el valor es menor, buscar en subárbol izquierdo
4. Si el valor es mayor, buscar en subárbol derecho

**Pseudocódigo:**
```
ACCION buscar(NODO raiz, TD valor) RETORNA NODO
   SI(raiz = NULL)
      RETORNAR(NULL)
   FIN_SI
   SI(valor = raiz.info)
      RETORNAR(raiz)
   SINO
      SI(valor < raiz.info)
         RETORNAR(buscar(raiz.izq, valor))
      SINO
         RETORNAR(buscar(raiz.der, valor))
      FIN_SI
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
NODO* buscar(NODO *raiz, TD valor) {
    if (raiz == NULL) return NULL;
    if (valor == raiz->info) return raiz;
    
    if (valor < raiz->info) {
        return buscar(raiz->izq, valor);
    } else {
        return buscar(raiz->der, valor);
    }
}
```

### Eliminación (3 casos)

**Caso 1: Nodo hoja**
- Simplemente eliminar (padre apunta a NULL)

**Caso 2: Nodo con un hijo**
- Sustituir el nodo por su único hijo

**Caso 3: Nodo con dos hijos**
- Reemplazar con el **predecesor** (mayor del subárbol izquierdo) o el **sucesor** (menor del subárbol derecho)
- Eliminar ese nodo

**Pseudocódigo:**
```
ACCION eliminar(NODO cab, NODO cab1, TD valor)
   SI(cab = NULL)
      RETORNAR
   FIN_SI
   SI(valor < cab.info)
      eliminar(cab.izq, cab1, valor)
   SINO
      SI(valor > cab.info)
         eliminar(cab.der, cab1, valor)
      SINO
         // Encontrado el nodo a eliminar
         SI(cab.izq = NULL Y cab.der = NULL)
            // Caso 1: hoja
            liberaNodo(cab1, cab)
            cab ← NULL
         SINO
            SI(cab.izq = NULL)
               // Caso 2a: solo hijo derecho
               temp ← cab
               cab ← cab.der
               liberaNodo(cab1, temp)
            SINO
               SI(cab.der = NULL)
                  // Caso 2b: solo hijo izquierdo
                  temp ← cab
                  cab ← cab.izq
                  liberaNodo(cab1, temp)
               SINO
                  // Caso 3: dos hijos
                  temp ← maximo(cab.izq)
                  cab.info ← temp.info
                  eliminar(cab.izq, cab1, temp.info)
               FIN_SI
            FIN_SI
         FIN_SI
      FIN_SI
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
NODO* encontrarMinimo(NODO *raiz) {
    while (raiz->izq != NULL) {
        raiz = raiz->izq;
    }
    return raiz;
}

NODO* eliminar(NODO *raiz, TD valor) {
    if (raiz == NULL) return raiz;
    
    if (valor < raiz->info) {
        raiz->izq = eliminar(raiz->izq, valor);
    } else if (valor > raiz->info) {
        raiz->der = eliminar(raiz->der, valor);
    } else {
        // Encontrado el nodo a eliminar
        if (raiz->izq == NULL) {
            // Caso 1 o 2a: 0 o 1 hijo (derecho)
            NODO *temp = raiz->der;
            delete raiz;
            return temp;
        } else if (raiz->der == NULL) {
            // Caso 2b: 1 hijo (izquierdo)
            NODO *temp = raiz->izq;
            delete raiz;
            return temp;
        }
        
        // Caso 3: dos hijos
        NODO *temp = encontrarMinimo(raiz->der);
        raiz->info = temp->info;
        raiz->der = eliminar(raiz->der, temp->info);
    }
    return raiz;
}
```

---

## Ejemplos

### Ejemplo 1: Construir un ABB

**Secuencia de inserción:** 40, 30, 45, 27, 35, 60, 38

**Paso a paso:**
```
Insertar 40:        40
Insertar 30:        40
                   /
                  30
Insertar 45:        40
                   /  \
                  30   45
Insertar 27:        40
                   /  \
                  30   45
                 /
                27
Insertar 35:        40
                   /  \
                  30   45
                 /  \
                27  35
Insertar 60:        40
                   /  \
                  30   45
                 /  \    \
                27  35   60
Insertar 38:        40
                   /  \
                  30   45
                 /  \    \
                27  35   60
                    \
                    38
```

**Recorridos del ABB:**
- **PreOrden:** 40, 30, 27, 35, 38, 45, 60
- **InOrden:** 27, 30, 35, 38, 40, 45, 60 (¡ordenado!)
- **PostOrden:** 27, 38, 35, 30, 60, 45, 40

### Ejemplo 2: Búsqueda en ABB

**Pregunta:** Buscar el valor 35 en el ABB anterior.

**Traza:**
```
1. Raíz = 40, 35 < 40 → ir a izquierda
2. Nodo = 30, 35 > 30 → ir a derecha
3. Nodo = 35, 35 = 35 → ¡encontrado!
```

**Complejidad:** 3 comparaciones (altura del árbol = 2)

### Ejemplo 3: Eliminación en ABB

**Pregunta:** Eliminar el valor 30 del ABB anterior.

**Análisis:**
- El nodo 30 tiene dos hijos (27 y 35)
- Usamos el sucesor: el mínimo del subárbol derecho = 35
- Reemplazamos 30 con 35
- Eliminamos el 35 original (que ahora tiene solo hijo derecho 38)

**Árbol resultante:**
```
        40
       /  \
      35   45
     /  \    \
    27  38   60
```

---

## Casos típicos de examen

### Caso 1: Construir ABB desde secuencia

**Pregunta:** Inserte los valores 50, 25, 75, 10, 30, 60, 80, 5, 15 en un ABB vacío. Muestre el árbol resultante y los recorridos.

**Solución:**
```
Árbol resultante:
        50
       /  \
      25   75
     / \   / \
    10 30 60 80
   / \
  5  15

PreOrden: 50, 25, 10, 5, 15, 30, 75, 60, 80
InOrden: 5, 10, 15, 25, 30, 50, 60, 75, 80
PostOrden: 5, 15, 10, 30, 25, 60, 80, 75, 50
```

### Caso 2: Determinar si es ABB

**Pregunta:** ¿Es el siguiente árbol un ABB? Justifique.
```
        10
       /  \
      5    15
     / \   /
    3   12 20
```

**Solución:** NO es un ABB. El nodo 12 está en el subárbol izquierdo de 10, pero 12 > 10, violando la propiedad ABB.

### Caso 3: Degeneración de ABB

**Pregunta:** ¿Qué pasa si insertamos 1, 2, 3, 4, 5 en ese orden en un ABB?

**Solución:** El ABB degenera en una lista:
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

**Consecuencia:** Búsqueda se vuelve O(n) en lugar de O(log n). Solución: usar árboles balanceados (AVL).

---

## Errores frecuentes

| Error | Qué pasa | Cómo evitarlo |
|-------|----------|---------------|
| Confundir propiedad ABB (≤ vs <) | Inserciones incorrectas | Memorizar: izq < raíz ≤ der |
| Olvidar caso de dos hijos en eliminación | Memory leak o árbol corrupto | Siempre manejar los 3 casos |
- No usar doble puntero en inserción | La inserción no persiste | Usar `NODO**` para modificar la cabeza |
- Asumir que InOrden siempre está ordenado | Solo es cierto para ABB | Verificar que sea un ABB primero |
- Insertar valores ya existentes | Puede causar duplicados | Decidir política: permitir o rechazar |

---

## Preguntas de recuperación activa

1. ¿Por qué el recorrido InOrden de un ABB produce los datos ordenados?
2. ¿Cuándo conviene utilizar un ABB en lugar de un arreglo ordenado?
3. ¿Qué diferencia existe entre un AVL y un ABB?
4. ¿Por qué un ABB puede degenerar en una lista?
5. ¿Cuál es la complejidad de búsqueda en un ABB balanceado vs desbalanceado?
6. ¿En qué caso de eliminación necesitamos buscar el sucesor o predecesor?
7. ¿Por qué la inserción en ABB es más eficiente que en lista enlazada?
8. ¿Cómo se determina si un árbol binario es un ABB?

---

## Autoevaluación

### Nivel 1 (Básico)
1. Defina la propiedad de ordenamiento de un ABB.
2. Escriba el pseudocódigo de búsqueda en ABB.
3. ¿Qué recorrido produce los datos ordenados en un ABB?

### Nivel 2 (Intermedio)
1. Construya un ABB con la secuencia: 20, 10, 30, 5, 15, 25, 35.
2. Implemente la función para encontrar el valor mínimo en C/C++.
3. Explique los tres casos de eliminación en ABB.

### Nivel 3 (Avanzado)
1. Demuestre que InOrden de un ABB produce datos ordenados.
2. Implemente una función que verifique si un árbol binario es un ABB.
3. Analice la complejidad temporal de todas las operaciones en mejor y peor caso.

---

## Resumen de una página

**ABB (Árbol Binario de Búsqueda):** Árbol binario con propiedad de ordenamiento.

**Propiedad ABB:** Para todo nodo: subárbol izquierdo < raíz ≤ subárbol derecho

**Estructura:**
```cpp
struct NODO {
    TD info;
    NODO *izq;
    NODO *der;
};
```

**Operaciones:**
- **Inserción:** Comparar con raíz, ir a izq si menor, der si mayor/igual
- **Búsqueda:** Comparar con raíz, ir a izq si menor, der si mayor
- **Eliminación:** 3 casos:
  1. Hoja: simplemente eliminar
  2. Un hijo: sustituir por el hijo
  3. Dos hijos: reemplazar con sucesor/predecesor

**Complejidad:**
- Mejor caso (balanceado): O(log n)
- Peor caso (degenerado): O(n)
- InOrden siempre produce datos ordenados

**Degeneración:** Si los datos vienen ordenados, el ABB se convierte en lista. Solución: AVL.

**Errores comunes:**
- Confundir ≤ vs < en propiedad ABB
- Olvidar caso de dos hijos en eliminación
- No usar doble puntero en inserción
- Asumir InOrden ordenado sin verificar que sea ABB
