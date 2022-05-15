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
    void helper(TreeNode *root, int &ans, int level, int &mlevel){
        if(root==NULL) return;
        if(level>mlevel) {cout<<level<<" "<<mlevel<<endl;ans=0;}
        mlevel=max(mlevel, level);
        if(level==mlevel) ans+=root->val;
        helper(root->left, ans, level+1, mlevel);
        helper(root->right, ans, level+1, mlevel);
        
    }
    int deepestLeavesSum(TreeNode* root) {
        int ans=0, mlevel=0;
        helper(root, ans, 0, mlevel);
        return ans;
    }
};