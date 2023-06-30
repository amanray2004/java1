package JAVA.trees;

public class Bst {
    private static class Node{
        int value;
        Node left;
        Node right;

        public Node(int value){
            this.value=value;
        }

    }

    private Node root;

    // private void insert(Node t,int value){
    //     if(t!=null){
    //         if(value>t.value){
    //             insert(t.right,value);
    //         }
    //         else if (value<t.value){
    //             insert(t.left,value);
    //         }
    //     }
    //     t=new Node(value);
    // }
    //my code is wrong because whenu providse root to the function call ,then at last u assign new memory which will not change root
// */   In your code, the insert method is not correctly updating the left and right references of the nodes. The line t = new Node(value) is assigning a new node to the local variable t, but it does not affect the actual tree structure.

// When you pass t as an argument to the insert method recursively, you are only passing the reference to the node, and modifying the reference within the method does not change the original reference in the parent call.

// To fix this issue, you can update the insert method to return the modified node after insertion. You should also handle the case when the t parameter is null (indicating an empty tree), and assign the new node directly to the root in that case. Here's the modified code:
    private Node insert(Node t, int value) {
        if (t == null) {
            return new Node(value);
        }
        if (value > t.value) {
            t.right = insert(t.right, value);
        } else if (value < t.value) {
            t.left = insert(t.left, value);
        }
        return t;
    }

    public void insertbst(int value){
        root=insert(root,value);
    }

    private void inordertraversal(Node t){
        if(t!=null){
            inordertraversal(t.left);
            System.out.print(t.value+"--");
            inordertraversal(t.right);
        }
    }

    public void display(){
        inordertraversal(root);
    }
}
