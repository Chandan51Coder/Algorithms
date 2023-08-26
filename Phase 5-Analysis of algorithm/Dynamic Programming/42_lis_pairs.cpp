class Solution {
public:
    int n;
    int t[1001][1001];
    
    int lis(vector<vector<int>>& nums, int prev, int curr) {
       if(curr == n)
           return 0;
        
        if(prev != -1 && t[prev][curr] != -1)
            return t[prev][curr];
        
        int taken = 0;
        if(prev == -1 || nums[curr][0] > nums[prev][1])
            taken = 1 + lis(nums, curr, curr+1);
        
        int not_taken = lis(nums, prev, curr+1);
        
        if(prev != -1)
            t[prev][curr] =  max(taken, not_taken);
        
        return max(taken, not_taken);
            
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(t, -1, sizeof(t));
        n = pairs.size();
        sort(begin(pairs), end(pairs)); //You can select pairs in any order.
        return lis(pairs, -1, 0);
    }
};