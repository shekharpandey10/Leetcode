#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> solution2(vector<int>& nums){    //in place O(1)
            for(int i=0;i<nums.size();i++){
                nums[i]+=1000*(nums[nums[i]]%1000);
            }
            for(int i=0;i<nums.size();i++){
                nums[i]=nums[i]/1000;
            }
            return nums;
        }
        vector<int> buildArray(vector<int>& nums) { // using extra space O(n)
            return solution2(nums);
            vector<int>ans(nums.size());
    
            for(int i=0;i<nums.size();i++){
                ans[i]=nums[nums[i]];
            }
            return ans;
        }
    };