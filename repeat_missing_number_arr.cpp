#include<bits/stdc++.h>
using namespace std;

vector<int> optimalAns(const vector<int>&arr){
    long long n=arr.size();
    long long sumOfN=(n*(n+1))/2;    //sum of first N number
   
     
     long long sumOfSqureOfN= (n*(n+1)*(2*n+1))/6; //sum of first N square numbers
    
     long long sumOfArr=0;
     long long sumOfSqareArr=0;
     for(int i=0;i<n;i++){
         sumOfArr +=arr[i];    
         sumOfSqareArr +=(long long)arr[i]*(long long)arr[i];
     }
    long long val1= sumOfArr-sumOfN;  //x-y
    long long val2= sumOfSqareArr-sumOfSqureOfN; //(x^2 + y^2) ==> (x+y)(x-y)
    val2=val2/val1;   //(x+y)
    
    long long x=(val1+val2)/2;    //(x+y)+(x-y)=>2x=K =>x=k/2;
    long long y=val2-x;
     return {(int)x,(int)y};  
 }
 vector<int> repeatedNumber(const vector<int> &A) {
     return optimalAns(A); //Using Math
     
     int n=A.size();
     vector<bool>ans(n,false);
     int firstEle;
     int secondEle;
     for(int i=0;i<n;i++){
         if(ans[A[i]-1]==true){
             firstEle=A[i];
         }else{
             ans[A[i]-1]=true;
         }
     }
     
     for(int i=0;i<n;i++){
         if(ans[i]==false){
             secondEle=i+1;
         }
     }
     return {firstEle,secondEle};
     
     
 }
 