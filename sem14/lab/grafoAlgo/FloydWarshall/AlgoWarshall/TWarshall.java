/**
 * @(#)TWarshall.java
 *		Teste operaciones de algoritmo Warshall.
 *
 *	0. Dibuje el grafo y analice los resultados.
 *	1. Cree/investigue un grafo, luego ingrese la matriz
 *	   de adyacenca y compuebe resultados.
 *
 *
 * @author 
 * @version 1.00 2025/11/15
 */


public class TWarshall {
    public static void main(String[] args) {
    	Warshall w = new Warshall();
        // Ejemplo de grafo (matriz de adyacencia)
        // Representacion: 
        // true significa que hay una arista/relacion directa.
        // false significa que no hay arista directa.
        boolean[][] graph = {
            {true, true, false, false},
            {false, true, true, false},
            {false, false, true, true},
            {false, false, false, true}
        };

        boolean[][] closure = w.transitiveClosure(graph);

        System.out.println("Matriz de cierre transitivo:\n");
        for (int i = 0; i < closure.length; i++) {
            for (int j = 0; j < closure.length; j++) {
                System.out.printf("%10s",closure[i][j]);
            }
            System.out.println();
        }
    }

}