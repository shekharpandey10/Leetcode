#include<iostream>
using namespace std;
class Solution {
public:
    void solve(set<vector<int>>&st,vector<int>&temp,vector<int>nums){
        if(nums.size()==0){
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        vector<int>temp1=temp;
        vector<int>temp2=temp;
        temp2.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        solve(st,temp1,nums);
        solve(st,temp2,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       set<vector<int>>st;
       vector<int>temp;
       solve(st,temp,nums);
     vector<vector<int>>ans(st.begin(),st.end());
     return ans;
    }
};