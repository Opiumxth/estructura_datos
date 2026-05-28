/**
 * nombreClase: NodoArbolBinario.java
 * descripcion:
 *
 *
 * @author: APATERNO AMATERNO, Nombre
 * @date  : 26-05-2026
 " @version 1
 */
package paqAbbGenerico2;

import java.util.*;


public class NodoArbolBinario<T extends Comparable<T>> {

    private T element;
    private NodoArbolBinario<T> parent;
    private NodoArbolBinario<T> left;
    private NodoArbolBinario<T> right;

    public NodoArbolBinario() {
    }
    public NodoArbolBinario(T element) {
        this.element = element;
    }

    public NodoArbolBinario(T element, NodoArbolBinario<T> parent, NodoArbolBinario<T> left, NodoArbolBinario<T> right) {
        this.element = element;
        this.parent  = parent;
        this.left    = left;
        this.right   = right;
    }

    public NodoArbolBinario(T element, NodoArbolBinario<T> parent) {
        this.element = element;
        this.parent = parent;
    }

    public NodoArbolBinario(T element, NodoArbolBinario<T> left, NodoArbolBinario<T> right) {
        this.element = element;
        this.left = left;
        this.right = right;
    }

    public T getElement() {
        return element;
    }

    public void setElement(T element) {
        this.element = element;
    }

    public NodoArbolBinario<T> getParent() {
        return parent;
    }

    public void setParent(NodoArbolBinario<T> parent) {
        this.parent = parent;
    }

    public NodoArbolBinario<T> getLeft() {
        return left;
    }

    public void setLeft(NodoArbolBinario<T> left) {
        this.left = left;
    }

    public NodoArbolBinario<T> getRight() {
        return right;
    }

    public void setRight(NodoArbolBinario<T> right) {
        this.right = right;
    }
    
    @Override
    public String toString() {
    	String cad=null;
    	cad = element.toString();
    	return cad;
    }
}
