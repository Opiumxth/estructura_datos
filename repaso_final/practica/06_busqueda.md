# PRÁCTICA 06: BÚSQUEDA

---

## Ejercicio 6.1 (Fácil) - Búsqueda lineal

**Enunciado:**
Implemente la búsqueda lineal para encontrar un valor en un arreglo. Retorne el índice si lo encuentra, -1 si no.

**Solución en C/C++:**
```cpp
int busquedaLineal(int arr[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == valor) {
            return i;
        }
    }
    return -1;
}
```

**Pseudocódigo:**
```
ACCION busquedaLineal(ENTERO arr[], ENTERO n, ENTERO valor) RETORNA ENTERO
   ENTERO i
   
   PARA i ← 0 HASTA n - 1
      SI(arr[i] = valor)
         RETORNAR(i)
      FIN_SI
   FIN_PARA
   
   RETORNAR(-1)
FIN_ACCION
```

---

## Ejercicio 6.2 (Medio) - Búsqueda binaria

**Enunciado:**
Implemente la búsqueda binaria para un arreglo ordenado. Retorne el índice si lo encuentra, -1 si no.

**Solución en C/C++:**
```cpp
int busquedaBinaria(int arr[], int n, int valor) {
    int izquierda = 0;
    int derecha = n - 1;
    
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        
        if (arr[medio] == valor) {
            return medio;
        }
        
        if (arr[medio] < valor) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    
    return -1;
}
```

**Pseudocódigo:**
```
ACCION busquedaBinaria(ENTERO arr[], ENTERO n, ENTERO valor) RETORNA ENTERO
   ENTERO izquierda, derecha, medio
   
   izquierda ← 0
   derecha ← n - 1
   
   MIENTRAS(izquierda ≤ derecha)
      medio ← izquierda + (derecha - izquierda) / 2
      
      SI(arr[medio] = valor)
         RETORNAR(medio)
      FIN_SI
      
      SI(arr[medio] < valor)
         izquierda ← medio + 1
      SINO
         derecha ← medio - 1
      FIN_SI
   FIN_MIENTRAS
   
   RETORNAR(-1)
FIN_ACCION
```

---

## Ejercicio 6.3 (Medio) - Búsqueda binaria recursiva

**Enunciado:**
Implemente la búsqueda binaria de forma recursiva.

**Solución en C/C++:**
```cpp
int busquedaBinariaRecursiva(int arr[], int izquierda, int derecha, int valor) {
    if (izquierda > derecha) {
        return -1;
    }
    
    int medio = izquierda + (derecha - izquierda) / 2;
    
    if (arr[medio] == valor) {
        return medio;
    }
    
    if (arr[medio] < valor) {
        return busquedaBinariaRecursiva(arr, medio + 1, derecha, valor);
    } else {
        return busquedaBinariaRecursiva(arr, izquierda, medio - 1, valor);
    }
}
```

---

## Ejercicio 6.4 (Difícil) - Contar ocurrencias

**Enunciado:**
Usando búsqueda binaria, cuente cuántas veces aparece un valor en un arreglo ordenado que puede tener duplicados.

**Solución en C/C++:**
```cpp
int contarOcurrencias(int arr[], int n, int valor) {
    int primera = -1, ultima = -1;
    
    // Buscar primera ocurrencia
    int izq = 0, der = n - 1;
    while (izq <= der) {
        int mid = izq + (der - izq) / 2;
        if (arr[mid] == valor) {
            primera = mid;
            der = mid - 1;
        } else if (arr[mid] < valor) {
            izq = mid + 1;
        } else {
            der = mid - 1;
        }
    }
    
    // Buscar última ocurrencia
    izq = 0, der = n - 1;
    while (izq <= der) {
        int mid = izq + (der - izq) / 2;
        if (arr[mid] == valor) {
            ultima = mid;
            izq = mid + 1;
        } else if (arr[mid] < valor) {
            izq = mid + 1;
        } else {
            der = mid - 1;
        }
    }
    
    if (primera == -1) return 0;
    return ultima - primera + 1;
}
```

---

## Ejercicio 6.5 (Tipo examen) - Comparar complejidad

**Enunciado:**
Para un arreglo de 1000 elementos, ¿cuántas comparaciones hace en el peor caso la búsqueda lineal vs la búsqueda binaria?

**Solución:**
- Búsqueda lineal: 1000 comparaciones (O(n))
- Búsqueda binaria: ⌊log₂(1000)⌋ + 1 = 10 comparaciones (O(log n))

La búsqueda binaria es aproximadamente 100 veces más eficiente en este caso.
