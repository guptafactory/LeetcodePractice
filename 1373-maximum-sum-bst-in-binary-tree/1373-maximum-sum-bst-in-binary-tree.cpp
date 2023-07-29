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
class Info 
{
    public:
    int maxSum;
    int maxLeft;
    int minRight;
    bool isBst;
    Info()
    {
        maxSum = 0;
        maxLeft = INT_MIN;
        minRight = INT_MAX;
        isBst = true;
    }
};
class Solution {
public:
    int ans = 0;
    Info solve(TreeNode* root)
    {
        if(root == NULL) return Info();
        Info node;
        Info nodeLeft = solve(root->left);
        Info nodeRight = solve(root->right);
        if(nodeLeft.isBst && nodeRight.isBst && root->val > nodeLeft.maxLeft && root->val < nodeRight.minRight)
        {
            node.isBst = true;
            node.maxSum = root->val + nodeLeft.maxSum + nodeRight.maxSum;
            node.minRight = min(root->val, nodeLeft.minRight);
            node.maxLeft = max(root->val, nodeRight.maxLeft);
        }
        else 
        {
            node.isBst = false;
            node.maxSum = max(nodeLeft.maxSum, nodeRight.maxSum);
        }
        ans = max(ans, node.maxSum);
        return node;
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};