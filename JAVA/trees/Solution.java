package JAVA.trees;

 class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {

      }
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
          this.right = right;
      }  }

public class Solution {
    private TreeNode root;

    private TreeNode insertTree(TreeNode t,int value){
        if (t==null){
            return new TreeNode(value, null, null);
        }
        if (t.val<value){
            t.right=insertTree(t.right, value);
        }
        else if(t.val>value){
            t.left=insertTree(t.left, value);
        }
        return t;
    }

    public TreeNode bstFromPreorder(int[] preorder) {
        for (int i=0;i<preorder.length;i++){
            insertTree(root, preorder[i]);
        }
        return root;

    }
}