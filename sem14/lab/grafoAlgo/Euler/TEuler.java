/**
 * @(#)TEuler.java
 *		Testea las operaciones de Euler.
 *
 *	1. Dibuje el grafo y analice los resultados.
 * 	2. Busque/investigue un grafo: ingrese los vertices, 
 *	   luego las relaciones y analice los rsultados, 
 *	   compruebe si da los resultados del autor.
 *
 *
 * @author 
 * @version 1.00 2025/11/15
 */

import java.util.*;

public class TEuler {
    public static void main(String args[]) {
        Euler g1 = new Euler(4);
        g1.agregarArista(0, 1);
        g1.agregarArista(0, 2);
        g1.agregarArista(1, 2);
        g1.agregarArista(2, 3);
        g1.imprimirCaminoEuleriano();
        // Grados: 0: 2, 1: 2, 2: 3, 3: 1. (2 impares, deberia encontrar un camino)

        System.out.println("\n---");

        Euler g2 = new Euler(3);
        g2.agregarArista(0, 1);
        g2.agregarArista(1, 2);
        g2.agregarArista(2, 0);
        g2.imprimirCaminoEuleriano();
        // Grados: 0: 2, 1: 2, 2: 2. (Todos pares, deberia encontrar un circuito)
    }
}