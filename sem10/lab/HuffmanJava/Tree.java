 /**
 * @(#)Tree.java
 *	La clase Tree implementa el arbol de Huffman
 *  con las operaciones necesarias.
 *
 *
 * @author Okoye Ch. Daniel
 * @version 1.00 2025/10/15
 */
 public class Tree extends Node{
    private Node root;
    
    public Tree(){
        root = null;
    }
    
    public Tree(Node node1, Node node2){
        root = super.addNode(node1, node2);
    }
    
    public void insertNode(int freq, char c){
        root.frequency =  freq;
        root.c = c;
        root.left = null;
        root.right = null;
    }
    
    public void insertNode(int freq, char c, Node left, Node right){
        root.frequency =  freq;
        root.c = c;
        this.root.left = left;
        this.root.right = right;
    }
    
    public void insertNode(Node node){
        this.root.frequency = node.frequency;
        this.root.c = node.c;
        this.root.left = node.left;
        this.root.right = node.right;
    }
    
    public void insertNode(Node node1, Node node2){
        root = super.addNode(node1, node2);   
    }
}
