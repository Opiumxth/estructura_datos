# TEMA 15: ÁRBOLES DE HUFFMAN

---

## Objetivos

- Comprender el principio de compresión de Huffman
- Dominar el algoritmo de construcción del árbol de Huffman
- Entender la relación entre frecuencia y longitud del código
- Implementar codificación y decodificación Huffman
- Analizar la eficiencia de compresión

---

## Conceptos clave

- **Árbol de Huffman:** Árbol binario óptimo para compresión sin pérdida
- **Frecuencia:** Número de veces que aparece un símbolo
- **Código de longitud variable:** Símbolos más frecuentes tienen códigos más cortos
- **Prefijo libre:** Ningún código es prefijo de otro (propiedad del árbol)
- **Compresión sin pérdida:** Datos originales pueden recuperarse exactamente
- **Hoja:** Cada símbolo es una hoja en el árbol

---

## Explicación detallada

### ¿Qué es un árbol de Huffman?

El árbol de Huffman es un árbol binario utilizado para compresión de datos. La idea principal es asignar códigos binarios más cortos a los símbolos más frecuentes y códigos más largos a los símbolos menos frecuentes.

**Principio clave:** Inversamente proporcional - mayor frecuencia → código más corto.

### Propiedades

1. **Prefijo libre:** Ningún código es prefijo de otro
2. **Óptimo:** Para un conjunto de frecuencias dado, Huffman produce la compresión óptima
3. **Sin pérdida:** Los datos originales pueden recuperarse exactamente
4. **Codificación:** 0 para ir a la izquierda, 1 para ir a la derecha

### Estructura del nodo Huffman

```
REGISTRO NODO
   CARACTER simbolo
   ENTERO frecuencia
   NODO *izq
   NODO *der
FIN_REGISTRO
```

En C/C++:
```cpp
struct NODO {
    char simbolo;
    int frecuencia;
    NODO *izq;
    NODO *der;
};
```

---

## Algoritmo de construcción

### Paso a paso

1. **Calcular frecuencias:** Contar cuántas veces aparece cada símbolo
2. **Crear hojas:** Crear un nodo por cada símbolo con su frecuencia
3. **Construir cola de prioridad:** Ordenar nodos por frecuencia (menor primero)
4. **Combinar nodos:**
   - Extraer los 2 nodos con menor frecuencia
   - Crear un nodo padre con frecuencia = suma de ambos
   - El nodo padre se convierte en padre de los 2 extraídos
   - Insertar el nodo padre en la cola
5. **Repetir:** Hasta que quede un solo nodo (la raíz)

### Pseudocódigo

```
ACCION construirHuffman(CARACTER simbolos[], ENTERO frecuencias[], ENTERO n) RETORNA NODO
   COLA_PRIORIDAD cola
   
   // Paso 1: Crear nodo por cada símbolo
   PARA i ← 0 HASTA n - 1
      NODO nuevo ← nuevoNodo(simbolos[i], frecuencias[i])
      cola.insertar(nuevo)
   FIN_PARA
   
   // Paso 2: Combinar hasta quedar uno
   MIENTRAS(cola.tamaño() > 1)
      NODO izq ← cola.extraerMinimo()
      NODO der ← cola.extraerMinimo()
      
      NODO padre ← nuevoNodo('', izq.frecuencia + der.frecuencia)
      padre.izq ← izq
      padre.der ← der
      
      cola.insertar(padre)
   FIN_MIENTRAS
   
   RETORNAR(cola.extraerMinimo())  // raíz
FIN_ACCION
```

**C/C++:**
```cpp
struct NODO {
    char simbolo;
    int frecuencia;
    NODO *izq;
    NODO *der;
    
    NODO(char s, int f) {
        simbolo = s;
        frecuencia = f;
        izq = der = NULL;
    }
};

// Comparador para cola de prioridad
struct Comparador {
    bool operator()(NODO* a, NODO* b) {
        return a->frecuencia > b->frecuencia;
    }
};

NODO* construirHuffman(map<char, int> frecuencias) {
    priority_queue<NODO*, vector<NODO*>, Comparador> cola;
    
    // Crear nodo por cada símbolo
    for (auto par : frecuencias) {
        cola.push(new NODO(par.first, par.second));
    }
    
    // Combinar hasta quedar uno
    while (cola.size() > 1) {
        NODO* izq = cola.top(); cola.pop();
        NODO* der = cola.top(); cola.pop();
        
        NODO* padre = new NODO('\0', izq->frecuencia + der->frecuencia);
        padre->izq = izq;
        padre->der = der;
        
        cola.push(padre);
    }
    
    return cola.top();
}
```

---

## Generación de códigos

### Algoritmo

1. Comenzar en la raíz
2. Ir a la izquierda: agregar '0' al código
3. Ir a la derecha: agregar '1' al código
4. Al llegar a una hoja: guardar el código para ese símbolo

### Pseudocódigo

```
ACCION generarCodigos(NODO raiz, CADENA codigo, MAPA codigos)
   SI(raiz = NULL)
      RETORNAR
   FIN_SI
   
   SI(raiz.izq = NULL Y raiz.der = NULL)
      // Es hoja
      codigos[raiz.simbolo] ← codigo
   SINO
      generarCodigos(raiz.izq, codigo + '0', codigos)
      generarCodigos(raiz.der, codigo + '1', codigos)
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
void generarCodigos(NODO* raiz, string codigo, map<char, string>& codigos) {
    if (raiz == NULL) return;
    
    if (raiz->izq == NULL && raiz->der == NULL) {
        codigos[raiz->simbolo] = codigo;
    } else {
        generarCodigos(raiz->izq, codigo + '0', codigos);
        generarCodigos(raiz->der, codigo + '1', codigos);
    }
}
```

---

## Ejemplos

### Ejemplo 1: Construcción básica

**Símbolos y frecuencias:**
| Símbolo | A | B | C | D | E | F |
|---------|---|---|---|---|---|---|
| Frecuencia | 0.22 | 0.18 | 0.05 | 0.15 | 0.30 | 0.10 |

**Paso 1: Crear hojas**
```
C(0.05), F(0.10), D(0.15), B(0.18), A(0.22), E(0.30)
```

**Paso 2: Combinar C y F**
```
Nodo1(0.15) [C(0.05), F(0.10)]
D(0.15), B(0.18), A(0.22), E(0.30)
```

**Paso 3: Combinar Nodo1 y D**
```
Nodo2(0.30) [Nodo1(0.15), D(0.15)]
B(0.18), A(0.22), E(0.30)
```

**Paso 4: Combinar B y A**
```
Nodo3(0.40) [B(0.18), A(0.22)]
Nodo2(0.30), E(0.30)
```

**Paso 5: Combinar Nodo2 y E**
```
Nodo4(0.60) [Nodo2(0.30), E(0.30)]
Nodo3(0.40)
```

**Paso 6: Combinar Nodo3 y Nodo4**
```
Raiz(1.00) [Nodo3(0.40), Nodo4(0.60)]
```

**Árbol final:**
```
              (1.00)
             /      \
        (0.40)      (0.60)
        /    \      /    \
      B(0.18) A(0.22) (0.30)  E(0.30)
                      /    \
                  (0.15)   D(0.15)
                  /    \
               C(0.05) F(0.10)
```

**Códigos resultantes:**
- A: 01
- B: 00
- C: 1000
- D: 101
- E: 11
- F: 1001

**Observación:** Símbolos más frecuentes (E, A, B) tienen códigos más cortos.

### Ejemplo 2: Codificación

**Mensaje:** "ABEAF"

**Codificación:**
- A → 01
- B → 00
- E → 11
- A → 01
- F → 1001

**Resultado:** 01 00 11 01 1001 = "001111011001"

**Longitud original:** 5 caracteres × 8 bits = 40 bits
**Longitud comprimida:** 13 bits
**Tasa de compresión:** 67.5%

### Ejemplo 3: Decodificación

**Código:** "001111011001"

**Decodificación:**
```
0 → ir izquierda
0 → ir izquierda → B (hoja) ✓

1 → ir derecha
1 → ir derecha → E (hoja) ✓

0 → ir izquierda
1 → ir derecha → A (hoja) ✓

1 → ir derecha
0 → ir izquierda
0 → ir izquierda
1 → ir derecha → F (hoja) ✓

Resultado: "BEAF"
```

---

## Casos típicos de examen

### Caso 1: Construir árbol de Huffman

**Pregunta:** Construya el árbol de Huffman para los símbolos con frecuencias: A=5, B=9, C=12, D=13, E=16, F=45.

**Solución:**
```
Paso 1: A(5), B(9), C(12), D(13), E(16), F(45)

Paso 2: Combinar A y B → AB(14)
C(12), D(13), E(16), AB(14), F(45)

Paso 3: Combinar C y D → CD(25)
E(16), AB(14), CD(25), F(45)

Paso 4: Combinar E y AB → EAB(30)
CD(25), EAB(30), F(45)

Paso 5: Combinar CD y EAB → CDEAB(55)
F(45), CDEAB(55)

Paso 6: Combinar F y CDEAB → Raiz(100)

Árbol final:
        (100)
       /     \
    F(45)   (55)
           /    \
        (25)   (30)
        /  \   /  \
      C(12) D(13) E(16) (14)
                       /  \
                     A(5) B(9)
```

### Caso 2: Calcular longitud promedio

**Pregunta:** Para el árbol anterior, calcule la longitud promedio del código.

**Solución:**
- F: 0 bits (código: 0)
- C: 2 bits (código: 10)
- D: 2 bits (código: 11)
- E: 2 bits (código: 10)
- A: 3 bits (código: 110)
- B: 3 bits (código: 111)

**Longitud promedio:**
= (45×0 + 12×2 + 13×2 + 16×2 + 5×3 + 9×3) / 100
= (0 + 24 + 26 + 32 + 15 + 27) / 100
= 124 / 100
= 1.24 bits por símbolo

### Caso 3: Verificar prefijo libre

**Pregunta:** ¿Los códigos A=0, B=10, C=11 son válidos para Huffman?

**Solución:** SÍ, son válidos. Ningún código es prefijo de otro:
- 0 no es prefijo de 10 ni 11
- 10 no es prefijo de 11
- 11 no es prefijo de 10

---

## Errores frecuentes

| Error | Qué pasa | Cómo evitarlo |
|-------|----------|---------------|
| No ordenar por frecuencia | Árbol no óptimo | Siempre extraer los 2 nodos con MENOR frecuencia |
- Olvidar sumar frecuencias del padre | Árbol incorrecto | La frecuencia del padre = suma de frecuencias de hijos |
- Confundir dirección de códigos | Decodificación incorrecta | Memorizar: izquierda = 0, derecha = 1 |
- No verificar que sea hoja | Asignar código a nodo interno | Solo asignar código cuando izq=NULL y der=NULL |
- Usar códigos de longitud fija | No hay compresión | Huffman usa códigos de longitud variable |

---

## Preguntas de recuperación activa

1. ¿Por qué los símbolos más frecuentes tienen códigos más cortos en Huffman?
2. ¿Qué significa que un código sea "prefijo libre"?
3. ¿Por qué Huffman garantiza compresión óptima?
4. ¿Cuál es la complejidad del algoritmo de construcción de Huffman?
5. ¿En qué situaciones NO conviene usar Huffman?
6. ¿Por qué Huffman es una compresión sin pérdida?
7. ¿Qué pasa si todos los símbolos tienen la misma frecuencia?
8. ¿Cómo se decodifica un mensaje comprimido con Huffman?

---

## Autoevaluación

### Nivel 1 (Básico)
1. Defina qué es un árbol de Huffman.
2. Escriba el pseudocódigo de construcción del árbol.
3. ¿Qué representa la frecuencia en Huffman?

### Nivel 2 (Intermedio)
1. Construya el árbol de Huffman para: A=3, B=4, C=5, D=6.
2. Implemente la función para generar códigos en C/C++.
3. Calcule la longitud promedio del código para el ejemplo anterior.

### Nivel 3 (Avanzado)
1. Demuestre que Huffman produce compresión óptima.
2. Implemente la decodificación de un mensaje comprimido.
3. Compare Huffman con otros métodos de compresión (LZW, RLE).

---

## Resumen de una página

**Huffman:** Árbol binario para compresión sin pérdida.

**Principio:** Símbolos más frecuentes → códigos más cortos.

**Algoritmo de construcción:**
1. Calcular frecuencias de cada símbolo
2. Crear nodo por cada símbolo
3. Extraer 2 nodos con menor frecuencia
4. Crear nodo padre (frecuencia = suma)
5. Repetir hasta quedar 1 nodo

**Estructura del nodo:**
```cpp
struct NODO {
    char simbolo;
    int frecuencia;
    NODO *izq;
    NODO *der;
};
```

**Generación de códigos:**
- Izquierda: agregar '0'
- Derecha: agregar '1'
- Hoja: guardar código

**Propiedades:**
- Prefijo libre (ningún código es prefijo de otro)
- Óptimo para frecuencias dadas
- Sin pérdida

**Complejidad:**
- Construcción: O(n log n) usando cola de prioridad
- Codificación: O(n)
- Decodificación: O(m) donde m = longitud del mensaje

**Aplicaciones:**
- Compresión de archivos (ZIP, GZIP)
- Compresión de imágenes (JPEG)
- Transmisión de datos

**Errores comunes:**
- No ordenar por frecuencia
- Olvidar sumar frecuencias del padre
- Confundir dirección de códigos
- No verificar que sea hoja
