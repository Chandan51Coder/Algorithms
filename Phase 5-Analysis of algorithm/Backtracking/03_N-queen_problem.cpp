#include<bits/stdc++.h>


void addSol(vector<vector<int>> &board,vector<vector<int>> &ans,int n){
    vector<int>temp;
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<n; j++){
            temp.push_back(board[i][j]);//there can be many answer possible 
        }
    }
    ans.push_back(temp);//storing each answer in the vector.
    
    // for(int i = 0; i<ans.size();i++){
    //     for(j = 0; j<i.size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
bool isSafe(int row,int col, vector<vector<int>> &board, int n){
    //no need to check the col and right part (till queen placed)
    //mai fill hee left to right kar raha hoon so no need to check right direction.
    //Queen to hame left wale part me hee milengi.
    int x = row;
    int y = col;
    //checking the row
    while(y>=0){
        // cout<<"row"<<endl;
        if(board[x][y]==1){
            return false;//agar kisi bhi column par queen mil jati hai then return false.
        }
        y--;
    }
    x = row;
    y = col;
    //checking the upper diagoanl 
    while(x>= 0 && y>=0){//
        // cout<<"upper diagonal"<<endl;
        if(board[x][y]==1){
            return false;//agar kisi bhi column par queen mil jati hai then return false.
        }
        x--;
        y--;
    }
    x = row;
    y = col;
    //checking the lower diagonal
    while(x<n && y>=0){
        // cout<<"lower diagonal"<<endl;
        if(board[x][y]==1){
            return false;
        }
        y--;
        x++;
    }
    return true;
}
void solve(int col,  vector<vector<int>> &ans,vector<vector<int>> &board,int n){
    if(col==n){//all travers add solution in answer board.
        // cout<<"col==n"<<endl;
        addSol(board,ans,n);//imp
        return;
    }
    //recursion and backtracking
    for(int row = 0; row<n ; row++){
        if(isSafe(row,col,board,n)){
            // cout<<"issafe"<<endl;
            //recursion 
            board[row][col] = 1;// placing the queen if it is safe place.
            solve(col+1,ans,board,n);
             //backtrack
            board[row][col] = 0;//if the placed place is not safe by other queen then remove the queen from that place.
        }
           
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    //intialize a 2D vector with all zero (initializing a board)
    vector<vector<int>>board(n,vector<int>(n,0));
    // ans vector(queen borad)
    vector<vector<int>> ans;
    solve(0,ans,board,n);//0th column and total n row
    return ans;
}