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
#define ll long long
class Solution {
public:
    void helper(TreeNode *root, ll &mn1, ll mn2){
        if(root==NULL) return;
        if(root->val<mn1 && root->val!=mn2) mn1=root->val;
        helper(root->left, mn1, mn2);
        helper(root->right, mn1, mn2);
    }
    int findSecondMinimumValue(TreeNode* root) {
        ll mn1=LLONG_MAX, mn2=LLONG_MAX;
        helper(root, mn1, mn2);
        helper(root, mn2, mn1);
        if(mn2==mn1) return -1;
        return mn2;
    }
};