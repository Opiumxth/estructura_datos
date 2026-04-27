/**
 * @(#)TLista.java
 *
 *
 * @author 
 * @version 1.00 2025/11/11
 */
 
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.function.Predicate;

public class TLista {
    public static void main(String[] args) {
        Lista<Persona> listaPersonas = new Lista<>();
        
        Persona p1 = new Persona(101, "Carlos", 30,5500.50);
        Persona p2 = new Persona(103, "Helena", 25,6550.89);
        Persona p3 = new Persona(102, "David", 35,4567.65);
        Persona p4 = new Persona(104, "Beatrice", 28,70000.00);

        listaPersonas.agregar(p1);
        listaPersonas.agregar(p2);
        listaPersonas.agregar(p3);
        listaPersonas.agregar(p4);
		
        System.out.println("--- Lista Original ---");
        listaPersonas.imprimirLista();

        // --- Busqueda Generica ---

        System.out.println("\n--- Busqueda por Nombre (String) = 'Helena' ---");
        // Usamos un Predicate para buscar nombres
        Lista<Persona> resultadoNombre = listaPersonas.buscar(p -> p.getNombre().equals("Helena"));
        resultadoNombre.imprimirLista();

        System.out.println("\n--- Busqueda por Edad (Int) = 25 ---");
        // Usamos un Predicate para buscar edades
        Lista<Persona> resultadoEdad = listaPersonas.buscar(p -> p.getEdad() == 25);
        resultadoEdad.imprimirLista();

        // --- Ordenamiento Generico ---

        System.out.println("\n--- Ordenamiento por Salario (Double) (Ascendente) ---");
        // Usamos Comparator.comparingDouble para ordenar por salario
        listaPersonas.ordenar(Comparator.comparingDouble(Persona::getSueldo));
        listaPersonas.imprimirLista();
        
        System.out.println("\n--- Ordenamiento por Nombre (String) (Descendente) ---");
        // Usamos Comparator.comparing para ordenar por nombre y luego revertir
        listaPersonas.ordenar(Comparator.comparing(Persona::getNombre).reversed());
        listaPersonas.imprimirLista();
    }
}