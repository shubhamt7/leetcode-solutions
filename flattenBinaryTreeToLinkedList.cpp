class Solution {
    public TreeNode buildLinkedList(TreeNode root){
        if(root == null)
            return null;
        
        if(root.left == null && root.right == null)
            return root;
        
        TreeNode leftSubtree = root.left != null ? root.left : null;
        TreeNode rightSubtree = root.right != null ? root.right : null;
        
        root.left = null;
        root.right = null;
        
        TreeNode leftList = buildLinkedList(leftSubtree);
        TreeNode rightList = buildLinkedList(rightSubtree);
        
        
        if(leftList != null){
            root.right = leftList;
        }
        
        TreeNode curr = root;
        while(curr.right != null){
            curr = curr.right;
        }
        
        curr.right = rightList;
        
        return root;
        
    }
    
    public void flatten(TreeNode root) {
        root = buildLinkedList(root);
    }
}
