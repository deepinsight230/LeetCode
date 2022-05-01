class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ns="", nt="";
        for(char ch: s){
            if(ch=='#')
            {
                if(ns!="")
                ns.pop_back();
            }
            else ns+=ch;
        }
        for(char ch: t){
            if(ch=='#')
            {
                if(nt!="")
                nt.pop_back();
            }
            else nt+=ch;
        }
        return (ns==nt);
    }
};