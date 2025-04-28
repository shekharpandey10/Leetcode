#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> getConcatenation(vector<int>& nums) {
            vector<int> arr(nums.begin(),nums.end());
            for(int i=0;i<arr.size();i++){
                nums.push_back(arr[i]);
            }
            return nums;
        }
    };