# GUÍA COMPLETA DE ESTRUCTURAS DE DATOS
## Biblioteca de Estudio Permanente

> **Enfoque:** Teoría + Pseudocódigo + C/C++ + Práctica + Simulacro de Examen Final  
> **Lenguaje:** Pseudocódigo del curso + C/C++ (Prof. Salinas — UNMSM)  
> **Alcance:** Curso completo de Estructuras de Datos

---

## Formato de examen

Esta guía integra **ambos formatos** en cada tema:
- **Preguntas en C/C++**
- **Preguntas en pseudocódigo**

---

## Índice de Temas

### Fundamentos
| # | Tema | Archivo |
|---|------|---------|
| 1 | Punteros | `01_punteros.md` |
| 2 | Structs | `02_structs.md` |
| 3 | Memoria Dinámica | `03_memoria_dinamica.md` |
| 4 | Archivos en C/C++ | `04_archivos.md` |

### Algoritmos Básicos
| # | Tema | Archivo |
|---|------|---------|
| 5 | Ordenamientos | `05_ordenamientos.md` |
| 6 | Búsqueda | `06_busqueda.md` |

### Estructuras Lineales
| # | Tema | Archivo |
|---|------|---------|
| 7 | Listas Enlazadas | `07_listas_enlazadas.md` |
| 8 | Pilas | `08_pilas.md` |
| 9 | Colas | `09_colas.md` |

### Árboles
| # | Tema | Archivo |
|---|------|---------|
| 10 | Árboles Binarios | `10_arboles_binarios.md` |
| 11 | Árboles Binarios de Búsqueda (ABB) | `11_abb.md` |
| 12 | Árboles AVL | `12_avl.md` |
| 13 | Árboles B | `13_arboles_b.md` |
| 14 | Árboles Trie | `14_arboles_trie.md` |
| 15 | Árboles Huffman | `15_arboles_huffman.md` |

### Material Complementario
| # | Tema | Archivo |
|---|------|---------|
| 16 | Tablas Comparativas + Complejidades | `16_comparativa.md` |
| 17 | Cheatsheet Rápida | `17_cheatsheet.md` |
| 18 | Errores Frecuentes | `18_errores_frecuentes.md` |

### Práctica y Exámenes
| # | Tema | Archivo |
|---|------|---------|
| 19 | Ejercicios de Práctica | `practica/` |
| 20 | Simulacro de Examen Final | `20_simulacro_final.md` |

---

## Mapa de Dependencias

```
Punteros ──→ Structs ──→ Nodo (dato + *sgte)
   │                         │
   ▼                         ▼
Mem. Dinámica        ┌─→ Lista Enlazada ──→ Pila (LIFO)
   │                 │                      │
   │                 └──→ Cola (FIFO)        │
   │                                        │
Archivos                                  Nodo Árbol (hi + info + hd)
   │                                        │
   │                    Arreglos ──→ Ordenamiento
   │                                        │
   │                    ┌────────────────────┘
   │                    │
   └────────────────────┤
                        ▼
                   Nodo Árbol Binario
                        │
        ┌───────────────┼───────────────┐
        │               │               │
        ▼               ▼               ▼
     ABB              AVL             B-Trees
        │               │               │
        └───────────────┴───────────────┘
                        │
        ┌───────────────┼───────────────┐
        │               │               │
        ▼               ▼               ▼
     Trie           Huffman         HeapSort
```

> **Regla de oro:** Si no entiendes un tema, revisa el anterior en la cadena.

---

## Tabla de Equivalencias Pseudocódigo ↔ C/C++ (Referencia rápida)

| Pseudocódigo | C/C++ |
|-------------|-------|
| `REGISTRO NODO` | `struct NODO {` |
| `FIN_REGISTRO` | `};` |
| `ACCION nombre(params)` | `void nombre(params) {` |
| `FIN_ACCION` | `}` |
| `RETORNAR(valor)` | `return valor;` |
| `p ← nuevoNodo(cab1, dato)` | `p = new NODO;` o `(NODO*)malloc(sizeof(NODO))` |
| `liberaNodo(cab1, p)` | `delete p;` o `free(p);` |
| `p.sgte ← cab` | `p->sgte = cab;` |
| `SI(cond) ... FIN_SI` | `if(cond) { ... }` |
| `MIENTRAS(cond) ... FIN_MIENTRAS` | `while(cond) { ... }` |
| `PARA i ← 0 HASTA n-1` | `for(int i=0; i<n; i++)` |
| `ESCRIBIR(...)` | `printf(...)` o `cout << ...` |
| `LEER(var)` | `scanf(...)` o `cin >> var` |

---

## Cómo usar esta guía

1. **Lee la teoría** de cada tema (entiende el "por qué")
2. **Estudia los ejemplos resueltos** en pseudocódigo Y en C/C++
3. **Practica traducir** pseudocódigo → C/C++ y viceversa
4. **Intenta los ejercicios** sin ver la solución
5. **Revisa los patrones de examen** para saber qué esperar
6. **Haz el simulacro final** cronometrado como examen real
7. **Usa la cheatsheet** para repaso rápido antes del examen

---

## Tiempo estimado de estudio por tema

| Tema | Tiempo estimado |
|------|-----------------|
| Punteros | 60-90 min |
| Structs | 45-60 min |
| Memoria Dinámica | 60-90 min |
| Archivos | 60-90 min |
| Ordenamientos | 90-120 min |
| Búsqueda | 45-60 min |
| Listas Enlazadas | 90-120 min |
| Pilas | 60-90 min |
| Colas | 60-90 min |
| Árboles Binarios | 90-120 min |
| ABB | 90-120 min |
| AVL | 120-150 min |
| Árboles B | 120-150 min |
| Trie | 60-90 min |
| Huffman | 60-90 min |

**Tiempo total estimado:** ~20-25 horas de estudio

---

## Notas importantes

- Esta guía reutiliza y mejora el contenido de PC02 y PC03
- Los temas de árboles avanzados (AVL, B, Trie, Huffman) se han desarrollado completamente
- Cada tema incluye implementaciones en pseudocódigo Y C/C++
- Los ejercicios de práctica están en la carpeta `practica/`
- El simulacro final integra todos los temas del curso
