class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<vector<int>> freq(n, vector<int> (26, 0));
        for(int i=0;i<n;i++){
            string word=words[i];
            for(char ch: word){
                freq[i][ch-'a']++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k;
                for(k=0;k<26;k++){
                    if(freq[i][k]>0&&freq[j][k]>0) break;
                }
                if(k==26){
                    int n1=words[i].size();
                    int n2=words[j].size();
                    int n3=n1*n2;
                    ans=max(ans, n3);
                }
            }
        }
        return ans;
    }
};