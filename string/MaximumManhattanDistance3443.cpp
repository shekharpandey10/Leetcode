class Solution {
public:
    int maxDistance(string s, int k) {
        
        int x=0,y=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
                if(s[i]=='N'){
                    y+=1;
                }else if(s[i]=='W'){
                    x -=(1);
                }else if(s[i]=='S'){
                    y -=(1);
                }else 
                    x+=1;

                ans=max(ans,min(abs(y)+abs(x)+k*2,i+1));
        }
        return ans;
    }
};