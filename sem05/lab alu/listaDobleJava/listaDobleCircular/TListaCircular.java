/**
 * @(#)TListaCircular.java
 *			Analice el codigo.
 *			
 *
 * @author 
 * @version 1.00 2020/7/1
 */

public class TListaCircular {
	public static void main( String args[]){
		ListaCircular lista = new ListaCircular();  
		/*
		Boolean booleano = Boolean.TRUE;
		Character caracter = new Character( '$' );
		Integer entero = new Integer( 34567 );
		String cadena = "hola";
		lista.insertarInicio( booleano );
		lista.mostrarLista();
		lista.insertarInicio( caracter );
		lista.mostrarLista();
		lista.insertarInicio( entero );
		lista.mostrarLista();
		lista.insertarInicio( cadena );
		lista.mostrarLista();
		Object objetoRemovido;
		*/
		Integer n1 = new Integer(11);
		Integer n2 = new Integer(22);
		Integer n3 = new Integer(33);
		lista.insertarInicio(n1);
		lista.mostrarLista();
		lista.insertarInicio(n2);
		lista.mostrarLista();
		lista.insertarInicio(n3);
		lista.mostrarLista();
		Object objetoRemovido;
		try {
			objetoRemovido = lista.eliminarInicio();
			System.out.println(objetoRemovido.toString()+" removido");
			lista.mostrarLista();
			/*
			objetoRemovido = lista.eliminarInicio();
			System.out.println(objetoRemovido.toString()+" removido");
			lista.mostrarLista();
			objetoRemovido = lista.eliminarInicio();
			System.out.println(objetoRemovido.toString()+" removido");
			lista.mostrarLista();
			System.out.println("hola 1");
			objetoRemovido = lista.eliminarInicio();
			System.out.println(objetoRemovido.toString()+" removido");
			lista.mostrarLista();
			System.out.println("hola 2");
			objetoRemovido = lista.eliminarInicio();
			System.out.println(objetoRemovido.toString()+" removido");
			lista.mostrarLista();
			*/
			
		}
		catch ( ListaVaciaExcepcion elv ) {
			elv.printStackTrace();
		}
	}
}
/*
 *     


 **/