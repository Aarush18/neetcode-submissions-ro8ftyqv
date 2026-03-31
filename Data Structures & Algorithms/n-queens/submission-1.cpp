class Solution {
private:
    void addSolution(vector<vector<string>>& res , vector<vector<int>>& board){
        vector<string> temp;
        for(int i = 0 ; i < board.size(); i++){
            string output = "";
            for(int j = 0 ; j < board[0].size(); j++){
                if(board[i][j] == 0){
                    output+=".";
                }else {
                    output+="Q";
                }
            }
            temp.push_back(output);
        }
        res.push_back(temp);
    }

    bool isSafe(int row , int col , vector<vector<int>>& board){
        int x = row;
        int y = col;

        // we have to check 3 paths from here , ek toh sidha left , ek diagonally upar , ek diagonally niche

        while(y >= 0){
            if(board[x][y] == 1){
                return false;
            }
            y--;
        }

        y = col;

        while(x < board.size() && y >= 0){
            if(board[x][y] == 1){
                return false;
            }
            x++;
            y--;
        }
        
        x = row;
        y = col;

        while(x >= 0 && y >= 0){
            if(board[x][y] == 1){
                return false;
            }
            x--;
            y--;
        }

        return true;
    }
    void solve(int col , vector<vector<int>>& board, vector<vector<string>>& res , int n){
        if(col == n){
            addSolution(res , board);
            return;
        }

        for(int row = 0 ; row < n ; row++){
            if(isSafe(row , col , board)){  
                board[row][col] = 1;
                solve(col + 1 , board , res , n);
                board[row][col] = 0;
            } 
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<int>> board(n , vector<int>(n , 0));

        solve(0 , board , res , n);

        return res;
    }
};
