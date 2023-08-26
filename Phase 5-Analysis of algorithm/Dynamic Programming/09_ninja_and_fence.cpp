#include <bits/stdc++.h> 
using namespace std;
#define mod 1000000007
int add (int a, int b){
    return (a%mod + b%mod)%mod;
}
int mul (int a , int b){
    return ((a%mod)*1LL*(b%mod))%mod;
}
//recursive call
int solve(int n, int k){
    if(n==1){
        return k;// with all different color
    }
    if(n==2){
        //k*k-1 + k
        return add(k,mul(k,k-1));
    }
    //formula for painting fence problem
    // solve(n-2,k)*k-1 + solve(n-1,k)*k-1
    int ans = add(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
    return ans;
}
//adding memoization
int solveMem(int n, int k, vector<int>&dp){
    if(n==1){
        return k;// with all different color
    }
    if(n==2){
        return add(k,mul(k,k-1));
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = add(mul(solveMem(n-2,k,dp),k-1),mul(k-1,solveMem(n-1,k,dp)));
    return dp[n];
}
//adding tabulation
int solveTab(int n, int k){
    vector<int>dp(n+1,0);
    dp[1] = k;
    dp[2] = add(k,mul(k,k-1));
   
    for(int i = 3; i<=n; i++){
        dp[i] = add(mul(dp[i-2],k-1),mul(k-1,dp[i-1]));
    }
    return dp[n];
}
//optimizing space
int solveSO(int n, int k){
    int prev2 = k;
    int prev1 = add(k,mul(k,k-1));
   
    for(int i = 3; i<=n; i++){
        int ans = add(mul(prev2,k-1),mul(k-1,prev1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
int numberOfWays(int n, int k) {
    // Write your code here.
    // return solve(n,k);
    // vector<int>dp(n+1,-1);
    // return solveMem(n,k,dp);
    // return solveTab(n,k);
    return solveSO(n,k);
}

