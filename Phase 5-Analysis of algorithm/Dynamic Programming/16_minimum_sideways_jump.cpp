class Solution {
public:
    int solve(vector<int>& obs,int currlane, int currpos){
        int n = obs.size();
        if(currpos == n){//pahuch gaye return zero.
            return 0;
        }
        if(obs[currpos+1] != currlane){//rasta saaf hai. usi raste par aage badho.
            return solve(obs,currlane,currpos+1);
        }else{
            int ans = INT_MAX;
            for(int i = 1 ; i<=3; i++){// 1 ,2,3 par hee check karenge.
                if(currlane != i && obs[currpos] != i){//kis raste par pathar nahi hai.
                    ans = min(ans,1+solve(obs,i,currpos));//calculating the number of the jump.
                }
            }
            return ans;
        }
    }
    //adding memoization
    int solveMem(vector<int>& obs,int currlane, int currpos,vector<vector<int>>&dp){
        int n = obs.size()-1;
        if(currpos == n){
            return 0;
        }
        if(dp[currlane][currpos] != -1){
            return dp[currlane][currpos];
        }
        if(obs[currpos+1] != currlane){
            return solveMem(obs,currlane,currpos+1,dp);
        }else{
            int ans = INT_MAX;
            for(int i = 1 ; i<=3; i++){
                if(currlane != i && obs[currpos] != i){
                    ans = min(ans,1+solveMem(obs,i,currpos,dp));
                }
            }
            dp[currlane][currpos] = ans;
            return dp[currlane][currpos];
        }
    }
    //tabulation and space optimization will pending................................
    int minSideJumps(vector<int>& obstacles) {
        //start from middle way
        //whenever min ans required we will use the INT_MAX value for initilization
        // return solve(obstacles,2,0);
        vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));
        return solveMem(obstacles,2,0,dp);
    }
};