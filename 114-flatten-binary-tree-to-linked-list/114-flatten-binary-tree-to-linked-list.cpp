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
    void preOrder(TreeNode *root, vector<int> &pre){
        if(root==NULL) return;
        pre.push_back(root->val);
        preOrder(root->left, pre);
        preOrder(root->right, pre);
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        vector<int> pre;
        preOrder(root, pre);
        TreeNode *left=root->left;
        TreeNode *right=root->right;
        delete left;
        delete right;
        root->left=NULL;
        for(int i=1;i<pre.size();i++){
            TreeNode *node=new TreeNode(pre[i], NULL, NULL);
            root->right=node;
            root=root->right;
        }
    }
};