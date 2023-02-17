Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
  int minDiffInBST(TreeNode* root) {
         int minDiff = INT_MAX;
        int prev = -1;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while (curr != NULL || !s.empty()) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            if (prev != -1) {
                minDiff = min(minDiff, curr->val - prev);
            }
            prev = curr->val;
            curr = curr->right;
        }
        return minDiff;
    }
