/**
 * @(#)Node.java
 *		Clae Node para el implementar el Arbol B
 *				TAREA
 *	0. Analice el coigo, luego compile, ejecute
 *	   y analice la salida integrada al arbol B.
 *	1. Que finalidad tiene instanciuar comparable en el 
 *	   y el vector hijos de  dimension 2*grado
 *	   en el constructor.
 *	2. Que es el metodo traverse, que hace?
 *	3. Que hace el metodo dividirHijo(...) a que metodo 
 *	   de vector de objetos desarrollado?
 *
 *
 *
 * @author 
 * @version 1.00 2025/10/25
 */
import java.util.Arrays;
public class Node<T extends Comparable<T>> {
    int nks; 			// Numero actual de claves
    T claves[]; 			// Array de claves
    Node<T> hijos[]; // Array de nodos hijos
    boolean hoja; 		// True si el nodo es una hoja
    int grado;

    @SuppressWarnings("unchecked")
    public Node(){
    }
    //public Node(int grado, boolean hoja) {
    public Node(int grado, boolean hoja) {
        this.grado = grado;
        this.hoja = hoja;
        this.claves = (T[]) new Comparable[2*grado - 1];
        //this.hijos = (Node<T>[]) new Node[2*grado];
        this.hijos = new Node[2*grado];
        this.nks = 0;
    }

    public void traverse() {
        int i;
        for (i = 0; i<nks; i++) {
            if (!hoja) {
                hijos[i].traverse();
            }
            System.out.print(claves[i]);
        }
        if (!hoja) {
            hijos[i].traverse();
        }
    }

    public void dividirHijo(int i, Node<T> y) {
    	int j;
        Node<T> z = new Node<>(grado, y.hoja);
        z.nks = grado-1;

        for (j = 0; j<grado - 1; j++) {
            z.claves[j] = y.claves[j+grado];
            y.claves[j+grado] = null;
        }

        if (!y.hoja) {
            for (j = 0; j <grado; j++) {
                z.hijos[j] = y.hijos[j+grado];
                y.hijos[j+grado] = null;
            }
        }
        y.nks = grado - 1;

        for (j = nks; j >= i + 1; j--) {
            hijos[j+1] = hijos[j];
        }
        hijos[i+1] = z;

        for (j = nks-1; j >= i; j--) {
            claves[j + 1] = claves[j];
        }
        claves[i] = y.claves[grado-1];
        y.claves[grado-1] = null;
        nks=nks+1;
    }
}

