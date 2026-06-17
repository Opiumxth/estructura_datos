# 🎯 SIMULACRO DE EXAMEN PC02

> **Tiempo sugerido:** 90 minutos
> **Instrucciones:** Resuelve sin consultar apuntes. Al terminar, revisa las soluciones.

---

## PARTE I: TEÓRICA (30 puntos)

### Pregunta 1 (6 pts)
Responda Verdadero o Falso. Justifique las falsas.

a) Un puntero almacena el valor de una variable.
b) La búsqueda binaria funciona con datos desordenados pero es más lenta.
c) En una pila, el primer elemento insertado es el último en salir.
d) El algoritmo de Inserción tiene complejidad O(n) en el mejor caso.
e) En una cola con lista enlazada, al hacer dequeue y quedar vacía, se debe actualizar tanto `frente` como `final` a NULL.
f) `delete[]` se usa para liberar un solo puntero creado con `new`.

### Pregunta 2 (6 pts)
Complete la siguiente tabla:

| Estructura | Política | Insertar | Eliminar | Buscar |
|------------|----------|----------|----------|--------|
| Arreglo    | ___      | ___      | ___      | ___    |
| Pila       | ___      | ___      | ___      | ___    |
| Cola       | ___      | ___      | ___      | ___    |
| Lista Simple | ___   | ___      | ___      | ___    |

### Pregunta 3 (6 pts)
Explique con sus propias palabras:
a) ¿Por qué se usa doble puntero (`NODO** cab`) al pasar la cabeza de una lista a una función?
b) ¿Qué es un memory leak? Dé un ejemplo en código de 2 líneas.
c) ¿En qué caso Insertion Sort es más eficiente que Selection Sort?

### Pregunta 4 (6 pts)
Trace la búsqueda binaria del valor **25** en el arreglo:
`{3, 7, 12, 18, 25, 31, 42, 56}`

Complete la tabla:

| Iteración | inicio | fin | medio | arr[medio] | Acción |
|-----------|--------|-----|-------|------------|--------|
| 1         |        |     |       |            |        |
| 2         |        |     |       |            |        |
| ...       |        |     |       |            |        |

### Pregunta 5 (6 pts)
Dada la siguiente secuencia de operaciones sobre una pila (inicialmente vacía) y una cola (inicialmente vacía):

**Pila:** push(5), push(10), push(15), pop(), push(20), pop(), pop()
**Cola:** enqueue(5), enqueue(10), enqueue(15), dequeue(), enqueue(20), dequeue(), dequeue()

a) ¿Qué valores devolvió cada pop de la pila?
b) ¿Qué valores devolvió cada dequeue de la cola?
c) ¿Qué queda en la pila? ¿Qué queda en la cola?

---

## PARTE II: PRÁCTICA (70 puntos)

### Problema 1 (20 pts): Archivos + Structs + Ordenamiento

Se tiene el siguiente struct:
```cpp
struct Empleado {
    int codigo;
    char nombre[30];
    float salario;
};
```

Se pide:
1. **(5 pts)** Declare los prototipos de las funciones necesarias.
2. **(5 pts)** Implemente un subprograma que lea un arreglo de `n` empleados desde un archivo binario "empleados.bin" usando `fread`.
3. **(5 pts)** Implemente un subprograma que ordene el arreglo de empleados de mayor a menor salario usando el método de **Selección**.
4. **(5 pts)** Implemente un subprograma que guarde en un nuevo archivo binario "altos.bin" solo los empleados con salario mayor a un valor dado.

### Problema 2 (25 pts): Lista Enlazada con Structs

Se tiene:
```cpp
struct Alumno {
    int codigo;
    char nombre[30];
    float promedio;
};

struct NODO {
    Alumno dato;
    NODO* sgte;
};
```

Implemente las siguientes funciones:

1. **(5 pts)** `NODO* crearNodo(Alumno a)` — Crea un nodo con los datos del alumno.
2. **(5 pts)** `void insertarOrdenado(NODO** cab, Alumno a)` — Inserta manteniendo la lista ordenada por código de menor a mayor.
3. **(5 pts)** `void mostrarAprobados(NODO* cab)` — Muestra solo los alumnos con promedio >= 11.0 con formato: `"Código - Nombre - Promedio"`.
4. **(5 pts)** `NODO* buscarAlumno(NODO* cab, int codigo)` — Busca un alumno por código y devuelve el puntero al nodo, o NULL si no existe.
5. **(5 pts)** `void eliminarAlumno(NODO** cab, int codigo)` — Elimina el nodo con el código dado. Manejar: lista vacía, primer nodo, nodo intermedio/final, no encontrado.

### Problema 3 (25 pts): Pila + Cola aplicados

Una empresa de soporte técnico recibe tickets que se procesan así:
- Los tickets **urgentes** van a una **PILA** (se atiende el último urgente primero).
- Los tickets **normales** van a una **COLA** (se atiende por orden de llegada).

```cpp
struct Ticket {
    int id;
    char descripcion[50];
    char tipo;  // 'U' = urgente, 'N' = normal
};
```

Implemente:
1. **(5 pts)** Las estructuras de datos necesarias (Nodo para pila, Nodo para cola con frente/final).
2. **(5 pts)** `void recibirTicket(Ticket t)` — Si es urgente, push a la pila. Si es normal, enqueue a la cola.
3. **(5 pts)** `Ticket atenderTicket()` — Primero atiende urgentes (pop de pila). Si no hay urgentes, atiende normales (dequeue de cola). Si no hay ninguno, mostrar mensaje.
4. **(5 pts)** `void mostrarPendientes()` — Muestra cuántos tickets urgentes y normales hay pendientes.
5. **(5 pts)** Escriba el `main()` con un menú: 1) Recibir ticket, 2) Atender ticket, 3) Ver pendientes, 4) Salir.

---

---

# ✅ SOLUCIONES DEL SIMULACRO

---

## PARTE I: SOLUCIONES TEÓRICAS

### Pregunta 1
a) **FALSO** — Un puntero almacena una **dirección de memoria**, no un valor.
b) **FALSO** — La búsqueda binaria **NO funciona** con datos desordenados. Da resultados incorrectos.
c) **VERDADERO** — Es la definición de LIFO.
d) **VERDADERO** — Cuando el arreglo ya está ordenado, no hay desplazamientos.
e) **VERDADERO** — Si no actualizas `final`, queda como dangling pointer.
f) **FALSO** — `delete[]` se usa para liberar arreglos creados con `new T[n]`. Para un solo puntero se usa `delete`.

### Pregunta 2

| Estructura | Política | Insertar | Eliminar | Buscar |
|------------|----------|----------|----------|--------|
| Arreglo | Libre | O(1)/O(n) | O(1)/O(n) | O(n)/O(log n) |
| Pila | **LIFO** | **O(1)** | **O(1)** | O(n) |
| Cola | **FIFO** | **O(1)** | **O(1)** | O(n) |
| Lista Simple | Libre | **O(1)**\* | **O(1)**\* | O(n) |

\*Al inicio.

### Pregunta 3

a) Porque necesitamos modificar el **puntero original** (`cab`), no una copia. Si pasamos `NODO* cab`, la función recibe una copia y los cambios se pierden al terminar. Con `NODO** cab`, pasamos la dirección del puntero y podemos modificar a dónde apunta.

b) Memory leak = memoria reservada que nunca se libera. Ejemplo:
```cpp
int* p = new int(42);
p = new int(99);    // ← se perdió la dirección del primer new, esos 4 bytes jamás se liberan
```

c) Insertion Sort es más eficiente cuando los datos están **casi ordenados**, porque su mejor caso es O(n) (solo recorre sin desplazar). Selection Sort SIEMPRE es O(n²) sin importar el estado de los datos.

### Pregunta 4

Arreglo: `{3, 7, 12, 18, 25, 31, 42, 56}`, buscar 25:

| Iteración | inicio | fin | medio | arr[medio] | Acción |
|-----------|--------|-----|-------|------------|--------|
| 1 | 0 | 7 | 3 | 18 | 18 < 25 → inicio = 4 |
| 2 | 4 | 7 | 5 | 31 | 31 > 25 → fin = 4 |
| 3 | 4 | 4 | 4 | 25 | 25 == 25 → **ENCONTRADO pos 4** |

Total: 3 iteraciones.

### Pregunta 5

**Pila:** push(5), push(10), push(15), pop()→**15**, push(20), pop()→**20**, pop()→**10**
Estado final pila: `[5]`

**Cola:** enqueue(5), enqueue(10), enqueue(15), dequeue()→**5**, enqueue(20), dequeue()→**10**, dequeue()→**15**
Estado final cola: `[20]`

a) Pop devolvió: 15, 20, 10
b) Dequeue devolvió: 5, 10, 15
c) Pila: queda [5]. Cola: queda [20].

> Nota cómo la **pila** devolvió los últimos insertados (LIFO) y la **cola** devolvió los primeros insertados (FIFO).

---

## PARTE II: SOLUCIONES PRÁCTICAS

### Problema 1: Solución

```cpp
#include <cstdio>
#include <cstring>
using namespace std;

struct Empleado {
    int codigo;
    char nombre[30];
    float salario;
};

// 1. Prototipos
int leerEmpleados(Empleado arr[], int maxN);
void ordenarPorSalario(Empleado arr[], int n);
void guardarSalarioAlto(Empleado arr[], int n, float minSalario);

// 2. Leer desde archivo binario
int leerEmpleados(Empleado arr[], int maxN) {
    FILE* f = fopen("empleados.bin", "rb");
    if (f == NULL) {
        printf("Error al abrir archivo\n");
        return 0;
    }
    int n = 0;
    while (fread(&arr[n], sizeof(Empleado), 1, f) == 1 && n < maxN) {
        n++;
    }
    fclose(f);
    return n;
}

// 3. Ordenar por salario DESCENDENTE con Selección
void ordenarPorSalario(Empleado arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].salario > arr[maxIdx].salario) {  // > para descendente
                maxIdx = j;
            }
        }
        // Intercambiar structs completos
        Empleado temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

// 4. Guardar empleados con salario mayor al dado
void guardarSalarioAlto(Empleado arr[], int n, float minSalario) {
    FILE* f = fopen("altos.bin", "wb");
    if (f == NULL) {
        printf("Error al crear archivo\n");
        return;
    }
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].salario > minSalario) {
            fwrite(&arr[i], sizeof(Empleado), 1, f);
            cont++;
        }
    }
    fclose(f);
    printf("Guardados %d empleados con salario > %.2f\n", cont, minSalario);
}
```

### Problema 2: Solución

```cpp
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Alumno {
    int codigo;
    char nombre[30];
    float promedio;
};

struct NODO {
    Alumno dato;
    NODO* sgte;
};

// 1. Crear nodo
NODO* crearNodo(Alumno a) {
    NODO* p = (NODO*)malloc(sizeof(NODO));
    if (p == NULL) {
        printf("Sin memoria!\n");
        return NULL;
    }
    p->dato = a;        // copiar struct completo
    p->sgte = NULL;
    return p;
}

// 2. Insertar ordenado por código
void insertarOrdenado(NODO** cab, Alumno a) {
    NODO* nuevo = crearNodo(a);
    if (nuevo == NULL) return;
    
    // Caso 1: lista vacía o insertar antes del primero
    if (*cab == NULL || a.codigo < (*cab)->dato.codigo) {
        nuevo->sgte = *cab;
        *cab = nuevo;
        return;
    }
    
    // Caso 2: buscar posición correcta
    NODO* temp = *cab;
    while (temp->sgte != NULL && temp->sgte->dato.codigo < a.codigo) {
        temp = temp->sgte;
    }
    
    // Insertar después de temp
    nuevo->sgte = temp->sgte;
    temp->sgte = nuevo;
}

// 3. Mostrar aprobados
void mostrarAprobados(NODO* cab) {
    NODO* temp = cab;
    int cont = 0;
    printf("\n--- ALUMNOS APROBADOS ---\n");
    while (temp != NULL) {
        if (temp->dato.promedio >= 11.0) {
            printf("%d - %s - %.1f\n", 
                   temp->dato.codigo,
                   temp->dato.nombre,
                   temp->dato.promedio);
            cont++;
        }
        temp = temp->sgte;
    }
    printf("Total aprobados: %d\n", cont);
}

// 4. Buscar alumno por código
NODO* buscarAlumno(NODO* cab, int codigo) {
    NODO* temp = cab;
    while (temp != NULL) {
        if (temp->dato.codigo == codigo)
            return temp;      // encontrado
        temp = temp->sgte;
    }
    return NULL;              // no encontrado
}

// 5. Eliminar alumno por código
void eliminarAlumno(NODO** cab, int codigo) {
    if (*cab == NULL) {
        printf("Lista vacía\n");
        return;
    }
    
    // Caso: eliminar el primero
    if ((*cab)->dato.codigo == codigo) {
        NODO* temp = *cab;
        *cab = (*cab)->sgte;
        printf("Eliminado alumno %d\n", codigo);
        free(temp);
        return;
    }
    
    // Caso: buscar en el resto
    NODO* anterior = *cab;
    NODO* actual = (*cab)->sgte;
    
    while (actual != NULL && actual->dato.codigo != codigo) {
        anterior = actual;
        actual = actual->sgte;
    }
    
    if (actual == NULL) {
        printf("Alumno %d no encontrado\n", codigo);
        return;
    }
    
    anterior->sgte = actual->sgte;   // saltar el nodo
    printf("Eliminado alumno %d\n", codigo);
    free(actual);
}
```

### Problema 3: Solución

```cpp
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Ticket {
    int id;
    char descripcion[50];
    char tipo;  // 'U' o 'N'
};

// Nodo genérico para ambas estructuras
struct NODO {
    Ticket dato;
    NODO* sgte;
};

// 1. Estructuras
// PILA (solo tope)
NODO* pilaTope = NULL;

// COLA (frente y final)
struct Cola {
    NODO* frente;
    NODO* final_c;
};
Cola colaNormal = {NULL, NULL};

// Contadores
int contUrgentes = 0;
int contNormales = 0;

// Push a la pila de urgentes
void pushUrgente(Ticket t) {
    NODO* nuevo = (NODO*)malloc(sizeof(NODO));
    nuevo->dato = t;
    nuevo->sgte = pilaTope;
    pilaTope = nuevo;
    contUrgentes++;
}

// Enqueue a la cola de normales
void enqueueNormal(Ticket t) {
    NODO* nuevo = (NODO*)malloc(sizeof(NODO));
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
        NODO* temp = pilaTope;
        Ticket t = temp->dato;
        pilaTope = pilaTope->sgte;
        free(temp);
        contUrgentes--;
        printf("Atendido URGENTE #%d: %s\n", t.id, t.descripcion);
        return t;
    }
    
    // Luego normales (FIFO)
    if (colaNormal.frente != NULL) {
        NODO* temp = colaNormal.frente;
        Ticket t = temp->dato;
        colaNormal.frente = colaNormal.frente->sgte;
        if (colaNormal.frente == NULL)
            colaNormal.final_c = NULL;   // ← CRÍTICO
        free(temp);
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

// 5. Main con menú
int main() {
    int opcion;
    do {
        printf("\n=== SISTEMA DE TICKETS ===\n");
        printf("1. Recibir ticket\n");
        printf("2. Atender ticket\n");
        printf("3. Ver pendientes\n");
        printf("4. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1: {
                Ticket t;
                printf("ID: "); scanf("%d", &t.id);
                printf("Descripción: "); scanf(" %[^\n]", t.descripcion);
                printf("Tipo (U/N): "); scanf(" %c", &t.tipo);
                recibirTicket(t);
                break;
            }
            case 2:
                atenderTicket();
                break;
            case 3:
                mostrarPendientes();
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida\n");
        }
    } while (opcion != 4);
    
    return 0;
}
```

**Puntos clave de la solución:**
- Urgentes en **pila** (LIFO): el último urgente se atiende primero.
- Normales en **cola** (FIFO): se atienden en orden de llegada.
- Se priorizan urgentes: solo si la pila está vacía se atiende la cola.
- Al dequeue, si `frente == NULL` → `final_c = NULL`.
