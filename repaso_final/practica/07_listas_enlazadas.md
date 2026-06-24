# PRÁCTICA 07: LISTAS ENLAZADAS

---

## Ejercicio 7.1 (Fácil) - Contar nodos

**Enunciado:**
Escriba una función que cuente el número de nodos en una lista enlazada simple.

**Solución en C/C++:**
```cpp
int contarNodos(NODO* cab) {
    int count = 0;
    NODO* temp = cab;
    
    while (temp != NULL) {
        count++;
        temp = temp->sgte;
    }
    
    return count;
}
```

**Pseudocódigo:**
```
ACCION contarNodos(NODO cab) RETORNA ENTERO
   ENTERO count
   NODO temp
   
   count ← 0
   temp ← cab
   
   MIENTRAS(temp ≠ NULL)
      count ← count + 1
      temp ← temp.sgte
   FIN_MIENTRAS
   
   RETORNAR(count)
FIN_ACCION
```

---

## Ejercicio 7.2 (Medio) - Sumar valores

**Enunciado:**
Escriba una función que sume todos los valores de una lista enlazada de enteros.

**Solución en C/C++:**
```cpp
int sumarValores(NODO* cab) {
    int suma = 0;
    NODO* temp = cab;
    
    while (temp != NULL) {
        suma += temp->valor;
        temp = temp->sgte;
    }
    
    return suma;
}
```

**Pseudocódigo:**
```
ACCION sumarValores(NODO cab) RETORNA ENTERO
   ENTERO suma
   NODO temp
   
   suma ← 0
   temp ← cab
   
   MIENTRAS(temp ≠ NULL)
      suma ← suma + temp.valor
      temp ← temp.sgte
   FIN_MIENTRAS
   
   RETORNAR(suma)
FIN_ACCION
```

---

## Ejercicio 7.3 (Medio) - Insertar ordenado

**Enunciado:**
Escriba una función que inserte un valor en una lista enlazada manteniéndola ordenada de menor a mayor.

**Solución en C/C++:**
```cpp
void insertarOrdenado(NODO** cab, int valor) {
    NODO* nuevo = new NODO;
    nuevo->valor = valor;
    nuevo->sgte = NULL;
    
    if (*cab == NULL || valor < (*cab)->valor) {
        nuevo->sgte = *cab;
        *cab = nuevo;
        return;
    }
    
    NODO* temp = *cab;
    while (temp->sgte != NULL && temp->sgte->valor < valor) {
        temp = temp->sgte;
    }
    
    nuevo->sgte = temp->sgte;
    temp->sgte = nuevo;
}
```

**Pseudocódigo:**
```
ACCION insertarOrdenado(NODO cab, NODO cab1, ENTERO valor)
   NODO nuevo, temp
   
   nuevo ← nuevoNodo(cab1, valor)
   
   SI(cab = NULL O valor < cab.valor)
      nuevo.sgte ← cab
      cab ← nuevo
      RETORNAR
   FIN_SI
   
   temp ← cab
   MIENTRAS(temp.sgte ≠ NULL Y temp.sgte.valor < valor)
      temp ← temp.sgte
   FIN_MIENTRAS
   
   nuevo.sgte ← temp.sgte
   temp.sgte ← nuevo
FIN_ACCION
```

---

## Ejercicio 7.4 (Difícil) - Invertir lista

**Enunciado:**
Escriba una función que invierta una lista enlazada in-place.

**Solución en C/C++:**
```cpp
void invertirLista(NODO** cab) {
    NODO* anterior = NULL;
    NODO* actual = *cab;
    NODO* siguiente = NULL;
    
    while (actual != NULL) {
        siguiente = actual->sgte;
        actual->sgte = anterior;
        anterior = actual;
        actual = siguiente;
    }
    
    *cab = anterior;
}
```

**Pseudocódigo:**
```
ACCION invertirLista(NODO cab)
   NODO anterior, actual, siguiente
   
   anterior ← NULL
   actual ← cab
   siguiente ← NULL
   
   MIENTRAS(actual ≠ NULL)
      siguiente ← actual.sgte
      actual.sgte ← anterior
      anterior ← actual
      actual ← siguiente
   FIN_MIENTRAS
   
   cab ← anterior
FIN_ACCION
```

---

## Ejercicio 7.5 (Tipo examen) - Eliminar duplicados

**Enunciado:**
Dada una lista enlazada ordenada, elimine los nodos duplicados.

**Solución en C/C++:**
```cpp
void eliminarDuplicados(NODO* cab) {
    NODO* actual = cab;
    
    while (actual != NULL && actual->sgte != NULL) {
        if (actual->valor == actual->sgte->valor) {
            NODO* temp = actual->sgte;
            actual->sgte = actual->sgte->sgte;
            delete temp;
        } else {
            actual = actual->sgte;
        }
    }
}
```
