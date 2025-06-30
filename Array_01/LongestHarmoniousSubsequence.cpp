class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        vector<int>ans;
        vector<int>ans2;
        for(auto m:mp){
            ans.push_back(m.first);
            ans2.push_back(m.second);
        }
        int len=0;
        for(int i=1;i<ans.size();i++){
            if(abs(ans[i]-ans[i-1])==1){
                len=max(len,ans2[i]+ans2[i-1]);
            }
        }
        return len;
    }
};