/**
 * @(#)Euler.java
 *		Operaciones de algoritmo de Euler
 *
 *	0. Analice el codigo, luego compile y ejecute y analice los resultados
 *	1. Implemente un metodo para determinar si el grafo es conexo.
 *	2. Implemente una clase Euler para grafo dirigido
 *	3. Implemente una clase Euler con metodos iterativos utilizado una 
 *	   libreria con Pilas y Colasm genericas  vistos en clase.
 *
 *
 * @author 
 * @version 1.00 2025/11/15
 */

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.Iterator;

class Euler {
    private int V; // Numero de vertices
    private List<Integer>[] adj; // Lista de adyacencia

    public Euler(){
    }
    public  Euler(int v) {
        V = v;
        adj = new ArrayList[V];
        for (int i = 0; i < V; ++i){
            adj[i] = new ArrayList<>();
        }
    }

     public void agregarArista(int u, int v) {
        adj[u].add(v);
        adj[v].add(u); // Para grafo no dirigido
    }

    // Funcion para encontrar el camino/circuito euleriano
     public void encontrarYEliminarCaminoEuleriano(int u, List<Integer> camino) {
        // Recorre los vecinos del vertice actual 'u'
        for (Integer v : adj[u]) {
            // Si la arista (u, v) todavia existe, la "elimina" y 
            // hace una llamada recursiva
            if (v != -1) { 
                // Eliminar la arista de ambas listas de adyacencia 
                // (u -> v y v -> u)
                int tempV = v;
                // Vease las operaciones de ArrayList
                adj[u].set(adj[u].indexOf(v), -1); // Marca como eliminada
                adj[v].set(adj[v].indexOf(u), -1); // Marca como eliminada

                encontrarYEliminarCaminoEuleriano(tempV, camino);
            }
        }
        // Agrega el vertice a la lista del camino despues de visitar 
        // todas sus aristas
        camino.add(u);
    }

    // Metodo principal para imprimir el camino euleriano
     public void imprimirCaminoEuleriano() {
     	int i;
        int verticeInicio = 0;
        int countImpar = 0;
        
        // 1. Verificar las condiciones de existencia y encontrar el 
        // vertice de inicio
        for (i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0) {
                countImpar++;
                verticeInicio = i;
            }
        }

        if (countImpar > 2) {
            System.out.println("El grafo no tiene un camino ni circuito Euleriano.");
            return;
        }
        // Si countImpar es 0, es un circuito (cualquier inicio sirve). 
        // Si es 2, es un camino (inicia en un impar).
        System.out.println("Inicia busqueda del camino Euleriano desde el vertice: " + verticeInicio);

        List<Integer> camino = new ArrayList<>();
        encontrarYEliminarCaminoEuleriano(verticeInicio, camino);

        // El camino se construye al reves, se imprime en orden 
        // inverso para mostrar el camino correcto
        System.out.println("Camino/Circuito Euleriano encontrado:");
        for (i = camino.size() - 1; i >= 0; i--) {
            System.out.print(camino.get(i) + " ");
        }
        System.out.println();
    }
}
