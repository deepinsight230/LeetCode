class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> ms, mg, msame;
        for(char ch: secret) ms[ch]++;
        for(char ch: guess) mg[ch]++;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) msame[secret[i]]++;
        }
        int bulls=0, cows=0;
        for(auto m: ms){
            char ch=m.first;
            ms[ch]=min(ms[ch], mg[ch])-msame[ch];
            cows+=ms[ch];
        }
        for(auto m: msame){
            bulls+=m.second;
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};