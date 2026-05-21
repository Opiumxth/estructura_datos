/**
 * @(#)TPila.java
 *
 *
 * @author 
 * @version 1.00 2025/4/6
 */


public class TPila {

    public static void main(String[] args) {
        Pila<String> lunas = new Pila<>();

        System.out.println("Elementos en pila: "+lunas.getTalla()+"\n");

        lunas.empilar("Fobos");
        lunas.empilar("Deimos");
        lunas.empilar("Io");
        lunas.empilar("Europa");
        lunas.empilar("Ganimedes");
        lunas.empilar("Calisto");
		lunas.mostrarPila();
        System.out.println("# Elementos en pila: "+lunas.getTalla()+"\n");

        System.out.println("Depila: "+lunas.depilar());
        System.out.println("Depila: "+lunas.depilar());
        System.out.println("Depila: "+lunas.depilar());

        System.out.println("# Elementos en pila: "+lunas.getTalla());
        System.out.println("Esta Vacio?: "+lunas.estaVacio()+"\n");

        System.out.println("Depila: "+lunas.depilar());
        System.out.println("Depila: "+lunas.depilar());
        System.out.println("Depila: "+lunas.depilar());

        System.out.println("# Elementos en pila: "+lunas.getTalla()+"\n");

        System.out.println(lunas.depilar());
        System.out.println(lunas.depilar());

        System.out.println("# Elementos en pila: "+lunas.getTalla());
        System.out.println("Esta Vacio?: "+lunas.estaVacio()+"\n");

        lunas.empilar("Mimas");
        lunas.empilar("Miranda");
        lunas.empilar("Luna");

        System.out.println("# Elementos en pila: "+lunas.getTalla()+"\n");
        System.out.println("Primer elemento: "+lunas.visorPila());
    }
}