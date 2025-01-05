class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        // Base cases
        if (p == null && q == null) return true; // Both trees are null
        if (p == null || q == null) return false; // One tree is null
        
        // Compare current nodes and recursively compare subtrees
        boolean cond1 = (p.val == q.val); // Compare values using '=='
        boolean cond2 = isSameTree(p.left, q.left); // Compare left subtree
        boolean cond3 = isSameTree(p.right, q.right); 

        return cond1 && cond2 && cond3; 
    }
}
