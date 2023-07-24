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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue <TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int cnt = que.size();
            vector <int> arr;
            for(int i = 0; i < cnt; i++)
            {
                TreeNode* curr = que.front();
                que.pop();
                arr.push_back(curr->val);
                if(curr->left != NULL) que.push(curr->left);
                if(curr->right != NULL) que.push(curr->right);
            }
            ans.push_back(arr);
            arr.clear();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};