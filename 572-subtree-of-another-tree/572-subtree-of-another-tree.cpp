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
    bool helper(TreeNode *root, TreeNode *subRoot){
        if(root==NULL&&subRoot==NULL) return true;
        if(root&&!subRoot||!root&&subRoot) return false;
        if(root->val!=subRoot->val) return false;
        return helper(root->left, subRoot->left)&&helper(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL&&subRoot==NULL) return true;
        if(root&&!subRoot||!root&&subRoot) return false;
        if(root->val==subRoot->val){
            bool temp=helper(root, subRoot);
            if(temp) return true;
        }
        bool left=isSubtree(root->left, subRoot);
        bool right=isSubtree(root->right, subRoot);
        return (left||right);
    }
};