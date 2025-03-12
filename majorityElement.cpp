#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int optimal(vector<int>& nums){
            int count=0;
            int ele;
            for(int i=0;i<nums.size();i++){
                if(count==0){
                    ele=nums[i];
                }
                if(ele==nums[i]){
                    count++;
                }else{
                    count--;
                }
            }
            return ele;
        }
        int usingMap(vector<int>& nums){       //Using map datastructure.
            map<int,int>m;
            int n=nums.size();
    
            for(int i=0;i<n;i++){
                  m[nums[i]]++;
            }
    
            for(auto i:m){
                if(i.second>n/2){
                    return i.first;
                }
            }
            return -1;
    
        }
        int majorityElement(vector<int>& nums) {
            return optimal(nums); //using Moore's voting algorithm.
           return usingMap(nums);  //using Hash-Table
            int n=nums.size();
           for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int count=0;
            for(int j=i;j<nums.size();j++){
                    if(num==nums[j]) count++;
            }
            if(count > n/2) return num;
           }
           return -1;
        }
    };