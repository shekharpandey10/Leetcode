#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> usingHash(vector<int> &nums,int target){
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
    
        for(int i=0;i<nums.size();i++){
            int x=target-nums[i];
            if(m.find(x)!=m.end() && i!=m[x]){
               return {m[x],i};
            }
        }
     return {};
    }
        vector<int> usingSubtraction(vector<int>&nums,int target){
            int x,firstIdx=-1;
            for(int i=0;i<nums.size();i++){
                        x=target-nums[i];
                        for(int j=i+1;j<nums.size();j++){
                            if(nums[j]==x) return {i,j};
                        }
                }
                return {};
        }
        vector<int> twoSum(vector<int>& nums, int target) {
            // return usingSubtraction(nums,target);
           return usingHash(nums,target);
            for(int i=0;i<nums.size();i++){
                for(int j=i+1;j<nums.size();j++){
                    if(nums[i]+nums[j]==target)
                    return {i,j};
                }
            }
            return {};
        }
    };