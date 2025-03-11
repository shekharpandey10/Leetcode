#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool binarySearch(vector<vector<int>>& matrix, int target){
            int s=0;
            int e=matrix.size()-1;
            int mid=s+(e-s)/2;
            bool flag=false;
            while(s<=e){
                mid=s+(e-s)/2;
                if(target==matrix[mid][0]){
                    return true;
                }
                if(target>matrix[mid][0]){
                    if(mid<matrix.size()-1 && target<matrix[mid+1][0] ||mid == matrix.size()-1) {
                        flag=true;
                        break;}
                    s=mid+1;
                }else{
                    e=mid-1;
                }
            }
            if(flag){
                for(int i=0;i<matrix[0].size();i++){
                if(target==matrix[mid][i]) return true;
            }
            }
           
            return false;
        }
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
          return  binarySearch(matrix,target);
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[0].size();j++){
                    if(matrix[i][j]==target)
                    return true;
                }
            }
            return false;
        }
    };