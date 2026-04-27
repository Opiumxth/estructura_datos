/**
 * @(#)Lista.java
 *
 *
 * @author 
 * @version 1.00 2025/11/11
 */
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.function.Predicate;

public class Lista<T> {
    private Nodo<T> cabeza;

    public Lista() {
    	 this.cabeza = null;
    }

    // Metodo para anadir un elemento al final de la lista
    public void agregar(T dato) {
        Nodo<T> nuevoNodo = new Nodo<>(dato);
        if (cabeza == null) {
            cabeza = nuevoNodo;
        } else {
            Nodo<T> actual = cabeza;
            while (actual.siguiente != null) {
                actual = actual.siguiente;
            }
            actual.siguiente = nuevoNodo;
        }
    }



    // Metodo para imprimir la lista (util para verificar)
    public void imprimirLista() {
        Nodo<T> actual = cabeza;
        while (actual != null) {
            System.out.println(actual.dato.toString());
            actual = actual.siguiente;
        }
    }   
    // --- Metodo de Busqueda Generica ---
    /**
     * Busca elementos que cumplen con un predicado dado.
     * @param condicion El predicado que define el criterio de busqueda.
     * @return Una nueva lista enlazada con los elementos encontrados.
     */
    //public ListaEnlazadaGenerica<T> buscar(Predicate<T> condicion) {
    public Lista<T> buscar(Predicate<T> condicion) {
        Lista<T> resultados = new Lista<>();
        Nodo<T> actual = cabeza;
        while (actual != null) {
            if (condicion.test(actual.dato)) {
                resultados.agregar(actual.dato);
            }
            actual = actual.siguiente;
        }
        return resultados;
    }

    // --- Metodo de Ordenamiento Generico ---
    /**
     * Ordena la lista utilizando un comparador proporcionado.
     * Nota: Utiliza conversion temporal a java.util.LinkedList para eficiencia en el ordenamiento.
     * @param comparador El comparador que define el criterio de ordenacion.
     */
    public void ordenar(Comparator<T> comparador) {
        // Convertir a java.util.LinkedList para usar Collections.sort
        List<T> listaAuxiliar = new LinkedList<>();
        Nodo<T> actual = cabeza;
        while (actual != null) {
            listaAuxiliar.add(actual.dato);
            actual = actual.siguiente;
        }

        // Ordenar usando el comparador geneerico
        Collections.sort(listaAuxiliar, comparador);

        // Reconstruir la lista enlazada personalizada con los datos ordenados
        cabeza = null; // Vaciar la lista original
        for (T dato : listaAuxiliar) {
            agregar(dato);
        }
    }    	 
}