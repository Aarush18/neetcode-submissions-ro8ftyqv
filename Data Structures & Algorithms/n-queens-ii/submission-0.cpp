class Solution {
    int cnt = 0 ;
private:
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
    void solve(int col , vector<vector<int>>& board , int n){
        if(col == n){
            cnt++;
            return;
        }

        for(int row = 0 ; row < n ; row++){
            if(isSafe(row , col , board)){  
                board[row][col] = 1;
                solve(col + 1 , board , n);
                board[row][col] = 0;
            } 
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<int>> board(n , vector<int>(n , 0));
        solve(0 , board , n);
        return cnt;
    }
};