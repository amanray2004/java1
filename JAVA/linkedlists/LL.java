package JAVA.linkedlists;

public class LL {
    private Node head;
    private Node tail;
    private int size;

    public LL(){
        this.size=0;
        this.head=null;
        this.tail=null;
    }



    public class Node{
        int value;
        Node next;

        private Node(int value){
            this.value=value;
        }

        private Node(int value,Node next){
            this.value=value;
            this.next=next;

        }
    }
}
