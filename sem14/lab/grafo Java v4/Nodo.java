/**
 * @(#)Nodo.java
 *		La clase Nodo y su operaciones para 
 *		relacionadas con el Grafo.
 *
 *	1. Analice el metodo equals() y su finalidad
 *	   investigue.
 *	2. Analice el metodo toString().
 *
 *
 * @author 
 * @version 1.00 2025/11/2
 */
import java.util.*;

public class Nodo<T> {
    private T valor;
    private boolean visitado;

    public Nodo(T valor) {
        this.valor = valor;
        this.visitado = false;
    }

    public T getValor() {
        return valor;
    }

    public void setValor(T valor) {
        this.valor = valor;
    }

    public boolean isVisitado() {
        return visitado;
    }

    public void setVisitado(boolean visitado) {
        this.visitado = visitado;
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Nodo<?> nodo = (Nodo<?>) o;
        return Objects.equals(valor, nodo.valor);
    }

    @Override
    public int hashCode() {
        return Objects.hash(valor);
    }
    
    @Override
    public String toString() {
        String cad=new String();
        cad=valor.toString(); // String.valueOf(valor);
        return cad;
    }
}
