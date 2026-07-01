/**
 * @(#)TGrafo.java
 *		Analice la aplicacion
 *
 *	0. Analice la aplicacion y se esta aplicando 
 *	   todas las estructuras apredidas en clase
 *	   como: arreglos, listas, pilas y colas excepto
 *	   filas secuenciales/archivos, esperamos que
 *	   usted agregue salvar y recuperar grafos.
 *	1. Que problema de la realidad le motiva dar 
 *	   solucion con lo aprendido?
 *	2. Dibuje el grafo ejemplo en su cuaderno y analice 
 *	   la representacion del grafo. 
 *	   
 *
 *
 * @author 
 * @version 1.00 2025/11/2
 */


public class TGrafo {
    public static void main(String[] args) {
        Grafo<String> grafo = new Grafo<>();

        // Agregar nodos
        grafo.agregarNodo("A");
        grafo.agregarNodo("B");
        grafo.agregarNodo("C");
        grafo.agregarNodo("D");
        grafo.agregarNodo("E");

        // Agregar aristas (dirigidas, ponderadas y no ponderadas)
        grafo.agregarArista("A", "B", 1);
        grafo.agregarArista("A", "C", 2);
        grafo.agregarArista("B", "D", 1);
        grafo.agregarArista("C", "D", 3);
        grafo.agregarArista("D", "E", 1);
        grafo.agregarArista("E", "A", 1);

        // Imprimir el grafo
		System.out.println(grafo);
        // Realizar recorridos
        grafo.bfs("A");
        grafo.dfs("A");
    }   
}

/*
 *
        LISTA DE ADYACENCIA

A--> B (peso:  1)--> C (peso:  2)
B--> D (peso:  1)
C--> D (peso:  3)
D--> E (peso:  1)
E--> A (peso:  1)

Recorrido BFS comenzando desde A:
A B C D E 
Recorrido DFS comenzando desde A:
A B D E C 

Process completed.



        LISTA DE ADYACENCIA

A --> B --> C (peso: 2)
B --> D
C --> D (peso: 3)
D --> E
E --> A

Recorrido BFS comenzando desde A:
A B C D E 
Recorrido DFS comenzando desde A:
A B D E C 

Process completed.

 **/