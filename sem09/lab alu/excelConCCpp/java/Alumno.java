/**
 * @(#)Alumno.java
 *
 *
 * @author 
 * @version 1.00 2020/6/13
 */


public class Alumno {
	int cod;
	String nom;
	double nota;
	
   public Alumno() {
   }
	
	public void setCod(int vcod){
		cod=vcod;
	}   
	public void setNom(String vnom){
		nom=vnom;
	}   
	public void setNota(double vnota){
		nota=vnota;
	}   
   public int getCod(){
   	return(cod);
   }
   public String getNom(){
   	return(nom);
   }
   public double getNota(){
   	return(nota);
   }
   public String toString(){
   	return(cod+" "+nom+" "+nota);
   }
   	
}