/**
 * @(#)Nodo.java
 *
 *
 * @author 
 * @version 1.00 2020/7/10
 */


public class Nodo {
    private int valor;
    private Nodo sgte;
    
    public void Nodo(){
        this.valor = 0;
        this.sgte = null;
    }

    public void Nodo(int val){
        this.valor = val;
        this.sgte = null;
    }
    
    // Metodos get y set para los atributos.
    
    public void setValor(int val) {
        this.valor = val;
    }
    public void setSgte(Nodo sig) {
        this.sgte = sig;
    }
       
    public int getValor() {
        return valor;
    }
    public Nodo getSgte() {
        return sgte;
    }

}