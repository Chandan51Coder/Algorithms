class Solution {
    //the logic is same as LCS, in place of another string we will place the reverse of the string.
public:
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
    int longestPalindromeSubseq(string s) {
        string revStr = s;
        reverse(revStr.begin(),revStr.end());
        return solveSO(s,revStr);
    }
};