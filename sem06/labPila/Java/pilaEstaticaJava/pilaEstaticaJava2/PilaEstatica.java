/**
 * @(#)PilaEstatica.java
 *		TAREA
 *	Complete y mejore la implementacion de las operaciones basicas
 *  para una pila pasado por paramaetro.
 *
 * @author 
 * @version 1.00 2020/7/10
 */
import java.util.*;
public class PilaEstatica {
	final int MAX = 5;
	Object Pila[] = new Object[MAX];
	int tope=-1;
	
	public PilaEstatica(){
	}
	
	public boolean pilaVacia(Object Pila[],int tope){
		return tope == -1;
	}
	
	public boolean pilaLlena(Object Pila[], int tope, int MAX){
		return tope == MAX-1;
	}

	public void push(Object Pila[],Object Dato,int tope,int MAX){
		if (pilaLlena()==true) {
			System.out.println("\nPila llena...");
		} 
		else {
			tope ++;
			Pila[tope] = Dato;
			System.out.println(tope);
		}
	}
	
	public Object pop(Object Pila[],int tope){
		Object Dato = null;
		if (pilaVacia()) {
			System.out.println("\nPila Vacia..."); 
		} 
		else {
			Dato = Pila[tope];
			tope --;
		}
		return Dato;
	}

	public void desplegarPila(Object Pila[],int tope){
		if (pilaVacia() == true) {
			System.out.println("\nPila vacia...");
		} 
		else {
			System.out.print("\nDatos de la pila: { ");
			for (int i = 0; i<=tope; i++) {
				System.out.printf("%d, ",Pila[i]);
			}
			System.out.println("}\n");
		}
	}
	public void menu(){
		Object dato;
		int opc;
		Scanner teclado = new Scanner(System.in);
		PilaEstatica p1=new PilaEstatica();

		do{
			System.out.println("\nOPERACIONES DE PILA\n");
			System.out.println("0. SALIR");
			System.out.println("1. Push");
			System.out.println("2. Pop");
			System.out.println("3. Desplegar Pila\n");
			System.out.print("Digite su opcion ---> ");
			opc = teclado.nextInt();
			
			switch(opc){
				case 0:
					System.out.println("\nEl programa a terminado...\n");
					System.exit(0);
				case 1: 				
					System.out.print("\nDato a empilar: ");
					dato = teclado.nextInt();
					p1.push(dato);
					break;
				case 2: 
					dato = p1.pop();
					if (dato != null) {
						System.out.println("\n"+dato+" Depilado... ");
					}
					break;
				case 3:
					p1.desplegarPila();
					break;
				default:
					System.out.println("\nERROR: Opcion invalida");
			}
		}while(opc!=4);
	}	
}