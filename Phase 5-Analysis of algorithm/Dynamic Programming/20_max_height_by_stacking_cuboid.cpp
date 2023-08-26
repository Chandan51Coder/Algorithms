class Solution {
public:
    bool check(vector<int>base,vector<int>newBox){
        if(newBox[0]<=base[0] && newBox[1]<=base[1] && newBox[2]<=base[2]){
            return true;
        }else{
            return false;
        }
    }
    int solveTab(int n , vector<vector<int>>&a){
       vector<int>currv(n+1,0);
       vector<int>nextv(n+1,0);
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1;prev--){
                //include
                int take = 0;
                if(prev == -1 || check(a[curr],a[prev])){
                    take = a[curr][2] + nextv[curr+1];//calculating maximum heights
                }
                //exclude
                int nonTake = 0 + nextv[prev+1];
                currv[prev+1] = max(take,nonTake);
            }
            nextv = currv;
        }
        return nextv[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
    //step 1: sort all the dimention for every cuboid
    for(auto &a: cuboids){//for actual change in vectors use the & operator.
        sort(a.begin(),a.end());
    }
    //step 2: sort all cuboids basis on w or l
    sort(cuboids.begin(),cuboids.end());
    //use LIS logic
    return solveTab(cuboids.size(),cuboids);
    }
};