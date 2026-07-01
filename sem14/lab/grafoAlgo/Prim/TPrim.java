/**
 * @(#)TPrim.java
 *		Prueba las operaciones de Prim.
 *
 *	0. Dibuje los grafos y compruebe los resultados
 *	1. Cree/investigue grafos, ingrese los datos y 
 *	   compruebe los resultados.
 *
 *
 * @author 
 * @version 1.00 2025/11/15
 */

import java.util.*;

public class TPrim {
    public static void main(String[] args) {
        int V = 5; // 5 vertices (0 a 4)
        Prim grafo = new Prim(V);

        // Anadir aristas: (u, v, peso)
        grafo.agregarArista(0, 1, 2);
        grafo.agregarArista(0, 3, 6);
        grafo.agregarArista(1, 2, 3);
        grafo.agregarArista(1, 3, 8);
        grafo.agregarArista(1, 4, 5);
        grafo.agregarArista(2, 4, 7);
        grafo.agregarArista(3, 4, 9);

        // Ejecutar el algoritmo de Prim comenzando desde el vertice 0
        grafo.primMST(0);
    } 
}