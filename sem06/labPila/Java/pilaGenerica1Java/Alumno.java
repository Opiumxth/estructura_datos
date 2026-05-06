package paqPilas;

public class Alumno {
    private int cod;
    private String nom;
    private double nota;

    public Alumno(){
    }
    public Alumno(int vcod, String vnom, double vnota){
        cod = vcod;
        nom = vnom;
        nota = vnota;
    }

    public int getCod(){
        return cod;
    }
    public String getNom(){
        return nom;
    }
    public double getNota(){
        return nota;
    }

    @Override
    public String toString(){
        String cad=null;
        cad = String.format("%d %s %8.1f", cod,nom,nota);
        return cad;
    }
}
