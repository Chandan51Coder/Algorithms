//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int n, int *a, int curr, int prev){
        if(curr == n){//traversing complete 
            return 0;
        }
        //include
        int take = 0;
        if(prev == -1 || a[curr]>a[prev]){//agar aage koi greater number available hai.
            take = 1 + solve(n,a,curr+1,curr);
        }
        //exclude
        int nonTake = 0 + solve(n,a,curr+1,prev);
        return max(take,nonTake);
    }
    //adding memoization
    int solveMem(int n, int *a, int curr, int prev, vector<vector<int>>&dp){
        if(curr == n){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        //include
        int take = 0;
        if(prev == -1 || a[curr]>a[prev]){
            take = 1 + solveMem(n,a,curr+1,curr,dp);
        }
        //exclude
        int nonTake = 0 + solveMem(n,a,curr+1,prev,dp);
        dp[curr][prev+1] = max(take,nonTake);
        return dp[curr][prev+1];
    }
    //adding tabulation
    int solveTab(int n , int *a){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1;prev--){
                //include
                int take = 0;
                if(prev == -1 || a[curr]>a[prev]){
                    take = 1 + dp[curr+1][curr+1];
                }
                //exclude
                int nonTake = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(take,nonTake);
            }
        }
        return dp[0][-1+1];
    }
    // optimizing space
    int solveSO(int n , int *a){
        vector<int>currv(n+1,0);
        vector<int>nextv(n+1,0);
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1;prev--){
                //include
                int take = 0;
                if(prev == -1 || a[curr]>a[prev]){
                    take = 1 + nextv[curr+1];
                }
                //exclude
                int nonTake = 0 + nextv[prev+1];
                currv[prev+1] = max(take,nonTake);
            }
            nextv = currv;
        }
        return nextv[0];
    }
    // optimal solution
    int solveOpt(int n, int *a){
        if(n==0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(a[0]);
        for(int i = 1; i<n ; i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }else{
                int index = lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
    //   return solve(n,a,0,-1);
    //   vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //   return solveMem(n,a,0,-1,dp);
    // return solveTab(n,a);
    // return solveSO(n,a);
    return solveOpt(n,a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends