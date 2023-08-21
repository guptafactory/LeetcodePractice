/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> que;
        que.push(root);
        vector<int> arr, val;
        while(!que.empty()) {
            int m = que.size();
            for(int i = 0; i < m; i++) {
                TreeNode* node = que.front();
                que.pop();
                // Node stored in temp, Now can change value of node after checking level, if needed.
                if(level%2 == 1) node->val = val[m - i - 1];  // like 2 pointer
                if(node->left != NULL) { que.push(node->left); arr.push_back(node->left->val); }
                if(node->right != NULL) { que.push(node->right); arr.push_back(node->right->val); }
            }
            val = arr; // stores level values
            level++;
            arr.clear();
        }
        return root;
    }
};