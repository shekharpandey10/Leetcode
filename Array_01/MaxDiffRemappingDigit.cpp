class Solution {
public:
    int minMaxDifference(int num) {
        string n1 = to_string(num);
        char ch1 = '\0';

        // Step 1: Find first non-'9' digit to replace for max
        for (char c : n1) {
            if (c != '9') {
                ch1 = c;
                break;
            }
        }

        // Max: replace ch1 with '9'
        string maxStr = n1;
        for (char& c : maxStr) {
            if (c == ch1) c = '9';
        }

        // Min: replace first digit with '0'
        string minStr = n1;
        char ch2 = minStr[0];
        for (char& c : minStr) {
            if (c == ch2) c = '0';
        }

        int maxi = stoi(maxStr);
        int mini = stoi(minStr);
        return maxi - mini;
    }
};