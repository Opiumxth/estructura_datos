 /**
 * @(#)THuffman.java
 *		Clase de prueba de arbol de Huffman
 *				TAREA
 *	Se tiene las clses Nodo, Tree, Huffman y HuffmanTransversor:
 *  Analice el codigo, luego compila y ejecute la clase adecuada
 *  y comente brevemente las instrucciones y/o metodos.
 *  1. Pruebe la aplicacion arbol de Huffman y de sus impresiones    
 *     acerca de est aplicacion
 *  2. En el THuffman solo debe haber llamadas a metodos. 
 *     Implemenmte la clase SistemaArbolDeHuffmanm e
 *     implementar el metodo datosDePrueba()
 *  3. Comente las mejoras que debe hacerse e implemente.
 *  
 *
 * @author Okoye Ch. Daniel
 * @version 1.00 2025/10/15
 */
import java.util.*;

public class THuffman
{
    static Huffman huffman;
    private static Scanner input = new Scanner(System.in);
    private static String value;
    
    public static void main(String args[]){
		System.out.print("Enter String: ");
        value = input.nextLine();
        System.out.println("This is the value you entered: "+value);
        huffman = new Huffman(value);
        System.out.println("The bit representation of the String you entered is: "+huffman.hC.finalBitPattern);  
	}
}
