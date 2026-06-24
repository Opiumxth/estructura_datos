# TEMA 14: ÁRBOLES TRIE

---

## Objetivos

- Comprender la estructura de un Trie para almacenamiento de cadenas
- Dominar las operaciones de inserción, búsqueda y eliminación
- Entender las ventajas de Trie sobre otras estructuras para diccionarios
- Implementar Trie en C/C++ usando punteros o vectores
- Analizar la complejidad de operaciones en Trie

---

## Conceptos clave

- **Trie:** Árbol N-ario donde cada rama representa un carácter
- **Nodo Trie:** Contiene un carácter, puntero a hijos, y marca de fin de palabra
- **Prefijo compartido:** Característica clave que permite compresión
- **Diccionario:** Aplicación principal de Trie
- **Autocompletado:** Aplicación que aprovecha la estructura de prefijos
- **Complejidad por longitud:** Operaciones dependen de la longitud de la palabra, no del número de palabras

---

## Explicación detallada

### ¿Qué es un Trie?

Un Trie (del inglés "retrieval") es un árbol N-ario especializado en el almacenamiento y búsqueda eficiente de cadenas de caracteres. A diferencia de un árbol binario, cada nodo en un Trie puede tener múltiples hijos (uno por cada carácter posible).

**Característica principal:** Los prefijos comunes se comparten entre palabras.

### Estructura del nodo Trie

```
REGISTRO NODO
   CARACTER valor
   BOOLEANO finPalabra
   NODO* hijos[ALFABETO]  // punteros a hijos (uno por letra)
FIN_REGISTRO
```

En C/C++ (usando vector):
```cpp
class Nodo {
private:
    char mcar;
    bool mfin;
    vector<Nodo*> mhijos;

public:
    Nodo() {
        mcar = ' ';
        mfin = false;
    }
    
    char caracter() { return mcar; }
    void setCaracter(char car) { mcar = car; }
    bool finCadena() { return mfin; }
    void setFinCadena() { mfin = true; }
    
    Nodo* buscarHijo(char car);
    void agregarHijo(Nodo* hijo);
    vector<Nodo*> hijos() { return mhijos; }
};
```

### Representación visual

```
Trie con palabras: "ganar", "gancho", "gandula", "ganga", "ganglio"

           (raíz)
            |
            g
            |
            a
           / \
          n   n
         /     \
        d       g
       /       / \
      u       a   a
     /       |   |
    l       n   n
   /         \   \
  a           c   g
              \   \
               h   l
               o   i
                  \
                   o
```

**Observación:** "ganga" y "ganglio" comparten el prefijo "gang"

---

## Operaciones en Trie

### Inserción

**Algoritmo:**
1. Comenzar en la raíz
2. Para cada carácter de la palabra:
   - Si existe un hijo con ese carácter, avanzar
   - Si no existe, crear un nuevo nodo y avanzar
3. Marcar el último nodo como fin de palabra

**Pseudocódigo:**
```
ACCION insertar(Trie t, CADENA s)
   NODO p ← t.raiz
   
   SI(longitud(s) = 0)
      p.finPalabra ← VERDADERO
      RETORNAR
   FIN_SI
   
   PARA i ← 0 HASTA longitud(s) - 1
      NODO hijo ← p.buscarHijo(s[i])
      SI(hijo ≠ NULL)
         p ← hijo
      SINO
         NODO tmp ← nuevoNodo()
         tmp.setCaracter(s[i])
         p.agregarHijo(tmp)
         p ← tmp
      FIN_SI
      
      SI(i = longitud(s) - 1)
         p.setFinCadena()
      FIN_SI
   FIN_PARA
FIN_ACCION
```

**C/C++:**
```cpp
void Trie::adicionaCad(string s) {
    Nodo* p = raiz;
    
    if (s.length() == 0) {
        p->setFinCadena();
        return;
    }
    
    for (int i = 0; i < s.length(); i++) {
        Nodo* hijo = p->buscarHijos(s[i]);
        if (hijo != NULL) {
            p = hijo;
        } else {
            Nodo* tmp = new Nodo();
            tmp->setCaracter(s[i]);
            p->adicionaHijos(tmp);
            p = tmp;
        }
        
        if (i == s.length() - 1) {
            p->setFinCadena();
        }
    }
}
```

### Búsqueda

**Algoritmo:**
1. Comenzar en la raíz
2. Para cada carácter de la palabra:
   - Si existe un hijo con ese carácter, avanzar
   - Si no existe, la palabra no existe
3. Al final, verificar si el nodo está marcado como fin de palabra

**Pseudocódigo:**
```
ACCION buscar(Trie t, CADENA s) RETORNA BOOLEANO
   NODO p ← t.raiz
   NODO tmp
   
   SI(p = NULL)
      RETORNAR(FALSO)
   FIN_SI
   
   PARA i ← 0 HASTA longitud(s) - 1
      tmp ← p.buscarHijo(s[i])
      SI(tmp = NULL)
         RETORNAR(FALSO)
      FIN_SI
      p ← tmp
   FIN_PARA
   
   SI(p.finCadena())
      RETORNAR(VERDADERO)
   SINO
      RETORNAR(FALSO)
   FIN_SI
FIN_ACCION
```

**C/C++:**
```cpp
bool Trie::buscaCad(string s) {
    Nodo* p = raiz;
    Nodo* tmp;
    
    while (p != NULL) {
        for (int i = 0; i < s.length(); i++) {
            tmp = p->buscarHijos(s[i]);
            if (tmp == NULL) {
                return false;
            }
            p = tmp;
        }
        
        if (p->finCadena()) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}
```

### Eliminación

**Algoritmo:**
1. Buscar la palabra
2. Si no existe, retornar
3. Si existe:
   - Desmarcar el nodo como fin de palabra
   - Si el nodo no tiene hijos y no es fin de otra palabra, eliminarlo
   - Repetir hacia arriba hasta encontrar un nodo con hijos o fin de palabra

**Pseudocódigo:**
```
ACCION eliminar(Trie t, CADENA s)
   SI(NO t.buscaCad(s))
      RETORNAR  // palabra no existe
   FIN_SI
   
   NODO p ← t.raiz
   NODO camino[longitud(s)]
   ENTERO indices[longitud(s)]
   ENTERO len ← 0
   
   // Guardar el camino hacia la palabra
   PARA i ← 0 HASTA longitud(s) - 1
      camino[len] ← p
      indices[len] ← índice de s[i] en p.hijos
      p ← p.buscarHijo(s[i])
      len ← len + 1
   FIN_PARA
   
   // Desmarcar fin de palabra
   p.finPalabra ← FALSO
   
   // Eliminar nodos innecesarios
   MIENTRAS(len > 0 Y p.hijos.vacio() Y NO p.finPalabra)
      len ← len - 1
      p ← camino[len]
      eliminar p.hijos[indices[len]]
   FIN_MIENTRAS
FIN_ACCION
```

---

## Ejemplos

### Ejemplo 1: Inserción de palabras

**Insertar:** "ganar", "gancho", "gandula"

```
Paso 1: Insertar "ganar"
(g) -> (a) -> (n) -> (a) -> (r)*
* = fin de palabra

Paso 2: Insertar "gancho"
(g) -> (a) -> (n) -> (a) -> (r)*
                     \
                      (c) -> (h) -> (o)*

Paso 3: Insertar "gandula"
(g) -> (a) -> (n) -> (a) -> (r)*
             \     \
              (d)   (c) -> (h) -> (o)*
               \
                (u) -> (d) -> (l) -> (a)*
```

### Ejemplo 2: Búsqueda

**Pregunta:** ¿Existe "ganga" en el Trie anterior?

**Traza:**
```
1. Raíz -> buscar 'g': existe ✓
2. 'g' -> buscar 'a': existe ✓
3. 'a' -> buscar 'n': existe ✓
4. 'n' -> buscar 'g': NO existe ✗

Resultado: "ganga" NO existe
```

### Ejemplo 3: Autocompletado

**Pregunta:** ¿Qué palabras comienzan con "gan"?

**Solución:**
Recorrer desde el nodo después de "gan" y encontrar todos los caminos que terminan en fin de palabra:
- "ganar" (r*)
- "gancho" (c -> h -> o*)
- "gandula" (d -> u -> d -> l -> a*)

**Resultado:** ganar, gancho, gandula

---

## Casos típicos de examen

### Caso 1: Construir Trie desde palabras

**Pregunta:** Construya un Trie con las palabras: "casa", "carro", "cama", "calor".

**Solución:**
```
        (raíz)
         |
         c
         |
         a
        / \
       m   r
      / \   \
     a   a   o
    /     \   \
   *       s   r
          / \   \
         a   r   *
          \
           *
```

### Caso 2: Determinar si es Trie válido

**Pregunta:** ¿Es válido un Trie donde una palabra es prefijo de otra?

**Solución:** SÍ, es válido. Por ejemplo, "car" y "carro" pueden coexistir:
```
(c) -> (a) -> (r)* -> (r) -> (o)*
```
El primer 'r' está marcado como fin de palabra para "car".

### Caso 3: Calcular espacio

**Pregunta:** Un Trie con 1000 palabras de longitud promedio 10. ¿Cuántos nodos máximo?

**Solución:**
- En el peor caso (sin prefijos compartidos): 1000 × 10 = 10,000 nodos
- En el mejor caso (máxima compartición de prefijos): ~10 nodos (todas comparten el mismo prefijo largo)

---

## Errores frecuentes

| Error | Qué pasa | Cómo evitarlo |
|-------|----------|---------------|
| No marcar fin de palabra | Búsqueda incorrecta | Siempre marcar el último nodo como fin de palabra |
- Confundir prefijo con palabra completa | Falsos positivos | Verificar que el nodo esté marcado como fin de palabra |
- No eliminar nodos innecesarios | Memory leak | Eliminar nodos sin hijos que no son fin de palabra |
- Usar arreglo fijo para hijos | Desperdicio de memoria | Usar vector o lista dinámica para hijos |
- Olvidar manejar cadena vacía | Comportamiento indefinido | Manejar caso especial de cadena vacía |

---

## Preguntas de recuperación activa

1. ¿Por qué un Trie es más eficiente que un arreglo para buscar palabras?
2. ¿Cuál es la complejidad de búsqueda en un Trie?
3. ¿En qué situaciones conviene usar un Trie?
4. ¿Qué ventaja tiene un Trie sobre un árbol binario para diccionarios?
5. ¿Por qué los prefijos se comparten en un Trie?
6. ¿Cómo se implementa el autocompletado usando un Trie?
7. ¿Cuál es la desventaja principal de un Trie en términos de memoria?
8. ¿Qué pasa si insertamos la misma palabra dos veces en un Trie?

---

## Autoevaluación

### Nivel 1 (Básico)
1. Defina qué es un Trie.
2. Escriba el pseudocódigo de inserción en Trie.
3. ¿Qué representa cada nodo en un Trie?

### Nivel 2 (Intermedio)
1. Construya un Trie con las palabras: "sol", "solar", "soldado".
2. Implemente la función de búsqueda en C/C++.
3. Explique cómo funciona el autocompletado con Trie.

### Nivel 3 (Avanzado)
1. Implemente la eliminación en Trie con limpieza de nodos innecesarios.
2. Compare la complejidad de Trie vs Hash Table para diccionarios.
3. Diseñe una función que cuente el número de palabras en un Trie.

---

## Resumen de una página

**Trie:** Árbol N-ario para almacenamiento eficiente de cadenas.

**Característica principal:** Prefijos comunes se comparten entre palabras.

**Estructura del nodo:**
```cpp
class Nodo {
    char caracter;
    bool finPalabra;
    vector<Nodo*> hijos;
};
```

**Operaciones:**
- **Inserción:** O(L) donde L = longitud de la palabra
- **Búsqueda:** O(L)
- **Eliminación:** O(L) + posible limpieza

**Complejidad:** Depende de la longitud de la palabra, NO del número de palabras.

**Aplicaciones:**
- Diccionarios
- Autocompletado
- Corrector ortográfico
- Sugerencias de búsqueda

**Ventajas:**
- Búsqueda muy rápida
- Prefijos compartidos ahorran espacio
- Autocompletado natural

**Desventajas:**
- Mayor uso de memoria que otras estructuras
- Solo eficiente para cadenas
- Complejidad de implementación

**Errores comunes:**
- No marcar fin de palabra
- Confundir prefijo con palabra completa
- No eliminar nodos innecesarios
- Usar arreglo fijo para hijos
