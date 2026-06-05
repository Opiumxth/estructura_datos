/**
 * nombreClase: TBst.java
 * descripcion: operaciones basicas de ABB
 * 
 * 					TAREA ABB GENERICO
 *  0. disponga de 6 a 9 elementos enteros diferentes
 *  1. Construya el ABB para estos elementos 
 *  2. Determine los recorridos en anchura y pre, in y post orden
 *  Analice la aplicacion ABB y cargue datos en un metodo denominado
 *  datosDePrueba()
 *  1. Cargue el arbol con sus datos objetos de tipo entero
 *     1.1 Utilice los dos metodos add sobrecargados y vea la diferencia
 *  2. Muestre los recorridos en anchura y profundidad // no hacer el de anchura porque no lo vimos supongo
 *     2.1 Muestre los recorridos en profundidad
 *     2.2 Implememnte recorrido en anchura y muestre el resultado
 *  3. Determine la altura del arbol //Se tiene que pedir al usuario el nodo del cual se tiene que calcular la altura
 *  4. Pruebe todos los metodos
 *  4. Algunos metodos utilizan la estructura ListaDinamica<>, reutilice // Implementar esta clase de ListaDinamica<T>, lo hicimos en la semana de listas
 *	   La lista dinamica generica derrollada en clases adaptanado o
 *     implementando los metodos que hacen falta  
 *
 *Cada vez que se haga un arbol dibujarlo de manera simple pero que se entienda
 * 
 * @author: FLORES HOYOS, Mathias
 * @date  : 28-05-2026 / Ultima fecha de modificacion
 " @version 1
 */
package paqAbbGenerico;

public class TBst {

    public static void main(String[] args) {

        BinarySearchTree<Integer> arbol = new BinarySearchTree<>();

        Integer i1 = Integer.valueOf(50);
        Integer i2 = Integer.valueOf(30);
        Integer i3 = Integer.valueOf(70);
        Integer i4 = Integer.valueOf(20);
        Integer i5 = Integer.valueOf(40);
        Integer i6 = Integer.valueOf(60);
        Integer i7 = Integer.valueOf(80);

        arbol.add(i1);
        arbol.add(i2);
        arbol.add(i3);
        arbol.add(i4);
        arbol.add(i5);
        arbol.add(i6);
        arbol.add(i7);

        /*
                  50
                /    \
              30      70
             /  \    /  \
           20   40  60   80
        */

        System.out.println("Árbol construido:");
        arbol.mostrar(arbol.getRoot());

        System.out.printf("Inorden: ");
        arbol.inorder(arbol.getRoot());
        System.out.printf("\n");

        System.out.printf("Postorden: ");
        arbol.postorder(arbol.getRoot());
        System.out.printf("\n");

        arbol.height(arbol.getRoot());

        NodoArbolBinario<Integer> n = arbol.getRoot().getLeft();
        arbol.height(n);
    }
}