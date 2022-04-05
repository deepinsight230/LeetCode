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
    void helper(string &ds, int &ans, TreeNode *root){
        if(root==NULL) return;
        if(root->left==NULL&&root->right==NULL){
            ds+=to_string(root->val);
            cout<<ds<<endl;
            ans+=stoi(ds);
            ds.pop_back();
            return;
        }
        ds+=to_string(root->val);
        helper(ds, ans, root->left);
        helper(ds, ans, root->right);
        ds.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        string ds="";
        helper(ds, ans, root);
        return ans;
    }
};