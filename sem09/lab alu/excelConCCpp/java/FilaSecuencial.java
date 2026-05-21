/**
 * @(#)FilaSecuencial.java
 *		Operaciones basicas de una fila .
 *
 *		Crear una fila de texto
 *		Lee una fila texto creada por el programa
 *		lee una file texto creado por el bloc de notas
 *					
 *
 * @author 
 * @version 1.00 2020/6/13
 */
import java.io.*;

public class FilaSecuencial {

	public FilaSecuencial() {
	}
		
	public void leerFila(String nomFila){
      File f=null;				//Crea file
      FileReader fr=null;		//Abre file para leer
      BufferedReader br=null;	//Facilita manejo de file en lineas
		String linea;
		
      try {
         // Apertura file y creacion de BufferedReader 
         // hacer una lectura y disponer de readLine()).
         f = new File (nomFila);
         fr = new FileReader (f);
         br = new BufferedReader(fr);

         // Lectura del fichero
         linea=br.readLine();
         while(linea!=null){
            System.out.println(linea);
            linea=br.readLine();
         }
      }
      catch(Exception e){
         e.printStackTrace();
      }
      finally{
         // Cierra de todas maneras el file
         try{                    
            if( null != fr ){   
               fr.close();     
            }                  
         }catch (Exception e2){ 
            e2.printStackTrace();
         }
      }		
	}

	public void escribirFila(String nomFila)	{
		FileWriter f = null;
		PrintWriter pw = null;
		try{
			f = new FileWriter(nomFila);
			pw = new PrintWriter(f);
			for (int i = 0; i < 10; i++){
				pw.println("Linea " + i);
			}			
		} 
		catch (Exception e) {
			e.printStackTrace();
		} 
		finally {
			try {
				// Cerramos de todas maneras 
				if (f != null){
					f.close();
				}
			} 
			catch (Exception e2) {
				e2.printStackTrace();
			}
		}	
	}	
	public void copiaFile(String ffuente, String fdestino){
		try{
         // Se abre el file original para lectura
			FileInputStream fis = new FileInputStream(ffuente);
			BufferedInputStream bis = new BufferedInputStream(fis);
			
			// Se abre el file donde se hará la copia
			FileOutputStream fos= new FileOutputStream(fdestino);
			BufferedOutputStream bos = new BufferedOutputStream(fos);
			
			// Bucle para leer un file y escribir en el otro.
			byte array[] = new byte[1000];
			int leidos = bis.read(array);
			while (leidos > 0){
				bos.write(array,0,leidos);
				leidos=bis.read(array);
			}

			// Cierre files
			bis.close();
			bos.close();
		}
		catch (Exception e){
			e.printStackTrace();
		}
	}
	
	public void leerFilaBin(String nomFila){
		int i, v=0;
		char car;
		//byte[] vByte=new byte[1];
		FileInputStream fis = null;
		BufferedInputStream bis = null;
		try{
			fis = new FileInputStream(nomFila);
			bis = new BufferedInputStream(fis);
			//v=bis.read();
			//v=fis.read();
			while(v!=-1){	
				v=fis.read();
				car=(char)v;
				System.out.print(car);
				//System.out.print((char)v);
				//v=bis.read();
				//v=fis.read();
			}			
		} 
		catch (Exception e) {
			e.printStackTrace();
		} 
		finally {
			try {
				// Cerramos de todas maneras 
				if (fis != null){
					//bis.flush();
					fis.close();
				}
			} 
			catch (Exception e2) {
				e2.printStackTrace();
			}
		}	
	}
	
	public void escribirFilaBin(String nomFila){
		int i;
		FileOutputStream fos = null;
		BufferedOutputStream bos = null;
		try{
			fos = new FileOutputStream(nomFila);
			bos = new BufferedOutputStream(fos);
			for(i=0;i<10; i++){
				bos.write(i);
			}			
		} 
		catch (Exception e) {
			e.printStackTrace();
		} 
		finally {
			try {
				// Cerramos de todas maneras 
				if (fos != null){
					bos.flush();
					fos.close();
				}
			} 
			catch (Exception e2) {
				e2.printStackTrace();
			}
		}	
	}

}