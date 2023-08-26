//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int dice,int faces,int target){
        if(target<0){
            return 0;
        }
        if(dice == 0 && target != 0){
            return 0;
        }
        if(target == 0 && dice != 0){
            return 0;
        }
        if(target == 0 && dice == 0){
            return 1;
        }
        long long int ans = 0;
        for(int i = 1; i<=faces; i++){
            ans += solve(dice-1,faces,target-i);
        }
        return ans;
    }
    //adding memoization
    long long int solveMem(int dice,int faces,int target,vector<vector<long long int>>&dp){
        if(target<0){
            return 0;
        }
        if(dice == 0 && target != 0){//dice khatam but target not achieved.
            return 0;
        }
        if(target == 0 && dice != 0){//poori dices ko utilize nahi kar paye.
            return 0;
        }
        if(target == 0 && dice == 0){
            return 1;
        }
        if(dp[dice][target] != -1){
            return dp[dice][target];
        }
        long long int ans = 0;
        for(int i = 1; i<=faces; i++){
            ans += solveMem(dice-1,faces,target-i,dp);
        }
        dp[dice][target] = ans;
        return dp[dice][target];
    }
    //tabulation and space optizing will be pending...................
    long long noOfWays(int M , int N , int X) {
        // code here
        // return solve(N,M,X);
        vector<vector<long long int>>dp(N+1,vector<long long int>(X+1,-1));
        return solveMem(N,M,X,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends