#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int o,int c,vector<string>&s,string temp){
        if(o==0 && c==0){
            s.push_back(temp);
            return;
        }
        if(o!=0){
            string op1=temp;
            op1.push_back('(');
            solve(o-1,c,s,op1);
        }
        if(c>o){
            string op2=temp;
            op2.push_back(')');
            solve(o,c-1,s,op2); 
        }
    }
    vector<string> generateParenthesis(int n) {
        int o=n;
        int c=n;
        vector<string>s;
        char c1='(';
        char c2=')';
        string temp="";
        solve(o,c,s,temp);
        return s;
    }
};