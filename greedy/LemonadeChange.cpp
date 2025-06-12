class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,twenty=0;
        int i=0;
        while(i<bills.size()){
            if(bills[i]==5){
                five++;
            }else if(bills[i]==10){
                if(five==0) return false;
                ten++;
                five--;
            }else if(bills[i]==20){
                if(ten>=1 && five>=1){
                    twenty++;
                    ten--;
                    five--;
                }else if(five>=3){
                    five-=3;
                    twenty++;
                }else {
                    return false;
                }
            }else{
                return false;
            }
            i++;
        }
        return true;
    }
};