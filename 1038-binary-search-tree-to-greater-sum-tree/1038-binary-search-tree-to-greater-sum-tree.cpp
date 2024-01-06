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
    void inorder(TreeNode* root, vector<int>&arr)
    {
        if (root == NULL) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    void traverse(TreeNode* root, map<int, int> &mp) {
        if (root == NULL) return;
        traverse(root->left, mp);
        root->val = mp[root->val];
        traverse(root->right, mp);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        int n = arr.size(), sum = 0;
        map<int, int> mp;
        for (int i = n - 1; i >= 0; i--) {
            sum += arr[i];
            mp[arr[i]] = sum;
        }
        traverse(root, mp);
        return root;
    }
};