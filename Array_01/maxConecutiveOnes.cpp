#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c1=0;
        int c2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                c2=max(c1,c2);
                c1=0;
            }else{
                c1++;
            }
        }
        c2=max(c1,c2);
        return c2;
    }
};