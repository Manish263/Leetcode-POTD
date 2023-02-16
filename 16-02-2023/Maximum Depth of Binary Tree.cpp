Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
  
  ANS:

     int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;
        int leftd=maxDepth(root->left);
        int rightd=maxDepth(root->right);
        return max(leftd,rightd)+1;
    }
