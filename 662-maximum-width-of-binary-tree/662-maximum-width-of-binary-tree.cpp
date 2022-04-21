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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long ans=0;
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int n=q.size();
            unsigned long long mn=0, mx;
            for(int i=0;i<n;i++){
                auto temp=q.front();
                TreeNode *node=temp.first;
                unsigned long long num=temp.second;
                if(mn==0) mn=num;
                mx=num;
                q.pop();
                if(node->left) q.push({node->left, 2*num+1});
                if(node->right) q.push({node->right, 2*num+2});
            }
            ans=max(ans, (mx-mn+1));
        }
        return ans;
    }
};