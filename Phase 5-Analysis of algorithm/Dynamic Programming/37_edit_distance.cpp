class Solution {
public:
    int solve(string &a, string &b, int i, int j){
        //base case
        if(i == a.length()){//first string ends(first string length is less than second string.)
            return b.length()-j;//es length ka character insert karane se aa jayege.
        }
        if(j == b.length()){
            return a.length()-i;
        }
        int ans = 0; 
        if(a[i]==b[j]){
            return solve(a,b,i+1,j+1);//if matches then no problem
        }else{
            //increment to dono index hoga
            int insAns = 1 + solve(a,b,i,j+1);//first me insert hua,uska index unchage hoga,because already increment.
            int delAns = 1 + solve(a,b,i+1,j);//i increment but j at same position
            int repAns = 1 + solve(a,b,i+1,j+1);//we assume that replace karane se match kar gaya then we move ahea.
            ans = min(insAns, min(delAns,repAns));
        }
        return ans;
    }
    //adding memoization
    int solveMem(string &a, string &b, int i, int j,vector<vector<int>>&dp){
        //base case
        if(i == a.length()){
            return b.length()-j;
        }
        if(j == b.length()){
            return a.length()-i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0; 
        if(a[i]==b[j]){
            return solveMem(a,b,i+1,j+1,dp);
        }else{
            int insAns = 1 + solveMem(a,b,i,j+1,dp);
            int delAns = 1 + solveMem(a,b,i+1,j,dp);
            int repAns = 1 + solveMem(a,b,i+1,j+1,dp);
            ans = min(insAns, min(delAns,repAns));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    //tabulation and space optimization will be pending..................
    int minDistance(string word1, string word2) {
        // return solve(word1, word2, 0 , 0);
        int l1 = word1.length();
        int l2 = word2.length();
        vector<vector<int>>dp(l1,vector<int>(l2,-1));
        return solveMem(word1, word2, 0 , 0, dp);
    }
};