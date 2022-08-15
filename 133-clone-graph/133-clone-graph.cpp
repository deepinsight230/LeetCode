/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node *node, unordered_map<Node*, Node*> &mp){
        if(node==NULL) return;
        Node *clone=new Node(node->val);
        mp[node]=clone;
        for(auto child: node->neighbors){
            if(mp.find(child)==mp.end()){
                dfs(child, mp);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        dfs(node, mp);
        for(auto m: mp){
            Node *orig=m.first;
            Node *clone=m.second;
            for(auto child: orig->neighbors){
                clone->neighbors.push_back(mp[child]);
            }
        }
        return mp[node];
    }
};