# TEMA 6: MÉTODOS DE BÚSQUEDA

---

## 1. TEORÍA CLARA

### ¿Qué es buscar?
Encontrar la posición de un elemento dentro de una colección, o determinar que no existe.

### Búsqueda Lineal (Secuencial)

**Idea:** Recorre uno a uno desde el inicio hasta encontrar el objetivo o llegar al final.

```
Buscar 8 en [3, 7, 8, 1, 5]:
  pos 0: 3≠8  →  siguiente
  pos 1: 7≠8  →  siguiente
  pos 2: 8=8  →  ¡ENCONTRADO en posición 2!
```

```cpp
int busquedaLineal(int arr[], int n, int objetivo) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == objetivo)
            return i;       // encontrado: devuelve la posición
    }
    return -1;              // no encontrado
}
```

| Aspecto | Valor |
|---------|-------|
| Complejidad | **O(n)** |
| Requisito | Ninguno |
| Mejor caso | O(1) — está en la primera posición |
| Peor caso | O(n) — está al final o no existe |

---

### Búsqueda Binaria

**Idea:** Divide el espacio de búsqueda a la mitad en cada paso. **SOLO funciona con datos ORDENADOS.**

```
Buscar 7 en [1, 3, 5, 7, 9, 11, 13]:
  inicio=0, fin=6, medio=3 → arr[3]=7 → ¡ENCONTRADO!

Buscar 9 en [1, 3, 5, 7, 9, 11, 13]:
  inicio=0, fin=6, medio=3 → arr[3]=7 < 9 → buscar derecha: inicio=4
  inicio=4, fin=6, medio=5 → arr[5]=11 > 9 → buscar izquierda: fin=4
  inicio=4, fin=4, medio=4 → arr[4]=9 → ¡ENCONTRADO!

Buscar 6 en [1, 3, 5, 7, 9, 11, 13]:
  inicio=0, fin=6, medio=3 → arr[3]=7 > 6 → fin=2
  inicio=0, fin=2, medio=1 → arr[1]=3 < 6 → inicio=2
  inicio=2, fin=2, medio=2 → arr[2]=5 < 6 → inicio=3
  inicio=3 > fin=2 → NO ENCONTRADO (-1)
```

```cpp
int busquedaBinaria(int arr[], int n, int objetivo) {
    int inicio = 0, fin = n - 1;
    
    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;
        
        if (arr[medio] == objetivo)
            return medio;                 // encontrado
        else if (arr[medio] < objetivo)
            inicio = medio + 1;           // buscar en la mitad derecha
        else
            fin = medio - 1;              // buscar en la mitad izquierda
    }
    return -1;                            // no encontrado
}
```

| Aspecto | Valor |
|---------|-------|
| Complejidad | **O(log n)** |
| Requisito | **Datos ORDENADOS** |
| n = 1,000 | máx. 10 pasos |
| n = 1,000,000 | máx. 20 pasos |
| n = 1,000,000,000 | máx. 30 pasos |

### ¿Por qué requiere orden?
La binaria ASUME: "si el medio es menor que el buscado, todos los de la izquierda también lo son". Esto SOLO es verdad si el arreglo está ordenado. Si no está ordenado, la búsqueda puede descartar la mitad donde SÍ está el elemento.

### Error fatal
Aplicar Búsqueda Binaria a datos NO ordenados → **no da error de compilación ni CRASH**, simplemente devuelve resultados INCORRECTOS. Es el error más traicionero.

---

## 2. EJEMPLOS RESUELTOS

### Ejemplo 1: Buscar un alumno por código

**Enunciado:** Dado un arreglo de alumnos NO ordenado, buscar por código usando búsqueda lineal.

```cpp
#include <iostream>
using namespace std;

struct Alumno {
    int codigo;
    char nombre[30];
    float nota;
};

int buscarAlumno(Alumno arr[], int n, int codBuscado) {
    for (int i = 0; i < n; i++) {
        if (arr[i].codigo == codBuscado)
            return i;
    }
    return -1;
}

int main() {
    Alumno alumnos[4] = {
        {105, "Pedro", 15.5},
        {102, "Maria", 18.0},
        {108, "Juan",  12.3},
        {101, "Ana",   16.7}
    };
    
    int pos = buscarAlumno(alumnos, 4, 108);
    
    if (pos != -1)
        cout << "Encontrado: " << alumnos[pos].nombre 
             << " en posición " << pos << endl;
    else
        cout << "No encontrado" << endl;
    // Salida: Encontrado: Juan en posición 2
    
    return 0;
}
```

### Ejemplo 2: Búsqueda binaria con traza detallada

**Enunciado:** Buscar el valor 42 en el arreglo ordenado `{5, 12, 18, 25, 33, 42, 56, 70}`.

```
Arreglo: [5, 12, 18, 25, 33, 42, 56, 70]
Índices:  0   1   2   3   4   5   6   7

Iteración 1: inicio=0, fin=7, medio=(0+7)/2=3
  arr[3]=25, 25 < 42 → buscar derecha → inicio = 4

Iteración 2: inicio=4, fin=7, medio=(4+7)/2=5
  arr[5]=42, 42 == 42 → ¡ENCONTRADO en posición 5!

Total: 2 comparaciones (vs 6 con búsqueda lineal)
```

```cpp
// Versión con traza para estudiar:
int busqBinariaTraza(int arr[], int n, int obj) {
    int ini = 0, fin = n - 1, iter = 0;
    while (ini <= fin) {
        iter++;
        int med = (ini + fin) / 2;
        printf("Iter %d: ini=%d fin=%d med=%d arr[med]=%d\n",
               iter, ini, fin, med, arr[med]);
        if (arr[med] == obj) return med;
        else if (arr[med] < obj) ini = med + 1;
        else fin = med - 1;
    }
    return -1;
}
```

---


## Preguntas de recuperación

1. ¿Por qué la búsqueda eficiente es fundamental en estructuras de datos grandes?
2. ¿Cuál es la diferencia entre búsqueda lineal y búsqueda binaria y cuándo se usa cada una?
3. ¿Qué problema resuelve la búsqueda binaria respecto a la búsqueda lineal?
4. ¿Cómo se relaciona el requisito de datos ordenados con la búsqueda binaria?
5. ¿Qué ocurriría si aplicas búsqueda binaria a datos no ordenados?
6. ¿Cuándo conviene usar búsqueda lineal en lugar de binaria?
7. ¿Cómo se relaciona la complejidad de búsqueda con la estructura de datos utilizada?
8. ¿Qué ventajas y desventajas tiene cada algoritmo de búsqueda en diferentes escenarios?

## 3. EJERCICIOS PARA PRACTICAR

**Ejercicio 6.1 (Fácil):** Trace la búsqueda binaria de 18 en `{2, 5, 8, 12, 18, 23, 31, 40}`. Muestre inicio, fin, medio en cada paso.

**Ejercicio 6.2 (Fácil):** Trace la búsqueda binaria de 15 en `{2, 5, 8, 12, 18, 23, 31, 40}` (no existe). ¿Cuántas iteraciones?

**Ejercicio 6.3 (Medio):** Modifique la búsqueda lineal para que busque en un arreglo de structs `Producto` por nombre (usando `strcmp`). Devuelva el puntero al producto encontrado o `NULL`.

**Ejercicio 6.4 (Medio):** Escriba un programa que: (1) pida N números al usuario, (2) los ordene con Inserción, (3) busque un valor con Búsqueda Binaria. Combine los temas 5 y 6.

**Ejercicio 6.5 (Tipo examen):** ¿Cuántas comparaciones máximas necesita la búsqueda binaria para un arreglo de 1024 elementos? ¿Y para 500? Justifique con la fórmula.

---

## 4. PATRONES DE EXAMEN

- **Trazar búsqueda binaria:** Pregunta estrella. Te dan un arreglo y un valor. → Haz la tabla: `| iter | inicio | fin | medio | arr[medio] | acción |`
- **¿Cuál usar?** → Si datos desordenados: lineal. Si datos ordenados: binaria. Si no dicen nada: lineal (es seguro).
- **Calcular máx comparaciones:** `⌊log₂(n)⌋ + 1`. Para n=1024: log₂(1024)=10, máx=11 comparaciones.
- **Buscar en structs:** Es lo mismo pero la comparación es sobre un campo: `arr[i].codigo == buscado`.
- **Truco:** Si en el examen dicen "método eficiente de búsqueda", están pidiendo binaria. Si dicen "búsqueda sobre datos no ordenados", están pidiendo lineal.

### Chuleta de repaso rápido
```
LINEAL:  for i=0..n-1: if arr[i]==obj return i. O(n). Sin requisitos.
BINARIA: while ini<=fin: med=(ini+fin)/2. O(log n). REQUIERE ORDEN.

Si arr[med]==obj → encontrado
Si arr[med]<obj  → ini = med+1 (buscar derecha)
Si arr[med]>obj  → fin = med-1 (buscar izquierda)

Máx comparaciones binaria: ⌊log₂(n)⌋ + 1
n=1000 → ~10 pasos    n=1M → ~20 pasos

ERROR FATAL: usar binaria en datos desordenados → resultado incorrecto SIN crash
```
