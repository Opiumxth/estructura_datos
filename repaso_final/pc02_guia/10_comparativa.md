# 📊 TABLAS COMPARATIVAS Y HOJA DE COMPLEJIDADES

---

## Tabla Comparativa de Estructuras

| Estructura | Política | Acceso | Insertar inicio | Insertar final | Eliminar inicio | Buscar | Tamaño |
|------------|----------|--------|----------------|----------------|-----------------|--------|--------|
| **Arreglo** | Libre | **O(1)** | O(n) | O(1)* | O(n) | O(n) / O(log n)** | Fijo |
| **Lista Simple** | Libre | O(n) | **O(1)** | O(n) | **O(1)** | O(n) | Dinámico |
| **Pila** | LIFO | O(1)† | **O(1)** | N/A | **O(1)** | O(n) | Dep. impl. |
| **Cola** | FIFO | O(1)†† | N/A | **O(1)** | **O(1)** | O(n) | Dep. impl. |

```
*  Si hay espacio y se agrega al final del arreglo
** O(log n) solo si está ordenado (Búsqueda Binaria)
†  Solo acceso al tope
†† Solo acceso al frente
```

---

## Pila vs Cola vs Lista — Cuándo usar cada una

| Necesidad | Estructura | Por qué |
|-----------|-----------|---------|
| Acceso por índice | Arreglo | O(1) directo |
| Tamaño desconocido + inserciones frecuentes | Lista | Dinámico, O(1) al inicio |
| Deshacer/rehacer, recursión, paréntesis | **Pila** | LIFO natural |
| Turnos, orden de llegada, BFS | **Cola** | FIFO natural |
| Datos ordenados + búsqueda rápida | Arreglo ordenado | Búsqueda binaria O(log n) |

---

## Hoja de Complejidades

### Ordenamiento

| Algoritmo | Mejor | Promedio | Peor | Estable | Espacio |
|-----------|-------|----------|------|---------|---------|
| Burbuja | O(n) | O(n²) | O(n²) | ✅ | O(1) |
| Selección | O(n²) | O(n²) | O(n²) | ❌ | O(1) |
| **Inserción** | **O(n)** | O(n²) | O(n²) | ✅ | O(1) |
| QuickSort | O(n log n) | O(n log n) | O(n²) | ❌ | O(log n) |
| MergeSort | O(n log n) | O(n log n) | O(n log n) | ✅ | O(n) |

### Búsqueda

| Algoritmo | Complejidad | Requisito |
|-----------|-------------|-----------|
| Lineal | O(n) | Ninguno |
| **Binaria** | **O(log n)** | Datos ordenados |

### Jerarquía de eficiencia

```
O(1)  <  O(log n)  <  O(n)  <  O(n log n)  <  O(n²)  <  O(2ⁿ)  <  O(n!)
 │          │          │           │             │
const.   binaria    lineal     merge/quick    burbuja
                                             selección
                                             inserción
```

### Valores de referencia

| n | O(log n) | O(n) | O(n log n) | O(n²) |
|---|----------|------|------------|-------|
| 10 | 3 | 10 | 33 | 100 |
| 100 | 7 | 100 | 664 | 10,000 |
| 1,000 | 10 | 1,000 | 9,966 | 1,000,000 |
| 1,000,000 | 20 | 1M | 20M | 1 billón |

---

## Fórmulas clave para el examen

| Fórmula | Uso |
|---------|-----|
| `n(n-1)/2` | Comparaciones de Burbuja/Selección en peor caso |
| `⌊log₂(n)⌋ + 1` | Máx comparaciones de Búsqueda Binaria |
| `(frente + 1) % MAX` | Avanzar frente en cola circular |
| `(final + 1) % MAX` | Avanzar final en cola circular |
| `sizeof(struct)` | Bytes que ocupa un struct (para archivos binarios) |

---

## Resumen de operadores y funciones del curso

| Contexto | C (estilo profesor) | C++ |
|----------|-------------------|-----|
| Reservar memoria | `(TIPO*)malloc(sizeof(TIPO))` | `new TIPO` |
| Liberar memoria | `free(p)` | `delete p` / `delete[] p` |
| Abrir archivo | `fopen("nombre", "modo")` | `ofstream f("nombre")` |
| Escribir binario | `fwrite(&dato, sizeof, n, f)` | `f.write((char*)&dato, sizeof)` |
| Leer binario | `fread(&dato, sizeof, 1, f)` | `f.read((char*)&dato, sizeof)` |
| Cerrar archivo | `fclose(f)` | `f.close()` |
| Imprimir | `printf(...)` | `cout << ...` |

---

## Términos que DEBES memorizar

| Término | Definición exacta |
|---------|-------------------|
| Puntero | Variable que almacena una dirección de memoria |
| Struct | Tipo de dato que agrupa variables de distintos tipos |
| LIFO | Last In, First Out → Pila |
| FIFO | First In, First Out → Cola |
| TAD | Tipo Abstracto de Dato: define QUÉ hace sin decir CÓMO |
| Nodo | Struct con dato + puntero al siguiente |
| Memory leak | Memoria reservada que nunca se libera |
| Dangling pointer | Puntero que apunta a memoria ya liberada |
| Stack overflow | Push en pila llena |
| Stack underflow | Pop en pila vacía |
