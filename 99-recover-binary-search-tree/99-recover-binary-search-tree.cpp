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
    void helper(TreeNode *root, TreeNode *&first, TreeNode *&second, TreeNode *&prev){
        if(root==NULL) return;
        helper(root->left, first, second, prev);
        if(prev!=NULL&&root->val<prev->val){
            if(first==NULL) first=prev;
            second=root;
        }
        prev=root;
        helper(root->right, first, second, prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *first=NULL, *second=NULL, *prev=NULL;
        helper(root, first, second, prev);
        swap(first->val, second->val);
    }
};