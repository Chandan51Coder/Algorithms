//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solve(int n){
	    if(n==0){
	        return 0;
	    }
	    int ans = n;//if only using 1(any number can be represent as sum of square of 1)
	    for(int i = 1; i*i<n;i++){
	        int temp = i*i;
	        ans = min(ans,1+solve(n-temp));
	    }
	    return ans;
	}
	//adding memoization
	int solveMem(int n,vector<int>&dp){
	    if(n==0){
	        return 0;
	    }
	    if(dp[n] != -1){
	        return dp[n];
	    }
	    int ans = n;//if only using 1
	    for(int i = 1; i*i<=n;i++){
	        int temp = i*i;
	        ans = min(ans,1+solveMem(n-temp,dp));
	    }
	    dp[n] = ans;
	    return dp[n];
	}
	//adding tabulation method
	int solveTab(int n){
	    vector<int>dp(n+1,INT_MAX);
	    dp[0]=0;
	    for(int j = 1;j<=n ; j++){
	        for(int i = 1; i*i<=n;i++){
	        int temp = i*i;
	        if(j-temp>=0){//be care
	            dp[j] = min(dp[j],1+dp[j-temp]);
	        }
	     }
	    }
	    return dp[n];
	}
	int MinSquares(int n)
	{
	    // Code here
	   // return solve(n);
	   //vector<int>dp(n+1,-1);
	   //return solveMem(n,dp);
	   return solveTab(n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends