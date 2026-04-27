/**
 * @(#)Nodo.java
 *
 *
 * @author 
 * @version 1.00 2013/4/16
 */


public class Nodo {
    int dato;
	Nodo sgte;
	Nodo ante;
	
	public Nodo(int entrada){
		dato = entrada;
		sgte = null;
		ante = null;
	}
	public int getDato(){
		return dato;
	}
	public Nodo getEnlace(){
		return sgte;
	}
	public void setEnlace(Nodo sgte){
		this.sgte = sgte;
	}
	@Override
	public String toString(){
		String cad=null;
		cad=String.format("%4d", dato);
		return cad;
	}
}