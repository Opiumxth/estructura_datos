package tareaarbolserializable;
import java.util.ArrayList;

public class Pila<T> {
    private final ArrayList<T> elementos;

    public Pila() {
        elementos = new ArrayList<>();
    }

    public void enpilar(T dato) {
        elementos.add(dato);
    }

    public T desempilar() {
        return elementos.remove(elementos.size() - 1);
    }

    public T tope() {
        return elementos.get(elementos.size() - 1);
    }

    public boolean estaVacia() {
        return elementos.isEmpty();
    }
}