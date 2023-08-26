class Solution {
public:
    
    int solve(vector<int>&values, int i , int j){
        //base case
        if(i+1==j){//last point
            return 0;
        }
        int ans = INT_MAX;
        for(int k = i+1; k<j; k++){
            ans = min(ans,values[i]*values[j]*values[k]+solve(values,i,k)+solve(values,k,j));
        }
        return ans;
    }
    //adding memoization
    int solveMem(vector<int>&values, int i , int j,vector<vector<int>>&dp){
        //base case
        if(i+1==j){//last point
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k = i+1; k<j; k++){
            ans = min(ans,values[i]*values[j]*values[k]+solveMem(values,i,k,dp)+solveMem(values,k,j,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    //using tabulation method
    int solveTab(vector<int>&values){
        //base case
        int n = values.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i = n-1; i>=0; i--){
            for(int j = i+2; j<n; j++){//for triangle minimum three point required
                int ans = INT_MAX;
                for(int k = i+1; k<j; k++){
                ans = min(ans,values[i]*values[j]*values[k]+dp[i][k]+dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        
        return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n  = values.size();
        // return solve(values,0,n-1);
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return solveMem(values,0,n-1,dp);
        return solveTab(values);
    }
};