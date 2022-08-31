struct TrieNode{
    TrieNode *links[26];
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!= NULL);
    }
    void put(char ch, TrieNode *node){
        links[ch-'a']=node;
    }
    TrieNode *next(char ch){
        return links[ch-'a'];
    }
};

class MagicDictionary {
    TrieNode *root;
public:
    MagicDictionary() {
        root=new TrieNode();
    }
    
    void insert(string &word){
        TrieNode *curr=root;
        for(int j=0;j<word.size();j++){
            if(!curr->containsKey(word[j])) curr->put(word[j], new TrieNode());
            curr=curr->next(word[j]);
        }
        curr->flag=true;
    }
    void buildDict(vector<string> dictionary) {
        for(int i=0;i<dictionary.size();i++){
            string word=dictionary[i];
            insert(word);
        }
    }
    
    bool helper(int idx, string &s, int changes, TrieNode *curr){
        if(idx==s.size()) return (curr->flag && changes==1);
        TrieNode *next=curr->next(s[idx]);
        if(changes==1){
            if(!next) return false;
            else return helper(idx+1, s, 1, next);
        }
        else{
            if(next && helper(idx+1, s, 0, next)) return true;
            for(int i=0;i<26;i++){
                if('a'+i == s[idx]) continue;
                if(curr->links[i] && helper(idx+1, s, changes+1, curr->links[i])) return true;
            }
            return false;
        }
    }
    bool search(string search) {
        return helper(0, search, 0, root);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */