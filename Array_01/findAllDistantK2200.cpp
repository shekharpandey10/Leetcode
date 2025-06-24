class Solution {
public:
    vector<int> sol2(vector<int>& nums, int key, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        vector<int> v(nums.size() + 1);
        while (i < nums.size()) {
            if (nums[i] == key) {
                int start = max(0, i - k);
                int end = min(n, k + i + 1);
                v[start]++;
                v[end]--;
            }
            i++;
        }
        vector<int> ans;
        j = 0;
        int sum = 0;
        while (j <= n) {
            sum += v[j];
            if (sum)
                ans.push_back(j);
            j++;
        }
        return ans;
    }
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        return sol2(nums, key, k);
        set<int> ans;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == key) {
                for (int j = 0; j < nums.size(); j++) {
                    if (abs(i - j) <= k) {
                        ans.insert(j);
                    }
                }
            }
        }
        vector<int> res(ans.begin(), ans.end());
        return res;
    }
};