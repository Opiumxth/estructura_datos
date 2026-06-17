# TEMA 8: PILAS (STACKS)

---

## 1. TEORÍA CLARA

### ¿Qué es?
Una pila es una estructura de datos **LIFO** — **Last In, First Out** (Último en entrar, primero en salir). Solo se accede al **tope** (el último elemento insertado).

### Analogía
Piensa en una pila de platos: solo puedes poner o sacar platos **por arriba**. No puedes acceder al plato del medio sin quitar los de arriba.

```
push(1): [1]
push(2): [1, 2]     ← tope
push(3): [1, 2, 3]  ← tope
pop():   [1, 2]     → devuelve 3
pop():   [1]         → devuelve 2
top():   [1]         → devuelve 1 (sin quitarlo)
```

### Operaciones

| Operación | Qué hace | Complejidad |
|-----------|----------|-------------|
| `push(x)` | Agrega x al tope | **O(1)** |
| `pop()` | Quita y devuelve el tope | **O(1)** |
| `top()` / `peek()` | Devuelve el tope SIN quitarlo | **O(1)** |
| `isEmpty()` | ¿Está vacía? | **O(1)** |
| `isFull()` | ¿Está llena? (solo con arreglo) | **O(1)** |

> **Todas las operaciones son O(1).** Es la estructura más eficiente para operar en un solo extremo.

### Aplicaciones reales
- **Ctrl+Z (Deshacer):** Cada acción se apila; deshacer = pop.
- **Pila de llamadas:** El sistema operativo usa una pila para las funciones recursivas.
- **Evaluación de expresiones:** Convertir infija → postfija, evaluar postfija.
- **Paréntesis balanceados:** Verificar que cada `(` tiene su `)`.
- **Navegador web:** Botón "Atrás" = pop de la pila de páginas visitadas.

### Errores comunes
- **Stack Overflow:** push en pila llena (con arreglo).
- **Stack Underflow:** pop/top en pila vacía → CRASH o valor basura.
- **Memory leak:** Olvidar `delete`/`free` al hacer pop (con lista enlazada).

---

## 2. EJEMPLOS RESUELTOS

### Ejemplo 1: Pila con arreglo estático

```cpp
#include <iostream>
using namespace std;

const int MAX = 100;

struct Pila {
    int datos[MAX];
    int tope;
};

void crear(Pila* p) {
    p->tope = -1;       // -1 = pila vacía
}

bool estaVacia(Pila* p) {
    return p->tope == -1;
}

bool estaLlena(Pila* p) {
    return p->tope == MAX - 1;
}

void push(Pila* p, int valor) {
    if (estaLlena(p)) {
        cout << "ERROR: Pila llena (overflow)" << endl;
        return;
    }
    p->tope++;
    p->datos[p->tope] = valor;
    // equivalente compacto: p->datos[++p->tope] = valor;
}

int pop(Pila* p) {
    if (estaVacia(p)) {
        cout << "ERROR: Pila vacía (underflow)" << endl;
        return -1;
    }
    int val = p->datos[p->tope];
    p->tope--;
    return val;
    // equivalente compacto: return p->datos[p->tope--];
}

int top(Pila* p) {
    if (estaVacia(p)) {
        cout << "ERROR: Pila vacía" << endl;
        return -1;
    }
    return p->datos[p->tope];
}

int main() {
    Pila miPila;
    crear(&miPila);
    
    push(&miPila, 10);
    push(&miPila, 20);
    push(&miPila, 30);
    
    cout << "Tope: " << top(&miPila) << endl;  // 30
    cout << "Pop: " << pop(&miPila) << endl;    // 30
    cout << "Pop: " << pop(&miPila) << endl;    // 20
    cout << "Tope: " << top(&miPila) << endl;   // 10
    
    return 0;
}
```

**Clave:** `tope = -1` indica pila vacía. `tope = MAX-1` indica pila llena.

### Ejemplo 2: Pila con lista enlazada

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

struct NODO {
    int valor;
    NODO* sgte;
};

NODO* tope = NULL;  // pila vacía

void push(int dato) {
    NODO* nuevo = (NODO*)malloc(sizeof(NODO));
    nuevo->valor = dato;
    nuevo->sgte = tope;    // nuevo apunta al antiguo tope
    tope = nuevo;           // el tope ahora es el nuevo
    // ¡Es exactamente insertarInicio de una lista!
}

int pop() {
    if (tope == NULL) {
        printf("Pila vacía!\n");
        return -1;
    }
    NODO* temp = tope;
    int val = temp->valor;
    tope = tope->sgte;     // el tope baja al siguiente
    free(temp);             // liberar el nodo eliminado
    return val;
}

int peek() {
    if (tope == NULL) {
        printf("Pila vacía!\n");
        return -1;
    }
    return tope->valor;
}

bool estaVacia() {
    return tope == NULL;
}

int main() {
    push(100);
    push(200);
    push(300);
    
    printf("Tope: %d\n", peek());     // 300
    printf("Pop: %d\n", pop());        // 300
    printf("Pop: %d\n", pop());        // 200
    printf("Vacía: %d\n", estaVacia()); // 0 (false)
    printf("Pop: %d\n", pop());        // 100
    printf("Vacía: %d\n", estaVacia()); // 1 (true)
    
    return 0;
}
```

**Observación clave:** `push` = insertar al inicio de lista. `pop` = eliminar al inicio de lista. ¡La pila ES una lista que solo opera en la cabeza!

### Ejemplo 3: Verificar paréntesis balanceados (aplicación clásica)

**Enunciado:** Verificar si una expresión tiene paréntesis balanceados. Ej: `((a+b)*c)` → ✅, `((a+b)` → ❌

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;
char pila[MAX];
int tope = -1;

void push(char c)    { pila[++tope] = c; }
char pop()           { return pila[tope--]; }
bool estaVacia()     { return tope == -1; }

bool verificarParentesis(const char* expr) {
    tope = -1;  // reiniciar pila
    
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(') {
            push('(');              // abrir: apilar
        }
        else if (expr[i] == ')') {
            if (estaVacia()) {
                return false;       // ')' sin '(' previo
            }
            pop();                  // cerrar: desapilar
        }
    }
    
    return estaVacia();  // si la pila está vacía, todo cerró bien
}

int main() {
    cout << "((a+b)*c): " << verificarParentesis("((a+b)*c)") << endl;   // 1 ✓
    cout << "((a+b): "    << verificarParentesis("((a+b)")    << endl;    // 0 ✗
    cout << "a+b): "      << verificarParentesis("a+b)")      << endl;    // 0 ✗
    return 0;
}
```

---

## 3. EJERCICIOS PARA PRACTICAR

**Ejercicio 8.1 (Fácil):** ¿Cuál es el estado de la pila después de estas operaciones?
```
push(5), push(10), pop(), push(15), push(20), pop(), pop()
```
¿Qué queda en la pila? ¿Qué valores devolvió cada pop?

**Ejercicio 8.2 (Medio):** Implemente una función `void invertirArreglo(int arr[], int n)` que use una pila para invertir un arreglo. (Push todos, luego pop todos de vuelta al arreglo.)

**Ejercicio 8.3 (Medio):** Extienda el verificador de paréntesis del Ejemplo 3 para que soporte `()`, `[]` y `{}`. Cada tipo de cierre debe corresponder con su apertura.

**Ejercicio 8.4 (Difícil — tipo examen):** Use una pila para convertir un número decimal a binario. (Dividir entre 2 repetidamente, apilar los restos, luego desapilar para obtener el binario.)

**Ejercicio 8.5 (Tipo examen):** Dada una pila de enteros, escriba una función que devuelva el valor mínimo de la pila SIN destruirla (use una pila auxiliar para restaurarla).

---

## 4. PATRONES DE EXAMEN

- **Traza de operaciones:** Te dan push/pop/top y piden el estado de la pila. → Dibuja la pila como una torre vertical.
- **Implementar push/pop:** Completar código. → Recuerda: `tope = -1` vacía (arreglo), `tope = NULL` vacía (lista).
- **Aplicación con paréntesis:** Muy frecuente. → `(` = push, `)` = pop. Al final, pila vacía = balanceado.
- **Conversión decimal a binario:** Dividir entre 2, apilar restos, desapilar. → Es un ejercicio estrella.
- **Truco para examen:** Si ves "LIFO" o "último en entrar, primero en salir" → PILA. Si ves "deshacer", "recursión", "paréntesis" → PILA.

### Chuleta de repaso rápido
```
PILA = LIFO (Last In, First Out)
Solo opera en el TOPE.

CON ARREGLO:
  tope = -1 → vacía
  push: datos[++tope] = valor
  pop:  return datos[tope--]

CON LISTA ENLAZADA:
  tope = NULL → vacía
  push = insertarInicio
  pop  = eliminarInicio (con delete/free)

Todas las operaciones: O(1)
Overflow = push en pila llena
Underflow = pop en pila vacía
```
