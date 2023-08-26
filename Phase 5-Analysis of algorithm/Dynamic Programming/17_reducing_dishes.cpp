#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& sat,int index, int time){
        if(index == sat.size()){//all diishes are covered
            return 0;
        }
        int inc = sat[index]*(time+1) + solve(sat,index+1,time+1);
        int exc = 0 + solve(sat,index+1,time);
        return max(inc,exc);
    }
    //adding memoization
    int solveMem(vector<int>& sat,int index, int time,vector<vector<int>>&dp){
        if(index == sat.size()){
            return 0;
        }
        if(dp[time][index] != -1){
            return dp[time][index];
        }
        int inc = sat[index]*(time+1) + solveMem(sat,index+1,time+1,dp);
        int exc = 0 + solveMem(sat,index+1,time,dp);
        dp[time][index] = max(inc,exc);
        return dp[time][index];
    }
    //using tabulation method
    int solveTab(vector<int>&sat){
        int n = sat.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int index = n-1; index>= 0; index--){
            for(int time = index; time>=0; time--){
                int inc = sat[index]*(time+1) + dp[index+1][time+1];
                int exc = 0 + dp[index+1][time];
                dp[index][time] = max(inc,exc);
            }
        }
        return dp[0][0];
    }
    //optimizing space
    int solveSO(vector<int>&sat){
        int n = sat.size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        
        for(int index = n-1; index>= 0; index--){
            for(int time = index; time>=0; time--){
                int inc = sat[index]*(time+1) + next[time+1];
                int exc = 0 + next[time];
                curr[time] = max(inc,exc);
            }
            next = curr;
        }
        return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        //sorting 
        sort(satisfaction.begin(),satisfaction.end());
        // return (satisfaction,0,0);
        // int n = satisfaction.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solveMem(satisfaction,0,0,dp);
        // return solveTab(satisfaction);
        return solveSO(satisfaction);
    }
};