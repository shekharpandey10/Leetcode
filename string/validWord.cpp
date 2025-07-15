class Solution {
public:
    int isVowel(char ch) {
        string str = "aeiouAEIOU";
        return (str.find(ch) != string::npos);
    }
    bool isValid(string word) {
        if (word.length() < 3)
            return false;
    int vowelCount=0;
    int consonentCount=0;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] >= 48 && word[i] <= 57 ||
                word[i] >= 65 && word[i] <= 90 ||
                word[i] >= 97 && word[i] <= 122) {
                    
                    if(isVowel(word[i])){
                        vowelCount++;
                    }else if(word[i]>=65&& word[i]<=90 || word[i]>=97 && word[i]<=122)
                        consonentCount++;
            } else {
                return false;
            }
        }

        if(vowelCount>0 && consonentCount>0) return true;
        else return false;
    }
};