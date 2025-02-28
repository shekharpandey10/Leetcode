class Solution {
    public:
     vector<int> ncr(int n){
        vector<int>arr;
        int ans=1;
         arr.push_back(ans);
        for(int i=0;i<n;i++){
          
            ans *= (n-i);
            ans /= (i+1);
             arr.push_back(ans);
            }
    return arr;
    }
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>>ans;
           vector<int>s=ncr(3);
           for(int i :s){
            cout<<i<<" ";
           }
            for(int i=0;i<numRows;i++){
                 vector<int>temp;
                    temp=ncr(i);
                    ans.push_back(temp);
            }
            return ans;
        }
    };