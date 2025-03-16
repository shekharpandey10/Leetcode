#include <bits/stdc++.h> 
using namespace std;
void merge(int s,int mid,int e,long long arr[],int &count){
    vector<long long>ans;
    int left=s;
    int right=mid+1;
    while(left<=mid && right<=e){
        if(arr[left]>arr[right]){
            ans.push_back(arr[right++]);
            count+=mid-left+1;
        }else{
            ans.push_back(arr[left++]);
        }
    }

    while(left<=mid){
        ans.push_back(arr[left++]);
    }
    while(right<=e){
        ans.push_back(arr[right++]);
    }
int k=0;
    for(int i=s;i<=e;i++){
        arr[i]=ans[k++];
    }
    
}
void mergeSort(int s,int e,long long arr[],int &count){
    int mid=s+(e-s)/2;
    if(s>=e) return;
    mergeSort(s,mid,arr,count);
    mergeSort(mid+1,e,arr,count);
    merge(s,mid,e,arr,count);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    int count=0;
    mergeSort(0,n-1,arr,count);
   
    return count;
}
int main(){
   long long arr[]={2,5,1,3,4};
    int n=sizeof(arr)/sizeof(long long);
   cout<< getInversions(arr,n);
}