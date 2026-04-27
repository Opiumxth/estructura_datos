/**
 * @(#)TLista.java
 *	Descripcion: Testea las operaciones de lista enlazada doble
 *
 *					TAREA 1
 *	Analice, compile y ejecute.
 *	1. Analice cda de las operaciones y comente adecuadamente las instrucciones
 *		de las operaciones
 *	2. Complete las especificaciones de cada una de las operaciones
 * 				Problema
 * 1. Se tiene dos enteros 1234 y 9878799001 se pide: Hallar la suma de los dos 
 *		numeros en una lista enlazada cuyos numeros tambien esta representados 
 *		en sendas listas. Implemente las operaciones necesarias en esta  
 *		aplicacion.
 *
 * @author GASA
 * @version 1.00 2020/01/18
 */

import java.util.Scanner;

public class TLista {

	public static void main(String ar[]){
		int num, dato;
		Nodo q;
		Lista la=new Lista();
			
		la.insertarInicio(33);
		la.insertarInicio(22);
		la.insertarInicio(11);
		la.mostrarLista();
		/*
		la.insertarFinal(50);	
		la.mostrarLista();
		
		la.eliminarNodo(33);			
		la.mostrarLista();
		*/
		la.insertarOrdenado(100);
		la.mostrarLista();
		q=la.buscarNodo(22);
		System.out.println(q);
			
		la.insertarDespues(q, 25);
		
		la.mostrarLista();
		
	}        
}