/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package tareaarbolserializable;
import java.util.*;


public class TareaArbolSerializable {
    public static void main(String ar[]) {
        // valores
        int i0=12, i1=15, i2=1, i3=4, i4=25, i5=99, i6=4, i7=11, i8=7, i9=19;
        // nodos
        Nodo<Integer> n12 = new Nodo<>(i0);
        Nodo<Integer> n15 = new Nodo<>(i1);
        Nodo<Integer> n1  = new Nodo<>(i2);
        Nodo<Integer> n4  = new Nodo<>(i3);
        Nodo<Integer> n25 = new Nodo<>(i4);
        Nodo<Integer> n99 = new Nodo<>(i5);
        Nodo<Integer> n42 = new Nodo<>(i6);
        Nodo<Integer> n11 = new Nodo<>(i7);
        Nodo<Integer> n7  = new Nodo<>(i8);
        Nodo<Integer> n19 = new Nodo<>(i9);

        // construccion del arbol
        //        12
        //      / | \ \
        //    15  99  4  7
        //   /|\     /\
        //  1  4 25  11 19
        n15.agregarHijo(n1);
        n15.agregarHijo(n4);
        n15.agregarHijo(n25);
        n42.agregarHijo(n11);
        n42.agregarHijo(n19);
        n12.agregarHijo(n15);
        n12.agregarHijo(n99);
        n12.agregarHijo(n42);
        n12.agregarHijo(n7);

        ArbolNArio<Integer> arbol = new ArbolNArio<>(n12);

        // 1. existe un nodo
        System.out.println("1. Existe 25? R: " + arbol.existe(25));
        System.out.println("1. Existe 99? R: " + arbol.existe(99));
        System.out.println("1. Existe 50? R: " + arbol.existe(50));

        // 2. numero total de nodos
        System.out.println("\n2. Total nodos: " + arbol.getNumeroNodos());

        // 3. descendientes
        System.out.println("\n3. Descendientes de 15: " + arbol.getNumeroDescendientes(n15));
        System.out.println("3. Descendientes de 4:  " + arbol.getNumeroDescendientes(n42));
        System.out.println("3. Descendientes de 12: " + arbol.getNumeroDescendientes(n12));

        // 4. ramas
        System.out.println("\n4. Ramas:");
        for (ArrayList<Nodo<Integer>> rama : arbol.getRamas()) {
            System.out.println("   " + rama);
        }

        // 5. camino mas largo
        System.out.println("\n5. Camino mas largo: " + arbol.caminoMasLargo());
        System.out.println("5. Longitud: " + arbol.getCaminoMasLargo());

        // 6. recorridos recursivos (versión original)
        ArrayList<Nodo<Integer>> anod = new ArrayList<>();
        anod = arbol.getPreOrder();
        System.out.print("\n6. PreOrden  (recursivo):  ");
        for (Nodo<Integer> nod : anod) System.out.printf("%4d", nod.getDato());

        anod = arbol.getPostOrder();
        System.out.print("\n6. PostOrden (recursivo):  ");
        for (Nodo<Integer> nod : anod) System.out.printf("%4d", nod.getDato());

        // 7. recorridos iterativos (Tarea 02 - Punto 1)
        anod = arbol.getPreOrdenIterativo();
        System.out.print("\n\n7. PreOrden  (iterativo):  ");
        for (Nodo<Integer> nod : anod) System.out.printf("%4d", nod.getDato());

        anod = arbol.getInOrdenIterativo();
        System.out.print("\n7. InOrden   (iterativo):  ");
        for (Nodo<Integer> nod : anod) System.out.printf("%4d", nod.getDato());

        anod = arbol.getPostOrdenIterativo();
        System.out.print("\n7. PostOrden (iterativo):  ");
        for (Nodo<Integer> nod : anod) System.out.printf("%4d", nod.getDato());

        // 8. salvar y recuperar (Tarea 02 - Punto 2)
        System.out.println("\n\n8. Salvar y Recuperar:");
        String archivo = "arbol.txt";
        arbol.salvar(archivo);

        ArbolNArio<Integer> arbol2 = new ArbolNArio<>();
        arbol2.recuperar(archivo);

        anod = arbol2.getPreOrdenIterativo();
        System.out.print("   PreOrden arbol recuperado: ");
        for (Nodo<Integer> nod : anod) System.out.printf("%4d", nod.getDato());
        System.out.println();
        System.out.println("   Total nodos recuperados: " + arbol2.getNumeroNodos());
    }
}