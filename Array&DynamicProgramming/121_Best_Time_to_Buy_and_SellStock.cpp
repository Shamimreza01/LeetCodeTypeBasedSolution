class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int currentMinimum=prices[0]; //initialize current minimum and maxprofit
        int maxProfit=0;

        for(int i=1;i<prices.size();i++){
           maxProfit=max(maxProfit,prices[i]-currentMinimum); //update maxProfit for each index
           currentMinimum=min(currentMinimum,prices[i]); //if any value is minimum than latest then update minimum
        }
        return maxProfit;
    }
};