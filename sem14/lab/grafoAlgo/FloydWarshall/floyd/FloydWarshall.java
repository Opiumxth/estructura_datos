/**
 * @(#)FloydWarshall.java
 *		Encuenta el camino mas corto entre cada par de
 *		de nodos.
 *		No funciona con ciclos de peso negativo
 *
 *
 * @author 
 * @version 1.00 2025/11/15
 */

public class FloydWarshall {
    public final int INF = 99999; // Representa infinito para distancias no conectadas
	
	public FloydWarshall(){
	}
    public void floydWarshall(int graph[][], int V) {
    	int i,j,k;
        int dist[][] = new int[V][V];

        // 1. Inicializar la matriz de distancias
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                dist[i][j] = graph[i][j];
            }
        }

        // 2. Algoritmo principal
        // k es el nodo intermedio, i es el origen, j es el destino
        for (k = 0; k < V; k++) {
            for (i = 0; i < V; i++) {
                for (j = 0; j < V; j++) {
                    // Si pasar por 'k' es mas corto que la ruta directa actual
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // 3. Imprimir la matriz de distancias finales
        System.out.println("La matriz de distancias mas cortas es:\n");
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] == INF) {
                    System.out.print("INF\t");
                }
                else {
                    System.out.print(dist[i][j] + "\t");
                }
            }
            System.out.println();
        }
    }
}
