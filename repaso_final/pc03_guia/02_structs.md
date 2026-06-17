# TEMA 2: STRUCTS

---

## 1. TEORÍA CLARA

### ¿Qué es un struct?
Un struct agrupa **variables de distintos tipos** bajo un solo nombre. Es la forma de modelar entidades del mundo real.

En **pseudocódigo** se llama `REGISTRO`. En **C/C++** se llama `struct`.

### ¿Para qué sirve?
- **Modelar entidades:** Un `Alumno` tiene código, nombre y nota. En vez de 3 variables sueltas, las empaquetas en un struct.
- **Crear nodos:** El struct `NODO` con `dato` + `*sgte` es la pieza fundamental de listas, pilas y colas.
- **Guardar/leer de archivos:** Un struct se escribe/lee completo de un archivo binario con `write()`/`read()`.

### Cómo funciona internamente
El compilador reserva espacio contiguo para todos los campos. El tamaño total es la suma de los campos (con posible padding por alineación).

```
struct Alumno { int codigo; char nombre[20]; float nota; };

Memoria de un Alumno:
[  4 bytes  |     20 bytes      | 4 bytes ]
   codigo       nombre             nota
```

### Acceso: punto vs flecha

| Situación | Operador | Ejemplo |
|-----------|----------|---------|
| Variable directa del struct | `.` | `a1.codigo = 101;` |
| Puntero al struct | `->` | `ptr->codigo = 101;` |

**Regla infalible:** `ptr->campo` es lo mismo que `(*ptr).campo`.

### El Nodo: el struct más importante del curso

**Pseudocódigo:**
```
REGISTRO NODO
   TD valor
   NODO sgte
FIN_REGISTRO
```

**C/C++:**
```cpp
typedef int TD;
struct NODO {
    int valor;       // el dato que guarda
    NODO* sgte;      // puntero al siguiente nodo (autorreferencia)
};
```

> Este struct ES la pieza de LEGO con la que construyes listas, pilas, colas y árboles.

### Errores comunes
- Usar `.` con un puntero → error de compilación. Usa `->`.
- Olvidar `sgte = NULL` al crear un nodo → puntero basura → CRASH al recorrer.
- Olvidar el `;` al cerrar el struct → errores de compilación crípticos.

---

## 2. EJEMPLOS RESUELTOS

### Ejemplo 1: Registro de alumnos con struct

**Enunciado:** Defina un struct `Alumno` con código, nombre y nota. Cree un arreglo de 3 alumnos, llénelos y muestre el de mayor nota.

```cpp
#include <iostream>
#include <cstring>
using namespace std;

struct Alumno {
    int codigo;
    char nombre[50];
    float nota;
};

int main() {
    Alumno alumnos[3];
    
    // Llenar datos
    for (int i = 0; i < 3; i++) {
        cout << "Código: "; cin >> alumnos[i].codigo;
        cout << "Nombre: "; cin >> alumnos[i].nombre;
        cout << "Nota: ";   cin >> alumnos[i].nota;
    }
    
    // Buscar el mayor
    int posMayor = 0;
    for (int i = 1; i < 3; i++) {
        if (alumnos[i].nota > alumnos[posMayor].nota)
            posMayor = i;
    }
    
    cout << "Mejor alumno: " << alumnos[posMayor].nombre
         << " con nota " << alumnos[posMayor].nota << endl;
    return 0;
}
```

**Paso a paso:**
1. `Alumno alumnos[3]` → reserva espacio para 3 structs contiguos.
2. Se accede con `alumnos[i].campo` porque son variables directas (no punteros).
3. Se compara `nota` como cualquier número.

### Ejemplo 2: Crear un nodo dinámico con puntero

**Enunciado:** Cree una función `crearNodo` que reserve memoria para un NODO, le asigne un valor y devuelva el puntero. (Estilo del profesor Salinas.)

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

typedef int TD;  // Tipo de dato genérico

struct NODO {
    TD valor;
    NODO* sgte;
};

NODO* crearNodo(TD dato) {
    NODO* p = (NODO*)malloc(sizeof(NODO));  // estilo C del curso
    if (p == NULL) {
        printf("No hay espacio de memoria!\n");
        return NULL;
    }
    p->valor = dato;
    p->sgte = NULL;    // MUY IMPORTANTE: inicializar a NULL
    return p;
}

int main() {
    NODO* n1 = crearNodo(42);
    NODO* n2 = crearNodo(99);
    
    n1->sgte = n2;  // enlazar: n1 apunta a n2
    
    // Recorrer
    NODO* temp = n1;
    while (temp != NULL) {
        cout << temp->valor << " -> ";
        temp = temp->sgte;
    }
    cout << "NULL" << endl;
    // Salida: 42 -> 99 -> NULL
    
    free(n2);  // liberar en orden inverso
    free(n1);
    return 0;
}
```

**Clave:** `p->sgte = NULL` es obligatorio. Si no lo haces, el puntero `sgte` contiene basura y al recorrer la lista harás CRASH.

---

## 3. EJERCICIOS PARA PRACTICAR

**Ejercicio 2.1 (Fácil):** Defina un struct `Producto` con campos `codigo` (int), `nombre` (char[30]) y `precio` (float). Cree una variable, llénela e imprímala.

**Ejercicio 2.2 (Medio):** Defina un struct `Fecha` con `dia`, `mes`, `año`. Escriba una función `bool esMayor(Fecha f1, Fecha f2)` que devuelva `true` si `f1` es posterior a `f2`.

**Ejercicio 2.3 (Medio):** Dado un arreglo de structs `Empleado` (nombre, salario, departamento), escriba funciones para:
- Mostrar todos los empleados de un departamento dado.
- Calcular el salario promedio.
- Encontrar el empleado con mayor salario.

**Ejercicio 2.4 (Ambos):** Escriba la función `crearNodo` primero en pseudocódigo y luego en C/C++ usando `new`. ¿Qué cambia respecto a `malloc`?

---

## 4. PATRONES DE EXAMEN

- **Definir structs:** Te piden modelar una entidad con campos específicos. → Lee bien qué campos piden y qué tipos.
- **Operar sobre arreglos de structs:** Filtrar, buscar el mayor, calcular promedios. → Es como operar sobre un arreglo normal pero accediendo con `.campo`.
- **Struct + puntero:** Te piden crear nodos y enlazarlos. → Siempre `nuevo->sgte = NULL` al crear.
- **Truco:** Si te dicen "defina la estructura" en un examen, esperan ver el struct Y los prototipos de función. No solo el struct.

### Chuleta de repaso rápido
```
struct = agrupa variables de distintos tipos
. = acceso directo (variable)
-> = acceso por puntero (equivale a (*ptr).campo)
NODO = { dato, NODO* sgte }  ← BASE de listas/pilas/colas
typedef int TD  ← estilo del curso para generalizar el tipo
Siempre: nuevo->sgte = NULL al crear un nodo
```
