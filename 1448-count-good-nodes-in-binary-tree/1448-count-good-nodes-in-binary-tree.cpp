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
    void helper(TreeNode *root, int &ans, int mx){
        if(!root) return;
        if(root->val >= mx) ans++;
        mx=max(mx, root->val);
        helper(root->left, ans, mx);
        helper(root->right, ans, mx);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        helper(root, ans, INT_MIN);
        return ans;
    }
};