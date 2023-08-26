// recursion and memoization

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int index, int diff , vector<int>&nums){
        if(index < 0){//traverse all elements
            return 0;
        }
        int ans = 0;
        for(int j = index-1; j>=0; j--){//yaha backward se ham check rahe hai is any element with common difference.
            if(nums[index]-nums[j] == diff){//common difference wala ek element mil gaya.
                ans = max(ans,1+solve(j,diff,nums));//picche bhi toh answer ho sakata hai.
            }
        }
        return ans;
    }
    //adding memoization
    int solveMem(int index, int diff , vector<int>&nums,unordered_map<int,int>dp[]){
        if(index < 0){
            return 0;
        }
        if(dp[index].count(diff)){
            return dp[index][diff];//till i index the length of longest matrix with common difference diff "kitani hai."
            //diff depends on index
            //on each index there can be multiple diff
        }
        int ans = 0;
        for(int j = index-1; j>=0; j--){
            if(nums[index]-nums[j] == diff){
                ans = max(ans,1+solveMem(j,diff,nums,dp));
            }
        }
        dp[index][diff]=ans;
        return dp[index][diff];
    }
    //adding tabulation method
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        //adding memoization with hashing
        unordered_map<int,int>dp[n+1];
        if(n <= 2){
            return n;
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                // ans = max(ans,2 + solve(i,nums[j]-nums[i],nums));//ye do already a.p. me hai.
                ans = max(ans,2 + solveMem(i,nums[j]-nums[i],nums,dp));
            }
        }
        return ans;
    }
};

// tabulation method
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return n;
        }
        int ans = 0;
        unordered_map<int,int>dp[n+1];
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                int diff = nums[i]-nums[j];
                int count = 1;//ith element a.p. me toh aayega hee aayega.
                if(dp[j].count(diff)){//kya j par es difference ke sath answer pada hua hai.
                    count = dp[j][diff];//count ko update kar dena.
                }
                dp[i][diff] = 1 + count;//update the actual answer.
                ans = max(ans,dp[i][diff]);//update the max
            }
        }
        return ans;
    }
};