class Solution {
public:
    int solve(int i,int buy, vector<int>& prices,int limit){
        if(i==prices.size()){//if all days completed
            return 0;
        }
        if(limit==0){
            return 0;
        }
        int profit = 0;
        if(buy){
            int buyProfit = -prices[i] + solve(i+1,0,prices,limit);
            int sellProfit = 0 + solve(i+1,1,prices,limit);
            profit = max(buyProfit, sellProfit);
        }else{
            int sellProfit = prices[i] + solve(i+1,1,prices,limit-1);
            int buyProfit = 0+solve(i+1,0,prices,limit);
            profit = max(sellProfit, buyProfit);
        }
        return profit;
    }
    //adding memoization
    int solveMem(int i,int buy, vector<int>& prices,int limit,vector<vector<vector<int>>>&dp){
        if(i==prices.size()){//if all days completed
            return 0;
        }
        if(limit==0){
            return 0;
        }
        if(dp[i][buy][limit] != -1){
            return dp[i][buy][limit];
        }
        int profit = 0;
        if(buy){
            int buyProfit = -prices[i] + solveMem(i+1,0,prices,limit,dp);
            int sellProfit = 0 + solveMem(i+1,1,prices,limit,dp);
            profit = max(buyProfit, sellProfit);
        }else{
            int sellProfit = prices[i] + solveMem(i+1,1,prices,limit-1,dp);
            int buyProfit = 0+solveMem(i+1,0,prices,limit,dp);
            profit = max(sellProfit, buyProfit);
        }
        dp[i][buy][limit] = profit;
        return dp[i][buy][limit];
    }
    int solveTab(vector<int> & prices){
        //observe the base case
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //using bottom up approach
        for(int index = n-1; index>= 0; index--){
            for(int buy = 0; buy<= 1; buy++){
                for(int limit = 1 ; limit<=2; limit++){
                    int profit = 0;
                    if(buy){
                        int buyProfit = -prices[index] + dp[index+1][0][limit];
                        int sellProfit = 0 + dp[index+1][1][limit];
                        profit = max(buyProfit, sellProfit);
                    }else{
                        int sellProfit = prices[index] + dp[index+1][1][limit-1];
                        int buyProfit = 0+dp[index+1][0][limit];
                        profit = max(sellProfit, buyProfit);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int solveSO(vector<int> & prices){
        //observe the base case
        int n = prices.size();
        vector<vector<int>>curr(2,vector<int>(3,0));
        vector<vector<int>>next(2,vector<int>(3,0));
        //using bottom up approach
        for(int index = n-1; index>= 0; index--){
            for(int buy = 0; buy<= 1; buy++){
                for(int limit = 1 ; limit<=2; limit++){
                    int profit = 0;
                    if(buy){
                        int buyProfit = -prices[index] + next[0][limit];
                        int sellProfit = 0 + next[1][limit];
                        profit = max(buyProfit, sellProfit);
                    }else{
                        int sellProfit = prices[index] +next[1][limit-1];
                        int buyProfit = 0+next[0][limit];
                        profit = max(sellProfit, buyProfit);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }
    int maxProfit(vector<int>& prices) {
        //added parameter limit
        // return solve(0,1,prices,2);
        // int n = prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solveMem(0,1,prices,2,dp);
        // return solveTab(prices);
        return solveSO(prices);
    }
};