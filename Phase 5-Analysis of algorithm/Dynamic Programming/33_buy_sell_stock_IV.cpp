class Solution {
public:
    int solve(int i, int opNo, int k, vector<int>&prices){
        int n = prices.size();
        if(i == n){
            return 0;
        }
        if(opNo == 2*k){
            return 0;
        }
        int profit = 0;
        if(opNo % 2== 0){
            int buyProfit = -prices[i] + solve(i+1,opNo+1,k,prices);
            int sellProfit = 0 + solve(i+1,opNo,k,prices);
            profit = max(buyProfit, sellProfit);
        }else{
            int sellProfit = prices[i] + solve(i+1,opNo+1,k,prices);
            int buyProfit = 0+solve(i+1,opNo,k,prices);
            profit = max(sellProfit, buyProfit);
        }
        return profit;
    }
    //adding memoization
    int solveMem(int i, int opNo, int k, vector<int>&prices, vector<vector<int>>&dp){
        int n = prices.size();
        if(i == n){
            return 0;
        }
        if(opNo == 2*k){
            return 0;
        }
        if(dp[i][opNo] != -1){
            return dp[i][opNo];
        }
        int profit = 0;
        if(opNo % 2== 0){
            int buyProfit = -prices[i] + solveMem(i+1,opNo+1,k,prices,dp);
            int sellProfit = 0 + solveMem(i+1,opNo,k,prices,dp);
            profit = max(buyProfit, sellProfit);
        }else{
            int sellProfit = prices[i] + solveMem(i+1,opNo+1,k,prices,dp);
            int buyProfit = 0+solveMem(i+1,opNo,k,prices,dp);
            profit = max(sellProfit, buyProfit);
        }
        dp[i][opNo] = profit;
        return dp[i][opNo];
    }
    //using tabulation 
    int solveTab(vector<int>&prices,int k){
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        
        for(int i = n-1; i>= 0; i--){
            for(int opNo = 0 ; opNo<2*k; opNo++){
                int profit = 0;
                if(opNo % 2== 0){
                    int buyProfit = -prices[i] + dp[i+1][opNo+1];
                    int sellProfit = 0 + dp[i+1][opNo];
                    profit = max(buyProfit, sellProfit);
                }else{
                    int sellProfit = prices[i] + dp[i+1][opNo+1];
                    int buyProfit = 0+dp[i+1][opNo];
                    profit = max(sellProfit, buyProfit);
                }
                dp[i][opNo] = profit;
            }
        }
        return dp[0][0];
    }
    //optimizing space
    int solveSO(vector<int>&prices,int k){
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        vector<int>curr(2*k+1,0);
        vector<int>next(2*k+1,0);
        for(int i = n-1; i>= 0; i--){
            for(int opNo = 0 ; opNo<2*k; opNo++){
                int profit = 0;
                if(opNo % 2== 0){
                    int buyProfit = -prices[i] + next[opNo+1];
                    int sellProfit = 0 + next[opNo];
                    profit = max(buyProfit, sellProfit);
                }else{
                    int sellProfit = prices[i] + next[opNo+1];
                    int buyProfit = 0+next[opNo];
                    profit = max(sellProfit, buyProfit);
                }
                curr[opNo] = profit;
            }
            next = curr;
        }
        return next[0];
    }
    int maxProfit(int k, vector<int>& prices) {
        int opNo = 2*k;
        // return solve(0,0,k,prices);
        // int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2*k,-1));
        // return solveMem(0,0,k,prices,dp);
        return solveSO(prices,k);
    }
};