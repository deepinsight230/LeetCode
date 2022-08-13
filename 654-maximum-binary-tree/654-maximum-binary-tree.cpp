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
    TreeNode *helper(vector<int> &nums, int l, int r){
        if(l>=r) return NULL;
        int mx=max_element(nums.begin()+l, nums.begin()+r)-nums.begin();
        TreeNode *root=new TreeNode(nums[mx]);
        root->left=helper(nums, l, mx);
        root->right=helper(nums, mx+1, r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return helper(nums, 0, n);
    }
};