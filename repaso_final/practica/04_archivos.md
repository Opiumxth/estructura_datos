# PRÁCTICA 04: ARCHIVOS

---

## Ejercicio 4.1 (Fácil) - Escribir texto

**Enunciado:**
Escriba un programa que cree un archivo de texto llamado "salida.txt" y escriba en él la línea "Hola Mundo".

**Solución en C/C++:**
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream archivo("salida.txt");
    
    if (archivo.is_open()) {
        archivo << "Hola Mundo" << endl;
        archivo.close();
        cout << "Archivo creado exitosamente" << endl;
    } else {
        cout << "Error al crear el archivo" << endl;
    }
    
    return 0;
}
```

**Pseudocódigo:**
```
ACCION ejercicio4()
   ARCHIVO archivo
   
   archivo ← abrir("salida.txt", "escritura")
   
   SI(archivo abierto)
      escribir(archivo, "Hola Mundo")
      cerrar(archivo)
      ESCRIBIR("Archivo creado exitosamente")
   SINO
      ESCRIBIR("Error al crear el archivo")
   FIN_SI
FIN_ACCION
```

---

## Ejercicio 4.2 (Medio) - Leer texto

**Enunciado:**
Lea el contenido del archivo "salida.txt" e imprímalo en pantalla.

**Solución en C/C++:**
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream archivo("salida.txt");
    string linea;
    
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo" << endl;
    }
    
    return 0;
}
```

---

## Ejercicio 4.3 (Medio) - Archivo binario (struct)

**Enunciado:**
Escriba un programa que guarde un struct ALUMNO en un archivo binario y luego lo lea de vuelta.

**Solución en C/C++:**
```cpp
#include <iostream>
#include <fstream>
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
    
    // Escribir en archivo binario
    ofstream archivo("alumno.dat", ios::binary);
    archivo.write((char*)&a, sizeof(ALUMNO));
    archivo.close();
    
    // Leer del archivo binario
    ALUMNO b;
    ifstream lectura("alumno.dat", ios::binary);
    lectura.read((char*)&b, sizeof(ALUMNO));
    lectura.close();
    
    cout << "Código: " << b.codigo << endl;
    cout << "Nombre: " << b.nombre << endl;
    cout << "Nota: " << b.nota << endl;
    
    return 0;
}
```

---

## Ejercicio 4.4 (Difícil) - Arreglo de structs en archivo

**Enunciado:**
Guarde un arreglo de 5 alumnos en un archivo binario y luego léalo de vuelta.

**Solución en C/C++:**
```cpp
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct ALUMNO {
    int codigo;
    char nombre[50];
    float nota;
};

int main() {
    ALUMNO alumnos[5];
    
    // Llenar datos
    for (int i = 0; i < 5; i++) {
        alumnos[i].codigo = 1000 + i;
        strcpy(alumnos[i].nombre, "Alumno");
        alumnos[i].nota = 10 + i;
    }
    
    // Escribir en archivo
    ofstream archivo("alumnos.dat", ios::binary);
    archivo.write((char*)alumnos, sizeof(ALUMNO) * 5);
    archivo.close();
    
    // Leer del archivo
    ALUMNO leidos[5];
    ifstream lectura("alumnos.dat", ios::binary);
    lectura.read((char*)leidos, sizeof(ALUMNO) * 5);
    lectura.close();
    
    // Imprimir
    for (int i = 0; i < 5; i++) {
        cout << leidos[i].codigo << " - " << leidos[i].nombre << " - " << leidos[i].nota << endl;
    }
    
    return 0;
}
```

---

## Ejercicio 4.5 (Tipo examen) - Verificar existencia

**Enunciado:**
Escriba una función que verifique si un archivo existe antes de intentar abrirlo.

**Solución en C/C++:**
```cpp
#include <iostream>
#include <fstream>
using namespace std;

bool archivoExiste(const char* nombre) {
    ifstream archivo(nombre);
    return archivo.good();
}

int main() {
    if (archivoExiste("datos.txt")) {
        cout << "El archivo existe" << endl;
    } else {
        cout << "El archivo no existe" << endl;
    }
    
    return 0;
}
```
