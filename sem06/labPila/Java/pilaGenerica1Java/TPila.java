package paqPilas;

public class TPila {
    public static void main(String[] args) {
        Pila<String> libros = new Pila<>();

        libros.empilar("El Quijote");
        libros.empilar("Cien años de soledad");

        System.out.println("En la cima: " + libros.visorPila()); // Cien años de soledad
        System.out.println("Sacando: " + libros.depilar());    // Cien años de soledad
        System.out.println("Nueva cima: " + libros.visorPila()); // El Quijote

        Pila<Integer> pent = new Pila<>();

        pent.empilar(11);
        pent.empilar(22);
        pent.empilar(33);

        System.out.println("Cima: "+pent.visorPila() );
        System.out.println("Depilado: "+pent.depilar() );
        System.out.println("Cima: "+pent.visorPila() );

        Pila<Alumno> palu = new Pila<>();

        Alumno a1 = new Alumno(101, "eva", 15.8);
        Alumno a2 = new Alumno(103, "pepe", 12.5);
        Alumno a3 = new Alumno(105, "juana", 14.4);
        palu.empilar(a1);
        palu.empilar(a2);
        palu.empilar(a3);

        System.out.println("Cima: "+palu.visorPila() );
        System.out.println("Depilado: "+palu.depilar() );
        System.out.println("Cima: "+palu.visorPila() );

    }
}
