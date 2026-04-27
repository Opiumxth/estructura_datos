/**
 * @(#)Lista.java
 *
 *
 * @author 
 * @version 1.00 2025/11/11
 */


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

    // Metodo para ordenar la lista por el atributo 'nombre' de Persona (usando Bubble Sort)
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

    // Metodo para imprimir la lista (util para verificar)
    public void imprimirLista() {
        Nodo<T> actual = cabeza;
        while (actual != null) {
            System.out.println(actual.dato.toString());
            actual = actual.siguiente;
        }
    }    
}