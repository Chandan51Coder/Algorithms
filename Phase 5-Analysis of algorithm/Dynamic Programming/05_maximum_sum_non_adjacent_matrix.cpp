#include <bits/stdc++.h> 
//recursive call
int solve(vector<int>&nums, int n){
    //base case
    if(n<0){//for all the negaiive index in vector 
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    //recursive call
    int inc = nums[n]+ solve(nums,n-2);//if first include, we can't include next number.
    int exc = 0+solve(nums,n-1);//if we ignore the first number, then we can include next number.
    return max(inc,exc);
}
//recursive call with memoization
int solveMem(vector<int>&nums, int n,vector<int>&dp){
    //base case
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    if(dp[n] != -1){
        return dp[n];
    }
    //recursive call
    int inc = nums[n]+ solveMem(nums,n-2,dp);
    int exc = 0+solveMem(nums,n-1,dp);
    dp[n] = max(inc,exc);
    return dp[n];
}
//using tabulation method
int solveTab(vector<int>&nums){
    //base case
    int n = nums.size();
    vector<int>dp(n+1,0);
    dp[0] = nums[0];
    
    //recursive call
    for(int i = 1; i<n; i++){
        int inc = nums[i]+ dp[i-2];
        int exc = 0+dp[i-1];
        dp[i] = max(inc,exc);
    }
    return dp[n-1];
}
//optimizing space
int solveSO(vector<int>&nums){
    //removing dp vector by analyzing dependies of dp[i]
    int n = nums.size();
    int p2 = 0;
    int p1 = nums[0];
    
    //recursive call
    for(int i = 1; i<n; i++){
        int inc = nums[i]+ p2;
        int exc = 0+p1;
        int ans = max(inc,exc);
        p2= p1;
        p1= ans;
    }
    return p1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    // int n = nums.size();
    // int ans= solve(nums,n-1);//traversing right to left
    // vector<int>dp(n+1,-1);
    // int ans = solveMem(nums,n-1,dp);
    // int ans = solveTab(nums);
    int ans = solveSO(nums);
    return ans;
}