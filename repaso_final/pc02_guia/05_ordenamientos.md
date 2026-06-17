# TEMA 5: MÉTODOS DE ORDENAMIENTO

---

## 1. TEORÍA CLARA

### ¿Qué es ordenar?
Reorganizar los elementos de una colección según un criterio (generalmente de menor a mayor o viceversa).

### ¿Para qué sirve?
- **Requisito para Búsqueda Binaria** (O(log n) vs O(n)).
- Facilitar reportes, listados y consultas.
- Detectar duplicados rápidamente.

### Los tres algoritmos del curso

---

### 🫧 Burbuja (Bubble Sort)

**Idea:** Compara pares adyacentes. Si están desordenados, los intercambia. El mayor "burbujea" al final en cada pasada.

**Visualización:**
```
Pasada 1: [5, 3, 8, 1] → [3, 5, 8, 1] → [3, 5, 8, 1] → [3, 5, 1, 8]  ← 8 ya está
Pasada 2: [3, 5, 1, 8] → [3, 5, 1, 8] → [3, 1, 5, 8]                   ← 5 ya está
Pasada 3: [3, 1, 5, 8] → [1, 3, 5, 8]                                    ← 3 ya está
Resultado: [1, 3, 5, 8] ✓
```

```cpp
void burbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {           // n-1 pasadas
        for (int j = 0; j < n - 1 - i; j++) {   // cada pasada es más corta
            if (arr[j] > arr[j + 1]) {
                // intercambiar
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

**¿Por qué `n-1-i`?** Después de la pasada `i`, los últimos `i` elementos ya están ordenados.

---

### 🎯 Selección (Selection Sort)

**Idea:** Busca el MÍNIMO del subarreglo no ordenado y lo coloca en la posición correcta.

**Visualización:**
```
[5, 3, 8, 1] → min=1(pos3) → swap(pos0,pos3) → [1, 3, 8, 5]
[1, |3, 8, 5] → min=3(pos1) → ya está        → [1, 3, 8, 5]
[1, 3, |8, 5] → min=5(pos3) → swap(pos2,pos3) → [1, 3, 5, 8]
Resultado: [1, 3, 5, 8] ✓
```

```cpp
void seleccion(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;                       // asumir que i es el mínimo
        for (int j = i + 1; j < n; j++) {     // buscar en el resto
            if (arr[j] < arr[minIdx]) {
                minIdx = j;                   // actualizar posición del mínimo
            }
        }
        // intercambiar arr[i] con arr[minIdx]
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}
```

**Clave:** Siempre hace exactamente `n-1` intercambios (uno por pasada). Burbuja puede hacer muchos más.

---

### 🃏 Inserción (Insertion Sort)

**Idea:** Como ordenar cartas en la mano. Tomas una carta (elemento) y la insertas en su posición correcta dentro de la parte ya ordenada.

**Visualización:**
```
[5, |3, 8, 1]  clave=3 → 3<5, desplazar 5 → [3, 5, |8, 1]
[3, 5, |8, 1]  clave=8 → 8>5, queda ahí   → [3, 5, 8, |1]
[3, 5, 8, |1]  clave=1 → 1<8<5<3, desplazar todos → [1, 3, 5, 8]
Resultado: [1, 3, 5, 8] ✓
```

```cpp
void insercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {       // empezar desde el segundo
        int clave = arr[i];              // guardar el elemento a insertar
        int j = i - 1;
        // desplazar hacia la derecha los mayores que clave
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = clave;             // insertar en su posición
    }
}
```

**¿Por qué es el mejor de los tres?** Si el arreglo ya está casi ordenado, el `while` interno casi no ejecuta → O(n) en el mejor caso.

---

### Tabla comparativa

| Algoritmo | Mejor | Promedio | Peor | Estable | Intercambios |
|-----------|-------|----------|------|---------|-------------|
| Burbuja | O(n)* | O(n²) | O(n²) | ✅ Sí | Muchos |
| Selección | O(n²) | O(n²) | O(n²) | ❌ No | Exactamente n-1 |
| Inserción | **O(n)** | O(n²) | O(n²) | ✅ Sí | Variable |

*Burbuja O(n) solo con optimización de bandera (si no hubo intercambios, parar).

### ¿Qué significa "estable"?
Si hay dos elementos con el mismo valor, un algoritmo **estable** mantiene su orden original. Selección NO es estable porque al hacer `swap` puede alterar el orden relativo.

---

## 2. EJEMPLOS RESUELTOS

### Ejemplo 1: Ordenar un arreglo de structs por nota (Burbuja)

**Enunciado:** Dado un arreglo de alumnos, ordénelos de mayor a menor nota usando Burbuja.

```cpp
#include <iostream>
using namespace std;

struct Alumno {
    int codigo;
    char nombre[30];
    float nota;
};

void ordenarPorNota(Alumno arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            // DESCENDENTE: cambiar > por <
            if (arr[j].nota < arr[j + 1].nota) {
                Alumno temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    Alumno alumnos[4] = {
        {101, "Pedro", 15.5},
        {102, "Maria", 18.0},
        {103, "Juan",  12.3},
        {104, "Ana",   16.7}
    };
    
    ordenarPorNota(alumnos, 4);
    
    for (int i = 0; i < 4; i++) {
        cout << alumnos[i].nombre << ": " << alumnos[i].nota << endl;
    }
    // Maria: 18.0, Ana: 16.7, Pedro: 15.5, Juan: 12.3
    return 0;
}
```

**Clave:** Para ordenar structs, comparas UN CAMPO (`arr[j].nota`) pero intercambias EL STRUCT COMPLETO (`Alumno temp = arr[j]`).

### Ejemplo 2: Contar comparaciones e intercambios (Selección)

**Enunciado:** Ordene `{8, 4, 2, 6}` con Selección y cuente las operaciones.

```
Pasada 0: buscar min en {8,4,2,6} → min=2(pos2)
  Comparaciones: 8>4? sí(minIdx=1), 4>2? sí(minIdx=2), 2>6? no
  = 3 comparaciones, 1 intercambio: swap(pos0,pos2) → [2, 4, 8, 6]

Pasada 1: buscar min en {4,8,6} → min=4(pos1)
  Comparaciones: 4>8? no, 4>6? no
  = 2 comparaciones, 0 intercambios (ya está): [2, 4, 8, 6]

Pasada 2: buscar min en {8,6} → min=6(pos3)
  = 1 comparación, 1 intercambio: swap(pos2,pos3) → [2, 4, 6, 8]

TOTAL: 6 comparaciones, 2 intercambios
Fórmula comparaciones: n(n-1)/2 = 4(3)/2 = 6 ✓
```

---

## 3. EJERCICIOS PARA PRACTICAR

**Ejercicio 5.1 (Fácil):** Trace paso a paso Burbuja con el arreglo `{7, 2, 5, 1, 3}`. Muestre el estado del arreglo después de CADA pasada.

**Ejercicio 5.2 (Fácil):** Trace paso a paso Inserción con `{6, 3, 8, 1}`. Para cada iteración, indique la `clave` y qué elementos se desplazan.

**Ejercicio 5.3 (Medio):** Dado un arreglo de structs `Empleado` (nombre, salario), ordénelo alfabéticamente por nombre usando Selección. Use `strcmp` para comparar strings.

**Ejercicio 5.4 (Medio):** Implemente Burbuja con optimización: si en una pasada no hubo ningún intercambio, el arreglo ya está ordenado y se puede parar. Use una bandera `bool intercambio`.

**Ejercicio 5.5 (Tipo examen):** ¿Cuántas comparaciones e intercambios realiza Burbuja para ordenar `{1, 2, 3, 4, 5}` (ya ordenado)? ¿Y Selección? ¿Cuál es más eficiente en este caso?

---

## 4. PATRONES DE EXAMEN

- **Trazar el algoritmo:** Te dan un arreglo y piden el estado después de cada pasada de un algoritmo específico. → Practica trazas a mano, son puntos fáciles.
- **Ordenar structs por un campo:** → Comparas el CAMPO pero intercambias el STRUCT completo.
- **Elegir algoritmo:** "¿Cuál usaría si los datos están casi ordenados?" → Inserción (O(n) mejor caso).
- **Contar operaciones:** → Burbuja y Selección: n(n-1)/2 comparaciones en peor caso. Selección: siempre n-1 intercambios.
- **Ascendente vs Descendente:** Solo cambia el `>` por `<` en la condición.

### Chuleta de repaso rápido
```
BURBUJA:   compara adyacentes, swap si desordenados. O(n²). Estable.
SELECCIÓN: busca mínimo, lo pone en su lugar. O(n²) siempre. NO estable.
INSERCIÓN: inserta en posición correcta. O(n) mejor, O(n²) peor. Estable.

Para structs: comparar UN campo, intercambiar TODO el struct.
Descendente: invertir la comparación (< en vez de >).
Fórmula comparaciones: n(n-1)/2
```
