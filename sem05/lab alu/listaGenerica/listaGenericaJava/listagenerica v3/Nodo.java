/**
 * @(#)Nodo.java
 *
 *
 * @author 
 * @version 1.00 2025/11/11
 */

public class Nodo<T> {
    T dato;
    Nodo<T> siguiente;

    public Nodo(){
    }
    public Nodo(T dato) {
        this.dato = dato;
        this.siguiente = null;
    }
    
    public String toString(){
    	String cad=new String();
    	cad=dato.toString();
    	return cad;
    } 
}
