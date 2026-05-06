package paqPilas;

public class Nodo<T> {
    T dato;
    Nodo<T> siguiente;

    public Nodo(T dato) {
        this.dato = dato;
        this.siguiente = null;
    }

    public String toString(){
        String cad = null;
        cad = dato.toString();
        return cad;
    }
}