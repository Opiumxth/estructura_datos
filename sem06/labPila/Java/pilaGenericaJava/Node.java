/**
 * @(#)Node.java
 *
 *
 * @author Gilberto A. SALINAS
 * @version 1.00 2025/4/6
 */


class Node<T> {
    private T value;
    private Node<T> next;
    
    public Node(){
    }

    public Node(T value, Node<T> next) {
        this.value = value;
        this.next = next;
    }

    public T getValue() {
        return value;
    }

    public Node<T> getNext() {
        return next;
    }

    public void setNext(Node<T> next) {
        this.next = next;
    }
}