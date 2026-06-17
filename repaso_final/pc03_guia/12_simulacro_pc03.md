# SIMULACRO DE EXAMEN PC3

> **Tiempo sugerido:** 90 minutos
> **Formato:** Preguntas mixtas — pseudocódigo y C/C++ (como la última PC)
> **Alcance:** Sem 01 hasta Árboles
> **Instrucciones:** Resuelve sin consultar apuntes. Al terminar, revisa las soluciones.

---

## PARTE I: TEÓRICA (30 puntos)

### Pregunta 1 (6 pts)
Responda Verdadero o Falso. Justifique las falsas.

a) En un ABB, el recorrido InOrden produce los datos en orden ascendente.
b) Una pila puede implementarse con una lista enlazada donde push = insertarFinal.
c) En una cola con lista enlazada, al hacer dequeue y quedar vacía, solo se actualiza `frente` a NULL.
d) La búsqueda en un ABB balanceado tiene complejidad O(log n).
e) El árbol de Huffman asigna códigos más cortos a los símbolos más frecuentes.
f) En pseudocódigo, `p.sgte ← cab` equivale en C/C++ a `p.sgte = cab;`.

### Pregunta 2 (6 pts)
Complete la siguiente tabla:

| Estructura   | Insertar  | Eliminar  | Buscar    | Política |
|-------------|-----------|-----------|-----------|----------|
| Lista Simple | ___       | ___       | ___       | ___      |
| Pila         | ___       | ___       | ___       | ___      |
| Cola         | ___       | ___       | ___       | ___      |
| ABB          | ___       | ___       | ___       | ___      |

### Pregunta 3 (6 pts)
Explique con sus propias palabras:
a) ¿Por qué se usa doble puntero (`NODO** cab`) al pasar la cabeza de una lista a una función en C/C++? ¿Cómo se maneja esto en pseudocódigo?
b) ¿Cuál es la diferencia entre el recorrido por niveles y el recorrido PreOrden? ¿Qué estructura auxiliar usa cada uno?
c) ¿Qué ventaja tiene un ABB sobre una lista enlazada para búsquedas? ¿En qué caso pierde esa ventaja?

### Pregunta 4 (6 pts)
Dado el siguiente ABB, escriba los 4 recorridos:
```
        50
       /  \
      25    75
     / \   / \
    10  30 60  80
   /
  5
```

a) PreOrden:
b) InOrden:
c) PostOrden:
d) Por niveles:

### Pregunta 5 (6 pts)
Dada la secuencia de operaciones:

**Pila:** push(A), push(B), push(C), pop(), push(D), pop(), pop()
**Cola:** enqueue(A), enqueue(B), enqueue(C), dequeue(), enqueue(D), dequeue(), dequeue()

a) ¿Qué valores devolvió cada pop de la pila?
b) ¿Qué valores devolvió cada dequeue de la cola?
c) ¿Qué queda en la pila? ¿Qué queda en la cola?

---

## PARTE II: PRÁCTICA — PSEUDOCÓDIGO (35 puntos)

### Problema 1 (20 pts): Lista enlazada de alumnos

Se tiene:
```
REGISTRO ALUMNO
   ENTERO codigo
   CARACTER nombre[30]
   REAL promedio
FIN_REGISTRO

REGISTRO NODO
   ALUMNO dato
   NODO sgte
FIN_REGISTRO
```

Implemente en **pseudocódigo**:

1. **(5 pts)** Las estructuras y prototipos de función.
2. **(5 pts)** `insertarOrdenado(cab, cab1, alu)` — Inserta manteniendo la lista ordenada por código de menor a mayor.
3. **(5 pts)** `mostrarAprobados(cab)` — Muestra solo alumnos con promedio >= 11.0.
4. **(5 pts)** `eliminarAlumno(cab, cab1, codigo)` — Elimina el nodo con el código dado. Manejar: lista vacía, primer nodo, nodo intermedio/final, no encontrado.

### Problema 2 (15 pts): Operaciones con ABB

Dada la estructura:
```
REGISTRO BNODO
   BNODO hi
   TD info
   BNODO hd
FIN_REGISTRO
```

Implemente en **pseudocódigo**:

1. **(5 pts)** `insertarABB(raiz, dato)` — Inserción recursiva en el ABB.
2. **(5 pts)** `contarHojas(raiz)` — Contar recursivamente las hojas del árbol.
3. **(5 pts)** `recorridoPorNiveles(raiz)` — Recorrido por niveles usando cola.

---

## PARTE III: PRÁCTICA — C/C++ (35 puntos)

### Problema 3 (20 pts): Pila + Cola con Structs

Una empresa de soporte recibe tickets:
- Los **urgentes** van a una **PILA** (LIFO).
- Los **normales** van a una **COLA** (FIFO).

```cpp
struct Ticket {
    int id;
    char descripcion[50];
    char tipo;  // 'U' = urgente, 'N' = normal
};

struct NODO {
    Ticket dato;
    NODO *sgte;
};
```

Implemente en **C/C++**:

1. **(5 pts)** Las estructuras de datos necesarias (pila con tope, cola con frente/final).
2. **(5 pts)** `void recibirTicket(Ticket t)` — Si urgente: push a pila. Si normal: enqueue a cola.
3. **(5 pts)** `Ticket atenderTicket()` — Primero atiende urgentes (pop). Si no hay, atiende normales (dequeue).
4. **(5 pts)** `void mostrarPendientes()` — Muestra cuántos urgentes y normales hay pendientes.

### Problema 4 (15 pts): ABB con operaciones

```cpp
typedef int TD;
struct NODO {
    TD info;
    NODO *izq;
    NODO *der;
};
```

Implemente en **C/C++**:

1. **(5 pts)** `void insertar(NODO **raiz, TD dato)` — Inserción iterativa en ABB.
2. **(5 pts)** `void inOrden(NODO *raiz)` — Recorrido InOrden recursivo.
3. **(5 pts)** `int altura(NODO *raiz)` — Altura del árbol (recursivo).

---

---

# SOLUCIONES DEL SIMULACRO

---

## PARTE I: SOLUCIONES TEÓRICAS

### Pregunta 1
a) **VERDADERO** — El InOrden visita Izq→Raíz→Der, lo que en un ABB produce orden ascendente.
b) **FALSO** — Push debe ser insertarInicio (para que pop también sea O(1) al inicio). Si push fuera insertarFinal, pop tendría que recorrer toda la lista O(n).
c) **FALSO** — Se debe actualizar TANTO `frente` como `finalCola` a NULL. Si solo actualizas `frente`, `finalCola` queda como dangling pointer.
d) **VERDADERO** — En un ABB balanceado, cada comparación descarta la mitad del árbol.
e) **VERDADERO** — Es el principio fundamental del algoritmo de Huffman.
f) **FALSO** — En C/C++ con punteros se usa `p->sgte = cab;` (flecha, no punto). El pseudocódigo usa `.` siempre, pero C/C++ usa `->` cuando se accede mediante puntero.

### Pregunta 2

| Estructura   | Insertar      | Eliminar      | Buscar       | Política |
|-------------|---------------|---------------|--------------|----------|
| Lista Simple | **O(1)**\*   | **O(1)**\*   | O(n)         | Libre    |
| Pila         | **O(1)**     | **O(1)**     | O(n)         | **LIFO** |
| Cola         | **O(1)**     | **O(1)**     | O(n)         | **FIFO** |
| ABB          | **O(log n)** | **O(log n)** | **O(log n)** | Ordenado |

\*Al inicio. Al final sería O(n).

### Pregunta 3

a) En C/C++, si pasamos `NODO* cab`, la función recibe una copia del puntero. Los cambios al puntero se pierden al salir. Con `NODO** cab` pasamos la dirección del puntero, así podemos modificar a dónde apunta. En pseudocódigo del curso, el paso por referencia está implícito (se modifica directamente `cab`).

b) **PreOrden** es un recorrido en **profundidad** (baja hasta las hojas antes de explorar hermanos); usa **PILA** en su versión iterativa. **Por niveles** es un recorrido en **anchura** (visita todos los nodos de un nivel antes de pasar al siguiente); usa **COLA**.

c) En un ABB **balanceado**, la búsqueda es O(log n) porque cada comparación descarta la mitad del árbol. En una lista, la búsqueda es siempre O(n). El ABB pierde esta ventaja cuando está **degenerado** (los datos se insertaron en orden), ya que se convierte en una lista y la búsqueda vuelve a ser O(n).

### Pregunta 4

```
        50
       /  \
      25    75
     / \   / \
    10  30 60  80
   /
  5
```

a) PreOrden: **50, 25, 10, 5, 30, 75, 60, 80**
b) InOrden: **5, 10, 25, 30, 50, 60, 75, 80** ← ¡sale ordenado!
c) PostOrden: **5, 10, 30, 25, 60, 80, 75, 50**
d) Por niveles: **50, 25, 75, 10, 30, 60, 80, 5**

### Pregunta 5

**Pila:** push(A), push(B), push(C), pop()→**C**, push(D), pop()→**D**, pop()→**B**
Estado final pila: `[A]`

**Cola:** enqueue(A), enqueue(B), enqueue(C), dequeue()→**A**, enqueue(D), dequeue()→**B**, dequeue()→**C**
Estado final cola: `[D]`

---

## PARTE II: SOLUCIONES EN PSEUDOCÓDIGO

### Problema 1: Lista enlazada de alumnos

```
// 1. Estructuras y prototipos
REGISTRO ALUMNO
   ENTERO codigo
   CARACTER nombre[30]
   REAL promedio
FIN_REGISTRO

REGISTRO NODO
   ALUMNO dato
   NODO sgte
FIN_REGISTRO

ACCION crearNodo(NODO cab1, ALUMNO alu)
ACCION insertarOrdenado(NODO cab, NODO cab1, ALUMNO alu)
ACCION mostrarAprobados(NODO cab)
ACCION eliminarAlumno(NODO cab, NODO cab1, ENTERO codigo)

// 2. Insertar ordenado por código
ACCION insertarOrdenado(NODO cab, NODO cab1, ALUMNO alu)
   NODO p, q, ante
   p ← crearNodo(cab1, alu)
   SI(p = NULL)
      RETORNAR
   FIN_SI

   // Caso 1: lista vacía o insertar antes del primero
   SI(cab = NULL O alu.codigo < cab.dato.codigo)
      p.sgte ← cab
      cab ← p
   SINO
      // Caso 2: buscar posición correcta
      q ← cab
      MIENTRAS(q.sgte ≠ NULL Y q.sgte.dato.codigo < alu.codigo)
         q ← q.sgte
      FIN_MIENTRAS
      p.sgte ← q.sgte
      q.sgte ← p
   FIN_SI
FIN_ACCION

// 3. Mostrar aprobados
ACCION mostrarAprobados(NODO cab)
   NODO aux
   ENTERO cont ← 0
   aux ← cab
   ESCRIBIR("--- APROBADOS ---")
   MIENTRAS(aux ≠ NULL)
      SI(aux.dato.promedio >= 11.0)
         ESCRIBIR(aux.dato.codigo, " - ", aux.dato.nombre, " - ", aux.dato.promedio)
         cont ← cont + 1
      FIN_SI
      aux ← aux.sgte
   FIN_MIENTRAS
   ESCRIBIR("Total: ", cont)
FIN_ACCION

// 4. Eliminar alumno por código
ACCION eliminarAlumno(NODO cab, NODO cab1, ENTERO codigo)
   NODO aux, ante
   // Lista vacía
   SI(cab = NULL)
      ESCRIBIR("Lista vacía")
      RETORNAR
   FIN_SI
   // Caso: primer nodo
   SI(cab.dato.codigo = codigo)
      aux ← cab
      cab ← cab.sgte
      liberaNodo(cab1, aux)
      RETORNAR
   FIN_SI
   // Caso: buscar en el resto
   ante ← cab
   aux ← cab.sgte
   MIENTRAS(aux ≠ NULL Y aux.dato.codigo ≠ codigo)
      ante ← aux
      aux ← aux.sgte
   FIN_MIENTRAS
   SI(aux = NULL)
      ESCRIBIR("No encontrado")
   SINO
      ante.sgte ← aux.sgte
      liberaNodo(cab1, aux)
   FIN_SI
FIN_ACCION
```

### Problema 2: ABB en pseudocódigo

```
// 1. Inserción recursiva
ACCION insertarABB(BNODO raiz, TD dato)
   SI(raiz = NULL)
      raiz ← new BNODO
      raiz.info ← dato
      raiz.hi ← NULL
      raiz.hd ← NULL
   SINO
      SI(dato < raiz.info)
         insertarABB(raiz.hi, dato)
      SINO
         insertarABB(raiz.hd, dato)
      FIN_SI
   FIN_SI
FIN_ACCION

// 2. Contar hojas
ACCION contarHojas(BNODO raiz)
   SI(raiz = NULL)
      RETORNAR(0)
   FIN_SI
   SI(raiz.hi = NULL Y raiz.hd = NULL)
      RETORNAR(1)
   FIN_SI
   RETORNAR(contarHojas(raiz.hi) + contarHojas(raiz.hd))
FIN_ACCION

// 3. Recorrido por niveles con cola
ACCION porNiveles(BNODO raiz)
   COLA c
   BNODO t
   SI(raiz ≠ NULL)
      encolar(c, raiz)
      MIENTRAS(NO colaVacia(c))
         decolar(c, t)
         ESCRIBIR(t.info, " ")
         SI(t.hi ≠ NULL)
            encolar(c, t.hi)
         FIN_SI
         SI(t.hd ≠ NULL)
            encolar(c, t.hd)
         FIN_SI
      FIN_MIENTRAS
   FIN_SI
FIN_ACCION
```

---

## PARTE III: SOLUCIONES EN C/C++

### Problema 3: Pila + Cola con Tickets

```cpp
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Ticket {
    int id;
    char descripcion[50];
    char tipo;
};

struct NODO {
    Ticket dato;
    NODO *sgte;
};

// 1. Estructuras
NODO *pilaTope = NULL;
int contUrgentes = 0;

struct Cola {
    NODO *frente;
    NODO *final_c;
};
Cola colaNormal = {NULL, NULL};
int contNormales = 0;

// Push urgente (pila)
void pushUrgente(Ticket t) {
    NODO *nuevo = new NODO;
    nuevo->dato = t;
    nuevo->sgte = pilaTope;
    pilaTope = nuevo;
    contUrgentes++;
}

// Enqueue normal (cola)
void enqueueNormal(Ticket t) {
    NODO *nuevo = new NODO;
    nuevo->dato = t;
    nuevo->sgte = NULL;
    if (colaNormal.final_c == NULL) {
        colaNormal.frente = nuevo;
        colaNormal.final_c = nuevo;
    } else {
        colaNormal.final_c->sgte = nuevo;
        colaNormal.final_c = nuevo;
    }
    contNormales++;
}

// 2. Recibir ticket
void recibirTicket(Ticket t) {
    if (t.tipo == 'U') {
        pushUrgente(t);
        printf("Ticket #%d recibido como URGENTE\n", t.id);
    } else {
        enqueueNormal(t);
        printf("Ticket #%d recibido como NORMAL\n", t.id);
    }
}

// 3. Atender ticket
Ticket atenderTicket() {
    Ticket vacio = {0, "", ' '};
    // Primero urgentes (LIFO)
    if (pilaTope != NULL) {
        NODO *temp = pilaTope;
        Ticket t = temp->dato;
        pilaTope = pilaTope->sgte;
        delete temp;
        contUrgentes--;
        printf("Atendido URGENTE #%d: %s\n", t.id, t.descripcion);
        return t;
    }
    // Luego normales (FIFO)
    if (colaNormal.frente != NULL) {
        NODO *temp = colaNormal.frente;
        Ticket t = temp->dato;
        colaNormal.frente = colaNormal.frente->sgte;
        if (colaNormal.frente == NULL)
            colaNormal.final_c = NULL;   // ← CRÍTICO
        delete temp;
        contNormales--;
        printf("Atendido NORMAL #%d: %s\n", t.id, t.descripcion);
        return t;
    }
    printf("No hay tickets pendientes\n");
    return vacio;
}

// 4. Mostrar pendientes
void mostrarPendientes() {
    printf("\n--- TICKETS PENDIENTES ---\n");
    printf("Urgentes (pila): %d\n", contUrgentes);
    printf("Normales (cola): %d\n", contNormales);
    printf("Total: %d\n", contUrgentes + contNormales);
}
```

### Problema 4: ABB en C/C++

```cpp
#include <cstdio>
#include <cstdlib>

typedef int TD;
struct NODO {
    TD info;
    NODO *izq;
    NODO *der;
};

// 1. Inserción iterativa en ABB
void insertar(NODO **raiz, TD dato) {
    NODO *padre = NULL;
    NODO *actual = *raiz;
    
    while (actual != NULL) {
        padre = actual;
        if (dato < actual->info)
            actual = actual->izq;
        else
            actual = actual->der;
    }
    
    NODO *nuevo = new NODO;
    nuevo->info = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    
    if (padre == NULL)
        *raiz = nuevo;
    else if (dato < padre->info)
        padre->izq = nuevo;
    else
        padre->der = nuevo;
}

// 2. Recorrido InOrden (recursivo)
void inOrden(NODO *raiz) {
    if (raiz != NULL) {
        inOrden(raiz->izq);
        printf("%d ", raiz->info);
        inOrden(raiz->der);
    }
}

// 3. Altura del árbol (recursivo)
int altura(NODO *raiz) {
    if (raiz == NULL) return -1;
    int altIzq = altura(raiz->izq);
    int altDer = altura(raiz->der);
    return 1 + (altIzq > altDer ? altIzq : altDer);
}

int main() {
    NODO *raiz = NULL;
    
    insertar(&raiz, 50);
    insertar(&raiz, 25);
    insertar(&raiz, 75);
    insertar(&raiz, 10);
    insertar(&raiz, 30);
    insertar(&raiz, 60);
    insertar(&raiz, 80);
    
    printf("InOrden: ");
    inOrden(raiz);
    printf("\n");
    // Salida: 10 25 30 50 60 75 80
    
    printf("Altura: %d\n", altura(raiz));
    // Salida: 2
    
    return 0;
}
```

**Puntos clave de la solución:**
- Parte II en **pseudocódigo**: usa `←` para asignación, `.` para acceso, `SI/SINO/FIN_SI` para condicionales.
- Parte III en **C/C++**: usa `=` para asignación, `->` para acceso por puntero, `if/else` para condicionales.
- La lógica es idéntica en ambos lenguajes; solo cambia la sintaxis.
- Siempre manejar caso vacío, caso primer nodo, caso general.
- En cola: si `frente == NULL` después de dequeue → `finalCola = NULL`.
