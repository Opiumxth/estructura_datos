/**
 * @(#)TAbb.java
 *
 *
 * @author
 * @version 1.00 2023/5/26
 */

import java.util.*;

public class TAbb {

public static void main(String[] args) {

    //Creamos el Arbol binario de Busqueda
    Abb abb = new Abb();

    //Insertamos nos nodos
    abb.insertarElemento(15);
    abb.insertarElemento(9);
    abb.insertarElemento(20);
    abb.insertarElemento(6);
    abb.insertarElemento(14);
    abb.insertarElemento(13);
    abb.insertarElemento(17);
    abb.insertarElemento(64);
    abb.insertarElemento(72);
    abb.insertarElemento(26);

    //Imprimimos el número de elementos que tenemos:
    System.out.println("Número de elementos: " + abb.size());

    //Obtenemos los números ordenados ascendentemente
    ArrayList<Integer> numerosOrdenadosAscedentemente = abb.obtenerElementosOrdenadosAscendentemente();
    System.out.print("Lista de números ordenados ascendentemente: [ ");

    for (Integer numero: numerosOrdenadosAscedentemente) {
        System.out.print(numero + " ");
    }
    System.out.print("]\n");

    //Obtenemos los números ordenados descendentemente
    ArrayList<Integer> numerosOrdenadosDescedentemente = abb.obtenerElementosOrdenadosDescendentemente();
    System.out.print("Lista de números ordenados descendentemente: [ ");

    for (Integer numero: numerosOrdenadosDescedentemente) {
        System.out.print(numero + " ");
    }
    System.out.print("]\n");

    //Realizamos diferentes búsquedas
    if (abb.buscarElemento(20) != null) {
        System.out.println("Elemento encontrado");
    }else {
        System.out.println("Elemento no encontrado");
    }

    if (abb.buscarElemento(72) != null) {
        System.out.println("Elemento encontrado");
    }else {
        System.out.println("Elemento no encontrado");
    }

    if (abb.buscarElemento(56) != null) {
        System.out.println("Elemento encontrado");
    }else {
        System.out.println("Elemento no encontrado");
    }

    if (abb.buscarElemento(6) != null) {
        System.out.println("Elemento encontrado");
    }else {
        System.out.println("Elemento no encontrado");
    }

    if (abb.buscarElemento(9) != null) {
        System.out.println("Elemento encontrado");
    }else {
        System.out.println("Elemento no encontrado");
    }

    //imprimimos estadisticas
    System.out.println("Numero de iteraciones en la última búsqueda: " + abb.getNumeroIteracionesUltimaBusqueda());
    System.out.println("Numero de iteraciones medio en las búsquedas: " + abb.getNumeroIteracionesMedioEnBusquedas());

    //Eliminamos nodos
    //Eliminamos la raiz
    abb.eliminarElemento(15);
    //Eliminamos nodos
    abb.eliminarElemento(13);
    abb.eliminarElemento(14);
    abb.eliminarElemento(64);

    //Buscamos los elementos eliminado
    if (abb.buscarElemento(15) != null) {
        System.out.println("Elemento encontrado");
    }else {
        System.out.println("Elemento no encontrado");
    }

    if (abb.buscarElemento(13) != null) {
        System.out.println("Elemento encontrado");
    }else {
        System.out.println("Elemento no encontrado");
    }

    if (abb.buscarElemento(14) != null) {
        System.out.println("Elemento encontrado");
    }else {
        System.out.println("Elemento no encontrado");
    }

    if (abb.buscarElemento(64) != null) {
        System.out.println("Elemento encontrado");
    }else {
        System.out.println("Elemento no encontrado");
    }

    //Obtenemos los números ordenados ascendentemente
    numerosOrdenadosAscedentemente = abb.obtenerElementosOrdenadosAscendentemente();
    System.out.print("Lista de números ordenados ascendentemente: [ ");

    for (Integer numero: numerosOrdenadosAscedentemente) {
        System.out.print(numero + " ");
    }
    System.out.print("]\n");

    //Obtenemos los números ordenados descendentemente
    numerosOrdenadosDescedentemente = abb.obtenerElementosOrdenadosDescendentemente();
    System.out.print("Lista de números ordenados descendentemente: [ ");

    for (Integer numero: numerosOrdenadosDescedentemente) {
        System.out.print(numero + " ");
    }
    System.out.print("]\n");

    //Imprimimos el número de elementos que tenemos:
    System.out.println("Número de elementos: " + abb.size());
}
}