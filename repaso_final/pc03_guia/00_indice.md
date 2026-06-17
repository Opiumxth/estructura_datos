# GUÍA COMPLETA PC3 — ESTRUCTURA DE DATOS
> **Enfoque:** Teoría + Pseudocódigo + C/C++ + Simulacro de Examen
> **Lenguaje:** Pseudocódigo del curso + C/C++ (Prof. Salinas — UNMSM)
> **Alcance:** Sem 01 → Árboles

---

## Formato de examen

En la última PC el profesor cambió el formato habitual:
- **Una pregunta en C/C++**
- **Una pregunta en pseudocódigo**

Por ello, esta guía integra **ambos formatos** en cada tema.

---

## Índice de Temas

| # | Tema | Archivo |
|---|------|---------|
| 1 | Punteros | `01_punteros.md` |
| 2 | Structs | `02_structs.md` |
| 3 | Memoria Dinámica | `03_memoria_dinamica.md` |
| 4 | Archivos en C/C++ | `04_archivos.md` |
| 5 | Ordenamientos | `05_ordenamientos.md` |
| 6 | Búsqueda | `06_busqueda.md` |
| 7 | Listas Enlazadas | `07_listas_enlazadas.md` |
| 8 | Pilas | `08_pilas.md` |
| 9 | Colas | `09_colas.md` |
| **10** | **Árboles (NUEVO PC3)** | **`10_arboles.md`** |

---

## Material Complementario

| Recurso | Archivo |
|---------|---------|
| Tablas comparativas + Complejidades | `11_comparativa.md` |
| Simulacro de Examen PC3 con soluciones | `12_simulacro_pc03.md` |

---

## Mapa de Dependencias

```
Punteros ──→ Structs ──→ Nodo (dato + *sgte)
   │                         │
   ▼                         ├──→ Lista Enlazada ──→ Pila (LIFO)
Mem. Dinámica                │                  └──→ Cola (FIFO)
                             │
   Archivos                  └──→ Nodo Árbol (hi + info + hd)
                                        │
Arreglos ──→ Ordenamiento               ├──→ Árbol N-ario
   └──────→ Búsqueda Lineal             ├──→ Árbol Binario (ABB)
              Búsqueda Binaria           ├──→ Árbol Trie
                                         └──→ Árbol Huffman
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
6. **Haz el simulacro** cronometrado como examen real
