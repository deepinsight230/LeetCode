class Solution {
public:
    set<string> s;
    void permutations(int idx, set<string> &s, string &tiles){
        if(idx==tiles.size()){
            // if(tiles.size()==3) cout<<tiles<<endl;
            s.insert(tiles);
            return;
        }
        for(int i=idx;i<tiles.size();i++){
            swap(tiles[idx], tiles[i]);
            permutations(idx+1, s, tiles);
            swap(tiles[idx], tiles[i]);
        }
    }
    void subset(int idx, string ds, string tiles){
        if(idx==tiles.size()){
            
            if(ds!="") permutations(0, s, ds);
            // cout<<ds<<s.size()<<endl;
            // ans+=s.size();
            return;
        }
        subset(idx+1, ds+tiles[idx], tiles);
        subset(idx+1, ds, tiles);
    }
    int numTilePossibilities(string tiles) {
        subset(0, "", tiles);
        return s.size();
    }
};