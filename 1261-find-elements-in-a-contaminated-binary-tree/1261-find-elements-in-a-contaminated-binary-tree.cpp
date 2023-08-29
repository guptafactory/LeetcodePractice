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
class FindElements {
private:
    map<int, bool> mp;
    void tree(TreeNode* root, int x) {
        if(root == NULL) return;
        root->val = x;
        mp[x] = true;
        if(root->left != NULL) tree(root->left, x*2 + 1);
        if(root->right != NULL) tree(root->right, x*2 + 2);
    }
public:
    FindElements(TreeNode* root) {
        tree(root, 0);
    }
    
    bool find(int target) {
        if(mp.find(target) == mp.end()) return false;
        else return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */