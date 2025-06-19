class Solution {
public:
    int optimise(vector<int>& nums,int k){
        sort(nums.begin(),nums.end());
        int count=0;
        int j=0;
        for(int i=0;i<nums.size();){
            if(j<nums.size() && nums[j]-nums[i]<=k){
                j++;
            }else{
                count++;
                i=j;
            }
        }
        return count;
    }
    int partitionArray(vector<int>& nums, int k) {
        return optimise(nums,k);
        vector<vector<int>>ans;
            int j=0;
            vector<int>temp;
            sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();){
            if(j<nums.size() && nums[j]-nums[i]<=k){
                temp.push_back(nums[j]);
                j++;
            }else{
                ans.push_back(temp);
                temp.clear();
                i=j;
            }

        }
        
       return ans.size();
    }
};