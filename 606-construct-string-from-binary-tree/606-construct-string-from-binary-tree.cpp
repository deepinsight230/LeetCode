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
    string helper(TreeNode *root){
        if(root==NULL) return "()";
        string left=helper(root->left);
        string right=helper(root->right);
        string temp="("+to_string(root->val);
        if(left!= "()"){
            temp+=left;
            if(right != "()") temp+=right;
        }
        else{
            if(right != "()"){
                temp+=left, temp+=right;
            }
        }
        temp+=")";
        return temp;
    }
    string tree2str(TreeNode* root) {
        string str=helper(root);
        str.pop_back();
        str=str.substr(1, str.size()-1);
        return str;
    }
};