package JAVA.trees.testfiles;

class Node {
    Node lchild;
    int data;
    Node rchild;
}

class BST {
    private Node root;

    BST() {
        root = null;
    }

    Node getRoot() {
        return root;
    }

    void iInsert(int key) {
        Node t = root;
        Node p;
        Node r=new Node();

        if (root == null) {
            p = new Node();
            p.data = key;
            p.lchild = null;
            p.rchild = null;
            root = p;
            return;
        }

        while (t != null) {
            r = t;
            if (key < t.data) {
                t = t.lchild;
            } else if (key > t.data) {
                t = t.rchild;
            } else {
                return;
            }
        }

        p = new Node();
        p.data = key;
        p.lchild = null;
        p.rchild = null;

        if (key < r.data) {
            r.lchild = p;
        } else {
            r.rchild = p;
        }
    }

    void Inorder(Node p) {
        if (p != null) {
            Inorder(p.lchild);
            System.out.print(p.data + ", ");
            Inorder(p.rchild);
        }
    }

    Node iSearch(int key) {
        Node t = root;
        while (t != null) {
            if (key == t.data) {
                return t;
            } else if (key < t.data) {
                t = t.lchild;
            } else {
                t = t.rchild;
            }
        }
        return null;
    }

    Node rInsert(Node p, int key) {
        if (p == null) {
            Node t = new Node();
            t.data = key;
            t.lchild = null;
            t.rchild = null;
            return t;
        }

        if (key < p.data) {
            p.lchild = rInsert(p.lchild, key);
        } else if (key > p.data) {
            p.rchild = rInsert(p.rchild, key);
        }
        return p;
    }

    Node rSearch(Node p, int key) {
        if (p == null) {
            return null;
        }

        if (key == p.data) {
            return p;
        } else if (key < p.data) {
            return rSearch(p.lchild, key);
        } else {
            return rSearch(p.rchild, key);
        }
    }

    Node Delete(Node p, int key) {
        Node q;

        if (p == null) {
            return null;
        }

        if (p.lchild == null && p.rchild == null) {
            if (p == root) {
                root = null;
            }
            return null;
        }

        if (key < p.data) {
            p.lchild = Delete(p.lchild, key);
        } else if (key > p.data) {
            p.rchild = Delete(p.rchild, key);
        } else {
            if (Height(p.lchild) > Height(p.rchild)) {
                q = InPre(p.lchild);
                p.data = q.data;
                p.lchild = Delete(p.lchild, q.data);
            } else {
                q = InSucc(p.rchild);
                p.data = q.data;
                p.rchild = Delete(p.rchild, q.data);
            }
        }
        return p;
    }

    int Height(Node p) {
        if (p == null) {
            return 0;
        }
        int x = Height(p.lchild);
        int y = Height(p.rchild);
        return x > y ? x + 1 : y + 1;
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

public class Main {
    public static void main(String[] args) {
        BST bst = new BST();

        bst.iInsert(10);
        bst.iInsert(5);
        bst.iInsert(20);
        bst.iInsert(8);
        bst.iInsert(30);

        bst.Inorder(bst.getRoot());
        System.out.println();

        Node temp = bst.iSearch(2);
        if (temp != null) {
            System.out.println(temp.data);
        } else {
            System.out.println("Element not found");
        }

        temp = bst.rSearch(bst.getRoot(), 20);
        if (temp != null) {
            System.out.println(temp.data);
        } else {
            System.out.println("Element not found");
        }

        BST bs = new BST();
        bs.iInsert(5);
        bs.iInsert(2);
        bs.iInsert(8);
        bs.iInsert(7);
        bs.iInsert(9);
        bs.iInsert(1);

        temp = bs.InPre(bs.getRoot());
        System.out.println("InPre: " + temp.data);

        temp = bs.InSucc(bs.getRoot());
        System.out.println("InSucc: " + temp.data);

        bs.Inorder(bs.getRoot());
        System.out.println();

        bs.Delete(bs.getRoot(), 1);
        bs.Inorder(bs.getRoot());
    }
}
