class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];//at start can't sell only can buy
        int profit = 0;//initial profit
        int n = prices.size();
        for(int i = 0; i<n; i++){
            int diff= prices[i]-mini;//profit at various day
            profit = max(profit,diff);//maximum profit
            mini = min(mini,prices[i]);//minimum cost of single stock
        }
        return profit;
    }
};