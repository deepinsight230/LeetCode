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
    bool helper(TreeNode *root, TreeNode *p1, TreeNode *p2){
        if((p1&&!p2)||(!p1&&p2)) return false;
        if(!p1&&!p2) return true;
        if(p1->val!=p2->val) return false;
        bool c1=helper(root, p1->left, p2->right);
        bool c2=helper(root, p1->right, p2->left);
        return c1&&c2;
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode *p1=root->left, *p2=root->right;
        return helper(root, p1, p2);
    }
};