#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
void solve(string order, string s) {
    // Write your logic here
    sort(order.begin(),order.end());
    sort(s.begin(),s.end());

    int i=0;
    int j=0;
    string temp;
    while(i<order.length()){
        if(order[i]>s[j]){
            j++;
        }else if(order[i]==s[j]){
            temp.push_back(s[j]);
            j++;
        }else if(order[i]<s[j]){
            i++;
        }
    }
    string temp2;
     i=0; j=0;
     while(i<s.length() && j<temp.length()){
        if(s[i]<temp[j]){
            temp2.push_back(s[i]);
            i++;
        }else if(s[i]==temp[j]){
            i++;
            j++;
        }else j++;
     }
     while(i<s.length()){
        temp2.push_back(s[i++]);
     }
    reverse(temp.begin(),temp.end());
    temp+=temp2;
   cout<<temp;
}

int main() {
    string order, s;
    
    cin >> order >> s;
    
    solve(order, s);
    
    return 0;
}