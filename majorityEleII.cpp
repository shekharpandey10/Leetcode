#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> MooreVotingAlgo(vector<int> &nums){
            
            int n=nums.size();
            vector<int>ans;
            int count1=0,count2=0;
            int ele1=INT_MIN,ele2=INT_MIN;
            for(int i=0;i<n;i++){
                if(count1==0 &&nums[i] !=ele2 ){
                    count1=1;
                    ele1=nums[i];
                }else if(count2==0 && nums[i]!=ele1){
                    count2=1;
                    ele2=nums[i];
                }else if(ele1==nums[i]){
                    count1++;
                }else if(ele2==nums[i]){
                    count2++;
                }else{
                    count1--;
                    count2--;
                }
            }
            int c1=0,c2=0;
            for(int i=0;i<nums.size();i++){
                if(ele1==nums[i]) c1++;
                else if(ele2==nums[i]) c2++;
            }
            if(c1>n/3 && c2>n/3) return {ele1,ele2};
            if(c1>n/3) return {ele1};
            else if(c2>n/3) return {ele2};
          return {};
        }
        vector<int> hashMap(vector<int>& nums){
            map<int,int>m;
            vector<int>ans;
            int n=nums.size();
            for(int i=0;i<nums.size();i++){
                m[nums[i]]++;
            }
    
            for(auto it:m){
                if(it.second>n/3){
                    ans.push_back(it.first);
                }
            }
            return ans;
        }
        vector<int> majorityElement(vector<int>& nums) {
        //    return hashMap(nums);
       return MooreVotingAlgo(nums);
            int n=nums.size();
             int count=0;
             int ele;
             vector<int>ans;
            for(int i=0;i<nums.size();i++){
               
                 ele=nums[i];
                 
                
                if(ans.size()==0 || ans.back()!=ele){
                    count=0;
                    for(int j=i;j<nums.size();j++){
                    if(nums[j]==ele) count++;
                }
                if(count>n/3) ans.push_back(ele);
                }
                
             if(ans.size()==2) break;
            }
            return ans;
        }
    };