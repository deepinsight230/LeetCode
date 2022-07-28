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
    bool helper(TreeNode *root, int target, int &sum){
        if(root==NULL) return false;
        if(!root->left && !root->right){
            sum+=root->val;
            
            if(sum==target) return true;
            return false;
        }
        sum+=root->val;
        bool left=helper(root->left, target, sum);
        if(root->left) sum-=root->left->val;
        bool right=helper(root->right, target, sum);
        if(root->right) sum-=root->right->val;
        return left||right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return helper(root, targetSum, sum);
    }
};