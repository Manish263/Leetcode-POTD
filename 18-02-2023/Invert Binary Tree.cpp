 Invert Binary Tree
 TreeNode* invertTree(TreeNode* root) {
         if(root == NULL){
            return NULL;
        }
        invertTree(root->left);
        invertTree(root->right);
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
