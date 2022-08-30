struct Node{
    Node *link[26];
    bool flag=false;
    bool containsKey(char ch){
        return (link[ch-'a']!=NULL);
    }
    Node *getNext(char ch){
        return link[ch-'a'];
    }
};

class Trie {
public:
    Node *root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->containsKey(word[i])){
                curr->link[word[i]-'a']=new Node();
            }
            curr=curr->getNext(word[i]);
        }
        curr->flag=true;
    }
    
    bool search(string word) {
        Node *curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->containsKey(word[i])) return false;
            curr=curr->getNext(word[i]);
        }
        return (curr->flag);
    }
    
    bool startsWith(string prefix) {
        Node *curr=root;
        for(int i=0;i<prefix.size();i++){
            if(!curr->containsKey(prefix[i])) return false;
            curr=curr->getNext(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */