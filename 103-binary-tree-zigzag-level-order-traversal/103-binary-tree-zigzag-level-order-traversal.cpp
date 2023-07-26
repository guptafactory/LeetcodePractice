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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue <TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int cnt = que.size();
            vector <int> arr;
            while(cnt--)
            {
                TreeNode* first = que.front();
                que.pop();
                arr.push_back(first->val);
                if(first->left != NULL) que.push(first->left);
                if(first->right != NULL) que.push(first->right);
            }
            ans.push_back(arr);
            arr.clear();
        }
        for(int i = 1; i < ans.size(); i+=2) {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};