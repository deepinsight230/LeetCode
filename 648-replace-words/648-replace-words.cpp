struct Node{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node *next(char ch){
        return links[ch-'a'];
    }
};
class Solution {
    Node * root;
public:
    void createTrie(vector<string>& dictionary){
        for(int i=0;i<dictionary.size();i++){
            string word=dictionary[i];
            Node *curr=root;
            for(int j=0;j<word.size();j++){
                if(!curr->containsKey(word[j])) curr->links[word[j]-'a']=new Node();
                curr=curr->next(word[j]);
            }
            curr->flag=true;
        }
    }
    string helper(string word){
        // cout<<word<<" "<<word.size()<<endl;
        Node *curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->containsKey(word[i])) return word;
            curr=curr->next(word[i]);
            if(curr->flag) return word.substr(0, i+1);
            
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        root=new Node();
        createTrie(dictionary);
        sentence+=" ";
        string ans="", word="";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                string temp=helper(word);
                ans+=temp+" ";
                word="";
            }
            else word+=sentence[i];
        }
        ans.pop_back();
        return ans;
    }
};