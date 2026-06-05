/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package paqListas;

/**
 *
 * @author mathias
 */
public class Nodo<T> {
    public T dato;
    public Nodo<T> siguiente;

    public Nodo() {
    }

    public Nodo(T dato) {
        this.dato = dato;
        this.siguiente = null;
    }

    public String toString() {
        String cad = new String();
        cad = dato.toString();
        return cad;
    }
}