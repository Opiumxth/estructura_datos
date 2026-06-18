/**
 * @(#)BTree.java
 *		Operaciones basicas del arbol B.
 * 	0. Analice el codigo, luego compile, ejecute 
 *	   y analice los resultados.
 *	1. Porque se instancia root en el constructor.
 *	2. Porque o paraque el metodo insert() tiene las
 *	   inatrucciones hijos[0] y/o referencia los
 *	   metodos dividirHijo, insertarNoLleno.
 *	3. Porque el metodo insertarNoLleno es privado y 
 *	   dividirHijo es public.
 *	4. Para que es insertarNoLleno y para que dividirHijo
 *  5. El metodo search y el sobrecargado para que es, 
 *	   como busca?
 *	6. El metodo searchByAttribute y el sobrecargado, 
 *	   que hace, que diferencia hay con el anterior?
 *  7. Que hace el metodo traverse y el sobrecargado.
 *     
 *
 *
 *
 * @author 
 * @version 1.00 2025/10/25
 */


import java.util.Comparator;
import java.util.*;
import java.lang.Comparable;

public class BTree<T extends Comparable<T>> {
    private Node<T> raiz;  // root
    private int grado; // Grado minimo del arbol (t)

    public BTree(){
    }
    public BTree(int grado) {
        this.grado = grado;
        this.raiz = new Node<>(grado, true);
    }
	public Node<T> getRaiz(){
		return raiz;
	}
    public void insert(T dkey) {
        Node<T> r = raiz;
        if (r.nks == 2*grado - 1) {
            Node<T> s = new Node<>(grado, false);
            s.hijos[0] = r;// children hijos
            s.dividirHijo(0, r);// splitChild   dividirHijo
            insertarNoLleno(s, dkey);// insertNonFull  insertarNoLleno
            raiz = s;
        }
        else {
            insertarNoLleno(r, dkey);
        }
    }

    private void insertarNoLleno(Node<T> node, T dkey) {
        int i;
        i = node.nks - 1;
        if (node.hoja) { // keys claves. leaf hoja
            while (i >= 0 && dkey.compareTo(node.claves[i]) < 0) {
                node.claves[i+1] = node.claves[i];
                i--;
            }
            node.claves[i+1] = dkey;
            node.nks=node.nks+1;
        }
        else {
            while (i >= 0 && dkey.compareTo(node.claves[i]) < 0) {
                i--;
            }
            i++;
            if (node.hijos[i].nks == 2*grado-1) {
                node.dividirHijo(i, node.hijos[i]);
                if (dkey.compareTo(node.claves[i]) > 0) {
                    i++;
                }
            }
            insertarNoLleno(node.hijos[i], dkey);
        }
    }

    public T search(T dkey) {
        return search(raiz, dkey);
    }

    private T search(Node<T> node, T dkey) {
        int i = 0;
        while (i < node.nks && dkey.compareTo(node.claves[i]) > 0) {
            i++;
        }
        if (i < node.nks && dkey.compareTo(node.claves[i])==0) {
            return node.claves[i];
        }
        if (node.hoja) {
            return null;
        }
        else {
            return search(node.hijos[i], dkey);
        }
    }
	
    // Metodo para imprimir el arbol (opcional, para depuracion)
    public void traverse() {
        if (raiz != null) {
            raiz.traverse();
        }
    }
    
    public void traverse(Node<T> raiz) {
        int i;
        for (i = 0; i < raiz.nks; i++) {
            if (!raiz.hoja) {
                raiz.hijos[i].traverse();
            }
            System.out.print(raiz.claves[i]);
        }
        if (!raiz.hoja) {
            raiz.hijos[i].traverse();
        }
    }    
    
    public T buscarPorAtributo(T dkey, Comparator<T> comparator) {
        return buscarPorAtributo(raiz, dkey, comparator);
    }

    private T buscarPorAtributo(Node<T> node, T dkey, Comparator<T> comparator) {
        int i = 0;
        while (i < node.nks && comparator.compare(dkey, node.claves[i]) > 0) {
            i++;
        }
        if (i < node.nks && comparator.compare(dkey, node.claves[i]) == 0) {
            return node.claves[i];
        }
        if (node.hoja) {
            return null;
        }
        else {
            return buscarPorAtributo(node.hijos[i], dkey, comparator);
        }
    }
}
