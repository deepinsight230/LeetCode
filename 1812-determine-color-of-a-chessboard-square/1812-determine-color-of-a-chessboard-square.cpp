class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int check=(coordinates[0]-'a'+1)+(int)coordinates[1];
        return (check%2==0)?false:true;
    }
};