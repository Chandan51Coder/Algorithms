//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int index, int *arr, int N, int target){
        if(index>=N){//all element process.
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        bool inc = solve(index+1,arr,N,target-arr[index]);
        bool exc = solve(index+1,arr,N,target-0);
        return (inc || exc);
    }
    //adding memoization
    bool solveMem(int index, int *arr, int N, int target,vector<vector<int>>&dp){
        if(index>=N){
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        bool inc = solveMem(index+1,arr,N,target-arr[index],dp);
        bool exc = solveMem(index+1,arr,N,target-0,dp);
        dp[index][target] = (inc || exc);
        return dp[index][target];
    }
    //tabulation and space optimization will be pending...................
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i<N; i++){
            sum+=arr[i];
        }
        if(sum & 1){
            return 0;
        }
        int target = sum/2;
        // return solve(0,arr,N,target);
        vector<vector<int>>dp(N+1,vector<int>(target+1,-1));
        return solveMem(0,arr,N,target,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends