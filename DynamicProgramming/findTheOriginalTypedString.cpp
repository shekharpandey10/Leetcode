class Solution {
    private:
     int MOD=1e9+7;
public:
    int possibleStringCount(string word, int k) {
        int n=word.length();
        vector<int>group;

        int currentCount=1;
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]){
                currentCount++;
            }else{
                group.push_back(currentCount);
                currentCount=1;
            }
        }
         group.push_back(currentCount);


        long  comb=1;
        for(int i=0;i<group.size();i++){
            comb=(comb*group[i])%MOD; 
        }

        if(group.size()>=k) return comb;


        //use dp to subtract combination of length<k

        vector<int> dp(k, 0);
        dp[0] = 1;

        for (int g : group) {
            vector<int> new_dp(k, 0);
            long sum = 0;
            for (int s = 0; s < k; s++) {
                if (s > 0)
                    sum = (sum + dp[s - 1]) % MOD;
                if (s > g)
                    sum = (sum - dp[s - g - 1] + MOD) % MOD;
                new_dp[s] = sum;
            }
            dp = new_dp;
        }
        long long invalid=0;
    for(int i=group.size();i<k;i++){
        invalid=(invalid+dp[i])%MOD;
    }
        return (int)((comb-invalid+MOD)%MOD);
        
    }
};