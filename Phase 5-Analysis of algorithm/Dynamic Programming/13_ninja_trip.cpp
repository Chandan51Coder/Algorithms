#include<bits/stdc++.h>
using namespace std;
int solve(int n, vector<int>&days, vector<int>&cost,int index){
    if(index>=n){//all cover
        return 0;
    }

    //1 day pass
    int op1 = cost[0] + solve(n,days,cost,index+1);
    int i;
    //7 day pass
    for(i =index; i<n && days[i]<days[index]+7;i++);


    int op2 = cost[1] + solve(n,days,cost,i);
    //30 day pass
    for(i = index; i<n && days[i]<days[index]+30;i++);


    int op3 = cost[2] + solve(n,days,cost,i);
    
    return min(op1,min(op2,op3));
}
//using memoization
int solveMem(int n, vector<int>&days, vector<int>&cost,int index,vector<int>&dp){
    if(index>=n){//all cover
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    //1 day pass
    int op1 = cost[0] + solve(n,days,cost,index+1);
    int i;
    //7 day pass
    for(i =index; i<n && days[i]<days[index]+7;i++);


    int op2 = cost[1] + solve(n,days,cost,i);
    //30 day pass
    for(i = index; i<n && days[i]<days[index]+30;i++);


    int op3 = cost[2] + solve(n,days,cost,i);
    dp[n] = min(op1,min(op2,op3));
    return dp[n];
}
//using tabulation method
int solveTab(int n, vector<int>days,vector<int>cost){
    vector<int>dp(n+1,INT_MAX);
    dp[n] = 0;
    for(int  k= n-1; k>= 0; k--){//start from n so that there should not any problem to move ahead.
        int op1 = cost[0] + dp[k+1];
        int i;
        //7 day pass
        for(i =k; i<n && days[i]<days[k]+7;i++);
        int op2 = cost[1] + dp[i];
        //30 day pass
        for(i = k; i<n && days[i]<days[k]+30;i++);
        int op3 = cost[2] + dp[i];
        dp[k] = min(op1,min(op2,op3));
    }
    return dp[0];
}
//optimizing space
//pending..........................................
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    // return solve(n,days,cost,0);
    // vector<int>dp(n+1,-1);
    // return solveMem(n,days,cost,0,dp);
    return solveTab(n,days,cost);
}