#include<bits/stdc++.h>
using namespace std;
//solve using recursion
int solve(int n, int x, int y, int z){
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}
	int a = 1+solve(n-x,x,y,z);
	int b = 1+solve(n-y,x,y,z);
	int c = 1+solve(n-z,x,y,z);
	int ans = max(a,max(b,c));
	return ans;
}
//solve using recursion with memoization
int solveMem(int n, int x, int y, int z,vector<int>&dp){
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}
	if(dp[n] != -1){
		return dp[n];
	}
	int a = 1+solveMem(n-x,x,y,z,dp);
	int b = 1+solveMem(n-y,x,y,z,dp);
	int c = 1+solveMem(n-z,x,y,z,dp);
	int ans = max(a,max(b,c));
	dp[n] = ans;
	return dp[n];
}
//using tabulation method
int solveTab(int n, int x, int y, int z){
	vector<int>dp(n+1,INT_MIN);
	dp[0]=0;
	
	for(int i = 1; i<=n; i++){//dp[0] already handled
		if(i-x>=0 && dp[i-x] != INT_MIN){//dp negative ke liye bani nahi i-x>=0
			dp[i] = max(dp[i],1+dp[i-x]);
		}
		if(i-y>=0 && dp[i-y] != INT_MIN){
			dp[i] = max(dp[i],1+dp[i-y]);
		}
		if(i-z>=0 && dp[i-z] != INT_MIN){
			dp[i] = max(dp[i],1+dp[i-z]);
		}
	}
	return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	// int ans = solve(n,x,y,z);
	// vector<int>dp(n+1,-1);
	// int ans = solveMem(n,x,y,z,dp);
	int ans = solveTab(n,x,y,z);
	if(ans<0){
		return 0;
	}else{
		return ans;
	}

}