#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int l,m,h;
            l=m=0;
            h=nums.size()-1;
    
            while(m<=h){
               if(nums[m]==1){
                m++;
               }else if(nums[m]==0){
                swap(nums[m],nums[l]);
                    m++;
                    l++;
               }else{
                swap(nums[m],nums[h--]);
               }
            }
    
            
        }
    };