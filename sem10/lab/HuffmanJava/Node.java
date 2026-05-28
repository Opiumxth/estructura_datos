 /**
 * @(#)Node.java
 *	La clase Node implemente el nodo o las
 *  hojas co los atributos necesarios del 
 *  arbol binario de Huffman
 *
 *
 * @author Okoye Ch. Daniel
 * @version 1.00 2025/10/15
 */
public class Node{
    public int frequency;
    public char c;
    public Node left;
    public Node right;
    
    public Node(){
        //does Nothing
    }
    public Node(int frequency, char c, Node left, Node right){
        this.frequency = frequency;
        this.c = c;
        this.left = left;
        this.right = right;
    }
       
    public Node addNode(Node node1, Node node2){
        if(node1.frequency < node2.frequency){
            left = node1;
            right = node2;
        }
        else{
            right = node1;
            left = node2;
        }
        frequency = node1.frequency + node2.frequency;
        return this;
    }
    
}
