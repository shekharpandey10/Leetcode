#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(string s, string opt, vector<string>& ans) {
        if (s.length() == 0) {
            ans.push_back(opt);
            return;
        }
        char ch=s[0];
        s.erase(s.begin()+0);

        if(isalpha(ch)){
            solve(s,opt+(char)tolower(ch),ans);
            solve(s,opt+(char)toupper(ch),ans);
        }else{
            solve(s,opt+ch,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string opt;
        solve(s, opt, ans);
        return ans;
    }
};