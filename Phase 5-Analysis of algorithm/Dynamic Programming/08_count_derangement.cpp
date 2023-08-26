#include <bits/stdc++.h> 
using namespace std;
#define mod 1000000007
long long int solve(int n){
  //base case 
  if(n==1){
    return 0;
  }
  if(n==2){
    return 1;
  }
  //rr
  int ans = (n-1)%mod*(solve(n-2)+solve(n-1));
  return ans%mod;
}
//adding memoization
long long int solveMem(int n,vector<long long int>&dp){
  //base case 
  if(n==1){
    return 0;
  }
  if(n==2){
    return 1;
  }
  if(dp[n] != -1){
    return dp[n];
  }
  //rr
  int ans = ((n-1 )%mod* (solveMem(n-1,dp)%mod+solveMem(n-2,dp)%mod))%mod;
  dp[n] = ans%mod;
  return dp[n];
}
//using tabulation
long long int solveTab(int n){
  //base case 
  vector<int>dp(n+1,0);
  dp[1] = 0;
  dp[2] = 1;

  //rr
  for(int i = 3; i<= n; i++){
    long long int first = dp[i-1]%mod;
    long long int second = dp[i-2]%mod;
    long long int sum = (first + second)%mod;
    long long int ans = (i-1)%mod * sum;
    dp[i] = ans%mod;
  }
  return dp[n];
}
//optimizing space
long long int solveSO(int n){
  int prev2 = 0;
  int prev1 = 1;
  //rr
  for(int i = 3; i<= n; i++){
    long long int first = prev1%mod;
    long long int second = prev2%mod;
    long long int sum = (first + second)%mod;
    long long int ans = (i-1)%mod * sum;
    ans = ans%mod;
    prev2 = prev1;
    prev1 = ans;
  }
  return prev1;
}

long long int countDerangement(int n) {
  // Write your code here.
  // return solve(n);
  // vector<long long int>dp(n+1,-1);
  // return solveMem(n,dp);
  return solveSO(n);
}