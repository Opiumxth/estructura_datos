/**
 * @(#)Nodo.java
 *
 *
 *
 * @author 
 * @version 1.00 2025/4/6
 */

public class Nodo<T> {
	private T dato;
	private Nodo<T> sgte;
	
	public Nodo(){
	}
	/**
	 * Inicializa el dato que almacena el nodo y establece su referencia sgte como nula
	 * @param dato
	 */
	public Nodo(T dato) {
	    this.dato = dato;
	    this.sgte = null;
	}
	public void setDato(T vdato){
	    dato=vdato;
	}
	
	/**
	 * Establece la referencia sgte del nodo actual
	 * @param n Un nodo del mismo tipo T que el actual
	 */
	public void setSgte(Nodo<T> vsgte){
	    sgte = vsgte;
	}
	
	/**
	 * Retorna el sgte nodo (o null) del actual
	 * @return El sgte nodo, null de no tener sgte
	 */
	public Nodo<T> getSgte(){
	    return sgte;
	}
	
	/**
	 * Retorna el dato que almacena el nodo
	 * @return El dato que almacena el nodo
	 */
	public T getDato(){
	    return dato;
	}
	
	public String toString(){
		String cad=new String();
		cad=dato.toString();
		return cad;
	}
	
}
