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
    bool isPal(vector<int> &mp){
        int n=0;
        // map<int, int> mp;
        for(int x: mp){
            if(x != 0) n+=x;
        }
        bool flag = false;
        if(n%2 == 1){
            for(auto m: mp){
                if(m%2 == 1){
                    if(flag == false) flag = true;
                    else return false;
                }
            }
        }
        else{
            for(auto m: mp){
                if(m%2 == 1){
                    return false;
                }
            }
        }
        return true;
    }
    void helper(TreeNode *root, vector<int> &arr, int &cnt){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            // arr.push_back(root->val);
            arr[root->val]++;
            if(isPal(arr)) cnt++;
            arr[root->val]--;
            // arr.pop_back();
            return;
        }
        // arr.push_back(root->val);
        arr[root->val]++;
        helper(root->left, arr, cnt);
        helper(root->right, arr, cnt);
        // arr.pop_back();
        arr[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> arr(10, 0);
        int cnt=0;
        helper(root, arr, cnt);
        return cnt;
    }
};