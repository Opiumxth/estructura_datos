/**
 * @(#)Nodo.java
 *
 *
 * @author https://www.studocu.com/co/document/universidad-de-caldas/estructuras-de-datos/aboles-narios-codigo-fuente-para-la-implementacion-de-un-arbol-n-ario-en-netbeans/4954268
 * @version 1.00 2023/5/23
 */

import java.util.*;

public class Nodo<T> {
	private T dato;
	private Nodo<T> padre;
	private List<Nodo<T>> hijos;

	//Constructores
   public Nodo() {
   }
   public Nodo(T vdato) {
   	dato=vdato;
   	hijos=new ArrayList<>();
   }
   public Nodo(Nodo<T> nodo) {
   	this.dato=(T)nodo.getDato();
   	hijos=new ArrayList<>();
   }

	//Setters
	public void setDato(T vdato){
		this.dato=vdato;
	}
	public void setPadre(Nodo<T> vpadre){
		this.padre=vpadre;
	}
	public void setHijos(List<Nodo<T>> hijos){
		for (Nodo<T> hijo: hijos){
			hijo.setPadre(this);
		}
		this.hijos=hijos;
	}
	//Getters
	public T getDato(){
		return this.dato;
	}
	public Nodo<T> getPadre(){
		return this.padre;
	}
	public List<Nodo<T>> getHijos(){
		return this.hijos;
	}

	public Nodo<T> getHijoEn(int posicion){
		return hijos.get(posicion);
	}

   public void agregarHijo(Nodo<T> hijo) {
   	hijo.setPadre(this);
   	hijos.add(hijo);
   }

   public void agregarHijoEn(int posicion, Nodo<T> hijo) {
   	hijo.setPadre(this);
   	this.hijos.add(posicion,hijo);
   }

	public void eliminarHijo(Nodo<T> hijoBorrar){
		List<Nodo<T>> list=getHijos();
		list.remove(hijoBorrar);
	}

	public Nodo<T> eliminarHijoEn(int posicion){
		return hijos.remove(posicion);
	}

	public boolean equals(Object obj){
		if(obj==null){
			return false;
		}
		if(obj instanceof Nodo){
			if(((Nodo<?>)obj).getDato().equals(this.dato)){
				return true;
			}
		}
		return false;
	}

	@Override
	public String toString(){
		return this.dato.toString();
	}
}



