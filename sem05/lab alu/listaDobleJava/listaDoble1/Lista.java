/**
 * @(#)Lista.java
 *		Clase con las operaciones basicaas de listas dobles
 *
 *		Analice cada una de las operaciones para su entendimiento
 *		analice los casos cuando se inserta, elimin al inicio o al 
 *		final, o se inserta antes o despues de unnoddo dado.
 *				TAREA
 *	1. Complete las especificaciones de cada una de las operaciones.
 * 2. Implemente un metodo que devuelva una lista.
 * 3. Implementes los metodos por ejemplo que elimina, busqu o
 *    inserta nodos en una lista que llega como parametro.
 * 4. Convierta esta clase que opere con Object y con lista generica, 
 *    osea class NodoDoble <TD> {}, class ListaDoble<TD> {}
 * 

 * @author GASA
 * @version 1.00 2021/4/16
 */

import java.util.Scanner;

public class Lista {
   Nodo cab;
   
	/**
	 * 
	 * PRE: 
	 * POS:
	 */    
	public Lista(){
		cab = null;
	}
	
	/**
	 * Inserta nodo al incio de la lista
	 * PRE: 
	 * POS:
	 */ 
	public void insertarInicio(int dato){
		Nodo neo;
		neo=new Nodo(dato);
		//Consistencia de la variable nuevo
		
		if (cab==null ){
			//neo.sgte=cab;
			//cab.ante=neo;
			cab=neo;
		}
		else{
			neo.sgte=cab;
			cab.ante=neo;
			cab=neo;			
		}
	}
	
	/**
	 * Mostrar lista
	 * PRE: 
	 * POS:
	 */ 
	public void mostrarLista(){
		Nodo n;
		int k = 1;
		n = cab;
		if(n!=null){
			System.out.print("Lista = <");
			while (n != null){
				System.out.print(n.dato + " ");
				n = n.sgte;
				//System.out.print(((k%10 != 0)&& (n!= null)) ? " " : "\n");
				k=k+1;
			}
			System.out.println(">");
		}
		else{
			System.out.println("Lista vaciaaaa...!");
		}
	}
	
	/**
	 * Inserta nodo al final de la lista
	 * PRE: 
	 * POS:
	 */ 
	public void insertarFinal(int dato){
		Nodo neo,p;
		neo = new Nodo(dato);
		//Consistencia de la variable nuevo
		
		if (cab == null ){
			neo.sgte=cab;
			cab.ante=neo;
			cab=neo;
		}
		else{
			p=cab;
			while(p.sgte!=null){
				p=p.sgte;
			}
			p.sgte=neo;
			neo.ante=p;
		}
	}
	
	/**
	 * Elimina nodo de valor dato
	 * PRE: 
	 * POS:
	 */ 
	public void eliminarNodo(int dato){
		Nodo p;
		boolean hallado=false;
		p = cab;
		// Bucle de búsqueda
		while (( p!=null) && (!hallado)){
			/* la comparación se realiza con el método equals()...,
			depende del tipo Elemento */
			hallado = (p.dato == dato);
			if (!hallado){
				p = p.sgte;
			}
		}
		// Enlace de nodo anterior con el siguiente
		if (p != null){
		//distingue entre nodo cabecera o resto de la lista
			if (p == cab){
				cab = p.sgte;
				if (p.sgte != null){
					p.sgte.ante = null;
				}
			}
			else {
				if (p.sgte != null){
					// No es el último nodo
					p.ante.sgte = p.sgte;
					p.sgte.ante = p.ante;
				}
				else{
					// último nodo
					p.ante.sgte = null;
				}
				p = null;
			}
		}
	}

	/**
	 * Inserta el nodo dato en lisa ordenada
	 * PRE: 
	 * POS:
	 */ 
	public void insertarOrdenado(int dato){
	   Nodo p, q, r;
	   //p=(NODO*) malloc(sizeof(NODO));
	   p = new Nodo(dato);
	   //Consistencia de p
	   p.dato=dato;
	   p.sgte=null;
	   p.ante=null;
	
	   if(cab==null){
	      cab=p;
	   }
	   else{
	      q=cab;
	      r=q;
	      while(q!=null && q.dato<dato){
	         r=q;
	         q=q.sgte;
	      }
	      if(r==cab && r.dato>dato){
	         p.sgte=cab;
	         (cab).ante=p;
	         cab=p;
	      }
	      else{
	         if(r.sgte==null){
	            r.sgte=p;
	            p.ante=r;
	         }
	         else{
	            p.sgte=r.sgte;
	            r.sgte=p;
	            p.ante=r;
	            (p.sgte).ante=p;
	         }
	      }
	   }
	}
	
	/**
	 * Busca y retorna un nodo con dato
	 * PRE: 
	 * POS:
	 */ 	
	public Nodo buscarNodo(int dato ){
		Nodo p;
		boolean hallado=false;
		p=cab;
		if(p!=null){
			while(p!=null && !hallado){
				if(p.dato==dato){
					hallado=true;
					return(p);
				}
				p=p.sgte;
			}
			if(!hallado){
				return(p);
			}
		}
		else{
			System.out.println("Lista vaciaaa...!");
		}
		return(p);		
	}		
	/**
	 * Inserta un nodo despues de un nodo dado
	 * PRE: Lista de tipo int vacia o con elementos y contiene nodo anterior
	 * POS: Lista con un elemento ento o Lista con elemento adicional dato
	 */
	public Lista insertarDespues(Nodo anterior, int dato){
		Nodo nuevo;
		nuevo = new Nodo(dato);
		nuevo.sgte = anterior.sgte;
		if (anterior.sgte !=null) {
			anterior.sgte.ante = nuevo;
		}
		anterior.sgte = nuevo;
		nuevo.ante = anterior;
		return this;
	}
	
}