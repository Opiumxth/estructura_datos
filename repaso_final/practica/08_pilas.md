# PRÁCTICA 08: PILAS

---

## Ejercicio 8.1 (Fácil) - Push y Pop

**Enunciado:**
Implemente las operaciones push y pop para una pila implementada con lista enlazada.

**Solución en C/C++:**
```cpp
void push(NODO** pila, int valor) {
    NODO* nuevo = new NODO;
    nuevo->valor = valor;
    nuevo->sgte = *pila;
    *pila = nuevo;
}

int pop(NODO** pila) {
    if (*pila == NULL) {
        cout << "Stack underflow" << endl;
        return -1;
    }
    
    NODO* temp = *pila;
    int valor = temp->valor;
    *pila = (*pila)->sgte;
    delete temp;
    
    return valor;
}
```

**Pseudocódigo:**
```
ACCION push(NODO pila, NODO pila1, ENTERO valor)
   NODO nuevo
   
   nuevo ← nuevoNodo(pila1, valor)
   nuevo.sgte ← pila
   pila ← nuevo
FIN_ACCION

ACCION pop(NODO pila, NODO pila1) RETORNA ENTERO
   NODO temp
   ENTERO valor
   
   SI(pila = NULL)
      ESCRIBIR("Stack underflow")
      RETORNAR(-1)
   FIN_SI
   
   temp ← pila
   valor ← temp.valor
   pila ← pila.sgte
   liberaNodo(pila1, temp)
   
   RETORNAR(valor)
FIN_ACCION
```

---

## Ejercicio 8.2 (Medio) - Verificar paréntesis balanceados

**Enunciado:**
Use una pila para verificar si una cadena de paréntesis está balanceada.

**Solución en C/C++:**
```cpp
#include <stack>
#include <string>
using namespace std;

bool balanceado(string s) {
    stack<char> pila;
    
    for (char c : s) {
        if (c == '(') {
            pila.push(c);
        } else if (c == ')') {
            if (pila.empty()) return false;
            pila.pop();
        }
    }
    
    return pila.empty();
}
```

**Pseudocódigo:**
```
ACCION balanceado(CADENA s) RETORNA BOOLEANO
   PILA pila
   CARACTER c
   
   PARA cada c EN s
      SI(c = '(')
         push(pila, c)
      SINO
         SI(c = ')')
            SI(pilaVacia(pila))
               RETORNAR(FALSO)
            FIN_SI
            pop(pila)
         FIN_SI
      FIN_SI
   FIN_PARA
   
   RETORNAR(pilaVacia(pila))
FIN_ACCION
```

---

## Ejercicio 8.3 (Medio) - Palíndromo

**Enunciado:**
Use una pila para verificar si una cadena es un palíndromo.

**Solución en C/C++:**
```cpp
#include <stack>
#include <string>
using namespace std;

bool esPalindromo(string s) {
    stack<char> pila;
    
    // Push todos los caracteres
    for (char c : s) {
        pila.push(c);
    }
    
    // Comparar con la cadena original
    for (char c : s) {
        if (c != pila.top()) {
            return false;
        }
        pila.pop();
    }
    
    return true;
}
```

---

## Ejercicio 8.4 (Difícil) - Evaluar expresión postfija

**Enunciado:**
Use una pila para evaluar una expresión en notación postfija (ej: "5 3 + 2 *").

**Solución en C/C++:**
```cpp
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int evaluarPostfija(string expr) {
    stack<int> pila;
    stringstream ss(expr);
    string token;
    
    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = pila.top(); pila.pop();
            int a = pila.top(); pila.pop();
            
            if (token == "+") pila.push(a + b);
            else if (token == "-") pila.push(a - b);
            else if (token == "*") pila.push(a * b);
            else if (token == "/") pila.push(a / b);
        } else {
            pila.push(stoi(token));
        }
    }
    
    return pila.top();
}
```

---

## Ejercicio 8.5 (Tipo examen) - Convertir infija a postfija

**Enunciado:**
Use una pila para convertir una expresión infija a postfija.

**Solución en C/C++:**
```cpp
#include <stack>
#include <string>
using namespace std;

int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infijaAPostfija(string infija) {
    stack<char> pila;
    string resultado = "";
    
    for (char c : infija) {
        if (isalnum(c)) {
            resultado += c;
        } else if (c == '(') {
            pila.push(c);
        } else if (c == ')') {
            while (!pila.empty() && pila.top() != '(') {
                resultado += pila.top();
                pila.pop();
            }
            pila.pop();
        } else {
            while (!pila.empty() && precedencia(pila.top()) >= precedencia(c)) {
                resultado += pila.top();
                pila.pop();
            }
            pila.push(c);
        }
    }
    
    while (!pila.empty()) {
        resultado += pila.top();
        pila.pop();
    }
    
    return resultado;
}
```
