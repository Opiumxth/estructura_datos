/**
 * @(#)ListaVaciaExcepcion.java
 * 		Anlice el codigo.
 *
 * @author 
 * @version 1.00 2020/7/2
 */

public class ListaVaciaExcepcion extends RuntimeException {

   // inicializa an ExcepcionListaVacia
   public ListaVaciaExcepcion(){
      super();
   }
   public ListaVaciaExcepcion( String nombre ){
      super( "La lista xxx" + nombre + " esta vacia" );
   }

	public String toString(){
		String cad="Se ha produido la excepcion"+this.getClass().getName()+"\n"+"No hay elementos..."+this.getMessage()+"";
		return(cad);
	}
}
