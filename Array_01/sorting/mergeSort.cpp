#include<bits/stdc++.h>
using namespace std;
void merge(int s,int e,int mid,vector<int>&v){
    int n1=mid-s+1;
    int n2=e-mid;
     int left=s;
     int right=mid+1;
    int arr[n1+n2];
    int i=0;
     while(left<=mid && right<=e){
        if(v[left]<=v[right]){
            arr[i++]=v[left++];
        }else{
            arr[i++]=v[right++];
        }
     }
     
     while(left<=mid){
        arr[i++]=v[left++];
     }
     while(right<=e){
        arr[i++]=v[right++];
     }

     for(int i=s,k=0;i<=e;i++){
        v[i]=arr[k++];
     }
}
void mergeSort(int s,int e,vector<int>& arr){
    int mid=s+(e-s)/2;
    if(s>=e) return;
    mergeSort(s,mid,arr);
    mergeSort(mid+1,e,arr);
    merge(s,e,mid,arr);
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    mergeSort(0,v.size()-1,v);
    for(auto i:v){
        cout<<i<<" ";
    }
}