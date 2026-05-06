/**
 * @(#)TPila.java
 *
 *
 * @author 
 * @version 1.00 2020/7/10
 */

import java.util.*;
public class TPila {
    public static void main(String ar[])throws Exception {
        Pila pila = new Pila();
        
        System.out.println("\tEjemplo de Pila\n\n");
        pila.empilar(11);
        pila.empilar(22);
        pila.empilar(33);
        pila.empilar(44);
        pila.empilar(55);
        
        pila.listar();
        //System.out.println("\n\tTamano");
        System.out.println("\n\tTamano: "+pila.getTamanio());
        
        System.out.println("\nDepila elemento del tope...");
        pila.depilar();
        System.out.println("\tEstado actual de la Pila\n\n");
        pila.listar();
        System.out.println("\n\tTamano: " + pila.getTamanio());
        
        System.out.println("\n\tEdita el valor 333 por 33\n");
        pila.editar(333, 33);
        System.out.println("\tEstado actual de la Pila\n\n");
        pila.listar();
        System.out.println("\n\tTamano: " + pila.getTamanio());
        
        System.out.println("\n\tEliminar el nodo con el valor 22\n");
        pila.remover(22);
        System.out.println("\tEstado actual de la Pila\n\n");
        pila.listar();
        System.out.println("\n\tTamano: " + pila.getTamanio());
        
        System.out.println("\n\tConsulta si existe el valor 65");
        System.out.println(pila.buscar(65));
        
        System.out.println("\n\tConsulta el valor tope de la pila");
        System.out.println("Valor del tope: " + pila.cima());
        System.out.println("\tEstado actual de la Pila\n\n");
        pila.listar();
        
        
        System.out.println("\n\tElimina la pila");
        pila.eliminar();
        System.out.println("\tEstado actual de la Pila\n\n");
        pila.listar();
        
        System.out.println("\n\tConsulta si la pila esta vacia");
        System.out.println(pila.estaVacia());
        
    }
}