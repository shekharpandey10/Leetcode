#include<bits/stdc++.h>
using namespace std;
class Solution {
        
        int solve(vector<int>arr,int n,int i,int sum,int &mini){
            if(i==n) return sum;
            
          int inc=solve(arr,n,i+1,sum+arr[i],mini);
          int exc=solve(arr,n,i+1,sum,mini);
          mini= min(mini,abs(inc-exc));
          return sum;
        }
  public:
    int usingTabulationDP(vector<int>arr){
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        int mini=INT_MAX;
        for(int s1=0;s1<=sum;s1++){
            if(dp[n][s1]){
                int s2=sum-s1;
                mini= min(mini,abs(s2-s1));        
            }
            
        }
        return mini;
        
    }
    int minDifference(vector<int>& arr) {
      
       return usingTabulationDP(arr);
        int count=INT_MAX;
        solve(arr,arr.size(),0,0,count);
        return count;
    }
};
