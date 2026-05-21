/**
 * @(#)Cola.java
 *		Operaviones basicas de la cola
 *	(First in, First out) el primero en entrar es el frente en salir
 *		Es una implementacion de tipo T generico, el tipo T es 
 *	especificado por el usuario del TAD
 *	1. Analice las operaciones 
 *	   1.1 encolar(dato)	: encola el dato 
 *	   1.2 decola()			: retorna el dato decolado
 *	   1.3 getTalla()		: retorna la diomension de la cola
 *	   1.4 estaVacio()		: predicado retorna V si esta vacio, F en otro caso
 *	   1.5 visorCola()		: visorCola() visualiza el dato del frente
 *
 * @author 
 * @version 1.00 2025/4/6
 */


public class Cola<T> {
    private Nodo<T> finale;
    private Nodo<T> frente;
    private int talla;


    /**
     * Inicializa las referencias en null y el numero de elementos inicial en 0
     */
    public Cola() {
        finale = null;
        frente = null;
        talla = 0;
    }

    /**
     * Anade un elemento de tipo T al finale de la cola
     * @param dato El elemento a anadir a la cola
     * @return El elemento anadido
     */
    public void encolar(T dato){
        //El nuevo nodo que se colocara a a la lista interna
        Nodo<T> tmp = new Nodo<>(dato);

        //Si la cola esta vacia
        if(finale == null && frente == null){
            finale = frente = tmp;
        }
        else{
            finale.setSgte(tmp);
	        //Ahora el finale es el elemento nuevo
	        finale = tmp;
	        talla++;
        }
    }

    /***
     * Retorna el primer elemento de la cola y elimina su referencia
     * @return El primer elemento de la cola
     */
    public T decolar(){
        //Si no hay elementos en la cola
        if(frente == null){
            return null;
        }
        else{
	        //Referencia del primer elemento
	        Nodo<T> tmp = frente;
	        frente = frente.getSgte();
	        //El numero de elementos de la lista disminuye
	        talla--;
	        //Si el elemento que se quiere desencolar era el unico ...
	        if (frente == null){
	            finale = null;
	        }	        
	        return tmp.getDato();
        }
    }

    /**
     * Retorna el numero de elementos que contiene la cola
     * @return El numero de elementos que contiene la cola
     */
    public int getTalla(){
        return talla;
    }

    /**
     * Indica si la cola se encuentra vacia
     * @return Si la cola se encuentra vacia
     */
    public boolean estaVacio(){
        return frente == null;
    }

    /**
     * Esta funcion retorna el valor del primer 
     * elemento de la cola SIN eleminar
     * su referencia
     * @return El primer elemento de la cola
     */
    public T visorCola(){
        return frente.getDato();
    }
    
    public void mostrarCola(){
    	System.out.println("\n\tElementos de la Cola\n");
    	if(estaVacio()){
    		System.out.println("Esta vaciooo..");
    	}
    	else{
    		Nodo<T> tmp=new Nodo<>();
    		tmp=frente;
    		//while(!estaVacio()){
    		while(tmp!=null){
    			System.out.println(tmp.getDato());
    			tmp=tmp.getSgte();
    		}
    		System.out.println();
    	}
    }  
}