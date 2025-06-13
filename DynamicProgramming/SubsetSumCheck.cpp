class Solution {
  public:
    bool solve(vector<int>& arr,int sum,int i,int total){   //using recursion
         if(total==sum){
            return true;
        }
        if(arr.size()==i || total>sum){
            return false;
        }
        return solve(arr,sum,i+1,total+arr[i]) || solve(arr,sum,i+1,total);
        
    }
    bool usingDp(vector<int> &arr,int sum,int i,vector<vector<int>>&dp){   //memoization dp
        
        if(sum==0) return true;
        if(arr.size()==i || sum<0)  return false; 
        if(dp[i][sum]!=-1) return dp[i][sum]; 

      return dp[i][sum]=usingDp(arr,sum-arr[i],i+1,dp) || usingDp(arr,sum,i+1,dp);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int total=0,i=0;
    //  return solve(arr,sum,i,total);
     vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
     return usingDp(arr,sum,i,dp);
        
    }
};