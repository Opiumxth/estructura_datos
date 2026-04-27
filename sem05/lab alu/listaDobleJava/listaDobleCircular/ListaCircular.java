/**
 * @(#)ListaCircular.java
 *				TAREA
 *
 *	0.	Esquematice la lista logica y detalle las operaciones
 *		de isercion y eliminacion de nodos.
 *	1. Compile, ejecute y nalice los resultados.
 * 2. Analice cada una de las operaciones.
 * 3. Que finalidad tiene objetos de tipo Object.
 *	4. Implemente las operaciones basicas de la lista con clases genericas
 * 	con un menejador de exepciones.
 *	5. Complete las operaciones basicas de la lista.
 *
 * @author 
 * @version 1.00 2020/7/1
 */

public class ListaCircular {
	private NodoDoble cab;
	private String nombre;  
	
	public ListaCircular( String cadena ) {
		nombre = cadena;
		cab = null;
	}

	public ListaCircular() { 
		this("Circular"); 
	}  
	//synchronized: un solo proceso puede accesar a la vez
	//Atiende un solo proceso a la vez
	public synchronized void insertarInicio(Object obj){
		if ( estaVacio()) {
			cab = new NodoDoble(obj);
			cab.sgte=cab;
			cab.ante=cab;	
		}
		else {
			NodoDoble actual = cab;
			while(actual.sgte != cab) {
				actual = actual.sgte;
			}
			NodoDoble ultimoNodo = actual;
			
			NodoDoble desplazado = cab;
			cab = new NodoDoble( obj,desplazado,ultimoNodo );
			ultimoNodo.sgte = cab;
			desplazado.ante = cab;
		}
	}

	public synchronized Object eliminarInicio()throws ListaVaciaExcepcion{
		NodoDoble NodoARemover = cab;
		Object obj = null;
		
		if (estaVacio()){
			throw new ListaVaciaExcepcion( nombre );
		}	
				
		obj = cab.objeto;  
		if(cab==cab.sgte){
			cab = null;
		}
		else{
			NodoDoble actual = cab;
			while(actual.sgte != cab) {
				actual = actual.sgte;
			}
			//NodoDoble ultimoNodo = actual;
			NodoDoble ultimoNodo = cab.ante;;
			cab = cab.sgte;
			ultimoNodo.sgte = cab;
			cab.ante = ultimoNodo;
		}	
		NodoARemover.sgte=null;
		NodoARemover.ante=null;
		
		return obj;
	}
	
   public synchronized boolean estaVacio() { 
      return cab == null; 
   }

   public synchronized void mostrarLista() {
      if ( estaVacio() ) {
         System.out.println( "Lista " + nombre + " Vacia"  );
         return;
      }
      System.out.print( "La lista " + nombre + " es: " );
      NodoDoble actual = cab;
      do {
         System.out.print( actual.objeto.toString() + " " );
         actual = actual.sgte;
      } while (actual!=cab );
      System.out.println( "\n" );
   }
}

