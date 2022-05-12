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
    bool isValidBST(TreeNode* root, long long llim=INT_MIN, long long rlim=INT_MAX) {
        if(root==NULL) return true;
        if(root->val<llim||root->val>rlim) return false;
        bool left=true, right=true;
        if(root->val==INT_MIN){
            if(root->left) return false;
        }
        else left=isValidBST(root->left, llim, root->val-1);
        if(left==false) return false;
        if(root->val==INT_MAX){
            if(root->right) return false;
        }
        else right=isValidBST(root->right, root->val+1, rlim);
        return (left&&right);
    }
};