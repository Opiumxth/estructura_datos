# TEMA 3: MEMORIA DINÁMICA

---

## 1. TEORÍA CLARA

### ¿Qué es?
Memoria dinámica es memoria que **tú pides y liberas manualmente** durante la ejecución del programa. Vive en el **heap** (montículo), a diferencia de las variables locales que viven en el **stack**.

### ¿Para qué sirve?
- Crear arreglos cuyo tamaño NO conoces al compilar.
- Crear nodos para listas, pilas y colas (que crecen y se reducen).
- Cuando los datos deben sobrevivir al final de una función.

### Stack vs Heap

| | Stack (Pila del sistema) | Heap (Montículo) |
|--|--------------------------|-------------------|
| Gestión | Automática | Manual (`new`/`delete` o `malloc`/`free`) |
| Velocidad | Muy rápida | Más lenta |
| Tamaño | Limitado (~1-8 MB) | Grande (GBs) |
| Vida | Se destruye al salir de la función | Vive hasta que TÚ lo liberes |
| Riesgo | Stack overflow si se excede | Memory leak si no liberas |

### Dos estilos (ambos válidos en el curso)

**Estilo C (el que usa el profesor):**
```cpp
NODO* p = (NODO*)malloc(sizeof(NODO));   // reservar
if (p == NULL) { /* error */ }
free(p);                                  // liberar
```

**Estilo C++:**
```cpp
NODO* p = new NODO;    // reservar (más limpio)
delete p;               // liberar

int* arr = new int[n];  // arreglo dinámico
delete[] arr;            // liberar arreglo (NUNCA usar delete sin [])
```

### Errores comunes

| Error | Nombre técnico | Consecuencia |
|-------|---------------|--------------|
| Nunca hacer `free`/`delete` | Memory leak | El programa consume más y más RAM |
| Usar memoria después de liberar | Dangling pointer | Datos corruptos o CRASH |
| `delete` dos veces | Double free | CRASH |
| `delete` en vez de `delete[]` | Undefined behavior | Puede funcionar... o no |
| `free` algo que vino de `new` | Mezcla de estilos | Undefined behavior |

---

## 2. EJEMPLOS RESUELTOS

### Ejemplo 1: Arreglo dinámico de alumnos

**Enunciado:** Pida al usuario cuántos alumnos registrar, cree un arreglo dinámico de structs, llénelo e imprima los aprobados (nota >= 11).

```cpp
#include <iostream>
using namespace std;

struct Alumno {
    int codigo;
    char nombre[50];
    float nota;
};

int main() {
    int n;
    cout << "¿Cuántos alumnos? "; cin >> n;
    
    // Reservar arreglo dinámico en el heap
    Alumno* alumnos = new Alumno[n];
    
    // Llenar
    for (int i = 0; i < n; i++) {
        cout << "Código: "; cin >> alumnos[i].codigo;
        cout << "Nombre: "; cin >> alumnos[i].nombre;
        cout << "Nota: ";   cin >> alumnos[i].nota;
    }
    
    // Mostrar aprobados
    cout << "\n--- APROBADOS ---\n";
    for (int i = 0; i < n; i++) {
        if (alumnos[i].nota >= 11.0) {
            cout << alumnos[i].codigo << " - " 
                 << alumnos[i].nombre << " - " 
                 << alumnos[i].nota << endl;
        }
    }
    
    // LIBERAR — obligatorio
    delete[] alumnos;
    alumnos = nullptr;  // buena práctica
    
    return 0;
}
```

**Paso a paso:**
1. `new Alumno[n]` → reserva `n * sizeof(Alumno)` bytes en el heap.
2. Se usa `alumnos[i]` como un arreglo normal.
3. `delete[] alumnos` → libera TODO el bloque. Sin los `[]` es CRASH.

### Ejemplo 2: Crear y liberar una cadena de nodos

**Enunciado:** Cree 3 nodos enlazados dinámicamente y luego libere toda la memoria.

```cpp
#include <iostream>
using namespace std;

struct NODO {
    int valor;
    NODO* sgte;
};

NODO* crearNodo(int dato) {
    NODO* p = new NODO;
    p->valor = dato;
    p->sgte = NULL;
    return p;
}

void liberarLista(NODO* cab) {
    NODO* temp;
    while (cab != NULL) {
        temp = cab;           // guardar referencia
        cab = cab->sgte;      // avanzar ANTES de borrar
        delete temp;          // liberar el nodo
    }
}

int main() {
    // Crear 3 nodos: 10 -> 20 -> 30 -> NULL
    NODO* cab = crearNodo(10);
    cab->sgte = crearNodo(20);
    cab->sgte->sgte = crearNodo(30);
    
    // Recorrer
    NODO* p = cab;
    while (p != NULL) {
        cout << p->valor << " -> ";
        p = p->sgte;
    }
    cout << "NULL" << endl;
    
    // Liberar toda la lista
    liberarLista(cab);
    cab = NULL;
    
    return 0;
}
```

**Clave en la liberación:** SIEMPRE guardar `cab` en `temp` ANTES de avanzar, porque después de `delete temp` ya no puedes acceder a `temp->sgte`.

---

## 3. EJERCICIOS PARA PRACTICAR

**Ejercicio 3.1 (Fácil):** Reserve memoria para un entero con `new`, asígnele un valor, imprímalo y libere la memoria. Verifique que funciona.

**Ejercicio 3.2 (Medio):** Cree un arreglo dinámico de `n` flotantes. Calcule el promedio y luego libere la memoria. Use `new float[n]` y `delete[]`.

**Ejercicio 3.3 (Medio):** Convierta el Ejemplo 2 para usar `malloc`/`free` en vez de `new`/`delete` (estilo del profesor).

**Ejercicio 3.4 (Tipo examen):** ¿Qué problemas tiene este código? Identifique TODOS los errores:
```cpp
int* p = new int[10];
int* q = p;
delete p;     // Error 1: ¿cuál?
q[5] = 42;    // Error 2: ¿cuál?
delete[] q;   // Error 3: ¿cuál?
```

---

## 4. PATRONES DE EXAMEN

- **Detectar memory leaks:** Te muestran código y preguntan dónde se pierde memoria. → Busca todo `new`/`malloc` y verifica que tenga su `delete`/`free`.
- **Orden de liberación:** En listas, siempre liberar de adelante hacia atrás guardando `temp`. → Si el examen pide "liberar la lista", escribe el while con `temp`.
- **`new` vs `malloc`:** Pueden preguntar diferencias. `new` llama al constructor, `malloc` no. `new` devuelve el tipo correcto, `malloc` devuelve `void*`.
- **Truco:** Si ves `NODO** cab` en la firma de una función, es porque la función puede cambiar a dónde apunta `cab` (ej: insertar al inicio).

### Chuleta de repaso rápido
```
new T        → reserva 1 elemento     → delete p
new T[n]     → reserva n elementos    → delete[] p
malloc(size) → reserva size bytes     → free(p)

Stack = automático, rápido, limitado
Heap = manual, grande, riesgo de leak

Después de delete/free → poner puntero a NULL/nullptr
Para liberar lista: while con temp (guardar antes de borrar)
```
