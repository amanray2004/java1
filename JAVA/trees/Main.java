package JAVA.trees;
//import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        // BinaryTree a=new BinaryTree();
        // Scanner scanner = new Scanner(System.in);
        // a.inserttree(scanner);
        // a.display();

        // BinaryTree a=new BinaryTree();
        // a.createbinarytree();
        // a.display();

        Bst a=new Bst();
        a.insertbst(15);
        a.insertbst(10);
        a.insertbst(20);
        a.insertbst(5);
        a.insertbst(12);
        a.display();
        System.out.println();
        System.out.println("hello");
    }
}

