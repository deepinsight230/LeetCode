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
    void helper(TreeNode *root, string ds, vector<string> &ans){
        if(!root->left&&!root->right){
            string temp=ds;
            temp+="->"+to_string(root->val);
            temp=temp.substr(2);
            ans.push_back(temp);
            return;
        }
        if(root->left) helper(root->left, ds+"->"+to_string(root->val), ans);
        if(root->right) helper(root->right, ds+"->"+to_string(root->val), ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string ds="";
        vector<string> ans;
        helper(root, ds, ans);
        return ans;
    }
};