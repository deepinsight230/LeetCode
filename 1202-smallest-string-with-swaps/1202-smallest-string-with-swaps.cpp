class Solution {
public:
    string ans;
    void dfs(int i, vector<int> &pos, vector<int> &vis, vector<vector<int>> &g) {   
        vis[i]++;
        pos.push_back(i);
        for(auto child: g[i]){
            if (!vis[child]) dfs(child, pos, vis, g);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        ans = s;
        vector<vector<int>> g(n);
        for(auto i: pairs) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) {
            if (!vis[i]) {
                vector<int> pos;
                dfs(i, pos, vis, g);
                string tmp = "";
                for(auto c: pos) {
                    tmp += s[c];
                }
                sort(pos.begin(), pos.end());
                sort(tmp.begin(), tmp.end());
                for(int z = 0; z<pos.size(); z++) {
                    ans[pos[z]] = tmp[z];
                }
            }
        }
        return ans;
    }
};