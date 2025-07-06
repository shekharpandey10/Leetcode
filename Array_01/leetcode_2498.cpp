class Solution {
public:
    const int MOD = 1e9 + 7;
    int usingtwoPointer(vector<int>nums,int target){
        int i=0,j=nums.size()-1;
        int count=0;
         
         sort(nums.begin(),nums.end());
    int n=nums.size();
          vector<int> power(n, 1);
        for (int k = 1; k < n; ++k)
            power[k] = (power[k - 1] * 2) % MOD;

        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                count = (count + power[j - i]) % MOD;
                i++;
            } else {
                j--;
            }
        }

        return count;
    }
    int numSubseq(vector<int>& nums, int target) {
        return usingtwoPointer(nums,target);
    }
};

