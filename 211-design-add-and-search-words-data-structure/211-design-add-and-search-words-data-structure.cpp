#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
struct Node{
    Node *links[26];
    bool flag=false;
    inline bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    inline void puts(char ch, Node *node){
        links[ch-'a']=node;
    }
    inline Node *next(char ch){
        return links[ch-'a'];
    }
};

class WordDictionary {
public:
    Node *root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        FastIO;
        Node *curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->containsKey(word[i])){
                curr->puts(word[i], new Node());
            }
            curr=curr->next(word[i]);
        }
        curr->flag=true;
    }
    bool helper(string word, Node *curr){
        FastIO;
        for(int i=0;i<word.size();i++){
            if(word[i]=='.'){
                for(char ch='a';ch<='z';ch++){
                    if(curr->containsKey(ch) && helper(word.substr(i+1), curr->next(ch))) return true;
                }
                return false;
            }
            if(!curr->containsKey(word[i])) return false;
            curr=curr->next(word[i]);
        }
        return curr->flag;
    }
    bool search(string word) {
        FastIO;
        Node *curr=root;
        return helper(word, curr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */