/**
 * @(#)Curso.java
 *		Operaciones basicas de la clae Curso
 *				TAREA
 * ). Analice el codigo
 * 2. Para que implementa Comparable
 * 3. Que operaciones le permite realizar el metodo 
 *	  compareTo
 *	  3.1 Implemente un vector de cursos y haga busquedas
 *        por cualquiera de los atributos.		
 *
 *
 * @author 
 * @version 1.00 2025/10/25
 */

public class Curso implements Comparable<Curso> {
    private String cod; 
    private String nombre;
    private int cred;
    private String ciclo;

    public Curso(){
    }
    public Curso(String cod,String nombre, int cred, String ciclo) {
        this.cod = cod;
        this.nombre = nombre;
        this.cred = cred;
        this.ciclo = ciclo;
    }

    public String getCod() {
        return cod;
    }
    public String getNombre() {
        return nombre;
    }
    public int getCred() {
        return cred;
    }
    public String getCiclo() {
        return ciclo;
    }
    
    // Metodo para comparar objetos Persona
    @Override
    public int compareTo(Curso otroCurso) {
        return this.cod.compareTo(otroCurso.cod);
    }
	
    @Override
    public String toString() {
    	String cad;
    	cad=String.format("%10s %-20s %4d %10s\n",cod,nombre,cred,ciclo);
        return cad;
    }
}
