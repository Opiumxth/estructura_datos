/**
 * @(#)Arista.java
 *
 *
 * @author 
 * @version 1.00 2025/11/15
 */

public class Arista {
    int destino;
    int peso;
	
	public Arista(){
	}
    public Arista(int dest, int w) {
        this.destino = dest;
        this.peso = w;
    }
    
    public int getDestino(){
    	return destino;
    }
    public int getPeso(){
    	return peso;
    }
}

