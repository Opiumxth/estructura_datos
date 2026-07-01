/**
 * @(#)Prim.java
 *		Clase para obtener el arbol recubridor.
 *
 *	0. Analice la clase, luego compile y analice los resultados
 *	1. Implemente una Prim utilizando una copla prioridad  visto
 *	   en clase, (Esta cola no ordena por orden llegada, sino 
 *     reordena de acuerdo al valor del peso), implemente una 
 *     una libreria. 
 *
 *
 * @author 
 * @version 1.00 2025/11/15
 */
import java.util.*;

public class Prim {
    private int V; // Numero de vurtices
    private List<List<Arista>> adj;

    public Prim(){
    }
    public Prim(int v) {
        V = v;
        adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
    }

    public void agregarArista(int u, int v, int peso) {
        adj.get(u).add(new Arista(v, peso));
        adj.get(v).add(new Arista(u, peso)); // Grafo no dirigido
    }

    public void primMST(int inicioVertice) {
        // Cola de prioridad para almacenar aristas (ordenadas por peso ascendente)
        PriorityQueue<Arista> pq = new PriorityQueue<>(Comparator.comparingInt(e -> e.peso));
        
        // Array para rastrear que vertices han sido incluidos en el MST
        boolean[] enMST = new boolean[V];
        
        // Array para almacenar el padre de cada nodo en el MST final (opcional, 
        // para reconstruir el arbol) int[] padre = new int[V]; 
        
        // Inicializar con el vertice de inicio
        // Simulamos anadir una arista ficticia de peso 0 al nodo inicial 
        // para que la PQ lo procese primero
        pq.add(new Arista(inicioVertice, 0));
        
        int costoTotalMST = 0;
        List<String> aristasMST = new ArrayList<>();

        while (!pq.isEmpty()) {
            // Extraer la arista con el peso minimo
            Arista aristaActual = pq.poll();
            int u = aristaActual.destino;
            int peso = aristaActual.peso;

            // Si el vertice ya esta en el MST, lo ignoramos (para evitar 
            // ciclos y aristas redundantes)
            if (enMST[u]) {
                continue;
            }

            // Incluir el vertice 'u' en el MST
            enMST[u] = true;
            costoTotalMST += peso;
            
            // Registrar la arista anadida (excepto la ficticia inicial)
            if (peso != 0) {
                // Nota: para mostrar de que nodo vino, necesitariamos  
                // almacenar el padre en la clase Edge
                aristasMST.add(String.format("Arista anadida: (U, V) con peso %d", peso)); // Ejemplo simplificado
            }

            // Recorrer todos los vecinos del vertice 'u'
            for (Arista vecino : adj.get(u)) {
                int v = vecino.destino;
                int pesoVecino = vecino.peso;

                // Si el vecino 'v' no esta en el MST y el peso de la arista 
                // es menor que su peso actual conocido (implicito aqui), 
                // anadirlo a la cola de prioridad
                if (!enMST[v]) {
                    pq.add(new Arista(v, pesoVecino));
                }
            }
        }

        // Imprimir el resultado
        System.out.println("\nArbol de Expansion Minima (MST) Costo Total: " + costoTotalMST);
        System.out.println("Aristas en el MST:\n");
        for (String arista : aristasMST) {
            System.out.println(arista);
        }
    }
}
