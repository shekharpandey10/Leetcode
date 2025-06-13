#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>arr,int sum){   //top down approach
    int n=arr.size();
    vector<vector<bool>>t(n+1,vector<bool>(sum+1));

    for (int j = 1; j <= sum; j++) {
        t[0][j] = false; 
    }
    for (int i = 0; i <= n; i++) {
       t[i][0] = true;
   }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }else{
                t[i][j]= t[i-1][j];
                
            }
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return t[n][sum];


}
 bool solve(vector<int>& arr,int sum,int i,int total){   //using recursion
         if(total==sum){
            return true;
        }
        if(arr.size()==i){
            return false;
        }
        return solve(arr,sum,i+1,total+arr[i]) || solve(arr,sum,i+1,total);
        
    }
    bool usingDp(vector<int> arr,int sum,int i,vector<vector<int>>&dp){   //memoization dp
        
        if(sum==0) return true;
        if(arr.size()==i || sum<0) return false; 
        if(dp[i][sum]!=1) return dp[i][sum]; 

      return dp[i][sum]=usingDp(arr,sum-arr[i],i+1,dp) || usingDp(arr,sum,i+1,dp);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int total=0,i=0;
     return solve(arr,sum,i,total);
     vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
     return usingDp(arr,sum,i,dp);
        
    }
int main(){
    vector<int>arr={2,3,7,8,10};
    int sum=9;

    cout<<solve(arr,sum);
    isSubsetSum(arr,sum);
}