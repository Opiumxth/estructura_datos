# Formulario — solo tablas

---

## Complejidades

| Estructura | Inserción | Búsqueda | Eliminación | Uso |
|------------|-----------|----------|-------------|-----|
| Cola | O(1) | O(n) | O(1) | turnos, BFS |
| Binario | O(n) | O(n) | O(n) | jerarquías |
| ABB | O(log n)* | O(log n)* | O(log n)* | búsqueda dinámica |
| AVL | O(log n) | O(log n) | O(log n) | ABB balanceado |
| Árbol B | O(log_m n) | O(log_m n) | O(log_m n) | disco / BD |
| Trie | O(L) | O(L) | O(L) | diccionarios |
| Huffman | O(n log n)† | — | — | compresión |

\* peor caso O(n) si degenera · † construcción

---

## Cola — operaciones

| Op | Acción | Complejidad |
|----|--------|-------------|
| enqueue | al final | O(1) |
| dequeue | del frente | O(1) |
| front | mira frente | O(1) |
| isEmpty | ¿vacía? | O(1) |

| Impl. | Clave |
|-------|-------|
| Circular | `(i+1) % MAX` |
| Lista | vaciar → `final = NULL` |

---

## Árboles — comparación

| | Binario | ABB | AVL | B | Trie | Huffman |
|--|---------|-----|-----|---|------|---------|
| Orden | no | sí | sí | sí | por char | por freq |
| Hijos máx | 2 | 2 | 2 | m | alfabeto | 2 |
| Balance | no | no | sí | sí | — | — |
| Peor búsqueda | O(n) | O(n) | O(log n) | O(log_m n) | O(L) | — |

---

## Recorridos de árbol

| Nombre | Orden | Sigla |
|--------|-------|-------|
| PreOrden | Raíz, Izq, Der | RID |
| InOrden | Izq, Raíz, Der | IRD |
| PostOrden | Izq, Der, Raíz | IDR |

| Hecho | Valor |
|-------|-------|
| InOrden en ABB | datos **ordenados** |
| Altura vacío | **−1** |

---

## ABB — eliminación

| Caso | Acción |
|------|--------|
| 0 hijos (hoja) | borrar |
| 1 hijo | sustituir por el hijo |
| 2 hijos | sucesor o predecesor |

---

## AVL — rotaciones

| Caso | FE nodo | FE hijo | Rotación |
|------|---------|---------|----------|
| LL | < −1 | ≤ 0 | derecha |
| RR | > 1 | ≥ 0 | izquierda |
| LR | < −1 | > 0 | izq + der |
| RL | > 1 | < 0 | der + izq |

| Fórmula | |
|---------|--|
| FE | `alt(der) − alt(izq)` |
| Balance | `\|FE\| ≤ 1` |

---

## Árbol B (orden m)

| Concepto | Valor |
|----------|-------|
| Máx hijos | m |
| Máx claves | m − 1 |
| Mín claves (≠ raíz) | ⌈m/2⌉ − 1 |
| Overflow | split + mediana al padre |
| Hojas | mismo nivel |

---

## Trie / Huffman

| | Trie | Huffman |
|--|------|---------|
| Unidad | carácter | símbolo+frecuencia |
| Complejidad clave | O(L) | O(n log n) construir |
| Marca especial | finPalabra | hoja = símbolo |
| Códigos | — | izq=0, der=1 |

---

## Grafos — representación

| | Matriz adyacencia | Lista adyacencia |
|--|-------------------|------------------|
| Memoria | O(V²) | O(V+E) |
| ¿Hay arista? | O(1) | O(grado) |
| Ideal | densos | dispersos |
| No dirigido | matriz simétrica | arista en ambos |

| Tipo | Aristas máx |
|------|-------------|
| No dirigido | n(n−1)/2 |
| Dirigido | n(n−1) |

---

## Recorridos de grafo

| | DFS | BFS |
|--|-----|-----|
| Auxiliar | pila / recursión | cola |
| Orden | profundidad | niveles |
| Camino mín. (# aristas) | no | sí |
| Usos | ciclos, topológico | niveles, redes |

---

## Algoritmos de grafos

| Algoritmo | Problema | Complejidad (curso) |
|-----------|----------|---------------------|
| DFS | explorar / ciclos | O(V+E) |
| BFS | mín. aristas desde s | O(V+E) |
| Dijkstra | mín. peso desde s (≥0) | O(n²) / O(n log n) |
| Floyd | mín. entre todos | (existe en material) |
| Warshall | alcanzabilidad | (existe en material) |
| Prim/Kruskal | árbol cubrimiento mín. | (existe en material) |

---

## Dijkstra — pasos

| Paso | Acción |
|------|--------|
| 1 | dist[origen]=0; resto=∞ |
| 2 | elegir no marcado con menor dist |
| 3 | relajar vecinos (mejorar dist + prev) |
| 4 | marcar nodo |
| 5 | repetir; reconstruir con prev |

---

## Cuándo usar (1 línea)

| Estructura | Usa si… |
|------------|---------|
| Cola | orden de llegada / BFS |
| ABB | buscar+insertar, aceptas peor O(n) |
| AVL | necesitas O(log n) garantizado |
| B | índices / disco |
| Trie | strings / prefijos |
| Huffman | comprimir |
| Matriz | grafo denso |
| Lista | grafo disperso |
| BFS | camino más corto sin pesos |
| Dijkstra | camino más corto con pesos ≥0 |
