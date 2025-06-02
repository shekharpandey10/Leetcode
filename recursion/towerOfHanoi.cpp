#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // You need to complete this function
    void solve(int n,int from,int to,int aux,int &count){
        if(n>0){
            solve(n-1,from,to,aux,count);
            count++;
            solve(n-1,aux,to,from,count);
        }
    }

    int towerOfHanoi(int n, int from, int to, int aux) {
        // Your code here
        int count=0;
        solve(n,to,from,aux,count);
        return count;
    }
};