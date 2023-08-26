// code studio

#include <bits/stdc++.h> 
using namespace std;
#define mod 1000000007
//recursive approach
int solve(int n){
    //base case
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    //recurrence relation
    int ans  = solve(n-1) + solve(n-2);
    return ans;
}
//recursive approach with memoization
long long int solveMem(int n,vector<long long int> &dp){
    //base case
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    //recurrence relation
    long long int ans  = solveMem(n-1,dp) + solveMem(n-2,dp);
    dp[n] = ans%mod;
    return dp[n];
}
int countDistinctWays(int nStairs) {
    //  Write your code here.
    // int ans = solve(nStairs);
    vector<long long int>dp(nStairs+1,-1);
    long long int ans = solveMem(nStairs,dp);    
    return ans;                                                     
}

// leet code
class Solution {
public:
    int solve(vector<int>&cost, int n){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        int ans = cost[n] + min(solve(cost,n-1),solve(cost,n-2));
        return ans;
    }
// adding memoization (100%)
    int solveMem(vector<int>&cost, int n,vector<int>&dp){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = cost[n] + min(solveMem(cost,n-1,dp),solveMem(cost,n-2,dp));
        dp[n] = ans;
        return dp[n];
    }
//using tabulation
    int solveTab(vector<int>&cost, int n){
        //creating dp vector by analyzing the base case
        vector<int>dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        //removing recursive call via iteration
        for(int i = 2; i<n ; i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
//using tabulation
    int solveSO(vector<int>&cost, int n){
        //removing dp vector and analyzing the dependies of dp[i]
        int p0 = cost[0];
        int p1 = cost[1];
        
        //removing recursive call via iteration
        for(int i = 2; i<n ; i++){
            int curr = cost[i] + min(p0,p1);
            p0 = p1;
            p1 = curr;
        }
        return min(p0,p1);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int  n = cost.size();
        // int ans = min(solve(cost,n-1),solve(cost,n-2));
        // vector<int>dp(n+1,-1);
        // int ans = min(solveMem(cost,n-1,dp),solveMem(cost,n-2,dp));
        // int ans = solveTab(cost,n);
        int ans = solveSO(cost,n);
        return ans;
    }
};