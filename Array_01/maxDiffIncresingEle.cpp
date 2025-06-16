#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& nums){
            int mini=INT_MAX;
            int maxi=-1;
            for(int i=0;i<nums.size();i++){
                mini=min(mini,nums[i]);
                if(nums[i]>mini){
                    maxi=max(maxi,nums[i]-mini);
                }
            }
      return maxi;
    }
    int maximumDifference(vector<int>& nums) {
        return solve(nums);
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[i]){
                    maxi=max(maxi,nums[j]-nums[i]);
                }
            }
        }
        return maxi;
    }
};