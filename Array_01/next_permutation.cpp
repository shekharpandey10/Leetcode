#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
          int store;
          int i=nums.size()-2;
          while(i>=0){
            if(nums[i]<nums[i+1]){
                store=i;
                // cout<<i;
                break;
            }
            i--;
          }
    
        if(i<0){
            reverse(nums.begin(),nums.end());
            return;
        }
      int min=nums[store+1];
      int pointer=store+1;
        for(int i=store+1;i<nums.size();i++){
            if(nums[i]>nums[store] && min>=nums[i]){
             min=nums[i];
            pointer=i;
            }
        }
        
        cout<<min<<" "<<pointer;
        swap(nums[pointer],nums[store]);
        reverse(nums.begin()+store+1,nums.end());
        }
    };