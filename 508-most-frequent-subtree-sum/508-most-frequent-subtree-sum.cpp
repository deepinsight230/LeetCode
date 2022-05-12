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
    int treeSum(TreeNode *root, unordered_map<int, int> &mp){
        if(root==0) return 0;
        int left=treeSum(root->left, mp);
        int right=treeSum(root->right, mp);
        int temp=left+right+root->val;
        mp[temp]++;
        return temp;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> mp;
        treeSum(root, mp);
        int mx=0;
        for(auto m: mp) mx=max(mx, m.second);
        for(auto m: mp) if(m.second==mx) ans.push_back(m.first);
        return ans;
    }
};