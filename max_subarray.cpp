#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int optimalSol(vector<int>&nums){
        int ans=nums[0];
        int sum=nums[0];
        int a=0,b=nums.size()-1;
        for(int i=1;i<nums.size();i++){
             if(sum<0) {
                sum=0;
                a=i;
            }
            sum+=nums[i];
            if(ans<sum){
                b=i;
            }
            ans=max(ans,sum);
            
           
        }
        cout<<a<<" "<<b;   //print the indexes of the max subarray.
        return ans;
    }
        int maxSubArray(vector<int>& nums) {
           return optimalSol(nums);
            int ans=nums[0];
           
            for(int i=0;i<nums.size();i++){
                 int sum=nums[i];
                for(int j=i+1;j<nums.size();j++){
                    sum+=nums[j];
                    ans=max(sum,ans);
                    
                }
                
            }
            for(int i=0;i<nums.size();i++){
              ans=  max(ans,nums[i]);
            }
        
            return ans;
        }
    };