#include<bits/stdc++.h>
using namespace std;
 bool isExist(string temp,string s,int k){
        string str="";
        int j=0;
        while(k--) str+=temp;
        for(int i=0;i<s.size();i++){
            if(s[i]==str[j]){
                j++;
            }
            if(j==s.size()) break;
        }
        return j==s.size();
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string>q;
        q.push("");
        string ans;

        while(!q.empty()){
            string str=q.front(); 
            q.pop();

            for(char c='a';c<='z';c++){
                string temp=str+c;
                if(isExist(temp,s,k)){
                    q.push(temp);
                    if(temp.size()>ans.size() || temp>ans){
                        ans=temp;
                    }
                }
            }
        }
        return ans;
    }
    int main(){
        string s="letsleetcode";
        int k=2;
       cout<< longestSubsequenceRepeatedK(s,k);
    }