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
    int height(TreeNode *root){
        if(root == NULL) return 0;
        int left=height(root->left);
        int right=height(root->right);
        return max(left, right)+1;
    }
    void helper(TreeNode *root, int &ans){
        if(root == NULL) return;
        int lefth=height(root->left);
        int righth=height(root->right);
        ans=max(ans, lefth+righth);
        helper(root->left, ans);
        helper(root->right, ans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=-1;
        helper(root, ans);
        return ans;
    }
};