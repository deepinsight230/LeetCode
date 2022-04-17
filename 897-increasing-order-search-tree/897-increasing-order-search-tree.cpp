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
    TreeNode *ret=new TreeNode(0), *ans=ret;
    void helper(TreeNode *root){
        if(root==NULL) return;
        helper(root->left);
        ans->right=new TreeNode(root->val);
        ans=ans->right;
        helper(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) return NULL;
        helper(root);
        return ret->right;
    }
};