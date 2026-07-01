/**
 * @(#)TFloydWardhall.java
 *		Testea las operaciones de Algoritmo Floyd-Warshall
 *
 *	0. Dibuje el grafo y analice los resultados.
 *	1. Cree/investigue un grafo aplicaciones de Floyd-Warshall
 *	   ingrese la matriz de adyacencia y compruebe los resultados 
 *
 *
 *
 * @author 
 * @version 1.00 2025/11/15
 */


public class TFloydWardhall {
    public static void main(String[] args) {
        // Ejemplo de Grafo (matriz de adyacencia)
        // INF si no hay arista, 0 si es el mismo nodo
        int INF,dm;
        FloydWarshall fw=new FloydWarshall();
        INF=fw.INF;
        int graph[][] = { 
        	{0, 5, INF, 10},
            {INF, 0, 3, INF},
            {INF, INF, 0, 1},
            {INF, INF, INF, 0} 
        };                
        dm = graph.length;
        fw.floydWarshall(graph, dm);
    }
}