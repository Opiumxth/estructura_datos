/**
 * @(#)THamilton.java
 *		Prueba las operaciones camino de Euler
 *
 *	0. Dibuje el grafo y analice los resultados.
 *	1. Cree/investigue un grafo, ingrese la matriz
 *	   de adyacencia y compruebe resultados.
 *
 * @author 
 * @version 1.00 2025/11/15
 */

public class THamilton {
    // Ejemplo de uso
    public static void main(String args[]) {
        Hamilton hamiltonian = new Hamilton();
        
        // Grafo de ejemplo representado por una matriz de adyacencia
        // (0=sin arista, 1=con arista)
        int[][] graph1 = {
            {0, 1, 0, 1, 0},
            {1, 0, 1, 1, 1},
            {0, 1, 0, 0, 1},
            {1, 1, 0, 0, 1},
            {0, 1, 1, 1, 0},
        };

        hamiltonian.findHamiltonianPath(graph1);
    }
}