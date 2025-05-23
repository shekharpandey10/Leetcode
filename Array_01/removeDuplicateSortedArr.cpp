#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int usingSet(vector<int>& nums){ 
         set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        nums.assign(st.begin(),st.end());
        return nums.size();
}
    int usingtwoPointer(vector<int>& nums){

        int i=1;
        while(i<nums.size()){
            if(nums[i-1]==nums[nums.size()-1]){
                nums.pop_back();
                if(i>=nums.size()){
                    sort(nums.begin(),nums.end());
                    return nums.size();
                }
            }else if(nums[i]==nums[i-1]){
                swap(nums[i-1],nums[nums.size()-1]);
                nums.pop_back();
            }else
            i++;
        }
        sort(nums.begin(),nums.end());
        return nums.size();
    }
    int removeDuplicates(vector<int>& nums) {
        return usingtwoPointer(nums);
       return usingSet(nums);

    }
};