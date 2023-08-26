#include <bits/stdc++.h> 
using namespace std;
//recursive relation
int solve(vector<int>&num,int tar){
    if(tar<0){
        return 0;
    }
    if(tar==0){
        return 1;
    }
    int ans = 0;
    for(int i = 0; i<num.size(); i++){
        ans += solve(num,tar-num[i]);
    }
    return ans;
}
//recursive relation with memoization
int solveMem(vector<int>&num,int tar,vector<int>&dp){
    if(tar<0){
        return 0;
    }
    if(tar==0){
        return 1;
    }
    if(dp[tar] != -1){
        return dp[tar];
    }
    int ans = 0;
    for(int i = 0; i<num.size(); i++){
        ans += solveMem(num,tar-num[i],dp);
    }
    dp[tar] = ans;
    return dp[tar];
}
//using tabulation method
int solveTab(vector<int>&num,int tar){
    vector<int>dp(tar+1,0);
    dp[0] = 1;
    
    for(int i = 1; i<= tar; i++){
        for(int j = 0; j<num.size(); j++){
            if(i-num[j]>=0){
                dp[i] += dp[i-num[j]];
            }
        }
    }
    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    // return solve(num,tar);
    // vector<int>dp(tar+1,-1);
    // return solveMem(num,tar,dp);
    return solveTab(num,tar);

}