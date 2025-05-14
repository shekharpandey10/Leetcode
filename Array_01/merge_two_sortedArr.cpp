#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
           int i=m-1,j=0;
           while(i>=0 && j<n){
            if(nums1[i]>nums2[j]){
                swap(nums1[i],nums2[j]);
                i--,j++;
            }else{
                break;
            }
           }
           sort(nums1.begin(),nums1.begin()+m);
           sort(nums2.begin(),nums2.end());
           int k=0;
           for(int i=m;i<nums1.size();i++){
            nums1[i]=nums2[k++];
           }
        }
    };