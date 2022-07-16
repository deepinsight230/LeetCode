class Solution {
public:
    int mod=1e9+7;
    int maxArea(int height, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        long long h=hc[0], v=vc[0];
        for(int i=1;i<hc.size();i++){
            h=max(h, (long long)(hc[i]-hc[i-1]));
        }
        h=max(h, (long long)(height-hc[hc.size()-1]));
        for(int i=1;i<vc.size();i++){
            v=max(v, (long long)(vc[i]-vc[i-1]));
        }
        v=max(v, (long long)(w-vc[vc.size()-1]));
        long long ans=(h*v)%mod;
        return ans;
    }
};