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
private:
    int ans = 0;
    pair<int, int> dfs(TreeNode* root) {
        if(root == NULL) return {0, 0};
        
        pair<int, int> left_pr = dfs(root->left);
        int left_sum = left_pr.first;
        int left_cnt = left_pr.second;
        
        pair<int, int> right_pr = dfs(root->right);
        int right_sum = right_pr.first;
        int right_cnt = right_pr.second;
        
        int sum = root->val + left_sum + right_sum;
        int cnt = left_cnt + right_cnt + 1;
        
        if(sum / cnt == root->val) ans++;
        return {sum, cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};