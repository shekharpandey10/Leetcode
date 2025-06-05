#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve( vector<vector<int>>&ans,vector<int>op,vector<int>nums){
        if(nums.size()==0){
            ans.push_back(op);
            return;
        }
        vector<int>op1=op;
        vector<int>op2=op;
        op2.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        solve(ans,op1,nums);
        solve(ans,op2,nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>ans;
       vector<int>op;
        solve(ans,op,nums);
        return ans;
    }
};