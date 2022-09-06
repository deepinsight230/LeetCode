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
    TreeNode *helper(TreeNode *root){
        if(root==NULL) return NULL;
        TreeNode *left=helper(root->left);
        TreeNode *right=helper(root->right);
        // root->left=NULL, root->right=NULL;
        root->left=left;
        root->right=right;
        if(root->val == 0 && !left && !right){
            TreeNode *temp=root;
            delete temp;
            return NULL;
        }
        
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return helper(root);
    }
};