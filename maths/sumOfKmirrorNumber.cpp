class Solution {
public:
    string baseK(long long n, int k) {
        string res = "";
        if (n == 0)
            return res;
        else {
            while (n != 0) {
                res  += char('0' + (n % k)) ;
                n /= k;
            }
        }
        return res;
    }
    bool isPalindrome(string s) {
        if(s.length()==0) return false;
        int i = 0;
        int j = s.length() - 1;
        while (i <= j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    long long kMirror(int k, int n) {
        long long sum = 0;
        int l = 1;
        int half_len;
        while (n > 0) {
            if (l % 2 == 1)
                half_len = (l + 1) / 2;
            else
                half_len = l / 2;

            long long min = pow(10, half_len - 1);
            long long max = pow(10, half_len) - 1;

            for (int i = min; i <= max; i++) {
                string first_half = to_string(i);
                string second_half = first_half;
                string pal =first_half;
               if(l%2==1) second_half.pop_back();
               reverse(second_half.begin(),second_half.end());
               pal +=second_half;
                long long num = std::stoll(pal);
                string baseknum = baseK(num, k);

                if (isPalindrome(baseknum)) {
                    sum += num;
                    n--;
                    if (n == 0)
                        break;
                }
            }
            l++;
        }
        return sum;
    }
};