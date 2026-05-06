package paqPilas;

public class Pila<T> {
    private Nodo<T> cima; // El último que entró
    private int tamanio;

    public Pila() {
        this.cima = null;
        this.tamanio = 0;
    }

    // PUSH: Agrega un elemento arriba
    public void empilar(T elemento) {
        Nodo<T> nuevoNodo = new Nodo<>(elemento);
        nuevoNodo.siguiente = cima; // El nuevo nodo apunta al que antes era el primero
        cima = nuevoNodo;           // Ahora el nuevo nodo es la cima
        tamanio = tamanio+1;
    }

    // POP: Elimina y devuelve el elemento de arriba
    public T depilar() {
        if (estaVacio()) {
            throw new RuntimeException("La pila está vacía");
        }
        T valor = cima.dato;
        cima = cima.siguiente; // Movemos la cima al siguiente nodo
        tamanio = tamanio-1;
        return valor;
    }

    // PEEK: Solo mira qué hay arriba
    public T visorPila() {
        if (estaVacio()) return null;
        return cima.dato;
    }

    public boolean estaVacio() {
        return cima == null;
    }

    public int getTamanio() {
        return tamanio;
    }
}
