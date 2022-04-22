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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true;
        if((!p&&q)||(p&&!q)) return false;
        else if(p&&q&&p->val!=q->val) return false;
        bool left=isSameTree(p->left, q->left);
        if(!left) return false;
        bool right=isSameTree(p->right, q->right);
        if(!right) return false;
        return true;
    }
};