class Solution {
public:
    int possibleStringCount(string word) {
        int count =1;
        int n=word.length()-1;
       for(int i=n;i>0;i--){
            if(word[i]==word[i-1]){
                count +=1;
            }
       }
        return count;
    }
};