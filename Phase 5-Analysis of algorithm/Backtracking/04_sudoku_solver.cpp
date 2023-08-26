#include <bits/stdc++.h> 
bool isSafe(int row, int col, vector<vector<int>>& board,int val){
    for(int i = 0; i< 9; i++){
        if(board[row][i]==val){//jo hamne value insert kiya hai, agar voh pahale se present hai toh return false.
            return false;
        }
        if(board[i][col]==val){
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }
    }
    return true;//if not present already then return true.  
}
bool solve(vector<vector<int>>& board){
    int n = board.size();
    //loop for matrix traversal
    for(int row = 0; row < n; row++){
        //loop for col traversal
        for(int col = 0; col< n; col++){
            if(board[row][col]==0){//jaise koi cell empty milati hai
                for(int val = 1; val<=9; val++ ){//try with all value 1 to 9.
                    if(isSafe(row,col,board,val)){
                        board[row][col] = val;//put that value in the board.
                        bool nextStep = solve(board);//next possible solution.
                        if(nextStep){
                            return true;
                        }else{
                            //backtrack
                            board[row][col] = 0;//nahi toh jo value put kiya tha replace with zero.
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}