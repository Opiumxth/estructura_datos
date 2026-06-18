/**
 * @(#)GestionArbolB.java
 *		La clase implementa metodos con los datos 
 *		de prueba del arbol B.
 *			TAREA
 *	0. Analice el codigo, luego compile, ejecute y 
 *	   analice los resultados.
 *	1. Ahora se requiere metodos con los datos de prueba
 *	   solo para los datos, otro para ejecutar las 
 *	   operaciojnes del usuario como insertar, buscar, 
 *	   eliminar, implemente dicha mejora.
 *
 *
 * @author 
 * @version 1.00 2025/10/31
 */

import java.util.*;

public class GestionArbolB {

    public GestionArbolB() {
    }
    
    public void datosDePrueba1(){
    	//Comparator<Persona> dniComparator = Comparator.comparingInt(Persona::getDni);//Revisa no funciona: objeto string

        // Crear un comparador para buscar por codigo de curso
    	Comparator<Curso> codigoComparator = Comparator.comparing(Curso::getCod);
        BTree<Curso> bcur = new BTree<>(3);
		
		Curso c1=new Curso("C031001","Algoritmica I", 4, "III");
		Curso c2=new Curso("C041001","Algoritmica II", 4, "IV");
		Curso c3=new Curso("C051003","Estructura de datos", 5, "V");
		bcur.insert(c1);
		bcur.insert(c2);
		bcur.insert(c3);

        System.out.println("\nELEMENTOS CURSO DEL ARBOL B\n");
        bcur.traverse(bcur.getRaiz());
		System.out.println("\nBusqueda por codigo de Curso");
        // Crear un objeto Curso de busqueda con el codigo deseado
        Curso kcod = new Curso("C041001","", 0, "");
        // Usar el metodo de busqueda por atributo
        Curso bcod = bcur.buscarPorAtributo(kcod, codigoComparator);
        if (bcod != null) {
            System.out.println("Curso encontrado:\n" + bcod);
        }
        else {
            System.out.println("Curso no encontrado.");
        }		
        
        // Crear un comparador para buscar por nombre de persona
    	Comparator<Persona> nombreComparator = Comparator.comparing(Persona::getNombre);
        BTree<Persona> bper = new BTree<>(3);
		
		Persona p1=new Persona(15345,"Juan");
		Persona p2=new Persona(67893,"Ana");
		Persona p3=new Persona(11923,"Luis");
		Persona p4=new Persona(18356,"Janet");
        bper.insert(p1);
        bper.insert(p2);
        bper.insert(p3);
        bper.insert(p4);
        
        System.out.println("\nELEMENTOS PERSONA DEL ARBOL B\n");
        bper.traverse();
        //bper.traverse(bper.getRoot());        
        
		System.out.println("Busqueda por Nombre de Persona");            
        // Crear un objeto Persona de busqueda por nombre deseado
        Persona knom = new Persona(0, "Ana");
        // Usar el metodo de busqueda por atributo
        Persona bnom = bper.buscarPorAtributo(knom, nombreComparator);

        if (bnom != null) {
            System.out.println("Persona encontrada:\n" + bnom);
        }
        else {
            System.out.println("Persona no encontrada.");
        }	
    }

}