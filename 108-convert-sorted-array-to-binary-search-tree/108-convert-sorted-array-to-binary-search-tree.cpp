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
    TreeNode *helper(int l, int r, vector<int> &nums){
        if(l>r) return NULL;
        int mid=l+(r-l)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=helper(l, mid-1, nums);
        root->right=helper(mid+1, r, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return helper(0, n-1, nums);
    }
};