# TEMA 4: ARCHIVOS EN C/C++

---

## 1. TEORÍA CLARA

### ¿Qué es?
Los archivos permiten **persistencia**: los datos sobreviven al cierre del programa. Sin archivos, todo lo que el programa calcula se pierde al terminar.

### Dos mundos: C vs C++

| Aspecto | Estilo C | Estilo C++ |
|---------|----------|------------|
| Abrir | `fopen("archivo", "modo")` | `ofstream f("archivo")` / `ifstream f("archivo")` |
| Escribir texto | `fprintf(f, "...")` | `f << "..."` |
| Leer texto | `fscanf(f, "...")` | `f >> var` / `getline(f, str)` |
| Escribir binario | `fwrite(&dato, tam, n, f)` | `f.write((char*)&dato, sizeof(dato))` |
| Leer binario | `fread(&dato, tam, n, f)` | `f.read((char*)&dato, sizeof(dato))` |
| Cerrar | `fclose(f)` | `f.close()` |
| Tipo | `FILE*` | `fstream`, `ofstream`, `ifstream` |

### Modos de apertura (estilo C)

| Modo | Significado |
|------|-------------|
| `"r"` | Leer (el archivo debe existir) |
| `"w"` | Escribir (crea o BORRA contenido anterior) |
| `"a"` | Agregar al final (no borra) |
| `"rb"`, `"wb"`, `"ab"` | Lo mismo pero en modo binario |
| `"r+"` | Leer y escribir |

### Modos de apertura (estilo C++)

| Modo | Significado |
|------|-------------|
| `ios::in` | Leer |
| `ios::out` | Escribir (borra contenido previo) |
| `ios::app` | Agregar al final |
| `ios::binary` | Modo binario |
| Se combinan con `\|` | `ios::out \| ios::binary` |

### Texto vs Binario

| | Texto | Binario |
|--|-------|---------|
| Legible por humanos | ✅ Sí | ❌ No |
| Velocidad | Más lento | Más rápido |
| Guardar struct completo | Difícil (campo por campo) | Fácil (`fwrite`/`write`) |
| Tamaño | Mayor (caracteres ASCII) | Menor (bytes puros) |
| Uso típico | Logs, CSV, configuración | Base de datos, registros |

### Errores comunes
- No verificar si el archivo abrió: `if (f == NULL)` o `if (!f.is_open())`
- Olvidar `fclose`/`close()` → datos pueden quedar en el buffer sin escribirse
- Usar `"w"` / `ios::out` sin querer y BORRAR todo el archivo
- Mezclar `fprintf` con `<<` (no mezclar estilos C y C++)

---

## 2. EJEMPLOS RESUELTOS

### Ejemplo 1: Guardar y leer alumnos en archivo binario (estilo C)

**Enunciado:** Guardar un arreglo de alumnos en un archivo binario con `fwrite` y luego leerlos con `fread`.

```cpp
#include <cstdio>
#include <cstring>
using namespace std;

struct Alumno {
    int codigo;
    char nombre[30];
    float nota;
};

// GUARDAR en archivo binario
void guardarAlumnos(Alumno arr[], int n) {
    FILE* f = fopen("alumnos.bin", "wb");  // "wb" = write binary
    if (f == NULL) {
        printf("Error al abrir archivo!\n");
        return;
    }
    
    // fwrite(origen, tamaño_de_1_elemento, cantidad, archivo)
    fwrite(arr, sizeof(Alumno), n, f);
    
    fclose(f);
    printf("Guardados %d alumnos.\n", n);
}

// LEER desde archivo binario
int leerAlumnos(Alumno arr[], int maxN) {
    FILE* f = fopen("alumnos.bin", "rb");  // "rb" = read binary
    if (f == NULL) {
        printf("Archivo no encontrado!\n");
        return 0;
    }
    
    int n = 0;
    // fread devuelve cuántos elementos leyó
    while (fread(&arr[n], sizeof(Alumno), 1, f) == 1 && n < maxN) {
        n++;
    }
    
    fclose(f);
    return n;
}

int main() {
    // Guardar
    Alumno datos[3] = {
        {101, "Pedro", 15.5},
        {102, "Maria", 18.0},
        {103, "Juan",  12.3}
    };
    guardarAlumnos(datos, 3);
    
    // Leer
    Alumno leidos[10];
    int n = leerAlumnos(leidos, 10);
    
    printf("\n--- Leídos del archivo ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d - %s - %.1f\n", leidos[i].codigo, 
               leidos[i].nombre, leidos[i].nota);
    }
    return 0;
}
```

**Paso a paso:**
1. `fwrite(arr, sizeof(Alumno), 3, f)` → escribe 3 bloques de `sizeof(Alumno)` bytes.
2. `fread(&arr[n], sizeof(Alumno), 1, f)` → lee 1 bloque. Devuelve 1 si tuvo éxito, 0 si fin de archivo.
3. El archivo binario guarda los bytes EXACTOS del struct en memoria.

### Ejemplo 2: Archivo de texto con C++ streams

**Enunciado:** Guardar nombres y notas en un archivo de texto, luego leerlos y mostrar solo los aprobados.

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // ESCRIBIR
    ofstream fout("notas.txt");
    if (!fout.is_open()) { cout << "Error!\n"; return 1; }
    
    fout << "Pedro 15.5" << endl;
    fout << "Maria 18.0" << endl;
    fout << "Juan 9.5" << endl;
    fout.close();
    
    // LEER y filtrar
    ifstream fin("notas.txt");
    if (!fin.is_open()) { cout << "Error!\n"; return 1; }
    
    string nombre;
    float nota;
    cout << "--- Aprobados ---" << endl;
    while (fin >> nombre >> nota) {   // lee hasta fin de archivo
        if (nota >= 11.0) {
            cout << nombre << ": " << nota << endl;
        }
    }
    fin.close();
    
    return 0;
}
```

---

## 3. EJERCICIOS PARA PRACTICAR

**Ejercicio 4.1 (Fácil):** Escriba un programa que guarde 5 números enteros en un archivo de texto (uno por línea) y luego los lea e imprima su suma.

**Ejercicio 4.2 (Medio):** Defina un struct `Producto` (código, nombre, precio). Guarde un arreglo de productos en un archivo binario con `fwrite`. Luego léalos con `fread` y muestre los que cuestan más de S/. 50.

**Ejercicio 4.3 (Medio):** Modifique el Ejercicio 4.2 para que nuevos productos se **agreguen** al final del archivo (use modo `"ab"`), sin borrar los anteriores.

**Ejercicio 4.4 (Tipo examen):** Se tiene un archivo binario de registros `Alumno` (código, nombre, nota). Escriba un subprograma que lea todos los registros y separe a los aprobados en un nuevo archivo "aprobados.bin" y los desaprobados en "desaprobados.bin".

---

## 4. PATRONES DE EXAMEN

- **Guardar/leer structs de archivo binario:** El patrón más común. → `fwrite(&reg, sizeof(struct), 1, f)` y `fread` en un while.
- **Filtrar registros:** Leer de un archivo y escribir a otro solo los que cumplen una condición. → Es un `while(fread...) { if(condición) fwrite... }`.
- **Combinar con arreglos:** Leer archivo → cargar en arreglo de structs → procesar → guardar resultado.
- **Truco:** En examen, si te piden "persistencia", están pidiendo archivos. Si dicen "archivo secuencial", es un archivo que se lee de inicio a fin (fread en bucle).

### Chuleta de repaso rápido
```
ESTILO C:
  FILE* f = fopen("nombre", "modo");
  fwrite(&dato, sizeof(tipo), n, f);   // escribir
  fread(&dato, sizeof(tipo), 1, f);    // leer (devuelve cant leída)
  fclose(f);

ESTILO C++:
  ofstream fout("nombre");  // escribir
  ifstream fin("nombre");   // leer
  fout << dato;  fin >> var;
  f.write((char*)&dato, sizeof);
  f.read((char*)&dato, sizeof);
  f.close();

MODOS: "r"=leer  "w"=escribir(BORRA)  "a"=agregar  "b"=binario
SIEMPRE verificar apertura. SIEMPRE cerrar.
```
