/**
 * @(#)TLista.java
 *
 *
 * @author 
 * @version 1.00 2025/11/11
 */


public class TLista {
    public static void main(String[] args) {
        Lista<Persona> listaPersonas = new Lista<>();
        
        Persona p1 = new Persona(101, "Carlos", 30);
        Persona p2 = new Persona(103, "Ana", 25);
        Persona p3 = new Persona(102, "David", 35);
        Persona p4 = new Persona(104, "Beatriz", 28);

        listaPersonas.anadir(p1);
        listaPersonas.anadir(p2);
        listaPersonas.anadir(p3);
        listaPersonas.anadir(p4);
		/*
        listaPersonas.anadir(new Persona(101, "Carlos", 30));
        listaPersonas.anadir(new Persona(103, "Ana", 25));
        listaPersonas.anadir(new Persona(102, "David", 35));
        listaPersonas.anadir(new Persona(104, "Beatriz", 28));
		*/
        System.out.println("--- Lista Original ---");
        listaPersonas.imprimirLista();

        // Busqueda por ID
        int idABuscar = 102;
        Persona encontrada = listaPersonas.buscarPorId(idABuscar);
        System.out.println("\n--- Busqueda ---");
        if (encontrada != null) {
            System.out.println("Persona encontrada con ID " + idABuscar + ": " + encontrada.toString());
        }
        else {
            System.out.println("Persona con ID " + idABuscar + " no encontrada.");
        }

        // Ordenamiento por nombre
        listaPersonas.ordenarPorNombre();
        System.out.println("\n--- Lista Ordenada por Nombre ---");
        listaPersonas.imprimirLista();
    }
}