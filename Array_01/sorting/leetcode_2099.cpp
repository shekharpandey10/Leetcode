class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> p;


        for (int i = 0; i < nums.size(); i++) {
            p.push_back({nums[i], i});
        }

     
        sort(p.begin(), p.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

 
        vector<pair<int, int>> topK(p.begin(), p.begin() + k);

      
        sort(topK.begin(), topK.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<int> ans;
        for (auto &pr : topK) {
            ans.push_back(pr.first);
        }

        return ans;
    }
};