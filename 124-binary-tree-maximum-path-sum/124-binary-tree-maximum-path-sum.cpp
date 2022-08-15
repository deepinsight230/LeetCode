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
    int helper(TreeNode *root, int &maxSum){
        if(root==NULL) return 0;
        int left=helper(root->left, maxSum);
        int right=helper(root->right, maxSum);
        maxSum=max(maxSum, left+right+root->val);
        int temp=max(left, right)+root->val;
        return (temp>0)?temp:0;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
};