class Solution {
public:
    int solveSO(vector<int> & prices,int fee){
        //observe the base case
        int n = prices.size();
        vector<int>curr(2,0);
        vector<int>next(2,0);
        //using bottom up approach
        for(int index = n-1; index>= 0; index--){
            for(int buy = 0; buy<= 1; buy++){
                int profit = 0;
                if(buy){
                    int buyProfit = -prices[index] +next[0];
                    int sellProfit = 0 + next[1];
                    profit = max(buyProfit, sellProfit);
                }else{
                    int sellProfit = prices[index] + next[1]-fee;
                    int buyProfit = 0+next[0];
                    profit = max(sellProfit, buyProfit);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solveSO(prices,fee);
    }
};