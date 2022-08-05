class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int k=p.size();
        int i=0, j=0, n=s.size();
        unordered_map<char, int> mapS, mapP;
        for(char ch: p) mapP[ch]++;
        while(j<n){
            mapS[s[j]]++;
            if(j-i+1 < k) j++;
            else if(j-i+1 == k){
                if(mapS==mapP) ans.push_back(i);
                j++;
            }
            else{
                mapS[s[i]]--;
                if(mapS[s[i]]==0) mapS.erase(s[i]);
                i++;
                if(mapS==mapP) ans.push_back(i);
                j++;
            }
        }
        return ans;
    }
};