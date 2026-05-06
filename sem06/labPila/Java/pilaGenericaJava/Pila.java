/**
 * @(#)Pila.java
 *
 *
 * @author 
 * @version 1.00 2025/4/6
 */
 
import java.util.*;

public class Pila<T> implements Iterable<T> {
    private Node<T> top = null;  
    private int length = 0;  
    
    public Pila() {
    }

    T push(T element) {
        Node<T> newNode = new Node<T>(element, null);  
        if (top == null) {
            top = newNode;  
        } 
        else {
            newNode.setNext(top);  
            top = newNode;  
        }
        length++;  
        return top.getValue();  
    }

    T pop() {
        if (top == null) {
            return null;  
        }
        T delete = top.getValue();  
        top = top.getNext();  
        length--;  
        return delete;  
    }

    T peek() {
        if (top == null) {
            return null;  
        }
        return top.getValue();  
    }

    int size() {
        return length;  
    }

    @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            Node<T> current = top;  

            @Override
            public boolean hasNext() {
                return current != null;  
            }

            @Override
            public T next() {
                if (!hasNext()) {
                    throw new NoSuchElementException("No hay mas elementos en la pila");
                }
                T item = current.getValue();	// Obtiene el valor del nodo actual
                current = current.getNext();  	// Mueve el nodo actual al siguiente nodo
                return item;  					// Devuelve el valor del nodo actual
            }
        };
    }
}   
 