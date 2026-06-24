# TEMA 9: COLAS (QUEUES)

---

## 1. TEORÍA CLARA

### ¿Qué es?
Una cola es una estructura de datos **FIFO** — **First In, First Out** (Primero en entrar, primero en salir). Entra por el **final**, sale por el **frente**.

### Analogía
Es como la fila del banco: el primero que llega es el primero que es atendido. Los nuevos se forman al final.

```
enqueue(1): [1]           frente=1, final=1
enqueue(2): [1, 2]        frente=1, final=2
enqueue(3): [1, 2, 3]     frente=1, final=3
dequeue():  [2, 3]        → devuelve 1 (el primero que entró)
dequeue():  [3]            → devuelve 2
```

### Pila vs Cola — LA diferencia fundamental

| | Pila | Cola |
|--|------|------|
| Política | **LIFO** | **FIFO** |
| Entra por | El tope | El final |
| Sale por | El tope | El frente |
| Extremos usados | **Uno** | **Dos** |
| Analogía | Pila de platos | Fila del banco |

### Operaciones

| Operación | Qué hace | Complejidad |
|-----------|----------|-------------|
| `enqueue(x)` | Agrega x al final | **O(1)** |
| `dequeue()` | Quita y devuelve del frente | **O(1)** |
| `front()` | Devuelve el frente SIN quitarlo | **O(1)** |
| `isEmpty()` | ¿Está vacía? | **O(1)** |

### ¿Por qué cola circular?
Con un arreglo lineal, al hacer dequeue el frente avanza y los espacios al inicio se desperdician. La cola circular usa `% MAX` para que los índices "den la vuelta".

```
Cola lineal — desperdicia espacio:
  dequeue, dequeue → [_, _, 3, 4, 5]  ← posiciones 0 y 1 perdidas

Cola circular — reutiliza espacio:
  dequeue, dequeue, enqueue(6) → [6, _, 3, 4, 5]  ← posición 0 reutilizada
  Frente=2, Final=0 (dio la vuelta con %)
```

### Aplicaciones reales
- Cola de impresión (primer documento enviado, primero impreso)
- Planificador de CPU (procesos en espera)
- Buffer de red (paquetes en orden de llegada)
- Simulación de filas (banco, supermercado, hospital)
- BFS (recorrido en anchura de grafos)

### Errores comunes
- Confundir frente y final (enqueue va al FINAL, dequeue del FRENTE)
- **Olvidar `finalCola = NULL` cuando la cola queda vacía** (con lista enlazada) → error MUY frecuente
- No usar `% MAX` en cola circular → desbordamiento de índice
- Mezclar LIFO con FIFO en la implementación

---

## 2. EJEMPLOS RESUELTOS

### Ejemplo 1: Cola circular con arreglo

**Pseudocódigo (del material del profesor):**
```
MAX ← 10
ACCION crearCola(COLA c, ENTERO frente, ENTERO final)
   frente ← -1
   final ← -1
FIN_ACCION

ACCION encolar(COLA c, ENTERO frente, ENTERO final, TD dato)
   SI(final < 0)
      c[0] ← dato
      final ← 0
      frente ← 0
   SINO
      ENTERO n ← final + 1
      SI(n < MAX)
         c[n] ← dato
         final ← n
      SINO
         ESCRIBIR("Cola Llena...")
      FIN_SI
   FIN_SI
FIN_ACCION

ACCION decolar(COLA c, ENTERO frente, ENTERO final, TD dato)
   SI(frente = final)
      dato ← c[frente]
      frente ← -1
      final ← -1
   SINO
      SI(frente >= 0)
         dato ← c[frente]
         frente ← frente + 1
      SINO
         ESCRIBIR("Cola vacía...")
      FIN_SI
   FIN_SI
FIN_ACCION
```

**C/C++ (versión circular mejorada):**

```cpp
#include <iostream>
using namespace std;

const int MAX = 5;

struct Cola {
    int datos[MAX];
    int frente;
    int final_c;
    int tam;
};

void crear(Cola* q) {
    q->frente = 0;
    q->final_c = 0;
    q->tam = 0;
}

bool estaVacia(Cola* q) { return q->tam == 0; }
bool estaLlena(Cola* q) { return q->tam == MAX; }

void enqueue(Cola* q, int valor) {
    if (estaLlena(q)) {
        cout << "Cola llena!" << endl;
        return;
    }
    q->datos[q->final_c] = valor;
    q->final_c = (q->final_c + 1) % MAX;   // ← CLAVE: módulo para circular
    q->tam++;
}

int dequeue(Cola* q) {
    if (estaVacia(q)) {
        cout << "Cola vacía!" << endl;
        return -1;
    }
    int val = q->datos[q->frente];
    q->frente = (q->frente + 1) % MAX;      // ← CLAVE: módulo para circular
    q->tam--;
    return val;
}

int front(Cola* q) {
    if (estaVacia(q)) {
        cout << "Cola vacía!" << endl;
        return -1;
    }
    return q->datos[q->frente];
}

int main() {
    Cola miCola;
    crear(&miCola);
    
    enqueue(&miCola, 10);
    enqueue(&miCola, 20);
    enqueue(&miCola, 30);
    
    cout << "Frente: " << front(&miCola) << endl;    // 10
    cout << "Dequeue: " << dequeue(&miCola) << endl;  // 10
    cout << "Dequeue: " << dequeue(&miCola) << endl;  // 20
    
    enqueue(&miCola, 40);
    enqueue(&miCola, 50);
    
    cout << "Frente: " << front(&miCola) << endl;    // 30
    
    return 0;
}
```

**Traza del módulo circular:**
```
MAX = 5
enqueue(10): datos[0]=10, final_c=(0+1)%5=1, tam=1
enqueue(20): datos[1]=20, final_c=(1+1)%5=2, tam=2
enqueue(30): datos[2]=30, final_c=(2+1)%5=3, tam=3
dequeue():   val=datos[0]=10, frente=(0+1)%5=1, tam=2
dequeue():   val=datos[1]=20, frente=(1+1)%5=2, tam=1
enqueue(40): datos[3]=40, final_c=(3+1)%5=4, tam=2
enqueue(50): datos[4]=50, final_c=(4+1)%5=0 ← DIO LA VUELTA!, tam=3
```

### Ejemplo 2: Cola con lista enlazada

**Pseudocódigo:**
```
NODO frente ← NULL
NODO finalCola ← NULL

ACCION encolar(NODO frente, NODO finalCola, TD dato)
   NODO nuevo
   nuevo ← new NODO
   nuevo.valor ← dato
   nuevo.sgte ← NULL
   SI(finalCola = NULL)
      frente ← nuevo
      finalCola ← nuevo
   SINO
      finalCola.sgte ← nuevo
      finalCola ← nuevo
   FIN_SI
FIN_ACCION

ACCION decolar(NODO frente, NODO finalCola, TD dato)
   SI(frente = NULL)
      ESCRIBIR("Cola vacía")
   SINO
      NODO temp ← frente
      dato ← temp.valor
      frente ← frente.sgte
      SI(frente = NULL)
         finalCola ← NULL     // ¡CRUCIAL! No olvidar
      FIN_SI
      liberaNodo(temp)
   FIN_SI
FIN_ACCION
```

**C/C++:**

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

struct NODO {
    int valor;
    NODO* sgte;
};

struct Cola {
    NODO* frente;
    NODO* final_c;
};

void crear(Cola* q) {
    q->frente = NULL;
    q->final_c = NULL;
}

bool estaVacia(Cola* q) {
    return q->frente == NULL;
}

void enqueue(Cola* q, int dato) {
    NODO* nuevo = (NODO*)malloc(sizeof(NODO));
    nuevo->valor = dato;
    nuevo->sgte = NULL;
    
    if (q->final_c == NULL) {
        // Cola vacía: frente Y final apuntan al nuevo
        q->frente = nuevo;
        q->final_c = nuevo;
    } else {
        // Agregar al final
        q->final_c->sgte = nuevo;
        q->final_c = nuevo;
    }
}

int dequeue(Cola* q) {
    if (estaVacia(q)) {
        printf("Cola vacía!\n");
        return -1;
    }
    NODO* temp = q->frente;
    int val = temp->valor;
    q->frente = q->frente->sgte;
    
    // CRÍTICO: si la cola queda vacía, actualizar final también
    if (q->frente == NULL) {
        q->final_c = NULL;
    }
    
    free(temp);
    return val;
}

int main() {
    Cola miCola;
    crear(&miCola);
    
    enqueue(&miCola, 100);
    enqueue(&miCola, 200);
    enqueue(&miCola, 300);
    
    printf("Dequeue: %d\n", dequeue(&miCola));  // 100
    printf("Dequeue: %d\n", dequeue(&miCola));  // 200
    printf("Dequeue: %d\n", dequeue(&miCola));  // 300
    printf("Vacía: %d\n", estaVacia(&miCola));   // 1 (true)
    
    return 0;
}
```

**Punto crítico:** Cuando `frente` queda en `NULL` después de dequeue, **DEBES** poner `final_c = NULL` también. Si no, `final_c` queda apuntando a memoria liberada (dangling pointer).

---

## Preguntas de recuperación

1. ¿Por qué el principio FIFO de las colas es fundamental para modelar sistemas de espera?
2. ¿Cuál es la diferencia entre una cola y una pila en términos de orden de acceso y aplicaciones?
3. ¿Qué problema resuelve el uso de colas circulares en comparación con colas lineales?
4. ¿Cómo se relaciona el concepto de cola con el scheduling de procesos en sistemas operativos?
5. ¿Qué ocurriría si intentas hacer dequeue de una cola vacía en un programa real?
6. ¿Cuándo conviene implementar una cola con arreglos y cuándo con listas enlazadas?
7. ¿Cómo se utiliza una cola para implementar el recorrido BFS en árboles y grafos?

## 3. EJERCICIOS PARA PRACTICAR

**Ejercicio 9.1 (Fácil):** ¿Cuál es el estado de la cola después de estas operaciones?
```
enqueue(A), enqueue(B), dequeue(), enqueue(C), enqueue(D), dequeue(), dequeue()
```
¿Qué queda? ¿Qué devolvió cada dequeue?

**Ejercicio 9.2 (Fácil):** Con una cola circular de MAX=4, trace las operaciones:
```
enqueue(1), enqueue(2), enqueue(3), dequeue(), dequeue(), enqueue(4), enqueue(5)
```
Muestre frente, final_c y tam después de CADA operación.

**Ejercicio 9.3 (Medio):** Implemente una función que use una cola para simular la atención de N clientes. Cada cliente tiene un nombre y tiempo de atención. Muestre el orden de atención y el tiempo total.

**Ejercicio 9.4 (Medio):** Escriba una función que invierta una cola usando una pila auxiliar. (Dequeue todos a la pila, luego pop todos de vuelta a la cola.)

**Ejercicio 9.5 (Tipo examen):** Implemente una **cola de prioridad** simple: los elementos se insertan al final pero se extraen siempre el de mayor valor. (Hint: dequeue debe buscar el máximo.)

---

## 4. PATRONES DE EXAMEN

- **Traza de operaciones:** enqueue/dequeue y pedir estado final. → Dibuja la cola como flecha horizontal: frente ← ... ← final.
- **Cola circular — módulo %:** Te dan MAX y operaciones. Preguntan los valores de frente y final. → Aplica `% MAX` siempre.
- **Diferenciar pila de cola:** Pregunta teórica estrella. → LIFO vs FIFO, 1 extremo vs 2 extremos.
- **Implementar con lista:** Completar enqueue/dequeue. → Recordar: si cola vacía al hacer dequeue, `final_c = NULL`.
- **Truco:** Si el problema habla de "turnos", "orden de llegada", "fila", "atención" → COLA. Si habla de "deshacer", "último", "reversa" → PILA.

### Chuleta de repaso rápido
```
COLA = FIFO (First In, First Out)
Entra por el FINAL, sale por el FRENTE.

CON ARREGLO CIRCULAR:
  frente=0, final=0, tam=0 → vacía
  enqueue: datos[final] = valor; final = (final+1) % MAX; tam++
  dequeue: val = datos[frente]; frente = (frente+1) % MAX; tam--

CON LISTA ENLAZADA:
  frente=NULL, final=NULL → vacía
  enqueue: agregar al final (final->sgte = nuevo; final = nuevo)
  dequeue: quitar del frente (temp=frente; frente=frente->sgte)
  Si frente==NULL después de dequeue → final=NULL también

Todas las operaciones: O(1)
Cola vacía + dequeue = underflow
Cola llena + enqueue = overflow (solo con arreglo)
```
