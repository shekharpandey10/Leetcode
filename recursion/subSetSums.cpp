#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
   void solve(int i,vector<int>& arr,int n,vector<int>& ans,int sum){
        if(i>=n){
            ans.push_back(sum);
            return;
        }
        solve(i+1,arr,n,ans,sum+arr[i]);
        solve(i+1,arr,n,ans,sum);
    }
    vector<int> subsets(vector<int>&arr){
        
        int i=0;
        vector<int>ans;
        int sum=0;
        int n=arr.size();
        solve(i,arr,n,ans,sum);
        return ans;
        
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        
       return subsets(arr);
    }
};  