/**
 * @(#)Arista.java
 *		La clase Nodo y sus operacines basicas
 *		relaciones al Grafo.
 *	1. Analice el metodo toString() y su implementacion
 *	   para visualizar lo deseado.
 *
 *
 * @author 
 * @version 1.00 2025/11/2
 */

public class Arista<T> {
    private Nodo<T> destino;
    private int peso; // Peso opcional de la arista

    public Arista(Nodo<T> destino) {
        this(destino, 1); 
        // Por defecto peso 1 para grafos no ponderados
        // Ponderado o con peso y sin peso.
    }

    public Arista(Nodo<T> destino, int peso) {
        this.destino = destino;
        this.peso = peso;
    }

    public Nodo<T> getDestino() {
        return destino;
    }

    public int getPeso() {
        return peso;
    }

    @Override
    public String toString() {
		String cad=new String();       
        String ap=" -->";
        String pe="peso: "; 
        cad=(peso>1?String.format("%s %s (%s %d)",ap,destino.toString(),pe,peso):
        	        String.format("%s %s",ap,destino));
        return cad;
        
    }
}