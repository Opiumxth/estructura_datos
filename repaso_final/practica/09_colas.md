# PRÁCTICA 09: COLAS

---

## Ejercicio 9.1 (Fácil) - Enqueue y Dequeue

**Enunciado:**
Implemente las operaciones enqueue y dequeue para una cola implementada con lista enlazada.

**Solución en C/C++:**
```cpp
void enqueue(NODO** frente, NODO** final, int valor) {
    NODO* nuevo = new NODO;
    nuevo->valor = valor;
    nuevo->sgte = NULL;
    
    if (*final == NULL) {
        *frente = *final = nuevo;
    } else {
        (*final)->sgte = nuevo;
        *final = nuevo;
    }
}

int dequeue(NODO** frente, NODO** final) {
    if (*frente == NULL) {
        cout << "Cola vacía" << endl;
        return -1;
    }
    
    NODO* temp = *frente;
    int valor = temp->valor;
    *frente = (*frente)->sgte;
    
    if (*frente == NULL) {
        *final = NULL;
    }
    
    delete temp;
    return valor;
}
```

**Pseudocódigo:**
```
ACCION enqueue(NODO frente, NODO final, NODO cab1, ENTERO valor)
   NODO nuevo
   
   nuevo ← nuevoNodo(cab1, valor)
   nuevo.sgte ← NULL
   
   SI(final = NULL)
      frente ← final ← nuevo
   SINO
      final.sgte ← nuevo
      final ← nuevo
   FIN_SI
FIN_ACCION

ACCION dequeue(NODO frente, NODO final, NODO cab1) RETORNA ENTERO
   NODO temp
   ENTERO valor
   
   SI(frente = NULL)
      ESCRIBIR("Cola vacía")
      RETORNAR(-1)
   FIN_SI
   
   temp ← frente
   valor ← temp.valor
   frente ← frente.sgte
   
   SI(frente = NULL)
      final ← NULL
   FIN_SI
   
   liberaNodo(cab1, temp)
   RETORNAR(valor)
FIN_ACCION
```

---

## Ejercicio 9.2 (Medio) - Cola circular

**Enunciado:**
Implemente enqueue y dequeue para una cola circular usando arreglos.

**Solución en C/C++:**
```cpp
#define MAX 100

struct COLA {
    int datos[MAX];
    int frente;
    int final;
};

void inicializar(COLA* c) {
    c->frente = -1;
    c->final = -1;
}

bool estaLlena(COLA* c) {
    return (c->final + 1) % MAX == c->frente;
}

bool estaVacia(COLA* c) {
    return c->frente == -1;
}

void enqueue(COLA* c, int valor) {
    if (estaLlena(c)) {
        cout << "Cola llena" << endl;
        return;
    }
    
    if (c->frente == -1) {
        c->frente = c->final = 0;
    } else {
        c->final = (c->final + 1) % MAX;
    }
    
    c->datos[c->final] = valor;
}

int dequeue(COLA* c) {
    if (estaVacia(c)) {
        cout << "Cola vacía" << endl;
        return -1;
    }
    
    int valor = c->datos[c->frente];
    
    if (c->frente == c->final) {
        c->frente = c->final = -1;
    } else {
        c->frente = (c->frente + 1) % MAX;
    }
    
    return valor;
}
```

---

## Ejercicio 9.3 (Medio) - Imprimir cola

**Enunciado:**
Escriba una función que imprima todos los elementos de una cola sin modificarla.

**Solución en C/C++:**
```cpp
void imprimirCola(NODO* frente) {
    NODO* temp = frente;
    
    while (temp != NULL) {
        cout << temp->valor << " ";
        temp = temp->sgte;
    }
    cout << endl;
}
```

**Pseudocódigo:**
```
ACCION imprimirCola(NODO frente)
   NODO temp
   
   temp ← frente
   
   MIENTRAS(temp ≠ NULL)
      ESCRIBIR(temp.valor, " ")
      temp ← temp.sgte
   FIN_MIENTRAS
   ESCRIBIR("")
FIN_ACCION
```

---

## Ejercicio 9.4 (Difícil) - Cola con prioridad

**Enunciado:**
Implemente una cola con prioridad donde los elementos con mayor valor tienen mayor prioridad.

**Solución en C/C++:**
```cpp
#include <queue>
using namespace std;

void colaPrioridad() {
    priority_queue<int> pq;
    
    pq.push(10);
    pq.push(30);
    pq.push(20);
    
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
```

---

## Ejercicio 9.5 (Tipo examen) - BFS en árbol

**Enunciado:**
Use una cola para implementar el recorrido por niveles (BFS) de un árbol binario.

**Solución en C/C++:**
```cpp
#include <queue>
using namespace std;

void recorridoPorNiveles(NODO* raiz) {
    if (raiz == NULL) return;
    
    queue<NODO*> cola;
    cola.push(raiz);
    
    while (!cola.empty()) {
        NODO* actual = cola.front();
        cola.pop();
        
        cout << actual->info << " ";
        
        if (actual->izq != NULL) cola.push(actual->izq);
        if (actual->der != NULL) cola.push(actual->der);
    }
}
```
