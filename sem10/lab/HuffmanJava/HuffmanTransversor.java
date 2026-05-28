 /**
 * @(#)HuffmanTransversor.java
 *	 La clase responsable de decodificar el árbol de Huffman
 *
 *
 * @author Okoye Ch. Daniel
 * @version 1.00 2025/10/15
 */

public class HuffmanTransversor{
    private Node rootNode;
    private char c;
    private char charArray[];
    private int i=0;
    public String finalBitPattern = "";
    
    public HuffmanTransversor(Node myNode, char [] charArray){
        String temp;
        int i;
        rootNode = myNode;
        this.charArray = charArray;
        for(i = 0; i < charArray.length; i++){
            temp = search(rootNode, "", charArray[i]);
            finalBitPattern += temp+" ";
            System.out.println("My values: "+charArray[i]+" "+temp);
        }
      //  System.out.println("My final Bit Pattern: "+finalBitPattern);
    }
    
    public String search(Node rootNode, String value,char myChar){
        String valueL ="";
        if(rootNode != null){
            if(rootNode.left != null){
                valueL = search(rootNode.left, value+"0", myChar);
            }
            if(rootNode.c == myChar){
                return value;
            }
            else{
                if(valueL == "")                {
                    return search(rootNode.right, value+"1",myChar);
                }
                else{
                    return valueL;
                }
            }
        }
        else{
            return "";
        }
    }      
}
