# TEMA 13: ÁRBOLES B

---

## Objetivos

- Comprender la necesidad de árboles B para almacenamiento en disco
- Dominar la estructura de nodos en árboles B
- Implementar operaciones de inserción, búsqueda y eliminación
- Entender el proceso de división (split) de nodos
- Analizar las ventajas de árboles B sobre ABB para grandes volúmenes de datos

---

## Conceptos clave

- **Árbol B:** Árbol balanceado de búsqueda multi-vía (m-ario)
- **Orden m:** Máximo número de hijos que puede tener un nodo
- **Clave:** Valor almacenado en el nodo para búsqueda
- **Página/Nodo:** Unidad de almacenamiento en disco (tamaño fijo)
- **División (split):** Proceso de dividir un nodo sobrepoblado en dos
- **Promoción:** Subir una clave al nodo padre durante división
- **Factor de mínimo:** Cada nodo (excepto raíz) debe tener al menos ⌈m/2⌉ - 1 claves

---

## Explicación detallada

### ¿Qué es un árbol B?

Un árbol B es un árbol balanceado de búsqueda generalizado donde cada nodo puede tener múltiples hijos. Fue diseñado específicamente para **sistemas de almacenamiento en disco** donde el acceso a disco es costoso.

**Motivación:** En disco, leer un bloque de datos es costoso. Los árboles B minimizan el número de accesos a disco almacenando múltiples claves en cada nodo.

### Propiedades de un árbol B de orden m

1. **Raíz:** Tiene al menos 2 hijos (a menos que sea hoja)
2. **Nodos internos:** Cada nodo tiene entre ⌈m/2⌉ y m hijos
3. **Hojas:** Todas las hojas están al mismo nivel
4. **Claves por nodo:** Entre ⌈m/2⌉ - 1 y m - 1 claves
5. **Ordenamiento:** Las claves en cada nodo están ordenadas
6. **Balanceado:** El árbol siempre está balanceado por construcción

### Estructura del nodo B

```
REGISTRO Pagina
   ENTERO cuenta        // número de claves en el nodo
   tipoClave claves[m]  // arreglo de claves (índices 1 a m-1)
   Pagina* ramas[m]     // punteros a hijos (índices 0 a m-1)
FIN_REGISTRO
```

En C/C++:
```cpp
#define m 5  // orden del árbol B

typedef int tipoClave;

struct Pagina {
    int cuenta;              // número de claves
    tipoClave claves[m];    // claves [1..m-1]
    Pagina* ramas[m];       // punteros a hijos [0..m-1]
};
```

### Representación visual de un nodo B

```
Nodo B de orden 5 (máximo 4 claves, 5 hijos):

[ |k1|k2|k3|k4| ]
 ↓ ↓ ↓ ↓ ↓
r0 r1 r2 r3 r4

Donde:
- k1 < k2 < k3 < k4 (claves ordenadas)
- r0: puntero a subárbol con claves < k1
- r1: puntero a subárbol con k1 < claves < k2
- r2: puntero a subárbol con k2 < claves < k3
- r3: puntero a subárbol con k3 < claves < k4
- r4: puntero a subárbol con claves > k4
```

---

## Operaciones en Árboles B

### Búsqueda

**Algoritmo:**
1. Comenzar en la raíz
2. Buscar la clave en el nodo actual
3. Si se encuentra, retornar
4. Si no, seguir por el puntero correspondiente
5. Repetir hasta encontrar o llegar a una hoja

**Pseudocódigo:**
```
ACCION buscar(Pagina actual, tipoClave cl, ENTERO pos) RETORNA Pagina
   SI(actual = NULL)
      RETORNAR(NULL)
   FIN_SI
   
   pos ← 1
   MIENTRAS(pos ≤ actual.cuenta Y cl > actual.claves[pos])
      pos ← pos + 1
   FIN_MIENTRAS
   
   SI(pos ≤ actual.cuenta Y cl = actual.claves[pos])
      RETORNAR(actual)  // encontrado
   SINO
      RETORNAR(buscar(actual.ramas[pos-1], cl, pos))
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
Pagina* buscar(Pagina* actual, tipoClave cl, int* posicion) {
    if (actual == NULL) {
        return NULL;
    }
    
    int k = 1;
    while (k <= actual->cuenta && cl > actual->claves[k]) {
        k++;
    }
    
    if (k <= actual->cuenta && cl == actual->claves[k]) {
        *posicion = k;
        return actual;  // encontrado
    } else {
        return buscar(actual->ramas[k-1], cl, posicion);
    }
}
```

### Inserción

**Algoritmo:**
1. Buscar el nodo hoja donde debe insertarse la clave
2. Insertar la clave en orden
3. Si el nodo se desborda (cuenta = m-1):
   - Dividir el nodo en dos
   - Promover la clave mediana al padre
   - Repetir si el padre también se desborda

**Pseudocódigo - Insertar en hoja:**
```
ACCION meterHoja(Pagina actual, tipoClave cl, Pagina rd, ENTERO k)
   // Desplazar claves para hacer espacio
   PARA j ← actual.cuenta HASTA k PASO -1
      actual.claves[j+1] ← actual.claves[j]
      actual.ramas[j+1] ← actual.ramas[j]
   FIN_PARA
   
   actual.claves[k] ← cl
   actual.ramas[k] ← rd
   actual.cuenta ← actual.cuenta + 1
FIN_ACCION
```

**Pseudocódigo - Dividir nodo:**
```
ACCION dividirNodo(Pagina actual, tipoClave cl, Pagina rd, ENTERO k, 
                   tipoClave mediana, Pagina nuevo)
   ENTERO posMdna
   posMdna ← (k ≤ m/2) ? m/2 : m/2 + 1
   
   nuevo ← reservar memoria para Pagina
   
   // Mover mitad derecha al nuevo nodo
   PARA i ← posMdna + 1 HASTA m - 1
      nuevo.claves[i - posMdna] ← actual.claves[i]
      nuevo.ramas[i - posMdna] ← actual.ramas[i]
   FIN_PARA
   
   nuevo.cuenta ← (m - 1) - posMdna
   actual.cuenta ← posMdna
   
   // Insertar en el nodo correspondiente
   SI(k ≤ m/2)
      meterHoja(actual, cl, rd, k)
   SINO
      meterHoja(nuevo, cl, rd, k - posMdna)
   FIN_SI
   
   // Extraer clave mediana
   mediana ← actual.claves[actual.cuenta]
   nuevo.ramas[0] ← actual.ramas[actual.cuenta]
   actual.cuenta ← actual.cuenta - 1
FIN_ACCION
```

**C/C++ - Dividir nodo:**
```cpp
void dividirNodo(Pagina* actual, tipoClave cl, Pagina* rd, int k, 
                  tipoClave* mediana, Pagina** nuevo) {
    int posMdna = (k <= m/2) ? m/2 : m/2 + 1;
    
    *nuevo = (Pagina*)malloc(sizeof(Pagina));
    
    // Mover mitad derecha al nuevo nodo
    for (int i = posMdna + 1; i < m; i++) {
        (*nuevo)->claves[i - posMdna] = actual->claves[i];
        (*nuevo)->ramas[i - posMdna] = actual->ramas[i];
    }
    
    (*nuevo)->cuenta = (m - 1) - posMdna;
    actual->cuenta = posMdna;
    
    // Insertar en el nodo correspondiente
    if (k <= m/2) {
        meterHoja(actual, cl, rd, k);
    } else {
        meterHoja(*nuevo, cl, rd, k - posMdna);
    }
    
    // Extraer clave mediana
    *mediana = actual->claves[actual->cuenta];
    (*nuevo)->ramas[0] = actual->ramas[actual->cuenta];
    actual->cuenta--;
}
```

### Eliminación

**Algoritmo:**
1. Buscar la clave a eliminar
2. Si está en una hoja: simplemente eliminar
3. Si está en un nodo interno:
   - Reemplazar con su sucesor (menor del subárbol derecho)
   - Eliminar el sucesor de su hoja
4. Si el nodo tiene menos claves del mínimo:
   - Tomar clave de hermano (si tiene suficiente)
   - O combinar con hermano
   - O combinar con padre

**Pseudocódigo:**
```
ACCION eliminarRegistro(Pagina actual, tipoClave cl, ENTERO encontrado)
   ENTERO k
   
   SI(actual ≠ NULL)
      encontrado ← buscarNodo(actual, cl, k)
      
      SI(encontrado)
         SI(actual.ramas[k-1] = NULL)
            // Es hoja
            quitar(actual, k)
         SINO
            // Es nodo interno
            sucesor(actual, k)
            eliminarRegistro(actual.ramas[k], actual.claves[k], encontrado)
         FIN_SI
      SINO
         eliminarRegistro(actual.ramas[k], cl, encontrado)
      FIN_SI
      
      // Verificar si el hijo tiene menos del mínimo
      SI(actual.ramas[k] ≠ NULL)
         SI(actual.ramas[k].cuenta < m/2)
            restablecer(actual, k)
         FIN_SI
      FIN_SI
   SINO
      encontrado ← 0
   FIN_SI
FIN_ACCION
```

---

## Ejemplos

### Ejemplo 1: Inserción sin división

**Árbol B de orden 5 (máximo 4 claves por nodo)**

Insertar: 10, 20, 30

```
Insertar 10:
[10]

Insertar 20:
[10|20]

Insertar 30:
[10|20|30]
```

### Ejemplo 2: Inserción con división

**Continuando, insertar: 40**

```
Antes de insertar 40:
[10|20|30]  (cuenta = 3, máximo = 4)

Insertar 40:
[10|20|30|40]  (cuenta = 4, máximo = 4)

Insertar 50 (causa división):
[10|20|30|40|50]  (cuenta = 5, desbordamiento)

División:
- Mediana: 30
- Nodo izquierdo: [10|20]
- Nodo derecho: [40|50]
- Promover 30 al padre

Resultado:
       [30]
      /    \
[10|20]  [40|50]
```

### Ejemplo 3: Inserción con división en cascada

**Continuando, insertar: 5, 15, 25, 35, 45, 55**

```
Estado actual:
       [30]
      /    \
[10|20]  [40|50]

Insertar 5:
       [30]
      /    \
[5|10|20]  [40|50]

Insertar 15:
       [30]
      /    \
[5|10|15|20]  [40|50]  (máximo alcanzado)

Insertar 25 (causa división izquierda):
- Mediana: 15
- Nodo izquierdo: [5|10]
- Nodo derecho: [20|25]
- Promover 15 al padre

       [15|30]
      /  |   \
[5|10] [20|25] [40|50]

Insertar 35:
       [15|30]
      /  |   \
[5|10] [20|25|35] [40|50]

Insertar 45:
       [15|30]
      /  |   \
[5|10] [20|25|35] [40|45|50]

Insertar 55 (causa división derecha):
- Mediana: 45
- Nodo izquierdo: [40]
- Nodo derecho: [50|55]
- Promover 45 al padre

       [15|30|45]
      /  |   |   \
[5|10] [20|25|35] [40] [50|55]
```

---

## Casos típicos de examen

### Caso 1: Determinar si es un árbol B válido

**Pregunta:** ¿Es el siguiente árbol un B-tree de orden 5 válido? Justifique.
```
       [20]
      /    \
[10]  [30|40]
```

**Solución:** 
- Raíz tiene 2 hijos ✓ (mínimo 2)
- Nodo [10] tiene 1 clave ✓ (mínimo ⌈5/2⌉-1 = 1)
- Nodo [30|40] tiene 2 claves ✓
- Todos los nodos tienen ≤ 4 claves ✓
- **SÍ es válido.**

### Caso 2: Calcular número de accesos a disco

**Pregunta:** Un árbol B de orden 5 con altura 2. ¿Cuál es el máximo número de claves?

**Solución:**
- Nivel 0 (raíz): máximo 4 claves
- Nivel 1: máximo 5 nodos × 4 claves = 20 claves
- Nivel 2: máximo 25 nodos × 4 claves = 100 claves
- **Total máximo: 124 claves**

### Caso 3: Traza de inserción

**Pregunta:** Inserte 50, 25, 75, 10, 30, 60, 80 en un B-tree de orden 3.

**Solución:**
```
Insertar 50: [50]

Insertar 25: [25|50]

Insertar 75: [25|50|75]

Insertar 10 (causa división):
- Mediana: 50
- Resultado: [50]
           /    \
        [25]   [75]

Insertar 10: [10|25]

Insertar 30: [10|25|30]

Insertar 60: [60|75]

Insertar 80: [60|75|80]

Resultado final:
       [50]
      /    \
[10|25|30] [60|75|80]
```

---

## Errores frecuentes

| Error | Qué pasa | Cómo evitarlo |
|-------|----------|---------------|
| Confundir orden m con número de claves | Cálculos incorrectos | Orden m = máximo de hijos, máximo claves = m-1 |
- Olvidar verificar mínimo de claves | Árbol inválido | Cada nodo (excepto raíz) debe tener ≥ ⌈m/2⌉-1 claves |
- No actualizar punteros durante división | Árbol corrupto | Siempre actualizar punteros de hijos después de dividir |
- Promover clave incorrecta | Árbol desbalanceado | Promover siempre la mediana (posición ⌈m/2⌉) |
- Olvidar que hojas están al mismo nivel | Violación de propiedad B | Los árboles B SIEMPRE tienen hojas al mismo nivel |

---

## Preguntas de recuperación activa

1. ¿Cuándo conviene utilizar un Árbol B en lugar de un ABB?
2. ¿Qué diferencia existe entre un Árbol B y un Árbol B+?
3. ¿Por qué las hojas de un Árbol B siempre están al mismo nivel?
4. ¿Cuál es el propósito de promover una clave durante la división?
5. ¿Cómo se calcula el número máximo de claves en un árbol B de orden m y altura h?
6. ¿Por qué los árboles B son eficientes para almacenamiento en disco?
7. ¿Qué pasa si un nodo interno tiene menos del mínimo de claves después de una eliminación?
8. ¿Cuál es la complejidad de búsqueda en un árbol B?

---

## Autoevaluación

### Nivel 1 (Básico)
1. Defina qué es un árbol B.
2. ¿Cuál es el máximo número de claves en un nodo de orden 5?
3. ¿Por qué todos los nodos hoja están al mismo nivel?

### Nivel 2 (Intermedio)
1. Dibuje la estructura de un nodo B de orden 5.
2. Inserte 10, 20, 30, 40, 50 en un B-tree de orden 3.
3. Explique el proceso de división de un nodo.

### Nivel 3 (Avanzado)
1. Implemente la función de búsqueda en C/C++.
2. Calcule el número máximo de claves en un B-tree de orden 5 con altura 3.
3. Compare la eficiencia de B-tree vs ABB para 1 millón de registros.

---

## Resumen de una página

**Árbol B:** Árbol balanceado multi-vía diseñado para disco.

**Orden m:** Máximo número de hijos por nodo.
- Máximo claves por nodo: m - 1
- Mínimo claves (excepto raíz): ⌈m/2⌉ - 1

**Propiedades:**
- Raíz: mínimo 2 hijos (si no es hoja)
- Nodos internos: entre ⌈m/2⌉ y m hijos
- Hojas: todas al mismo nivel
- Claves ordenadas en cada nodo

**Estructura del nodo:**
```cpp
struct Pagina {
    int cuenta;
    tipoClave claves[m];    // [1..m-1]
    Pagina* ramas[m];       // [0..m-1]
};
```

**Operaciones:**
- **Búsqueda:** O(log_m n) accesos a disco
- **Inserción:** O(log_m n) + posible división
- **Eliminación:** O(log_m n) + posible combinación

**División (split):**
- Nodo se desborda (cuenta = m-1)
- Dividir en dos nodos
- Promover mediana al padre
- Repetir si padre se desborda

**Ventajas:**
- Minimiza accesos a disco
- Garantiza balanceo
- Eficiente para grandes volúmenes

**Errores comunes:**
- Confundir orden m con número de claves
- Olvidar verificar mínimo de claves
- No actualizar punteros durante división
