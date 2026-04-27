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


public class Lista<T> {
    private Nodo<T> cabeza;

    public Lista() {
    	 this.cabeza = null;
    }

    // Metodo para anadir un elemento al final de la lista
    public void anadir(T dato) {
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

    // Metodo para buscar una Persona por ID
    public Persona buscarPorId(int id) {
        Nodo<T> actual = cabeza;
        while (actual != null) {
            // Se asume que T es de tipo Persona para esta operacion especifica
            if (actual.dato instanceof Persona) {
                Persona p = (Persona) actual.dato;
                if (p.getId() == id) {
                    return p;
                }
            }
            actual = actual.siguiente;
        }
        return null; // No se encontro la persona
    }
    
    // agregado
	// Dentro de ListaEnlazadaGenerica<T> (si T es Persona) o en 
	// una clase aparte para genericos
	public Persona buscarPorNombre(String nombreBuscado) {
	    Nodo<T> actual = cabeza;
	    while (actual != null) {
	        // Se requiere que T sea Persona para acceder a getNombre()
	        if (actual.dato instanceof Persona) {
	            Persona p = (Persona) actual.dato;
	            if (p.getNombre().equals(nombreBuscado)) {
	                return p;
	            }
	        }
	        actual = actual.siguiente;
	    }
	    return null; // No se encontro ninguna persona con ese nombre
	}
	
    // Metodo para ordenar la lista por el atributo 'nombre' de Persona 
    // (usando Bubble Sort)
    public void ordenarPorNombre() {
        if (cabeza == null || cabeza.siguiente == null) {
            return;
        }

        boolean intercambio;
        do {
            intercambio = false;
            Nodo<T> actual = cabeza;
            while (actual.siguiente != null) {
                // Comparacion de nombres. Se asume que T es de tipo Persona
                Persona p1 = (Persona) actual.dato;
                Persona p2 = (Persona) actual.siguiente.dato;

                if (p1.getNombre().compareTo(p2.getNombre()) > 0) {
                    // Realizar el intercambio de datos (no de nodos completos, lo cual es mas simple)
                    T temp = actual.dato;
                    actual.dato = actual.siguiente.dato;
                    actual.siguiente.dato = temp;
                    intercambio = true;
                }
                actual = actual.siguiente;
            }
        } while (intercambio);
    }
    // agregado
	// Dentro de ListaEnlazadaGenerica<T>
	public void ordenarPorEdad() {
	    // Convertir a java.util.LinkedList para usar Collections.sort
	    List<Persona> listaAuxiliar = new LinkedList<>();
	    Nodo<T> actual = cabeza;
	    while (actual != null) {
	        if (actual.dato instanceof Persona) {
	            listaAuxiliar.add((Persona) actual.dato);
	        }
	        actual = actual.siguiente;
	    }
	
	    // Ordenar usando Comparator por edad
	    Collections.sort(listaAuxiliar, Comparator.comparingInt(Persona::getEdad));
	
	    // Reconstruir la lista enlazada personalizada con los datos ordenados
	    cabeza = null; // Vaciar la lista original
	    for (Persona p : listaAuxiliar) {
	        anadir( (T)p); // Agregar los elementos ordenados
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
}