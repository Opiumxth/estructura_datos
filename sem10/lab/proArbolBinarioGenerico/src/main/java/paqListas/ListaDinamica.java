/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package paqListas;

/**
 *
 * @author mathias
 */
public class ListaDinamica<T> {
    private Nodo<T> cabeza;

    public ListaDinamica() {
        this.cabeza = null;
    }

    // Metodo para anadir un elemento al final de la lista
    public void anadir(T dato) {
        Nodo<T> nuevoNodo = new Nodo<>(dato);
        if (cabeza == null) {
            cabeza = nuevoNodo;
        } else {
            Nodo<T> actual = cabeza;
            while (actual.siguiente != null) {
                actual = actual.siguiente;
            }
            actual.siguiente = nuevoNodo;
        }
    }

    // alias para compatibilidad con tu BST (addLast)
    public void addLast(T dato) {
        anadir(dato);
    }

    // getter para recorrer desde BST
    public Nodo<T> getCabeza() {
        return cabeza;
    }

    // Metodo para imprimir la lista (util para verificar)
    public void imprimirLista() {
        Nodo<T> actual = cabeza;
        while (actual != null) {
            System.out.println(actual.dato.toString());
            actual = actual.siguiente;
        }
    }
}