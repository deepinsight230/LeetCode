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
    TreeNode* convertBST(TreeNode* root, int sum=0) {
        if (!root) return nullptr;
        TreeNode* rightNode = convertBST(root->right, sum);
        
        if (rightNode) {
            while (rightNode->left && rightNode->left->left) 
                rightNode = rightNode->left;
            root->val += (rightNode->left) ? rightNode->left->val : rightNode->val;
        }
        else root->val += sum;
        convertBST(root->left, root->val);
            
        return root;
    }
};