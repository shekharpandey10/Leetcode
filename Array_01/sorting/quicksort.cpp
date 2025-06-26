#include<bits/stdc++.h>
using namespace std;
int pivotEle(vector<int>&v,int low,int high){
    int i=low;
    int j=high;
    int pivot=v[low];

    while(i<j){
        while(v[i]<=pivot && i<=high-1) i++;
        while(v[j]>pivot && j>=low-1) j--;
        if(i<j){
            swap(v[i],v[j]);
        }
    }
    swap(v[low],v[j]);
    return j;
}
void quickSort(vector<int>&v,int low,int high){

    if(low<high){
        int piv=pivotEle(v,low,high);
        quickSort(v,low,piv-1);
        quickSort(v,piv+1,high);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    quickSort(v,0,v.size()-1);
    for(auto i:v){
        cout<<i<<" ";
    }
}