//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int coins[],int N, int sum){
        if(sum<0){
            return 0;
        }
        if(sum==0){
            return 1;
        }
        if(N<=0){
            return 0;
        }
        return solve(coins,N,sum-coins[N-1])+solve(coins,N-1,sum);
    }
    long long int solveMemo(int coins[],int N, int sum,vector<vector<long long int>>&dp){
        if(sum<0){
            return 0;
        }
        if(sum==0){
            return 1;
        }
        if(N<=0){
            return 0;
        }
        if(dp[N][sum] != -1){
            return dp[N][sum];
        }
        dp[N][sum] = solveMemo(coins,N,sum-coins[N-1],dp)+solveMemo(coins,N-1,sum,dp);
        return dp[N][sum];
    }
    
    
    long long int count(int coins[], int N, int sum) {
        // code here.
        // return solve(coins,N,sum);
        // vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,-1));
        // return solveMemo(coins,N,sum,dp);
        return solveTab(coins,N,sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends