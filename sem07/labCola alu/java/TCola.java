/**
 * @(#)TCola.java
 *
 *
 * @author 
 * @version 1.00 2025/4/6
 */


public class TCola {

    public static void main(String[] args) {
        Cola<String> lunas = new Cola<>();

        System.out.println("Elementos en cola: "+lunas.getTalla()+"\n");

        lunas.encolar("Fobos");
        lunas.encolar("Deimos");
        lunas.encolar("Io");
        lunas.encolar("Europa");
        lunas.encolar("Ganimedes");
        lunas.encolar("Calisto");
		lunas.mostrarCola();
        System.out.println("Elementos en cola: "+lunas.getTalla()+"\n");

        System.out.println("Decola: "+lunas.decolar());
        System.out.println("Decola: "+lunas.decolar());
        System.out.println("Decola: "+lunas.decolar());

        System.out.println("#Elementos en cola: "+lunas.getTalla());
        System.out.println("Esta Vacio?: "+lunas.estaVacio()+"\n");

        System.out.println("Decola: "+lunas.decolar());
        System.out.println("Decola: "+lunas.decolar());
        System.out.println("Decola: "+lunas.decolar());

        System.out.println("#Elementos en cola: "+lunas.getTalla()+"\n");

        System.out.println("Decola: "+lunas.decolar());
        System.out.println("Decola: "+lunas.decolar());

        System.out.println("# Elementos en cola: "+lunas.getTalla());
        System.out.println("Rsta Vacio?: "+lunas.estaVacio()+"\n");

        lunas.encolar("Mimas");
        lunas.encolar("Miranda");
        lunas.encolar("Luna");

        System.out.println("#Elementos en cola: "+lunas.getTalla()+"\n");
        System.out.println("Primer elemento: "+lunas.visorCola());
    }
}