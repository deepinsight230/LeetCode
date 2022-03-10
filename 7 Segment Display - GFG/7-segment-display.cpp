// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    string sevenSegments(string S, int N) {
        // code here
        int seg[10] = {6,2,5,5,4,5,6,3,7,5};
        
        int tseg = 0;
        for(int i=0; i<N; i++)
            tseg += seg[S[i]-'0'];
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<10; j++) {
                int lseg = tseg-seg[j];
                if(lseg >= 2*(N-i-1) and lseg <= 7*(N-i-1)) {
                    S[i] = j+'0';
                    tseg = lseg;
                    break;
                }
            }
        }
        
        return S;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout << ob.sevenSegments(S,N) << endl;
    }
    return 0;
}  // } Driver Code Ends