class Solution {
private:

    void addSolution(vector<vector<int>>& board , vector<vector<string>>& result){
        vector<string> temp;
        for(int i = 0 ; i < board.size(); i++){
            string row = "";
            for(int j = 0 ; j < board[0].size(); j++){
                if(board[i][j] == 0){
                    row+='.';
                }else{
                    row+='Q';
                }
            }
            temp.push_back(row);
        }
        result.push_back(temp);
    }

    bool isSafe(int row , int col , vector<vector<int>>& board , int n){
        
        int x = row;
        int y = col;

        //left check 
        while(y >= 0){
            if(board[x][y] == 1){
                return false;
            }
            y--;
        }
        x = row;
        y = col;
        
        // upper left diagonal

        while(x>=0 && y>=0){
            if(board[x][y] == 1){
                return false;
            }
            x--;
            y--;
        }

        x = row;
        y = col;

        while(x < n && y >= 0){
            if(board[x][y] == 1){
                return false;
            }
            x++;
            y--;
        }

        return true;
    }
    void solve(int n ,vector<vector<string>>&result ,vector<vector<int>>& board , int col){
        if(col == n){
            addSolution(board , result);
            return;
        }

        for(int row = 0 ; row < n ; row ++){
            if(isSafe(row , col , board , n)){
                board[row][col] = 1;
                solve(n , result , board ,col + 1);
                board[row][col] = 0;
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<int>> board(n , vector<int> (n , 0));

        solve(n , result , board , 0);

        return result;
    }
};
