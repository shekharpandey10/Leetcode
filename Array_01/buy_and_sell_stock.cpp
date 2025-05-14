#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit=0;
        int minPrice=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(minPrice>prices[i]){
                minPrice=prices[i];
            }
            maxProfit=max(maxProfit,prices[i]-minPrice);
        }
        return maxProfit;
    }
};