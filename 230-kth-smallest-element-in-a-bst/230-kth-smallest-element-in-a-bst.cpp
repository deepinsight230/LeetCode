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
    int helper(TreeNode *root, int k, int &cnt){
        if(root==NULL) return -1;
        int left=helper(root->left, k, cnt);
        if(left!=-1) return left;
        cnt++;
        if(cnt==k) return root->val;
        int right=helper(root->right, k, cnt);
        if(right!=-1) return right;
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        return helper(root, k, cnt);
    }
};