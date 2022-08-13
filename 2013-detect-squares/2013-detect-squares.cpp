class DetectSquares {
public:
    map<pair<int, int>, int> mp;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    bool isValid(pair<int, int> pr, vector<int> &point){
        return (abs(pr.first-point[0])==abs(pr.second-point[1]) && (abs(pr.first-point[0])>0));
    }
    int count(vector<int> point) {
        int px=point[0], py=point[1];
        int ans=0;
        for(auto m: mp){
            if(!isValid(m.first, point)) continue;
            // cout<<px<<" "<<py<<endl;
            int x=m.first.first, y=m.first.second, cnt=m.second;
            int c1=mp[{x, py}];
            int c2=mp[{px, y}];
            ans+=cnt*c1*c2;
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */