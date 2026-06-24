# PRÁCTICA 15: ÁRBOLES DE HUFFMAN

---

## Ejercicio 15.1 (Fácil) - Construcción básica

**Enunciado:**
Construya el árbol de Huffman para los símbolos con frecuencias: A=5, B=9.

**Solución:**
```
Paso 1: A(5), B(9)

Paso 2: Combinar A y B → Nodo(14)
        [14]
       /   \
     A(5) B(9)

Códigos resultantes:
- A: 0
- B: 1
```

---

## Ejercicio 15.2 (Medio) - Construcción con más símbolos

**Enunciado:**
Construya el árbol de Huffman para: A=3, B=4, C=5, D=6.

**Solución:**
```
Paso 1: A(3), B(4), C(5), D(6)

Paso 2: Combinar A y B → AB(7)
C(5), D(6), AB(7)

Paso 3: Combinar C y D → CD(11)
AB(7), CD(11)

Paso 4: Combinar AB y CD → Raiz(18)
        (18)
       /    \
    (7)    (11)
   /  \    /  \
 A(3) B(4) C(5) D(6)

Códigos:
- A: 00
- B: 01
- C: 10
- D: 11
```

---

## Ejercicio 15.3 (Medio) - Codificación

**Enunciado:**
Usando el árbol del ejercicio anterior, codifique el mensaje "ABCD".

**Solución:**
- A → 00
- B → 01
- C → 10
- D → 11

**Resultado:** 00011011

**Longitud original:** 4 caracteres × 8 bits = 32 bits
**Longitud comprimida:** 8 bits
**Tasa de compresión:** 75%

---

## Ejercicio 15.4 (Difícil) - Longitud promedio

**Enunciado:**
Para el árbol del ejercicio 15.2, calcule la longitud promedio del código.

**Solución:**
- A: 2 bits, frecuencia 3
- B: 2 bits, frecuencia 4
- C: 2 bits, frecuencia 5
- D: 2 bits, frecuencia 6

**Longitud promedio:**
= (3×2 + 4×2 + 5×2 + 6×2) / (3+4+5+6)
= (6 + 8 + 10 + 12) / 18
= 36 / 18
= 2 bits por símbolo

---

## Ejercicio 15.5 (Tipo examen) - Verificar prefijo libre

**Enunciado:**
¿Los códigos A=0, B=10, C=11 son válidos para Huffman? Justifique.

**Solución:**
SÍ, son válidos. Ningún código es prefijo de otro:
- 0 no es prefijo de 10 ni 11
- 10 no es prefijo de 11
- 11 no es prefijo de 10

Esta propiedad de "prefijo libre" garantiza que la decodificación sea unívoca.
