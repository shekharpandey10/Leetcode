class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi=INT_MIN;
        int j=1,i=0;
       while(j<nums.size()){
            int diff=nums[j]-nums[i];
            maxi= max(abs(diff),maxi);
            j++;
            i++;
       }
      int diff=abs(nums[0]-nums[nums.size()-1]);
        maxi=max(diff,maxi);
        return maxi;
    }
};