struct TrieNode{
    TrieNode *links[26];
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    TrieNode *next(char ch){
        return links[ch-'a'];
    }
};
static bool myComp(string &a, string &b){
    if(a.size()!=b.size()) return a.size()<b.size();
    else return (a<b);
}
class Solution {
    TrieNode *root=new TrieNode();
public:
    void insert(string &s){
        TrieNode *curr=root;
        for(int i=0;i<s.size();i++){
            if(!curr->containsKey(s[i])) curr->links[s[i]-'a']=new TrieNode();
            curr=curr->next(s[i]);
        }
        curr->flag=true;
    }
    bool helper(string s){
        TrieNode *curr=root;
        for(int i=0;i<s.size();i++){
            TrieNode *next=curr->next(s[i]);
            if(!next || !next->flag) return false;
            curr=next;
        }
        return true;
    }
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), myComp);
        int n=words.size();
        for(int i=0;i<n;i++){
            string s=words[i];
            insert(s);
        }
        int len=INT_MAX;
        bool found=false;
        string ans="";
        for(int i=n-1;i>=0;i--){
            string s=words[i];
            if(helper(s)){
                // cout<<s<<endl;
                if(s.size()<len){
                    len=s.size();
                    if(!found){
                        ans=s;
                        found=true;
                    }
                    else return ans;
                }
                else ans=s;
            }
        }
        return ans;
    }
};