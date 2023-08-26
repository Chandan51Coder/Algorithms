class Solution {
public:
    int solve(string &a, string &b, int i , int j){
        if( i == a.length()){
            return 0;
        }
        if( j == b.length()){
            return 0;
        }
        int ans = 0;
        if(a[i] == b[j]){
            ans = 1+solve(a,b,i+1,j+1);//if character matches in both string, increment and move ahead on both string.
        }else{
            ans = max(solve(a,b,i+1,j),solve(a,b,i,j+1));// if not match first increment first string and check another and vice-versa.
        }
        return ans;
    }
    //adding memoization 
    int solveMem(string &a, string &b, int i , int j, vector<vector<int>>&dp){
        if( i == a.length()){
            return 0;
        }
        if( j == b.length()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(a[i] == b[j]){
            ans = 1+solveMem(a,b,i+1,j+1,dp);
        }else{
            ans = max(solveMem(a,b,i+1,j,dp),solveMem(a,b,i,j+1,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    //using tabulation
    int solveTab(string &a, string &b){
        int l1 = a.length();
        int l2 = b.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        for(int i = l1-1; i>= 0; i--){
            for(int j = l2-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1+dp[i+1][j+1];
                }else{
                    ans = max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    //optimizing space
    int solveSO(string &a, string &b){
        int l1 = a.length();
        int l2 = b.length();
        vector<int>curr(l2+1,0);
        vector<int>next(l2+1,0);
        for(int i = l1-1; i>= 0; i--){
            for(int j = l2-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1+next[j+1];
                }else{
                    ans = max(next[j],curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // return solve(text1, text2, 0, 0);
        // int length1 = text1.length();
        // int length2 = text2.length();
        // vector<vector<int>>dp(length1,vector<int>(length2,-1));
        // return solveMem(text1, text2, 0, 0, dp);
        // return solveTab(text1, text2);
        return solveSO(text1, text2);
    }
};