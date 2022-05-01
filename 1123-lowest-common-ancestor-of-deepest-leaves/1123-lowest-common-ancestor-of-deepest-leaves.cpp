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
    TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root==NULL) return NULL;
        if(root==p||root==q) return root;
        TreeNode *left=lca(root->left, p, q);
        TreeNode *right=lca(root->right, p, q);
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;
    }
    void deepestleaves(TreeNode *root, pair<TreeNode *, TreeNode *> &pr){
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode *node=q.front();
                q.pop();
                if(i==0) pr.first=node;
                if(i==n-1) pr.second=node;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pair<TreeNode *, TreeNode *> pr;
        deepestleaves(root, pr);
        return lca(root, pr.first, pr.second);
    }
};