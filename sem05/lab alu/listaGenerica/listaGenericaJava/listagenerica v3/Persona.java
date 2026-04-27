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
    private double sueldo;

    public Persona(){
    }
    public Persona(int id,String nombre,int edad,double sueldo) {
        this.id = id;
        this.nombre = nombre;
        this.edad = edad;
        this.sueldo = sueldo;
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
    public double getSueldo() {
        return sueldo;
    }

    @Override
    public String toString() {
    	String cad=new String();
    	cad=String.format("%7d %-15s %5d %10.2f", id,nombre,edad,sueldo);
        return cad;
    }
}
