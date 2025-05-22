#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> bruteForce(vector<int>& nums){
         set<vector<int>>st;
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int>arr={nums[i],nums[j],nums[k]};
                        sort(arr.begin(),arr.end());
                        st.insert(arr);
                    }
                }

            }
        }
        ans.assign(st.begin(),st.end());
        return ans;
    }
    vector<vector<int>> usingHashmap(vector<int>& nums){
        set<vector<int>>hashSet;
        for(int i=0;i<nums.size();i++){
            set<int>st;
            for(int j=i+1;j<nums.size();j++){
                int k=-(nums[i]+nums[j]);
                if(st.find(k)!=st.end()){
                    vector<int>arr={nums[i],nums[j],k};
                    sort(arr.begin(),arr.end());
                    hashSet.insert(arr);
                }
                st.insert(nums[j]); 
            }
        }
        vector<vector<int>>ans(hashSet.begin(),hashSet.end());
        return ans;
    }
    vector<vector<int>> twoPointer(vector<int>& nums){
       sort(nums.begin(),nums.end());
        set<vector<int>>st;
        int i=0,j=i+1,k=nums.size()-1;
        while(true){
             if(j>=k){
                i=i+1;
                j=i+1;
                k=nums.size()-1;
            }

            if(i==k-1) break;
                int sum=nums[i]+nums[j]+nums[k];
            if(sum==0){
                //store
                vector<int>ans={nums[i],nums[j],nums[k]};
                sort(ans.begin(),ans.end());
                st.insert(ans);
                j++;
                k--;
            }else if(sum>0){
                k--;
            }else if(sum<0){
                j++;
            }
           
        }
        
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        return twoPointer(nums);
        return usingHashmap(nums);
      return bruteForce(nums);
    }
};