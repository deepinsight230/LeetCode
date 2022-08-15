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
        int temp=0, tempMax=0;
        if(left!=0 && root->left->val==root->val) temp+=left, tempMax=max(tempMax, left);
        if(right!=0 && root->right->val==root->val) temp+=right, tempMax=max(tempMax, right);
        ans=max(ans, temp+1);
        return tempMax+1;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        helper(root, ans);
        return ans-1;
    }
};