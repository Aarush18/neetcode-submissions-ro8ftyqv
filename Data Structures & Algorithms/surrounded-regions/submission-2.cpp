class Solution {
private:
    void dfs(int i , int j , vector<vector<bool>>& safety , vector<vector<char>>& board){

        int n = board.size();
        int m = board[0].size();

        if( i >= n || j >= m || i < 0 || j < 0 || board[i][j] == 'X' || safety[i][j]){
            return;
        }

        safety[i][j] = true;

        dfs(i+1 , j , safety , board);
        dfs(i , j+1 , safety , board);
        dfs(i -1 , j , safety, board);
        dfs(i , j - 1 , safety , board);
    }
public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> safety(n , vector<bool>(m , false));

        for(int i = 0 ; i < n ; i++){
            if(board[i][0] == 'O'){
                dfs(i , 0 , safety , board);
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(board[i][m-1] == 'O'){
                dfs(i , m - 1 , safety , board);
            }
        }

        for(int i = 0 ; i < m ; i++){
            if(board[0][i] == 'O'){
                dfs(0 , i , safety , board);
            }
        }

        for(int i = 0 ; i < m ; i++){
            if(board[n - 1][i] == 'O'){
                dfs( n - 1 , i , safety , board);
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == 'O' && safety[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
