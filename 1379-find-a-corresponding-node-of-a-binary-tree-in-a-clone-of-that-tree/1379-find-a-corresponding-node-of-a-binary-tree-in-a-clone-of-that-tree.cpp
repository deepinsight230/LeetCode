/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* orig, TreeNode* cloned, TreeNode* target) {
        if(orig==NULL) return cloned;
        if(orig==target) return cloned;
        TreeNode *left=getTargetCopy(orig->left, cloned->left, target);
        if(left) return left;
        TreeNode *right=getTargetCopy(orig->right, cloned->right, target);
        if(!left) return right;
        if(!right) return left;
        else return NULL;
    }
};