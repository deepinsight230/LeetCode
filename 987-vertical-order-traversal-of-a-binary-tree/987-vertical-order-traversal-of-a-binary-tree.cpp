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
    void helper(TreeNode *root, vector<vector<int>> &arr, int level, int hor){
        if(root==NULL) return;
        arr.push_back({hor, level, root->val});
        helper(root->left, arr, level+1, hor-1);
        helper(root->right, arr, level+1, hor+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> arr;
        vector<vector<int>> ans;
        helper(root, arr, 0, 0);
        sort(arr.begin(), arr.end());
        vector<int> row;
        row.push_back(arr[0][2]);
        for(int i=1;i<arr.size();i++){
            if(arr[i][0]==arr[i-1][0]){
                row.push_back(arr[i][2]);
            }
            else{
                ans.push_back(row);
                row.clear();
                row.push_back(arr[i][2]);
            }
        }
        ans.push_back(row);
        return ans;
    }
};