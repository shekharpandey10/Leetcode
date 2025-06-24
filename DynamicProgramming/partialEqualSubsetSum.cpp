class Solution {
public:
    bool usingRecursion(vector<int>& nums,int target,int i,vector<vector<int>>&dp){
        if(nums.size()<=i || target<0) return false;
        if(target==0) return true;
        if(dp[i][target]!=-1) return dp[i][target];
        return dp[i][target]=usingRecursion(nums,target-nums[i],i+1,dp) || usingRecursion(nums,target,i+1,dp);
        
    }
    bool canPartition(vector<int>& nums) {
    int sum=accumulate(nums.begin(),nums.end(),0);
    cout<<sum;
    if(sum%2!=0) return false;
    int final=0;
    vector<vector<int>>dp(nums.size(),vector<int>((sum/2)+1 ,-1));
       return usingRecursion(nums,sum/2,0,dp);
    }
};