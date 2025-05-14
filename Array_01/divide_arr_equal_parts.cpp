#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool usingHash(vector<int>&nums){
    cout<<nums.size()<<endl;
            map<int,int>m;
            for(int i=0;i<nums.size();i++){
                m[nums[i]]++;
            }
            int count=0;
            for(auto i:m){
                while(i.second%2==0 && i.second!=0){
                    count++;
                    if(i.second>0)
                    i.second=i.second-2;
                    else
                    i.second=i.second+2;
                }
            }
            cout<<count;
            if(count==nums.size()/2) return true;
            return false;
        }
        bool divideArray(vector<int>& nums) {
            return usingHash(nums);
            int count=0;
            sort(nums.begin(),nums.end());
           int i=1;
           while(i<nums.size()){
            if(nums[i]==nums[i-1]){
                count++;
                i+=2;
            }else{
                i++;
            }
           }
           if(count==nums.size()/2) return true;
           return false;
        }
    };