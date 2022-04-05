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
    void helper(vector<int> &ds, vector<vector<int>> &ans, TreeNode *root, int &target){
        if(root==NULL) return;
        if(root->left==NULL&&root->right==NULL){
            if(target==root->val){
                ds.push_back(root->val);
                ans.push_back(ds);
                ds.pop_back();
            }
            return;
        }
        ds.push_back(root->val);
        target-=root->val;
        helper(ds, ans, root->left, target);
        helper(ds, ans, root->right, target);
        ds.pop_back();
        target+=root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(ds, ans, root, targetSum);
        return ans;
    }
};