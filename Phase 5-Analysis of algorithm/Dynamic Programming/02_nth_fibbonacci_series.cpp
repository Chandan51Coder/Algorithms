#include<bits/stdc++.h>
using namespace std;
//recursive algorithm
//adding memoization
int fibonacci(int n,vector<int>&dp){
        //base case
        if(n<=2){
                return 1;
        }
        if(dp[n] != -1){
                return dp[n];
        }
        //recursive call
        int ans = fibonacci(n-1,dp)+fibonacci(n-2,dp);
        dp[n] = ans;
        return ans;
}
//using tabulation method bottom up approach
int fibonacciTab(int n){
        //creating dp vector analyzing the base case
        vector<int>dp(n+1,1);
        // removing recursive call by loop
        for(int i = 3;i<=n; i++){
             dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
}
//using space optimization method
int fibonacciSO(int n){
        //removing dp vector and analyzing the dependencies of dp[i]
        int prev1 = 1;
        int prev2 = 1;//
        for(int i = 3;i<=n; i++){
             //replacing corresponding dp
             int curr = prev2+prev1;
             prev2 = prev1;//first very previous will move ahead
             prev1 = curr;

        }
        return prev1;
}
int main()
{       
        int n;
        cin>>n;
        // vector<int>dp(n+1,-1);
        // int ans = fibonacci(n,dp);
        // int ans = fibonacciTab(n);
        int ans = fibonacciSO(n);
        cout<<ans<<endl;
}