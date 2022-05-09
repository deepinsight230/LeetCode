class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> s;
        for(auto circle: circles){
            vector<int> xarr, yarr;
            int x=circle[0], y=circle[1], r=circle[2];
            for(int i=x-r;i<=x+r;i++){
                for(int j=y-r;j<=y+r;j++){
                    if(pow(x-i,2)+pow(y-j,2)<=pow(r,2)) s.insert({i,j});
                }
            }
        }
        // for(auto x: s) cout<<x.first<<" "<<x.second<<endl;
        return s.size();
    }
};