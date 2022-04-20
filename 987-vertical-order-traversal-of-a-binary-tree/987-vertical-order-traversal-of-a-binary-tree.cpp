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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            multiset<pair<int, int>> ms;
            int n=q.size();
            for(int i=0;i<n;i++){
                auto temp=q.front();
                q.pop();
                TreeNode *node=temp.first;
                int hd=temp.second;
                ms.insert({hd, node->val});
                if(node->left) q.push({node->left, hd-1});
                if(node->right) q.push({node->right, hd+1});
            }
            for(auto m: ms) mp[m.first].push_back(m.second);
        }
        for(auto m: mp){
            ans.push_back(m.second);
        }
        return ans;
    }
};