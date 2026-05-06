/**
 * @(#)TPila.java
 *
 *
 * @author 
 * @version 1.00 2025/4/6
 */


public class TPila {

    public static void main(String ar[]) {
    	Integer i1=11;
    	//Integer i1 = new Integer(11);
    	Integer i2 = new Integer(22);
    	Integer i3 = new Integer(33);
    	Integer i4 = new Integer(44);
    	Integer i5 = new Integer(55);
    	
    	Pila<Integer> p1=new Pila<>();
    	p1.push(i1);
    	p1.push(i2);
    	p1.push(i3);
    	p1.push(i4);
    	
    	System.out.println("Valor depilado: "+ p1.pop());
    	System.out.println("Valor Tope    : "+ p1.peek());
    	System.out.println("Size de   pila: "+ p1.size());
    	
    }
}