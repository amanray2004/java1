package JAVA.trees;
//import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        //1.binary tree insert
        // BinaryTree a=new BinaryTree();
        // Scanner scanner = new Scanner(System.in);
        // a.inserttree(scanner);

        // a.display();

        // BinaryTree a=new BinaryTree();
        // a.createbinarytree();
        // a.display();




        //2.binary search tree insert
        // Bst a=new Bst();
        // a.insertbst(15);
        // a.insertbst(10);
        // a.insertbst(20);
        // a.insertbst(5);
        // a.insertbst(12);
        // a.display();
        // System.out.println();
        // System.out.println("hello");

        // BinaryTree a=new BinaryTree();
        // a.createbinarytree();
        // a.levelprint();

        Bst2 a=new Bst2();
        a.insertbst(23);
        a.insertbst(12);
        a.insertbst(5);
        a.insertbst(10);
        a.insertbst(30);
        a.insertbst(25);
        a.insertbst(35);
        a.printbst();
        System.out.println("hello");

        a.deletebst(5);
        a.printbst();
    }
}

