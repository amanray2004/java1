package JAVA.linkedlists;

public class Dll {
    private Node head;

    private class Node{
        int data;
        Dll next;
        Dll prev;

        public Node(int value){
            this.data=value;
            this.next=null;
            this.prev=null;
        }
    }
    
}
