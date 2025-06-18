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
            if(nums[i+2]-nums[i]>k) return {};
            else temp.insert(temp.end(),nums.begin()+i,nums.begin()+i+3);
            ans.push_back(temp);
            i+=3;
        }
        return ans;
    }
};