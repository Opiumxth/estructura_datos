# PRÁCTICA 14: ÁRBOLES TRIE

---

## Ejercicio 14.1 (Fácil) - Inserción básica

**Enunciado:**
Inserte las palabras "sol" y "sol" en un Trie. ¿Qué pasa si insertamos la misma palabra dos veces?

**Solución:**
La primera vez se crea el camino para "sol". La segunda vez, se recorre el mismo camino y se marca el nodo final como fin de palabra (ya estaba marcado). No se crean nodos adicionales.

---

## Ejercicio 14.2 (Medio) - Construir Trie

**Enunciado:**
Construya un Trie con las palabras: "casa", "carro", "cama".

**Solución:**
```
        (raíz)
         |
         c
         |
         a
        / \
       m   r
      /     \
     a      r
    /        \
   *         o
              \
               *
```

---

## Ejercicio 14.3 (Medio) - Búsqueda

**Enunciado:**
Dado el Trie anterior, ¿existe "cal"? ¿Existe "cama"?

**Solución:**
- "cal": NO. Después de "ca", no hay hijo con 'l'.
- "cama": SÍ. El camino c→a→m→a existe y está marcado como fin de palabra.

---

## Ejercicio 14.4 (Difícil) - Autocompletado

**Enunciado:**
Dado un Trie con "ganar", "gancho", "gandula", ¿qué palabras comienzan con "gan"?

**Solución:**
Recorrer desde el nodo después de "gan" y encontrar todos los caminos que terminan en fin de palabra:
- "ganar"
- "gancho"
- "gandula"

---

## Ejercicio 14.5 (Tipo examen) - Prefijo compartido

**Enunciado:**
¿Cuál es la ventaja principal de un Trie sobre un arreglo para almacenar palabras?

**Solución:**
Los prefijos comunes se comparten entre palabras, lo que ahorra espacio de memoria. Por ejemplo, "ganga" y "ganglio" comparten el prefijo "gang".

Además, la búsqueda es O(L) donde L es la longitud de la palabra, independiente del número total de palabras.
