package JAVA.trees;

import java.util.Scanner;
public class BinaryTree {
    private static class Node {
        int value;
        Node left;
        Node right;

        public Node(int data) {
            this.value = data;
        }
    }


    


    private static Node root;


    public void inserttree(Scanner sc){
        root=new Node(0);
        System.out.println("enter root node value:");
        int value=sc.nextInt();
        root.value=value;
        populate(sc,root);
    }
    private void populate(Scanner sc,Node node){
        System.out.println("leftchild?? of -"+node.value);
        boolean a=sc.nextBoolean();
        if(a){
            System.out.println("left of "+node.value);
            int value=sc.nextInt();
            node.left=new Node(value);
            populate(sc, node.left);
        }
        System.out.println("rightchild?? of-"+node.value);
        a=sc.nextBoolean();
        if(a){
            System.out.println("right of "+node.value);
            int value=sc.nextInt();
            node.right=new Node(value);
            populate(sc, node.right);

        }
    }

    public void display(){
        System.out.println("treee is:");
        inordertraversal(root);
    }

    private void inordertraversal(Node node){
        if (node!=null){
            inordertraversal(node.left);
            System.out.print(node.value+"--");
            inordertraversal(node.right);
        }
    }



    public void createbinarytree(){
        root=new Node(2);
        root.left=new Node(3);
        root.right=new Node(4);
        root.left.left=new Node(5);
        root.left.right=new Node(6);
        root.right.left=new Node(7);
        root.right.right=new Node(8);

    }


}



        // boolean a=sc.nextBoolean();

        // if(a){
        //     System.out.println("left of "+);
        //     value=sc.nextInt();
        // }