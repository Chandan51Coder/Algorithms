#include <bits/stdc++.h> 

bool isSafe(int x,int y, vector<vector<int>> visited, vector<vector<int>> &m, int n){
        
        if((x>=0 && x<n) &&(y>=0 && y<n) && visited[x][y] ==0 && m[x][y] ==1){
            return true;
        }else{
            return false;
        }
        
    }
        void solve(vector<vector<int>> &m,int n, vector<string>&ans,int x, int y, string path, vector<vector<int>>visited){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        visited[x][y] = 1;
        //down
        int newX = x + 1;
        int newY = y;
        if(isSafe(newX,newY,visited,m,n)){
            path.push_back('D');
            solve(m,n,ans,newX,newY,path,visited);
            //backtracking
            path.pop_back();
        }
        //left
        newX = x;
        newY = y-1;
        if(isSafe(newX,newY,visited,m,n)){
            path.push_back('L');
            solve(m,n,ans,newX,newY,path,visited);
            //backtracking
            path.pop_back();
        }
        //right
        newX = x;
        newY = y+1;
        if(isSafe(newX,newY,visited,m,n)){
            path.push_back('R');
            solve(m,n,ans,newX,newY,path,visited);
            //backtracking
            path.pop_back();
        }
        //up
        newX = x - 1;
        newY = y;
        if(isSafe(newX,newY,visited,m,n)){
            path.push_back('U');
            solve(m,n,ans,newX,newY,path,visited);
            //backtracking
            path.pop_back();
        }
        visited[x][y] = 0;
    }
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
     vector<string> ans;
        int source_x = 0;
        int source_y = 0;
        if(arr[0][0]==0){
            return ans;
        }
        vector<vector<int>> visited = arr;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                visited[i][j]=0;
            }
        }
        string path = "";
        solve(arr,n,ans,source_x, source_y,path,visited);
        sort(ans.begin(),ans.end());
        return ans;
}