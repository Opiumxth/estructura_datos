/**
 * @(#)NodoDoble.java
 *
 *
 * @author 
 * @version 1.00 2020/7/1
 */


class NodoDoble {
   Object objeto;    
   NodoDoble sgte;
   NodoDoble ante;

   public NodoDoble(Object obj) { 
      this(obj,null,null ); 
   }
   public NodoDoble(Object obj, NodoDoble vsgte, NodoDoble vante){
      objeto = obj;    
      sgte = vsgte;
      ante = vante;   
   }
   public Object obtenerObjeto() { 
      return objeto; 
   }

   public NodoDoble obtenerSiguiente(){ 
      return sgte; 
   }
   
   public NodoDoble obtenerAnterior() {
   	return ante; 
   }
   //mmm
} 
