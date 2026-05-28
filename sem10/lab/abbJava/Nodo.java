/**
 * @(#)Nodo.java
 *
 *
 * @author
 * @version 1.00 2023/5/26
 */


public class Nodo<V> {

    private V value;
    private Nodo<V> izq;
    private Nodo<V> der;

    public Nodo(V value, Nodo<V> izq, Nodo<V> der) {
        super();
        this.value = value;
        this.izq = izq;
        this.der = der;
    }

    public void setValue(V value) {
        this.value = value;
    }
    public void setIzq(Nodo<V> izq) {
        this.izq = izq;
    }
    public void setDer(Nodo<V> der) {
        this.der = der;
    }

    public V getValue() {
        return value;
    }
    public Nodo<V> getIzq() {
        return izq;
    }
    public Nodo<V> getDer() {
        return der;
    }

	@Override
	public String toString(){
		String cad;
		cad=value.toString();
		return cad;
	}
}