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
    void helper(TreeNode* root, int val){
        
        if(root->val>val){
            if(root->left) helper(root->left, val);
            else{
                TreeNode *node=new TreeNode(val);    
                root->left=node;
                return;
            }
        }
        else{
            if(root->right) helper(root->right, val);
            else{
                TreeNode *node=new TreeNode(val);    
                root->right=node;
                return;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode *node=new TreeNode(val);
                return node;
        }
        helper(root, val);
        return root;
    }
};