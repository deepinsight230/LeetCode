class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans=INT_MAX, n=cards.size();
        unordered_map<int, int> mp;
        int i=0, j=0;
        while(j<n){
            mp[cards[j]]++;
            if(mp[cards[j]]==1) j++;
            else{
                while(mp[cards[j]]>1){
                    mp[cards[i]]--;
                    i++;
                }
                j++;
                ans=min(ans, j-i+1);
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};