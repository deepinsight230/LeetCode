class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp1, mp2;
        for(char ch: s) mp1[ch]++;
        for(char ch: t) mp2[ch]++;
        return mp1==mp2;
    }
};