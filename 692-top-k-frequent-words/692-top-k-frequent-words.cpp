#define pis pair<int, string>
class Solution {
public:
    struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second < b.second;
            }
        }
    };
    static bool myCmp(pis &a, pis &b){
        if(a.first!=b.first) return a.first>b.first;
        else return a.second<b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(string s: words) mp[s]++;
        priority_queue<pis, vector<pis>, MyComp> pq;
        for(auto m: mp){
            pq.push({m.second, m.first});
            if(pq.size()>k) pq.pop();
        }
        vector<pis> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        sort(ans.begin(), ans.end(), myCmp);
        vector<string> res;
        for(pis x: ans) res.push_back(x.second);
        return res;
    }
};