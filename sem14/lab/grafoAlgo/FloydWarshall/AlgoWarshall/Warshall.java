/**
 * @(#)Warshall.java
 *	Operaciones encuentra el cierre transitivo de
 *	una operaciones binaria.
 *
 *	Que es cierre transitivo?
 *
 *
 * @author 
 * @version 1.00 2025/11/15
 */


public class Warshall {
	
	public Warshall(){
	}
    /**
     * Calcula el cierre transitivo de una matriz de adyacencia booleana 
     * utilizando el algoritmo de Warshall.
     *
     * @param graph La matriz de adyacencia booleana original.
     * @return La matriz que representa el cierre transitivo.
     */
    public boolean[][] transitiveClosure(boolean[][] graph) {
    	int i,j,k;
        int n = graph.length;
        boolean[][] closure = new boolean[n][n];

        // Inicializar la matriz de cierre con los valores originales del grafo
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                closure[i][j] = graph[i][j];
            }
        }
        // Aplicar el algoritmo de Warshall
        // k es el vertice intermedio
        for (k = 0; k < n; k++) {
            // i es el vertice de inicio
            for (i = 0; i < n; i++) {
                // j es el vertice de destino
                for (j = 0; j < n; j++) {
                    // Si hay un camino de i a k Y de k a j, 
                    // entonces hay un camino de i a j
                    if (closure[i][k] && closure[k][j]) {
                        closure[i][j] = true;
                    }
                }
            }
        }
        return closure;
    }
}
