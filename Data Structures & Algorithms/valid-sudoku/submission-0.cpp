class Solution {
private: 
    bool isSafe(int row , int col ,vector<vector<char>>& board , char val , int n){

        for(int i = 0 ; i < n ; i++){
            if(i!=col && board[row][i] == val){
                return false;
            }
            if(i!=row && board[i][col] == val ){
                return false;
            }
            if((3*(row/3) + i/3 != row || 3*(col/3) + i % 3 != col) && board[3*(row/3) + i/3][3*(col/3) + i % 3] == val){
                return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(isSafe(i , j , board , board[i][j] , n) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
