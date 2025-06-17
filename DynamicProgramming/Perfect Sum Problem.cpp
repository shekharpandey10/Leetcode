class Solution {
  public:
    void solve(vector<int>& arr, int target,int i,int &sum){
        if(target==0){
            sum++;
            return;
        }
        if(arr.size()==i || target<0){
            return;
        }
        solve(arr,target-arr[i],i+1,sum); 
        solve(arr,target,i+1,sum);
        
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
         int countzero=0;
        int sum=0;
        vector<int>filtered;
         for(int i=0;i<arr.size();i++){
            if(arr[i]==0) 
            countzero++;
            else 
            filtered.push_back(arr[i]);
        }
        solve(filtered,target,0,sum);
       
       
        return sum * (1 << countzero);
    }
};