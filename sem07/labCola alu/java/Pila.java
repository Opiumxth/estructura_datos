/**
 * @(#)Pila.java
 *		Operaviones basicas de la pila LIFO
 *	(Last in, First out) el ultimo en entrar es el primer en salir
 *		Es una implementacion de tipo T generico, el tipo T es 
 *	especificado por el usuario del TAD
 *	1. Analice las operaciones 
 *	   1.1 enpilar(dato)	: enpila el dato 
 *	   1.2 depila()			: retorna el dato depilado
 *	   1.3 getTalla()		: retorna la dimension de la pila
 *	   1.4 estaVacio()		: predicado retorna V si esta vacio, F en otro caso
 *	   1.5 visorPila()		: visorPila() visualiza el dato de la cima
 *
 * @author 
 * @version 1.00 2025/4/6
 */


public class Pila<T> {
    private Nodo<T> tope;
    private int talla;


    /**
     * Inicializa las referencias en null y el numero de elementos inicial en 0
     */
    public Pila() {
        tope = null;
        talla = 0;
    }

    /**
     * Anade un elemento de tipo T al tope de la pila
     * @param dato El elemento a anadir a la pila
     * @return El elemento anadido
     */
    public void empilar(T dato){
        //El nuevo nodo que se colocara a a la lista interna
        Nodo<T> tmp = new Nodo<>(dato);

        //Si la cola esta vacia
        if(tope == null){
            tope = tmp;
        }
        else{
            tmp.setSgte(tope);
            tope=tmp;
            talla=talla+1;
        }
    }

    /***
     * Retorna el primer elemento de la pila y elimina su referencia
     * @return El primer elemento de la pila
     */
    public T depilar(){
        //Si no hay elementos en la pila
        if(estaVacio()){
            return null;
        }
        else{
	        //Referencia del primer elemento
	        Nodo<T> tmp = tope;
	        tope = tope.getSgte();
	        talla--;
	        return tmp.getDato();
        }

    }

    /**
     * Retorna el numero de elementos que contiene la pila
     * @return El numero de elementos que contiene la pila
     */
    public int getTalla(){
        return talla;
    }

    /**
     * Indica si la pila se encuentra vacia
     * @return Si la pila se encuentra vacia
     */
    public boolean estaVacio(){
        return tope == null;
    }

    /**
     * Esta funcion retorna el valor del tope 
     * elemento de la pila SIN eleminar
     * su referencia
     * @return El primer elemento de la pila
     */
    public T visorPila(){
        return tope.getDato();
    }
    
    public void mostrarPila(){
    	System.out.println("\n\tElementos de la Pila\n");
    	if(estaVacio()){
    		System.out.println("Esta vaciooo..");
    	}
    	else{
    		Nodo<T> tmp=new Nodo<>();
    		tmp=tope;
    		//while(!estaVacio()){
    		while(tmp!=null){
    			System.out.println(tmp.getDato());
    			tmp=tmp.getSgte();
    		}
   	    	System.out.println();    		
    	}
    }
}