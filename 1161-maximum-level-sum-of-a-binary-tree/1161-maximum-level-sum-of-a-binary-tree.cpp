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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = 0, finalLevel = 0, level = 0, maxSum = INT_MIN;
        queue <TreeNode*> que;
        que.push(root);
        while(!que.empty()) 
        {
            int cnt = que.size();
            sum = 0; level++;
            while(cnt--)
            {
                TreeNode* curr = que.front();
                que.pop();
                sum += curr->val;
                if(curr->left != NULL) que.push(curr->left);
                if(curr->right != NULL) que.push(curr->right);
            }
            if(sum > maxSum) {
                maxSum = sum;
                finalLevel = level;
            }
        }
        return finalLevel;
    }
};