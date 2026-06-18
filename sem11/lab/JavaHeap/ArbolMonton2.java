/**
 * @(#)ArbolMonton1.java
 *				TAREA
 *
 * 1. Analice el codigo, luego completo el diseno y la espcificacion
 *		de las operaciones, adaptando a la documentacion de Java.
 * 2. Analice las operaciones y comente sistematizando los conceptos 
 *		del AM. 
 * 3. Crear un vector 100 mil con numeros enteros aleatorios y temporizar 
 *		el metodo.
 * 3. Mejore el programa de tal forma que se redimencione
 *		automaticamente, o sea debemos prescindir la utilizacion
 *		de la constante MAX, de esa forma utilizar el espacio de 
 *		memoria libre que hay en el equipo.
 *
 *
 * @author 
 * @version 1.00 2020/2/15
 */
import java.util.*;

public class ArbolMonton2 {
	final int MAX=30;
	int nele;
	int am[];
	
	/**
	 * Constructor por dfecto
	 * PRE: true
	 * POS: vector vacio
	 */   
   public ArbolMonton2() {
   	am=new int[0];
   }

	/**
	 * Constructor inicializa los elementos del vector am con x vector
	 * @param x[]: La dimension de x no debe superar a MAX
	 * POS: Fuera de rango o el am[] con los elementos de x
	 */   
   public ArbolMonton2(int x[]) {
   	int i, nam;
   	am=new int[MAX];
   	nele=x.length;
   	if(nele>MAX){
   		System.out.println("Dimension demasiado grande....!");
   	}
   	else{
	   	for(i=0;i<nele;){
	   		am[i]=x[i];
	   		i=i+1;
	   	}
   	}
   }
	//Meetodo de ordenacion
	public int[] ordenaMonticulo(int x[]){
		int ix,dx,tmp;
		dx=x.length;
		for(ix=dx/2;ix>=0;ix--){
			hacerMonticulo(x,ix,dx-1);
		}
		for(ix=dx-1;ix>=0;ix--){
			tmp=x[0];
			x[0]=x[ix];
			x[ix]=tmp;
			//intercambio(0,ix);
			hacerMonticulo(x,0,ix-1);
		}
		return x;
	}
	//Metodo para el arbol en monton 
	private void hacerMonticulo(int x[], int ix, int fin){
		int izq,der,may,tmp;
		izq=2*ix+1;
		der=izq+1;
		if(izq>fin){
			return;
		}
		if(der>fin){
			may=izq;
		}
		else{
			//may=x[izq]>x[der]?izq:der;
			if(x[izq]>x[der]){
				may=izq;
			}
			else{
				may=der;	
			}
		}
		if(x[ix]<x[may]){
			tmp=x[ix];
			x[ix]=x[may];
			x[may]=tmp;	
			hacerMonticulo(x,may,fin);			
		}
	}  
		 
	public int[] leerVector(int x[]){
		int i,nx,val;
		Scanner jin=new Scanner(System.in);
		System.out.print("Ingrese dimension del vector: ");
		nx=jin.nextInt();
		if(nx>0){
			x=new int[nx];
			for(i=0;i<nx;){
				System.out.print("Ingrese  x["+(i+1)+"] = ");
				val=jin.nextInt();
				x[i]=val;
				i=i+1;
			}
			return(x);
		}
		else{
			System.out.println("Dimension demansiado pequeno...");
			return(null);
		}
	}
	
	public void mostrarVector(int x[]){
		int i,nx;
		nx=x.length;
		if(nx<1){
			System.out.println("Vector vaciooo...!");
		}
		else{
			System.out.print("Vector=<");
			for(i=0;i<nx;){
				System.out.printf("%2d, ", x[i]);
				//System.out.print(x[i]+" ");
				i=i+1;
			}
			System.out.println(">");
		}		
	} 
		
	public boolean arbolVacio() {
		if (nele == 0) {
			return true;
		} 
		else {
			return false;
		}
	} 	 
}
