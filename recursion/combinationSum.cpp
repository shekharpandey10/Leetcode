#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<int>&candidates,int target,int i,vector<vector<int>>&ans,vector<int>temp){
        if(i>=candidates.size()){
            return;
        }
        if(target==0){
            ans.push_back(temp);
            return;
        }
        vector<int>op1=temp;
        vector<int>op2=temp;
         
         if(candidates[i]<=target){
            op1.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i,ans,op1);
         }
        solve(candidates,target,i+1,ans,op2);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int i=0;
        vector<vector<int>>ans;
        vector<int>temp;
        solve(candidates,target,i,ans,temp);
        return ans;
    }
};