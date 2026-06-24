# PRÁCTICA 02: STRUCTS

---

## Ejercicio 2.1 (Fácil) - Declaración y uso

**Enunciado:**
Defina un struct `ALUMNO` con los campos: código (entero), nombre (cadena de caracteres), nota (real). Declare una variable de este tipo, asigne valores e imprima sus campos.

**Solución en C/C++:**
```cpp
#include <iostream>
#include <cstring>
using namespace std;

struct ALUMNO {
    int codigo;
    char nombre[50];
    float nota;
};

int main() {
    ALUMNO a;
    
    a.codigo = 12345;
    strcpy(a.nombre, "Juan Perez");
    a.nota = 15.5f;
    
    cout << "Código: " << a.codigo << endl;
    cout << "Nombre: " << a.nombre << endl;
    cout << "Nota: " << a.nota << endl;
    
    return 0;
}
```

**Pseudocódigo:**
```
REGISTRO ALUMNO
   ENTERO codigo
   CADENA nombre
   REAL nota
FIN_REGISTRO

ACCION ejercicio2()
   ALUMNO a
   
   a.codigo ← 12345
   a.nombre ← "Juan Perez"
   a.nota ← 15.5
   
   ESCRIBIR("Código: ", a.codigo)
   ESCRIBIR("Nombre: ", a.nombre)
   ESCRIBIR("Nota: ", a.nota)
FIN_ACCION
```

---

## Ejercicio 2.2 (Medio) - Arreglo de structs

**Enunciado:**
Declare un arreglo de 5 alumnos. Lea los datos de cada uno y luego imprima solo aquellos con nota mayor o igual a 14.

**Solución en C/C++:**
```cpp
#include <iostream>
#include <cstring>
using namespace std;

struct ALUMNO {
    int codigo;
    char nombre[50];
    float nota;
};

int main() {
    ALUMNO alumnos[5];
    
    // Leer datos
    for (int i = 0; i < 5; i++) {
        cout << "Alumno " << i + 1 << ":" << endl;
        cout << "Código: ";
        cin >> alumnos[i].codigo;
        cin.ignore();
        cout << "Nombre: ";
        cin.getline(alumnos[i].nombre, 50);
        cout << "Nota: ";
        cin >> alumnos[i].nota;
    }
    
    // Imprimir aprobados
    cout << "\nAlumnos aprobados:" << endl;
    for (int i = 0; i < 5; i++) {
        if (alumnos[i].nota >= 14) {
            cout << alumnos[i].nombre << " - Nota: " << alumnos[i].nota << endl;
        }
    }
    
    return 0;
}
```

---

## Ejercicio 2.3 (Medio) - Punteros a structs

**Enunciado:**
Escriba una función que reciba un puntero a un struct ALUMNO y aumente su nota en 1 punto (máximo 20).

**Solución en C/C++:**
```cpp
#include <iostream>
#include <cstring>
using namespace std;

struct ALUMNO {
    int codigo;
    char nombre[50];
    float nota;
};

void aumentarNota(ALUMNO* a) {
    if (a->nota < 20) {
        a->nota += 1;
        if (a->nota > 20) {
            a->nota = 20;
        }
    }
}

int main() {
    ALUMNO a;
    a.codigo = 12345;
    strcpy(a.nombre, "Juan Perez");
    a.nota = 15.5f;
    
    cout << "Nota original: " << a.nota << endl;
    aumentarNota(&a);
    cout << "Nota aumentada: " << a.nota << endl;
    
    return 0;
}
```

**Pseudocódigo:**
```
ACCION aumentarNota(ALUMNO a)
   SI(a.nota < 20)
      a.nota ← a.nota + 1
      SI(a.nota > 20)
         a.nota ← 20
      FIN_SI
   FIN_SI
FIN_ACCION
```

---

## Ejercicio 2.4 (Difícil) - Búsqueda en arreglo de structs

**Enunciado:**
Escriba una función que busque un alumno por código en un arreglo de alumnos y retorne su índice o -1 si no lo encuentra.

**Solución en C/C++:**
```cpp
int buscarPorCodigo(ALUMNO alumnos[], int n, int codigoBuscado) {
    for (int i = 0; i < n; i++) {
        if (alumnos[i].codigo == codigoBuscado) {
            return i;
        }
    }
    return -1;
}
```

**Pseudocódigo:**
```
ACCION buscarPorCodigo(ALUMNO alumnos[], ENTERO n, ENTERO codigoBuscado) RETORNA ENTERO
   ENTERO i
   
   PARA i ← 0 HASTA n - 1
      SI(alumnos[i].codigo = codigoBuscado)
         RETORNAR(i)
      FIN_SI
   FIN_PARA
   
   RETORNAR(-1)
FIN_ACCION
```

---

## Ejercicio 2.5 (Tipo examen) - Cálculo de promedio

**Enunciado:**
Dado un arreglo de alumnos, calcule el promedio de notas de todos los alumnos.

**Solución en C/C++:**
```cpp
float calcularPromedio(ALUMNO alumnos[], int n) {
    if (n <= 0) return 0;
    
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += alumnos[i].nota;
    }
    
    return suma / n;
}
```

**Pseudocódigo:**
```
ACCION calcularPromedio(ALUMNO alumnos[], ENTERO n) RETORNA REAL
   REAL suma
   ENTERO i
   
   SI(n ≤ 0)
      RETORNAR(0)
   FIN_SI
   
   suma ← 0
   PARA i ← 0 HASTA n - 1
      suma ← suma + alumnos[i].nota
   FIN_PARA
   
   RETORNAR(suma / n)
FIN_ACCION
```
