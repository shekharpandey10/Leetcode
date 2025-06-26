class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.length();if(n==0) return 0;
        int maxi=INT_MIN;
        
        for(int i=s.length()-1;i>=0;i--){
            double sum=0;
            int count=0;
            for(int j=i;j>=0;j--){
                if(sum<=k){
                    if(s[j]!='0'){
                    int shift=n-j-1;
                    sum+=pow(2,shift);
                    }
                    if(sum<=k)
                    count++;
                }else if(s[j]=='0'){
                    count++;
                }
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};