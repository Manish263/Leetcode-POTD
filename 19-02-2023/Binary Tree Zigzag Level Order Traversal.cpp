Given the root of a binary tree, return the zigzag level order traversal of its nodes'
values. (i.e., from left to right, then right to left for the next level and alternate between).
  
  Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]


                                                                        ANS:

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result; // to store the zigzag level order traversal
        
        if (!root) {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        bool reverse = false; // to keep track of whether to reverse the order of nodes
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // determine the index to insert the node's value based on whether the order is reversed
                int index = reverse ? size - i - 1 : i;
                level[index] = node->val;
                
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            result.push_back(level);
            reverse = !reverse; // reverse the order for the next level
        }
        
        return result;
    }
