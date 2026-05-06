/**
 * @(#)Pila.java
 *
 *
 * @author 
 * @version 1.00 2020/7/10
 */
import java.util.*;

public class Pila {
    private Nodo tope;
    private int tamanio;
    
    public void Pila(){
        tope = null;
        tamanio = 0;
    }
    /**
     * Consulta si la pila esta vacia.
     * @return true si el primer nodo (tope), no apunta a otro nodo.
     */
    public boolean estaVacia(){
        return tope == null;
    }
    /**
     * Consulta cuantos elementos (nodos) tiene la pila.
     * @return numero entero entre [0,n] donde n es el numero de elementos
     * que contenga la lista.
     */
    public int getTamanio(){
        return tamanio;
    }
    /**
     * Agrega un nuevo nodo a la pila.
     * @param valor a agregar.
     */
    public void empilar(int val){
        Nodo nuevo = new Nodo();
        nuevo.setValor(val);

        if (estaVacia()) {
            tope = nuevo;
        }
        else{
            nuevo.setSgte(tope);
            tope = nuevo;
        }
        tamanio=tamanio+1;
    } 
    /**
     * Elimina el elemento que se encuentra en el tope de la piala.
     */
    public int depilar()throws Exception{
    	int val=-1;
        if (!estaVacia()) {
        	val=cima();
            tope = tope.getSgte();
            tamanio=tamanio-1;
            return val;
        }
        else{
        	System.out.println("La pila esta vacia...\n");
        	return val;
        } 
    }
    /**
     * Consulta el valor del nodo que se encuentra en la cima de la pila
     * @return valor del nodo.
     * @throws Exception 
     */
    public int cima() throws Exception{
        if(!estaVacia()){
            return tope.getValor();
        } 
        else {
            throw new Exception("La pila esta vacia...\n");
        }
    }
    /**
     * Busca un elemento en la pila.
     * @param referencia valor del nodo a buscar.
     * @return true si el valor de referencia existe en la pila.
     */
    public boolean buscar(int referencia){
        // Crea una copia de la pila.
        Nodo aux = tope;
        boolean existe = false;
        while(existe != true && aux != null){
            if (referencia == aux.getValor()) {
                existe = true;
            }
            else{
                aux = aux.getSgte();
            }
        }
        return existe;
    }
    /**
     * Elimina un nodo de la pila ubicado por su valor.
     * @param referencia valor de referencia para ubicar el nodo.
     */  
    public void remover(int referencia)throws Exception{
        // Consulta si el valor existe en la pila.
        if (buscar(referencia)) {
            Nodo pilaAux = null;
            while(referencia != tope.getValor()){
                Nodo temp = new Nodo();
                temp.setValor(tope.getValor());
                if(pilaAux == null){
                    pilaAux = temp;
                }
                else{
                    temp.setSgte(pilaAux);
                    pilaAux = temp;
                }
                depilar();
            }
            // Elimina el nodo que coincide con el de referencia.
            depilar();
            while(pilaAux != null){
                empilar(pilaAux.getValor());
                pilaAux = pilaAux.getSgte();
            }
            pilaAux = null;
        }
    }    
    /**
     * Actualiza el valor de un nodo en la pila.
     * @param referencia valor del nodo para ubicar el que se desea actualizar.
     * @param valor por el cual se desea remplazar el valor del nodo.
     */
    public void editar(int referencia, int valor)throws Exception{
        if (buscar(referencia)) {
            Nodo pilaAux = null;
            while(referencia != tope.getValor()){
                Nodo temp = new Nodo();
                temp.setValor(tope.getValor());
                if(pilaAux == null){
                    pilaAux = temp;
                }
                else{
                    temp.setSgte(pilaAux);
                    pilaAux = temp;
                }
                depilar();
            }
            // Actualiza el valor del nodo.
            tope.setValor(valor);
            while(pilaAux != null){
                empilar(pilaAux.getValor());
                pilaAux = pilaAux.getSgte();
            }
            pilaAux = null;
        }
    }
    /**
     * Elimina la pila
     */
    public void eliminar(){
        tope = null;
        tamanio = 0;
    }
    /**
     * Despliega en pantalla los elementos de la pila.
     */
    public void listar(){
        Nodo aux = tope;
        while(aux != null){
            System.out.println("|\t" + aux.getValor() + "\t|");
            System.out.println("---------");
            aux = aux.getSgte();
        }
    }
    
}
