#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
        // Code here
        
        int n=s.length();
        int k=pow(2,n);
        vector<string>ans;
        for(int i=0;i<(1<<n);i++){
            string part="";
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    part+=s[j];
                }
            }
            ans.push_back(part);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};