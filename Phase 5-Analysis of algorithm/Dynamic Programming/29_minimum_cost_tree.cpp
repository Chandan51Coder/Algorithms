class Solution {
public:
    int solve(vector<int>&arr,map<pair<int,int>,int>&maxi,int left, int right){
        //leaf node
        if(left == right){//you are at leaf node.
            return 0;//can't generate non leaf node hence 0
        }
        int ans= INT_MAX;
        for(int i =left ; i<right; i++){//partition between left and right thru i. 
            ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}]+solve(arr,maxi,left,i)+solve(arr,maxi,i+1,right));
            //since we want to find the maximum number from left and right sub tree.
        }
        return ans;
    }
    //adding memoization
    int solveMem(vector<int>&arr,map<pair<int,int>,int>&maxi,int left, int right,vector<vector<int>>&dp){
        //leaf node
        if(left == right){
            return 0;
        }
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int ans= INT_MAX;
        for(int i =left ; i<right; i++){
            ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}]+solveMem(arr,maxi,left,i,dp)+solveMem(arr,maxi,i+1,right,dp));
        }
        dp[left][right] = ans;
        return dp[left][right];
    }
    // tabulation will be pending ................
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>maxi;//for the leaf nodes
        int n = arr.size();
        for(int i = 0; i<arr.size();i++){
            maxi[{i,i}] = arr[i];//if both same it denotes the leaf node.(current value)
            for(int j = i+1;j<arr.size();j++){//basically two different index ke betweem we want to find maxi.
                maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);//current value ko previous value se compare karana hai.
                //i to j ke range me maxium value store kar rahe hai.
            }
        }
        return solve(arr,maxi,0,n-1);//left and right index.
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1)); 
        return solveMem(arr,maxi,0,arr.size()-1,dp);

    }
};