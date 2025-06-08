#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int solve(vector<int>val,vector<int>wt,int w,int n){
       if(w==0 || n==0){
           return 0;
       }
       int pick=0;
       if(wt[n-1]<=w){
           
           pick=val[n-1]+solve(val,wt,w-wt[n-1],n-1);
       }
       int notpick=solve(val,wt,w,n-1);
       return max(pick,notpick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        return solve(val,wt,W,n);
    }
};