# PRÁCTICA 13: ÁRBOLES B

---

## Ejercicio 13.1 (Fácil) - Orden del árbol

**Enunciado:**
Para un árbol B de orden 5, ¿cuál es el máximo número de claves por nodo y el mínimo número de claves (excepto raíz)?

**Solución:**
- **Máximo claves por nodo:** m - 1 = 5 - 1 = 4 claves
- **Mínimo claves (excepto raíz):** ⌈m/2⌉ - 1 = ⌈5/2⌉ - 1 = 3 - 1 = 2 claves

---

## Ejercicio 13.2 (Medio) - Verificar validez

**Enunciado:**
¿Es válido el siguiente árbol B de orden 5?
```
       [20]
      /    \
[10]  [30|40]
```

**Solución:**
- Raíz tiene 2 hijos ✓ (mínimo 2)
- Nodo [10] tiene 1 clave ✓ (mínimo 2)
- Nodo [30|40] tiene 2 claves ✓
- Todos los nodos tienen ≤ 4 claves ✓
- **SÍ es válido.**

---

## Ejercicio 13.3 (Medio) - Inserción simple

**Enunciado:**
Inserte 10, 20, 30 en un B-tree de orden 3. Muestre el árbol resultante.

**Solución:**
```
Insertar 10: [10]

Insertar 20: [10|20]

Insertar 30 (causa división):
- Mediana: 20
- Resultado: [20]
           /    \
        [10]   [30]
```

---

## Ejercicio 13.4 (Difícil) - Calcular número máximo de claves

**Enunciado:**
Calcule el número máximo de claves en un B-tree de orden 5 con altura 2.

**Solución:**
- Nivel 0 (raíz): máximo 4 claves
- Nivel 1: máximo 5 nodos × 4 claves = 20 claves
- Nivel 2: máximo 25 nodos × 4 claves = 100 claves
- **Total máximo: 124 claves**

---

## Ejercicio 13.5 (Tipo examen) - Número de accesos a disco

**Enunciado:**
Un B-tree de orden 5 con altura 3. ¿Cuál es el máximo número de accesos a disco para buscar una clave?

**Solución:**
Altura 3 significa 4 niveles (0, 1, 2, 3). En el peor caso, se necesita acceder a un nodo de cada nivel.

**Máximo accesos: 4**

Esto es mucho más eficiente que un ABB que podría requerir O(n) accesos en el peor caso.
