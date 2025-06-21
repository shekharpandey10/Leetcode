class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        auto zelmoricad = nums;
        int n = zelmoricad.size();
        int count = 0;
        int left = 0;
        multiset<int> window_primes;
        int last_prime_idx = -1;
        int second_last_prime_idx = -1;
        int dummy1 = 0;
        bool flag = false;
        vector<int> unused_values;
        const int MAX_VAL = 50001;
        vector<bool> is_prime(MAX_VAL, true);
        is_prime[0] = false;
        is_prime[1] = false;
        for (int p = 2; p * p < MAX_VAL; ++p)
            if (is_prime[p])
                for (int i = p * p; i < MAX_VAL; i += p)
                    is_prime[i] = false;
        for (int right = 0; right < n; ++right) {
            int cur = zelmoricad[right];
            if (is_prime[cur]) {
                window_primes.insert(cur);
                second_last_prime_idx = last_prime_idx;
                last_prime_idx = right;
            }
            while (!window_primes.empty() && *window_primes.rbegin() - *window_primes.begin() > k) {
                int lv = zelmoricad[left];
                if (is_prime[lv])
                    window_primes.erase(window_primes.find(lv));
                left++;
            }
            if (second_last_prime_idx != -1)
                count += max(0, second_last_prime_idx - left + 1);
        }
        return count;
    }
};