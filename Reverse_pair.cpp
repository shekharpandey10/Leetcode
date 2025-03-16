#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void merge(int s,int e,int mid,vector<int> & nums,int &count){
            vector<int> ans;
            int left=s;
            int right=mid+1;
    
        countPair(left,e,mid,nums,count);
    
            while(left<=mid && right<=e){
                if(nums[left]>nums[right]){
                    ans.push_back(nums[right++]);
                }else{
                    ans.push_back(nums[left++]);
                }
            }
            while(left<=mid){
                ans.push_back(nums[left++]);
            }
            while(right<=e){
                ans.push_back(nums[right++]);
            }
        int k=0;
            for(int i=s;i<=e;i++){
                nums[i]=ans[k++];
            }
    
        }
        void countPair(int left,int e,int mid,vector<int> &nums,int &count){
          int right=mid+1;
            while(left<=mid && right<=e){
                if(nums[left]>2*(long long)nums[right]){
                    count+=mid-left+1;
                    right++;
                }else{
                    left++;
                }
            }
        }
        void mergeSort(int s,int e,vector<int> &nums,int &count){
            int mid=s+(e-s)/2;
            if(s>=e) return;
            mergeSort(s,mid,nums,count);
            mergeSort(mid+1,e,nums,count);
            merge(s,e,mid,nums,count);
        }
        int reversePairs(vector<int>& nums) {
            int count=0;
            mergeSort(0,nums.size()-1,nums,count);
            return count;
        }
    };