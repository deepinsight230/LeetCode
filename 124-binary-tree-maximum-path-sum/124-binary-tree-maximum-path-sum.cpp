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
    int helper(TreeNode *root, int &ans){
        if(root==NULL) return 0;
        int left=helper(root->left, ans);
        int right=helper(root->right, ans);
        ans=max(ans, (left+right+root->val));
        int temp=root->val+max(left, right);
        return ((temp>0)?temp:0);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        helper(root, ans);
        return ans;
    }
};