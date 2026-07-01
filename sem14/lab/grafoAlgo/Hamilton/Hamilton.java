/**
 * @(#)Hamilton.java
 *		Operaciones de algorimo de caminos de Hamilton.
 *
 *	1,. Analice clase, luego, compile y analice los resultados
 *
 * @author gasal
 * @version 1.00 2025/11/15
 */

import java.util.Arrays;

public class Hamilton {
    final int V = 5; // Numero de vertices en el grafo de ejemplo
    int[] path;
    int[][] graph;
    
    public Hamilton(){
    }

    // Metodo principal para resolver el problema
    public void findHamiltonianPath(int[][] adjMatrix) {
        graph = adjMatrix;
        path = new int[V];
        Arrays.fill(path, -1);

        // Empezamos desde el vertice 0 (se puede empezar desde cualquier otro)
        path[0] = 0;

        if (!solveHamiltonianPath(1)) {
            System.out.println("No existe un camino hamiltoniano.\n");
        }
        else {
            printPath();
        }
    }

    // Funcion recursiva que usa backtracking para encontrar el camino
    public boolean solveHamiltonianPath(int pos) {
        // Caso base: si todos los vertices estan incluidos en el camino
        if (pos == V) {
            // Si buscamos un *ciclo*, aqui verificariamos si el ultimo vertice
            // esta conectado al primero (path[0]) en la matriz de adyacencia.
            // Para un *camino*, esto es suficiente.
            return true;
        }

        // Probar diferentes vertices como siguiente candidato en el camino
        for (int v = 1; v < V; v++) {
            if (isSafe(v, pos)) {
                path[pos] = v;
                if (solveHamiltonianPath(pos + 1)){
                    return true;
                }
                
                // Si anadir el vertice v no lleva a una solucion,
                // entonces lo eliminamos (backtrack)
                path[pos] = -1;
            }
        }
        return false;
    }

    // Funcion para verificar si el vertice 'v' se puede anadir 
    // 'a la posicion 'pos en el camino actual
    public boolean isSafe(int v, int pos) {
        // 1. Verificar si hay una arista del vertice anterior al actual
        if (graph[path[pos - 1]][v] == 0){
            return false;
        }

        // 2. Verificar si el vertice 'v' ya ha sido incluido en el camino
        for (int i = 0; i < pos; i++) {
            if (path[i] == v){
                return false;
            }
        }
        return true;
    }

    // Funcion de utilidad para imprimir la solucion
    public void printPath() {
        System.out.println("El camino hamiltoniano existe y es:\n");
        for (int i = 0; i < V; i++){
            System.out.print(path[i] + " ");
        }
        System.out.println();
    }
}
