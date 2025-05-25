#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
     int maxMeetings(vector<int>& start, vector<int>& end) {
        
        vector<pair<int,int>> sol;
        
        for(int i=0;i<start.size();i++){
            sol.push_back(make_pair(start[i],end[i]));
        }
        
        sort(sol.begin(),sol.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second<b.second;
        });
        int count=1;
        int latest=sol[0].second;
        
        for(int i=1;i<start.size();i++){
            if(sol[i].first>latest){
                count++;
                latest=sol[i].second;
            }
        }
        return count;
       
    }
};