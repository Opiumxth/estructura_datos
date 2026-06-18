/**
 * @(#)TArbolMonton1.java
 *		datos de prueba
 *		a={33,60,5,15,25,12,45,70,35,7};
 *
 *	1. Analice el codigo y complete programa con los  datos mencionados
 *		para obtener los resultados eesperados.
 * 
 * @author 
 * @version 1.00 2020/2/15
 */

import java.util.*;

public class TArbolMonton2 {
   public static void main(String ar[]){
   	int a[]={33,60,5,15,25,12,45,70,35,7};
   	int i,b[],c[],d[];
   	int dat;
   	ArbolMonton2 am1=new ArbolMonton2(a);
		am1.mostrarVector(a); 
		//b=new int[a.length];
		b=am1.ordenaMonticulo(a);  	
		am1.mostrarVector(b); 
   }
}
