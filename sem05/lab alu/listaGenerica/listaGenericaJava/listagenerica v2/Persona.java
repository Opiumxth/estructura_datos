/**
 * @(#)Persona.java
 *
 *
 * @author 
 * @version 1.00 2025/11/11
 */

public class Persona {
    private int id;
    private String nombre;
    private int edad;

    public Persona(){
    }
    public Persona(int id, String nombre, int edad) {
        this.id = id;
        this.nombre = nombre;
        this.edad = edad;
    }

    public int getId() {
        return id;
    }

    public String getNombre() {
        return nombre;
    }

    public int getEdad() {
        return edad;
    }

    @Override
    public String toString() {
    	String cad=new String();
    	cad=String.format("%7d %-15s %5d", id, nombre,edad);
        return cad;
    }
}
