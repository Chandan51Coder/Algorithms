class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped){
        //base case
        if(index == nums1.size()){
            return 0;
        }
        int ans = INT_MAX;
        int p1 = nums1[index-1];//getting the previous element.
        int p2 = nums2[index-1];
        if(swapped){
            swap(p1,p2);
        }
        //no swap
        if(p1<nums1[index] && p2<nums2[index]){//if previous index's value less than next then no swap.
            ans = solve(nums1,nums2,index+1,0);//move ahead.
        }
        //if apne next se small nahi hai then check that is it smaller that another array next if yes preform swap.
        if(p2<nums1[index] && p1<nums2[index]){//perform swap
            ans = min(ans,1+solve(nums1,nums2,index+1,1));
        }
        return ans;
    }
    //adding memoization
    int solveMem(vector<int>& nums1, vector<int>& nums2, int index, bool swapped,vector<vector<int>>&dp){
        //base case
        if(index == nums1.size()){
            return 0;
        }
        if(dp[index][swapped] != -1){
            return dp[index][swapped];
        }
        int ans = INT_MAX;
        int p1 = nums1[index-1];
        int p2 = nums2[index-1];
        if(swapped){
            swap(p1,p2);
        }
        //no swap
        if(p1<nums1[index] && p2<nums2[index]){
            ans = solveMem(nums1,nums2,index+1,0,dp);
        }
        if(p2<nums1[index] && p1<nums2[index]){
            ans = min(ans,1+solveMem(nums1,nums2,index+1,1,dp));
        }
        dp[index][swapped] = ans;
        return dp[index][swapped];
    }
    //adding tabulation method
    int solveTab(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int index = n-1; index>=1; index--){
            for(int swapped = 1;swapped>=0; swapped--){
                int ans = INT_MAX;
                int p1 = nums1[index-1];
                int p2 = nums2[index-1];
                if(swapped){
                    swap(p1,p2);
                }
                //no swap
                if(p1<nums1[index] && p2<nums2[index]){
                    ans = dp[index+1][0];
                }
                if(p2<nums1[index] && p1<nums2[index]){
                    ans = min(ans,1+dp[index+1][1]);
                }
                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }
    //using space optimization
    int solveSO(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for(int index = n-1; index>=1; index--){
            for(int swapped = 1;swapped>=0; swapped--){
                int ans = INT_MAX;
                int p1 = nums1[index-1];
                int p2 = nums2[index-1];
                if(swapped){
                    swap(p1,p2);
                }
                //no swap
                if(p1<nums1[index] && p2<nums2[index]){
                    ans = next[0];
                }
                if(p2<nums1[index] && p1<nums2[index]){
                    ans = min(ans,1+next[1]);
                }
                curr[swapped] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //s1: inserting -1 at the very beginning of both array
        int n = nums1.size();
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool swapped = 0;
        // return solve(nums1,nums2,1,swapped);
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return solveMem(nums1,nums2,1,swapped,dp);
        // return solveTab(nums1,nums2);
        return solveSO(nums1,nums2);
    }
};