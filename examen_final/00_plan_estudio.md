# Plan de estudio — Examen final

**Fuente:** material del curso (sem07–sem15 + `repaso_final/` + labs).  
**Alcance del examen (según el profesor):** Colas · Árboles · Grafos.

---

## Cómo usar esta carpeta

| Orden | Archivo | Tiempo |
|-------|---------|--------|
| 1 | `01_colas.md` | ~30 min |
| 2 | `02_arboles.md` | ~2 h |
| 3 | `03_grafos.md` | ~1.5 h |
| 4 | `05_formulario.md` | ~20 min |
| 5 | `04_cheatsheet.md` | lectura rápida (bus / antes de entrar) |

No intentes “terminar” toda la materia. Domina estos tres temas.

---

## Prioridad dentro de cada tema

### Colas (peso bajo-medio)
1. FIFO + operaciones (`enqueue` / `dequeue` / `front`)
2. Cola circular (`% MAX`)
3. Cola con lista (actualizar `final = NULL` al vaciar)
4. Relación con BFS

### Árboles (peso alto)
1. **ABB** — propiedad, inserción, eliminación (3 casos), InOrden ordenado
2. **AVL** — FE, 4 rotaciones (LL, RR, LR, RL)
3. **Árbol B** — orden m, split, hojas al mismo nivel
4. Binario — recorridos Pre/In/Post
5. Trie y Huffman — idea + complejidad (menos tiempo)

### Grafos (peso alto)
1. Definición + dirigido / no dirigido + peso
2. Matriz vs lista de adyacencia (cuándo cada una)
3. **DFS** (pila/recursión) y **BFS** (cola)
4. **Dijkstra** paso a paso (camino mínimo con pesos ≥ 0)

---

## Checklist “listo para el examen”

- [ ] Traza enqueue/dequeue (circular con `%`)
- [ ] Construyo un ABB e indico los 3 casos de borrado
- [ ] Calculo FE y digo qué rotación aplica
- [ ] Inserto en B-tree hasta forzar un split
- [ ] Dibujo matriz y lista de un grafo pequeño
- [ ] Escribo orden BFS y DFS desde un nodo
- [ ] Ejecuto Dijkstra a mano (distancias + predecesores)

---

## Fuentes del repo (si dudas)

| Tema | Dónde |
|------|--------|
| Colas | `repaso_final/09_colas.md`, `sem07/teoS07 Colas1.pdf`, lab cola |
| Árboles | `repaso_final/10`–`15_*.md`, PDFs sem09–sem12 |
| Grafos | `sem13/teoS13Grafos v2.pdf`, `sem14/teoS14GrafosAlgo.pdf`, labs DFS/BFS/Dijkstra |
| Resumen | `repaso_final/16_comparativa.md`, `17_cheatsheet.md` |

---

## Recomendación para las próximas horas

```
30 min  → Colas
2 h     → Árboles (ABB, AVL, B)
1.5 h   → Grafos (repr. + BFS/DFS + Dijkstra)
20 min  → Formulario
        → Dormir
```

Mañana ganas con ideas claras, no con volumen.
