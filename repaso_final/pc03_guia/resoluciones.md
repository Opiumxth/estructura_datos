# Punteros
## 1.1
```
ACCION principal
        flotante a = 3.14
        flotante* pa = &a
        escribir ("Valor de a: ", *pa)
        *pa = 2.74
        escribir ("Valor de a: ", *pa)
FIN ACCION
```

## 1.2
```
int main();
int duplicar(int* arr, int n);

int duplicar(int* arr, int n){
        for (int i = 0; i < n; i++){
                *arr *= 2;
                arr++;
        }
}

int main(){
        int a = {1,4,7,3};
        for (int i = 0; i < n; i ++){
                escribir (a[i], ", ")
        }
        duplicar (&a, sizeof(a));
        for (int i = 0; i < n; i ++){
                escribir (a[i], ", ")
        }
}
```

## 1.3
### Pseudo
```
ACCION principal
ACCION invertir(entero* a, entero n)
ACCION cambiar(entero* a, entero* b)
ACCION mostrar(entero* a, entero n)

ACCION cambiar(entero* a, entero* b)
        entero temp = 0
        temp = *a
        *a = *b
        *b = temp
FIN ACCION

ACCION mostrar(entero* a, entero n)
        PARA i = 0 HASTA i < n HACER
                escribir(*a, ", ")
                a++;
        FIN PARA
FIN ACCION

ACCION invertir(entero* a, entero n)
        SI n % 2 = 0 ENTONCES
                PARA i = 0 HASTA i < n/2 HACER
                        cambiar(&a, &(a+n-i))
                FIN PARA
        SINO
                PARA i = 0 HASTA i < (n-1)/2 HACER
                        cambiar(&a, &(a+n-i))
                FIN PARA
        FIN SI
FIN ACCION

ACCION principal
        entero a = {1,6,12,4,7,3,5}
        mostrar(&a, tamaño(a))
        invertir(&a, tamaño(a))
        mostrar(&a, tamaño(a))
FIN ACCION
```

# Structs
## 2.1
```
REGISTRO Producto
        entero codigo
        caracter[30] nombre
        flotante precio
FIN REGISTRO

ACCION principal
        Producto p1 = nuevo Producto
        escribir("Codigo: ")
        leer(p1.codigo)
        escribir("Nombre: ")
        leer(p1.nombre)
        escribir("Precio: ")
        leer(p1.precio)
FIN ACCION
```

## 2.2 No sé como hacerlo
```
struct Fecha {
        datetime

}
```

## 2.3
```
ACCION mostrar(Empleado* emp, entero n)
        PARA i = 0 HASTA i < n HACER
                escribir("Empleado ", i+1)
                escribir("Nombre: ")
                leer(*emp->nombre)
                escribir("Salario: ")
                leer(*emp->salario)
                escribir("Dpto: ")
                leer(*emp->dpto)
        FIN PARA
FIN ACCION

ACCION salarioProm(Empleado* emp, entero n)
        entero total = 0
        PARA i = 0 HASTA i < n HACER
                total += *emp->salario
        FIN PARA
        retornar total
FIN ACCION

ACCION mayorSalario(Empleado* emp, entero n)
        Empleado mayor = *emp
        PARA i = 0 HASTA i < n HACER
                SI *(emp+1)->salario > *mayor->salario
                        mayor = *(emp+1)
                FIN SI
        FIN PARA
        retornar mayor
FIN ACCION
```

## 2.4
### Pseudo
```
TIPO DATO entero

REGISTRO NODO
        TD valor
        NODO* sgte
FIN REGISTRO

ACCION crearNodo(TD dato)
        NODO* p = nuevo NODO
        SI p == NULL
                escribir("No hay espacio en memoria")
                retornar NULL
        FIN SI
        p->valor = dato
        p->sgte = NULL
        retornar p
FIN ACCION
```

### C++
```
typedef int TD;

struct NODO {
        TD valor
        NODO* sgte
}

NODO* crearNodo(TD) {
        NODO* p = (NODO*)malloc(sizeof(NODO));
        if (p == NULL) {
                printf("No hay espacio en memoria");
                return NULL;
        }
        p->valor = dato;
        p-sgte = NULL;
        return p;
}
```
# Memoria dinamica
## 3.1
```
int main () {
        int a = new int;
        a = 12;
        cout<<"Numero: "<<a<<endl;
        delete(a)
        return 0;
}
```

## 3.2
```
int main() {
        int n;
        cout<<"Ingrese el numero de elementos"<<endl;
        cin>>n;
        float arr = new float[n];
        // suponiendo que ya llenamos el arreglo
        float suma = 0;
        for(int i = 0; i < n; i++){
                suma += arr[i];
        }
        cout<<"Promedio: "<<(suma/n)<<endl;
        delete[] arr;
        return 0;
}
```

## 3.3
```
int main() {
        int n;
        // acá se usa printf y scanf
        cout<<"Ingrese el numero de elementos"<<endl;
        cin>>n;
        float arr = (float)malloc(sizeof(float));
        // suponiendo que ya llenamos el arreglo
        float suma = 0;
        for(int i = 0; i < n; i++){
                suma += arr[i];
        }
        printf("Promedio: ",(suma/n));
        free(arr);
        return 0;
}
```

## 3.4
```
int* p = new int[10];
int* q = p;
delete p;     // Error 1: ¿cuál?
q[5] = 42;    // Error 2: ¿cuál?
delete[] q;   // Error 3: ¿cuál?

```
Error 1:
hace un delete p cuando deberia sera delete *p, porque es un puntero

Error 2:


Error 3:
el q no representa al arreglo, ademas ya se hizo un delete de p anterior mente, deberia hacerse q = nullptr

# Archivos Aqui no comprendí muy bien, seguiré con el sgte
## 4.1
```


```

## 4.2
```


```

## 4.3
```

```
## 4.4

```

```

# Listas enlazadas
## 7.1
```

```
## 7.2
```

```
## 7.3
```

```
## 7.4

```

