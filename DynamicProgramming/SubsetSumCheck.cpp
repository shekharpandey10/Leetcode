#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int>arr,int sum){
    int n=arr.size();
    vector<vector<bool>>t(n+1,vector<bool>(sum+1));

    for (int j = 1; j <= sum; j++) {
        t[0][j] = false; 
    }
    for (int i = 0; i <= n; i++) {
       t[i][0] = true;
   }


    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            }else{
                t[i][j]= t[i-1][j];
                
            }
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return t[n][sum];


}
int main(){
    vector<int>arr={2,3,7,8,10};
    int sum=9;

    cout<<solve(arr,sum);
}