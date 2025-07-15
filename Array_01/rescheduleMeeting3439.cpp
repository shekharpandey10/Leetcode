class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>freq;

        freq.push_back(startTime[0]);
        for(int i=1;i<startTime.size();i++){
            freq.push_back(startTime[i]-endTime[i-1]);
        }
        freq.push_back(eventTime-endTime.back());

        for(auto f:freq) cout<<f<<" ";

        int i=0,j=0;
        int maxsum=0,currentsum=0;
        int n=freq.size();
        while(j<n){
            currentsum +=freq[j];

            if(i<n && j-i+1>k+1){
                currentsum -=freq[i];
                i++;
            }
            maxsum=max(maxsum,currentsum);
            j++;
        }
        return maxsum;
    }
};