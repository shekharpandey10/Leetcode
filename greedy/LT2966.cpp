class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size()/3;
        int i=0;
        while(i<nums.size()){
            vector<int>temp;
            int j=i;
            while(j<=i+2){
                if(nums[i+2]-nums[j]<=k){
                    temp.push_back(nums[j]);
                }else if(nums[i+2]-nums[j]>k){
                    return {};
                }
                j++;
            }
            if(flag)
            ans.push_back(temp);
            i+=3;
        }

        return ans;
    }
};