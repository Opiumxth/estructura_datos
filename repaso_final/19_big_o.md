# BIG-O NOTATION - COMPLEJIDADES

---

## Complejidades Temporales

### Jerarquía de Eficiencia

```
O(1)  <  O(log n)  <  O(n)  <  O(n log n)  <  O(n²)  <  O(2ⁿ)  <  O(n!)
 │          │          │           │             │
const.   binaria    lineal     merge/quick    burbuja
```

### Valores de Referencia

| n | O(log n) | O(n) | O(n log n) | O(n²) |
|---|----------|------|------------|-------|
| 10 | 3 | 10 | 33 | 100 |
| 100 | 7 | 100 | 664 | 10,000 |
| 1,000 | 10 | 1,000 | 9,966 | 1,000,000 |
| 1,000,000 | 20 | 1M | 20M | 1 billón |

---

## Estructuras de Datos

### Tabla Comparativa

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

---

## Algoritmos de Ordenamiento

### Tabla Comparativa

| Algoritmo | Mejor | Promedio | Peor | Estable | Espacio |
|-----------|-------|----------|------|---------|---------|
| **Burbuja** | O(n) | O(n²) | O(n²) | Sí | O(1) |
| **Selección** | O(n²) | O(n²) | O(n²) | No | O(1) |
| **Inserción** | O(n) | O(n²) | O(n²) | Sí | O(1) |
| **QuickSort** | O(n log n) | O(n log n) | O(n²) | No | O(log n) |
| **MergeSort** | O(n log n) | O(n log n) | O(n log n) | Sí | O(n) |
| **HeapSort** | O(n log n) | O(n log n) | O(n log n) | No | O(1) |

### Cuándo Usar Cada Uno

| Situación | Algoritmo Recomendado |
|-----------|----------------------|
| Datos casi ordenados | Inserción (O(n)) |
| Estabilidad requerida | MergeSort |
| Memoria limitada | HeapSort |
| Promedio rápido | QuickSort |
| Implementación simple | Burbuja (solo para n pequeño) |

---

## Algoritmos de Búsqueda

### Tabla Comparativa

| Algoritmo | Complejidad | Requisito |
|-----------|-------------|-----------|
| **Lineal** | O(n) | Ninguno |
| **Binaria** | O(log n) | Datos ordenados |

### Comparación

| n | Búsqueda Lineal | Búsqueda Binaria |
|---|----------------|------------------|
| 10 | 10 | 4 |
| 100 | 100 | 7 |
| 1,000 | 1,000 | 10 |
| 1,000,000 | 1,000,000 | 20 |

---

## Árboles

### Propiedades

| Propiedad | Fórmula |
|-----------|---------|
| Máx nodos en nivel n | 2ⁿ |
| Máx nodos en árbol altura h | 2^(h+1) - 1 |
| Altura de árbol vacío | -1 |
| Factor de Equilibrio AVL | FE = altura(der) - altura(izq) |

### Complejidades por Tipo de Árbol

| Tipo de Árbol | Búsqueda | Inserción | Eliminación |
|--------------|----------|-----------|-------------|
| **Binario** | O(n) | O(n) | O(n) |
| **ABB** | O(log n) promedio | O(log n) promedio | O(log n) promedio |
| **ABB** (peor caso) | O(n) | O(n) | O(n) |
| **AVL** | O(log n) | O(log n) | O(log n) |
| **Árbol B** | O(log_m n) | O(log_m n) | O(log_m n) |
| **Trie** | O(L) | O(L) | O(L) |

---

## Operaciones por Estructura

### Arreglos

| Operación | Complejidad |
|-----------|-------------|
| Acceso por índice | O(1) |
| Búsqueda lineal | O(n) |
| Búsqueda binaria | O(log n) |
| Inserción al final | O(1)* |
| Inserción al inicio | O(n) |
| Eliminación al final | O(1) |
| Eliminación al inicio | O(n) |

```
* Si hay espacio disponible
```

### Listas Enlazadas

| Operación | Complejidad |
|-----------|-------------|
| Acceso por índice | O(n) |
| Búsqueda | O(n) |
| Inserción al inicio | O(1) |
| Inserción al final | O(n) |
| Eliminación al inicio | O(1) |
| Eliminación al final | O(n) |
| Inserción ordenada | O(n) |

### Pilas (LIFO)

| Operación | Complejidad |
|-----------|-------------|
| Push | O(1) |
| Pop | O(1) |
| Peek (ver tope) | O(1) |
| Búsqueda | O(n) |

### Colas (FIFO)

| Operación | Complejidad |
|-----------|-------------|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Peek (ver frente) | O(1) |
| Búsqueda | O(n) |

---

## Notación Big-O - Definiciones

### O (O Grande) - Cota Superior

f(n) = O(g(n)) si existe c > 0 y n₀ tal que f(n) ≤ c·g(n) para todo n ≥ n₀

**Ejemplo:** n² + 3n + 2 = O(n²)

### Ω (Omega) - Cota Inferior

f(n) = Ω(g(n)) si existe c > 0 y n₀ tal que f(n) ≥ c·g(n) para todo n ≥ n₀

**Ejemplo:** n² + 3n + 2 = Ω(n²)

### Θ (Theta) - Cota Ajustada

f(n) = Θ(g(n)) si f(n) = O(g(n)) y f(n) = Ω(g(n))

**Ejemplo:** n² + 3n + 2 = Θ(n²)

---

## Reglas de Simplificación

1. **Constantes:** O(2n) = O(n)
2. **Términos de menor orden:** O(n² + n) = O(n²)
3. **Suma:** O(f(n)) + O(g(n)) = O(max(f(n), g(n)))
4. **Producto:** O(f(n)) · O(g(n)) = O(f(n) · g(n))
5. **Logaritmos:** O(log_a n) = O(log_b n) para cualquier base a, b

---

## Casos de Análisis

### Mejor Caso

El escenario más favorable para el algoritmo.

**Ejemplo:** Búsqueda binaria - el elemento está en el medio del arreglo.

### Caso Promedio

El escenario promedio esperado.

**Ejemplo:** Búsqueda lineal - el elemento está en la posición n/2.

### Peor Caso

El escenario menos favorable para el algoritmo.

**Ejemplo:** Búsqueda lineal - el elemento está al final o no existe.

---

## Espacio vs Tiempo

### Trade-off Común

| Estructura | Tiempo | Espacio |
|------------|--------|--------|
| Arreglo | Acceso rápido O(1) | Tamaño fijo |
| Lista | Acceso lento O(n) | Dinámico |
| Hash Table | Búsqueda O(1) promedio | Más espacio |
| AVL | Búsqueda O(log n) garantizado | Más complejidad |

### Regla General

- **Más tiempo → Menos espacio**
- **Menos tiempo → Más espacio**

Ejemplo: Hash table usa más memoria pero ofrece búsqueda O(1).
