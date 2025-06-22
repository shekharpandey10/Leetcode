class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        for(int i=0;i<s.length();i+=k){
                string str=s.substr(i,k);
                if(str.size()-k!=0){
                    int x= k-str.length();
                    while(x--) {
                        str +=fill;
                    }
                }
                ans.push_back(str);
        }
        return ans;
    }
};