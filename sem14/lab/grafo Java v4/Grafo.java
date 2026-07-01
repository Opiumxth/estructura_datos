/**
 * @(#)Grafo.java
 *		Operaciones de grafo implementada en un Map
 *				TAREA
 *	0. Analice el codigo, luego compile, ejecute y 
 *	   analice los resultados.
 *	2. Analice l carga/insercion de datos: agregarNodo
 *	   agregarArista. Que aplicaciones puede crear con
 *	   estructura?
 *  3. Analice recorridos bfs y dfs en anchura y profundidad
 *	   rspectivamente. Investigue en en la API de Java acerca
 *	   de las operaciones usadas.
 *	   3.1 Utilice las pilas y cola generica vistos en clase
 *		   implemente una nueva vesion.
 *	4. Analice el metodo imprimirGrafo()
 *  5. Analice el metodo toString(). Que se debe hacer para 
 *	   que esta y la anterior funcione?.
 *
 *
 *
 * @author 
 * @version 1.00 2025/11/2
 */

import java.util.*;

public class Grafo<T> {
    // Lista de adyacencia: mapea un nodo a su lista de aristas salientes
    private final Map<Nodo<T>, List<Arista<T>>> adyacencia;

    public Grafo() {
        this.adyacencia = new HashMap<>();
    }

    // Adiciona un nuevo nodo al grafo
    public void agregarNodo(T valor) {
        Nodo<T> nuevoNodo = new Nodo<>(valor);
        if (!adyacencia.containsKey(nuevoNodo)) {
            adyacencia.put(nuevoNodo, new ArrayList<>());
        }
    }

    // Adiciona una arista (conexion) entre dos nodos
    public void agregarArista(T valorOrigen, T valorDestino, int peso) {
        Nodo<T> origen =  encontrarNodo(valorOrigen);
        Nodo<T> destino = encontrarNodo(valorDestino);

        if (origen != null && destino != null) {
            // Para grafo dirigido, solo se adiciona una direccion
            adyacencia.get(origen).add(new Arista<>(destino, peso));
            // Si fuera no dirigido, se anadiria tambien: 
            // adyacencia.get(destino).add(new Arista<>(origen, peso));
        }
        else {
            System.out.println("Error: Nodos de origen o destino no encontrados.");
        }
    }

    // Metodo auxiliar para encontrar un nodo por su valor
    private Nodo<T> encontrarNodo(T valor) {
        for (Nodo<T> nodo : adyacencia.keySet()) {
            if (nodo.getValor().equals(valor)) {
                return nodo;
            }
        }
        return null;
    }
    
    // Metodo auxiliar para restablecer el estado visitado de todos los nodos
    private void restablecerVisitados() {
        for (Nodo<T> nodo : adyacencia.keySet()) {
            nodo.setVisitado(false);
        }
    }

    // Recorrido en Amplitud (BFS) usando Cola<T> (java.util.Queue)
    public void bfs(T valorInicio) {
        Nodo<T> inicio = encontrarNodo(valorInicio);
        if (inicio == null) return;

        restablecerVisitados();
        // Instanciacion de Cola
        Queue<Nodo<T>> cola = new LinkedList<>();
        
        inicio.setVisitado(true);
        cola.add(inicio);

        System.out.println("Recorrido BFS comenzando desde " + valorInicio + ":");
        while (!cola.isEmpty()) {
            Nodo<T> actual = cola.poll();
            System.out.print(actual + " ");

            for (Arista<T> arista : adyacencia.get(actual)) {
                Nodo<T> vecino = arista.getDestino();
                if (!vecino.isVisitado()) {
                    vecino.setVisitado(true);
                    cola.add(vecino);
                }
            }
        }
        System.out.println();
    }

    // Recorrido en Profundidad (DFS) usando Pila<T> (java.util.Stack)
    public void dfs(T valorInicio) {
        Nodo<T> inicio = encontrarNodo(valorInicio);
        if (inicio == null) return;

        restablecerVisitados();
        Stack<Nodo<T>> pila = new Stack<>(); // Implementacion de Pila

        pila.push(inicio);
        
        System.out.println("Recorrido DFS comenzando desde " + valorInicio + ":");
        while (!pila.isEmpty()) {
            Nodo<T> actual = pila.pop();

            if (!actual.isVisitado()) {
                actual.setVisitado(true);
                System.out.print(actual + " ");

                // Se adiciona los vecinos a la pila (orden inverso para mantener logica DFS)
                List<Arista<T>> vecinos = adyacencia.get(actual);
                for (int i = vecinos.size() - 1; i >= 0; i--) {
                    Nodo<T> vecino = vecinos.get(i).getDestino();
                    if (!vecino.isVisitado()) {
                        pila.push(vecino);
                    }
                }
            }
        }
        System.out.println();
    }

    // Metodo para imprimir el grafo (lista de adyacencia)
    public void imprimirGrafo() {
    	System.out.println("\n\t\tLISTA DE ADYACENCIA\n");
        for (Nodo<T> nodo : adyacencia.keySet()) {
            //System.out.print("Nodo " + nodo + " adyacente a:");
            System.out.print("Nodo " + nodo);
            for (Arista<T> arista : adyacencia.get(nodo)) {
                System.out.print(arista);
            }
            System.out.println();
        }
    }
    
    public String toString(){
    	String cad="";
    	System.out.println("\n\t\tLISTA DE ADYACENCIA\n");
    	for(Nodo<T> nodo:adyacencia.keySet()){
    		cad=cad+nodo.toString();
	    	for(Arista<T> arista:adyacencia.get(nodo)){
	    		cad=cad+arista;
	    	}
	    	cad=cad+"\n";	
    	}
    	return cad;
    }
}
