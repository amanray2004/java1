package JAVA.trees;

import java.util.LinkedList;
import java.util.Queue;
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


    private void levelorder(Node root ){
        Queue<Node> a=new LinkedList<>();
        a.add(root);
        while ( !a.isEmpty()){
            Node b=a.remove();
            System.out.print(b.value+"->");
            if (b.left!=null){
                a.add(b.left);
            }
            if (b.right!=null){
                a.add(b.right);
            }          
        }
    }

    public void levelprint(){
        levelorder(root);
    }

    private static int leafnodes(Node t){
        if(t!=null){
            int leafleftsub=leafnodes(t.left);
            int leafrightsub=leafnodes(t.right);

            if(t.left==null && t.right==null){
                return leafleftsub+leafrightsub+1;
            }
            else{
                return leafleftsub+leafrightsub;
            }
        }
        return 0;
    }

    public int countleafnodes(){
        return leafnodes(root);
    }

}



        // boolean a=sc.nextBoolean();

        // if(a){
        //     System.out.println("left of "+);
        //     value=sc.nextInt();
        // }