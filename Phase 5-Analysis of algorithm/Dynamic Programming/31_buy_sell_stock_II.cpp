
class Solution {
public:
    int solve(int i,int buy, vector<int>& prices){
        if(i==prices.size()){//if all days completed
            return 0;
        }
        int profit = 0;
        if(buy){
            int buyProfit = -prices[i] + solve(i+1,0,prices);
            int sellProfit = 0 + solve(i+1,1,prices);
            profit = max(buyProfit, sellProfit);
        }else{
            int sellProfit = prices[i] + solve(i+1,1,prices);
            int buyProfit = 0+solve(i+1,0,prices);
            profit = max(sellProfit, buyProfit);
        }
        return profit;
    }
    int solveMem(int i,int buy, vector<int>& prices,vector<vector<int>>&dp){
        if(i==prices.size()){//if all days completed
            return 0;
        }
        if(dp[i][buy] !=-1){
            return dp[i][buy];
        }
        int profit = 0;
        if(buy){
            int buyProfit = -prices[i] + solveMem(i+1,0,prices,dp);
            int sellProfit = 0 + solveMem(i+1,1,prices,dp);
            profit = max(buyProfit, sellProfit);
        }else{
            int sellProfit = prices[i] + solveMem(i+1,1,prices,dp);
            int buyProfit = 0+solveMem(i+1,0,prices,dp);
            profit = max(sellProfit, buyProfit);
        }
        dp[i][buy] = profit;
        return dp[i][buy];
    }
    int solveTab(vector<int> & prices){
        //observe the base case
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        //using bottom up approach
        for(int index = n-1; index>= 0; index--){
            for(int buy = 0; buy<= 1; buy++){
                int profit = 0;
                if(buy){
                    int buyProfit = -prices[index] + dp[index+1][0];
                    int sellProfit = 0 + dp[index+1][1];
                    profit = max(buyProfit, sellProfit);
                }else{
                    int sellProfit = prices[index] + dp[index+1][1];
                    int buyProfit = 0+dp[index+1][0];
                    profit = max(sellProfit, buyProfit);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
    int solveSO(vector<int> & prices){
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
                    int sellProfit = prices[index] + next[1];
                    int buyProfit = 0+next[0];
                    profit = max(sellProfit, buyProfit);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        // return solve(0,1,prices,dp);
        //adding memoization
        // int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return solveMem(0,1,prices,dp);
        //using tabulation
        // return solveTab(prices);
        return solveSO(prices);
    }
};