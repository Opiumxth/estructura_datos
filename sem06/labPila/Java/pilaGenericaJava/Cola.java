/**
 * @(#)Cola.java
 *
 *
 * @author 
 * @version 1.00 2025/4/6
 */

import java.util.*;
public class Cola<T> implements Iterable<T> {

    private int size = 0;  // Inicializa el tamano de la cola
    private Node<T> first = null;  // Inicializa el primer nodo de la cola
    private Node<T> last = null;  // Inicializa el ultimo nodo de la cola
    
    
    public Cola() {
    }

    public boolean isEmpty() {
        return first == null;  // Verifica si la cola esta vacia
    }

    public T first() {
        if (isEmpty()) {
            return null;  // Si la cola esta vacia, devuelve null
        }
        return first.getValue();  // Devuelve el valor del primer nodo (primer elemento en la cola)
    }

    public T enqueue(T element) {
        Node<T> newNode = new Node<>(element, null);  // Crea un nuevo nodo con el elemento dado
        if (isEmpty()) {
            first = newNode;  // Si la cola esta vacia, el nuevo nodo se convierte en el primer nodo
            last = newNode;  // Y tambien en el ultimo nodo
        } else {
            last.setNext(newNode);  // Establece el siguiente del ultimo nodo al nuevo nodo
            last = newNode;  // El nuevo nodo se convierte en el ultimo nodo
        }
        size++;  // Incrementa el tamano de la cola
        return newNode.getValue();  // Devuelve el valor del nuevo nodo
    }

    public T dequeue() {
        if (isEmpty()) {
            return null;  // Si la cola esta vacia, devuelve null
        }
        T item = first.getValue();  // Obtiene el valor del primer nodo (primer elemento en la cola)
        first = first.getNext();  // El nodo siguiente al primer nodo actual se convierte en el primer nodo
        size--;  // Decrementa el tamano de la cola
        if (isEmpty()) {
            last = null;  // Si la cola se queda vacia, el ultimo nodo tambien se establece en null
        }
        return item;  // Devuelve el valor eliminado
    }

    public int size() {
        return this.size;  // Devuelve el tamano de la cola
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private Node<T> current = first;  // Inicializa el nodo actual como el primer nodo

            @Override
            public boolean hasNext() {
                return current != null;  // Verifica si hay un siguiente nodo en la estructura
            }

            @Override
            public T next() {
                if (!hasNext()) {
                    throw new NoSuchElementException("No hay mas elementos en la cola");
                }
                T item = current.getValue();  	// Obtiene el valor del nodo actual
                current = current.getNext();  	// Mueve el nodo actual al siguiente nodo
                return item;  					// Devuelve el valor del nodo actual
            }
        };
    }
}    