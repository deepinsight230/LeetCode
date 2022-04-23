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
    void helper(TreeNode* node,string temp, string &ans){
        temp+=(char)(node->val+'a');
        if(node->left==NULL&&node->right==NULL){
            reverse(temp.begin(), temp.end());
            if(ans=="") ans=temp;
            else ans=min(ans,temp);
        }
        if(node->left) helper(node->left,temp, ans);
        if(node->right) helper(node->right, temp, ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        if(!root) return ans;
        helper(root, "", ans);
        return ans;
    }
};