package JAVA.trees;

public class Bst2 {



    private class Node{
        int value;
        Node lchild;
        Node rchild;

        public Node(int value){
            this.value=value;
        }


    }



    private Node root;



    private Node insert(Node node,int data){
        if(node==null){
            return new Node(data);
        }

        if(node.value>data){
            node.lchild=insert(node.lchild,data);
        }
        else if(node.value<data){
            node.rchild=insert(node.rchild,data);
        }
        return node;


    }

    public void insertbst(int data){
        root=insert(root, data);


    }
    


    private void inorder(Node node){
        if(node!=null){
            inorder(node.lchild);
            System.out.print(node.value+"-->");
            inorder(node.rchild);
        }

    }

    public void printbst(){
        inorder(root);
    }


    private int height(Node t){
        if(t==null){
            return 0;

        }else {
        int x=height(t.lchild);
        int y=height(t.rchild);
        if(x>y){
            return x+1;
        }
        else{
            return y+1;
        }
        }


    }
    private Node delete(Node node,int value){
        Node q;
        if(node==null){
            return null;
        }
        if(node.lchild==null&&node.rchild==null){
            if(node==root){
                root=null;
            }
            return null;
        }

        if(node.value<value){
            node.rchild=delete(node.rchild, value);
        }
        else if(node.value>value){
            node.lchild=delete(node.lchild,value);
        }
        else{
            if(height(node.lchild)>height(node.rchild)){
                q=InPre(node.lchild);
                node.value=q.value;
                node.lchild=delete(node.lchild,q.value);

            }
            else{
                q=InSucc(node.rchild);
                node.value=q.value;
                node.rchild=delete(node.rchild,value);
            }
            
        }
        return node;

    }

    // Node Delete(Node p, int key) {
    //     Node q;

    //     if (p == null) {
    //         return null;
    //     }

    //     if (p.lchild == null && p.rchild == null) {
    //         if (p == root) {
    //             root = null;
    //         }
    //         return null;
    //     }

    //     if (key < p.value) {
    //         p.lchild = Delete(p.lchild, key);
    //     } else if (key > p.value) {
    //         p.rchild = Delete(p.rchild, key);
    //     } else {
    //         if (height(p.lchild) > height(p.rchild)) {
    //             q = InPre(p.lchild);
    //             p.value = q.value;
    //             p.lchild = Delete(p.lchild, q.value);
    //         } else {
    //             q = InSucc(p.rchild);
    //             p.value = q.value;
    //             p.rchild = Delete(p.rchild, q.value);
    //         }
    //     }
    //     return p;
    // }
    public void deletebst(int data){
        root=delete(root, data);
    }
    Node InPre(Node p) {
    while (p != null && p.rchild != null) {
        p = p.rchild;
    }
    return p;
    }
    Node InSucc(Node p) {
        while (p != null && p.lchild != null) {
            p = p.lchild;
        }
        return p;
    }



}
