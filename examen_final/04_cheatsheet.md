# Cheatsheet — Colas · Árboles · Grafos

Lectura de bus. Máximo concentrado. Fuente: `repaso_final` + sem07–sem14.

---

## Complejidades

| Estructura | Insertar | Buscar | Eliminar | Notas |
|------------|----------|--------|----------|-------|
| Cola | O(1) | O(n) | O(1) frente | solo frente/final |
| Binario | O(n) | O(n) | O(n) | sin orden |
| ABB | O(log n)* | O(log n)* | O(log n)* | *peor O(n) |
| AVL | O(log n) | O(log n) | O(log n) | garantizado |
| Árbol B | O(log_m n) | O(log_m n) | O(log_m n) | disco |
| Trie | O(L) | O(L) | O(L) | L = longitud |
| Huffman | O(n log n) construir | — | — | compresión |
| DFS / BFS | — | O(V+E) | — | lista adyacencia |
| Dijkstra | — | O(n²) típico | — | O(n log n) con heap |

---

## Operaciones clave

### Cola
```
FIFO · enqueue final · dequeue frente
Circular: (i+1)%MAX
Lista: si frente==NULL → final=NULL
```

### Árboles — recorridos
```
Pre  RID  Raíz Izq Der
In   IRD  Izq Raíz Der   ← ordenado en ABB
Post IDR  Izq Der Raíz
```

### ABB
```
izq < raíz ≤ der
Borrar: hoja | 1 hijo | 2 hijos (sucesor/predecesor)
```

### AVL
```
FE = alt(der) − alt(izq)   |FE| ≤ 1
LL → der    RR → izq
LR → izq+der    RL → der+izq
```

### Árbol B (orden m)
```
máx hijos = m · máx claves = m−1
mín claves (≠ raíz) = ⌈m/2⌉−1
lleno → split + promover mediana
hojas al mismo nivel
```

### Trie / Huffman
```
Trie: carácter a carácter · marcar finPalabra · O(L)
Huffman: 2 menores → padre suma · izq=0 der=1 · prefijo libre
```

### Grafos
```
Matriz: O(V²) mem · arista O(1) · densos
Lista:  O(V+E) mem · dispersos
DFS = pila    BFS = cola
Dijkstra: menor dist no marcado → relajar vecinos → marcar
```

---

## ¿Cuándo usar qué?

| Necesidad | Estructura |
|-----------|------------|
| Turnos / fila / BFS | **Cola** |
| Jerarquía simple | Binario |
| Buscar + insertar dinámico | **ABB** |
| ABB sin degenerar | **AVL** |
| Muchos datos en disco | **Árbol B** |
| Diccionario / autocomplete | **Trie** |
| Comprimir por frecuencia | **Huffman** |
| Relaciones / redes / rutas | **Grafo** |
| Camino mín. #aristas | **BFS** |
| Camino mín. con pesos ≥0 | **Dijkstra** |
| Ciclos / topológico | **DFS** |

---

## Diferencias flash

| A vs B | Diferencia en 1 línea |
|--------|------------------------|
| Pila vs Cola | LIFO vs FIFO |
| Binario vs ABB | sin orden vs ordenado |
| ABB vs AVL | puede ser lista vs \|FE\|≤1 |
| AVL vs B | binario RAM vs multi-vía disco |
| Matriz vs Lista | densos / O(1) arista vs dispersos / O(V+E) |
| DFS vs BFS | profundidad+pila vs niveles+cola |
| BFS vs Dijkstra | cuenta aristas vs suma pesos |

---

## Palabras clave (si las ves en el enunciado)

| Palabra | Piensa en |
|---------|-----------|
| FIFO, frente, final, circular, % | Cola |
| RID / IRD / IDR, hoja, altura | Binario |
| izq menor, InOrden ordenado, degenera | ABB |
| FE, rotación, balance | AVL |
| orden m, split, mediana, página | B |
| prefijo, finPalabra, autocomplete | Trie |
| frecuencia, código, 0/1 | Huffman |
| V, A, adyacencia, dirigido | Grafo |
| profundidad, pila, ciclo | DFS |
| anchura, niveles, cola | BFS |
| peso, distancia, camino mínimo | Dijkstra |

---

## Errores frecuentes (los del curso)

1. Cola lista: olvidar `final = NULL` al vaciar  
2. Circular: olvidar `% MAX`  
3. Árbol: olvidar caso base `NULL`  
4. ABB: olvidar caso 2 hijos al borrar  
5. AVL: FE al revés o no actualizar altura  
6. B: confundir m (hijos) con m−1 (claves)  
7. Trie: no marcar fin de palabra  
8. Huffman: no sacar los 2 de menor frecuencia  
9. Grafo no dirigido: no poner arista en ambos lados  
10. Confundir DFS/BFS o BFS/Dijkstra  

---

## Fórmulas útiles

```
Cola circular:  frente = (frente+1)%MAX
Máx aristas no dirigido: n(n−1)/2
Máx aristas dirigido:    n(n−1)
Árbol B: claves máx = m−1 · mín = ⌈m/2⌉−1
FE AVL: alt(der)−alt(izq)
Altura vacío: −1
Densidad ≈ 2|A|/|V|
```

---

## Mini traza mental (antes de entrar)

```
Cola:  enq 1,2,3 · deq →1 · queda 2,3
ABB:   40,30,45,27 → InOrden 27,30,40,45
AVL:   10,20,30 → RR → raíz 20
B m=3: llenar hoja → split mediana al padre
BFS:   usa COLA · por niveles
DFS:   usa PILA · una rama hasta el fondo
Dijkstra: dist[origen]=0 · cerrar el de menor dist · relajar
```
