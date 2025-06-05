class Solution {
  public:
    
    void solve(string temp,string s,vector<string>&ans){
        if(s.length()==0){
            ans.push_back(temp);
            return;
        }
        
        string s1=temp;
        string s2=temp;
        
        s1.push_back(' ');
        s1.push_back(s[0]);
        s2.push_back(s[0]);
        s.erase(s.begin()+0);
        solve(s1,s,ans);
        solve(s2,s,ans);

    }
    

    vector<string> permutation(string s) {
        // Code Here
      string opt(1, s[0]);
       vector<string>ans;
       s.erase(s.begin()+0);
       solve(opt,s,ans);
       return ans;
    }
};