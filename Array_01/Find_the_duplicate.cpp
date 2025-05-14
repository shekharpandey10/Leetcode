#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int optimal(vector<int>& nums){
            while(true){
                if(nums[nums[0]]==nums[0]){
                    return nums[0];
                }else swap(nums[nums[0]],nums[0]);
            }
            return -1;
        }
        int findDuplicate(vector<int>& nums) {
      return optimal(nums);
            sort(nums.begin(),nums.end());
            for(int i=1;i<nums.size();i++){
                if(nums[i]==nums[i-1]){
                    return nums[i];
                }
            }
            return -1;
       
        }
    };