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
    void helper(TreeNode *root, int target, vector<int> path, vector<vector<int>> &ans){
        if(root==NULL) return;
        if(!root->left && !root->right){
            path.push_back(root->val);
            if(target==root->val) ans.push_back(path);
            return;
        }
        path.push_back(root->val);
        helper(root->left, target-root->val, path, ans);
        // if(root->left) path.pop_back();
        helper(root->right, target-root->val, path, ans);
        // if(root->right) path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(root, targetSum, path, ans);
        return ans;
    }
};