/**
 * @(#)TCola.java
 *
 *
 * @author 
 * @version 1.00 2025/4/6
 */

import java.util.*;
public class TCola {
   public static void main(String ar[]) {
  		
    	Integer i1 = new Integer(11);
    	Integer i2 = new Integer(22);
    	Integer i3 = new Integer(33);
    	Integer i4 = new Integer(44);
    	Integer i5 = new Integer(55);

    	Cola<Integer> c1=new Cola<>();
    	c1.enqueue(i1);
    	c1.enqueue(i2);
    	c1.enqueue(i3);
    	c1.enqueue(i4);
    	c1.enqueue(i5);
    	
    	System.out.println("Valor depilado: "+ c1.dequeue());
    	System.out.println("Valor Tope    : "+ c1.first());
    	System.out.println("Size de   cola: "+ c1.size());
    	
    }  
}