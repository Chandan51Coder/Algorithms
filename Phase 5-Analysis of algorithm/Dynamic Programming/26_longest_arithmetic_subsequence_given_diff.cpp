class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>dp;
        int ans= 0;
        for(int i = 0; i<arr.size(); i++){
            int temp = arr[i]-difference;//find the behind element.agar es temp ke sath dp me answer mil jaye then add with one.
            int tempAns = 0;
            if(dp.count(temp)){//check answer exist for temp already or not.
                tempAns = dp[temp];//jaha par khade hai uske behind element ke a.p. ka length.
            }
            dp[arr[i]] = 1 + tempAns;//updating answer for current element.
            ans = max(ans,dp[arr[i]]);//update the answer.
        }
        return ans;
    }
};