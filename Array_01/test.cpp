#include<bits/stdc++.h>
using namespace std;
int main(){
      vector<int> nums={1,2,3,4,5};
    int sum=accumulate(nums.begin(),nums.end(),0);
    cout<<sum; 
}