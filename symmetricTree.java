/**
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.
*/

//cpp version : (Recursive)
  bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        else
            return isMirror(root->left,root->right);
    }
    bool isMirror(TreeNode*  n1, TreeNode* n2)
    {
        if(!n1 || !n2)
            return n1==n2;
        return (n1->val == n2->val && isMirror(n1->left,n2->right) && isMirror(n1->right,n2->left));
    }
	
	
	
	
//java version : (Non - Recursive)

public boolean isSymmetric(TreeNode root) {
    if (root == null) return true;
    Stack<TreeNode> stack = new Stack<>();
    stack.push(root.left);
    stack.push(root.right);
    while (!stack.empty()) {
        TreeNode n1 = stack.pop(), n2 = stack.pop();
        if (n1 == null && n2 == null) continue;
        if (n1 == null || n2 == null || n1.val != n2.val) return false;
        stack.push(n1.left);
        stack.push(n2.right);
        stack.push(n1.right);
        stack.push(n2.left);
    }
    return true;
}