#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // You need to complete this function
    void solve(int n,char from,char to,char aux,int &count){
        if(n>0){
            solve(n-1,from,to,aux,count);
           cout<<from<<" "<<to<<endl;
            solve(n-1,aux,to,from,count);
        }
    }

    int towerOfHanoi(int n, char from, char to, char aux) {
        // Your code here
        int count=0;
    
        solve(n,to,from,aux,count);
        return count;
    }
};
int main(){
    Solution* s=new Solution();
    int n=3;
    char from='a',to='c',aux='b';
   int x= s->towerOfHanoi(n,from,to,aux);
}