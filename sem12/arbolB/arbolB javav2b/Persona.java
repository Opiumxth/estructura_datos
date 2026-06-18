/**
 * @(#)Persona.java
 *
 *
 * @author 
 * @version 1.00 2025/10/25
 */

public class Persona implements Comparable<Persona> {
    private int dni; //problemas para manejo compareTo
    //private String dni;
    private String nombre;

    public Persona(){
    }
    public Persona(int dni,String nombre) {
        this.dni = dni;
        this.nombre = nombre;
    }

    public int getDni() {
        return dni;
    }
    public String getNombre() {
        return nombre;
    }
    
    // Metodo para comparar objetos Persona
    @Override
    public int compareTo(Persona otraPersona) {
        return this.nombre.compareTo(otraPersona.nombre);
    }
	
    @Override
    public String toString() {
    	String cad;
    	cad=String.format("%10d %-15s\n",dni,nombre);
        return cad;
    }
}
