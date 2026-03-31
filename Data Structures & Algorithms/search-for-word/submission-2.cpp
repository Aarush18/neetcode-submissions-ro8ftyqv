class Solution {
private:
    bool dfs(int i , int j , vector<vector<char>>& board , string word ,vector<vector<bool>>& visited , int ind){

        int n = board.size();
        int m = board[0].size();
        
        if(i >= n || j >= m || i < 0 || j < 0 || visited[i][j] == true || board[i][j] != word[ind]){
            return false;
        }

        if(ind == word.size() - 1){
            return true;
        }

        visited[i][j] = true;

        bool found =  dfs(i + 1, j , board , word , visited , ind + 1) || dfs(i , j - 1, board , word , visited , ind + 1) 
        || dfs(i - 1, j , board , word , visited , ind + 1) || dfs(i , j + 1 , board , word , visited , ind + 1);

        visited[i][j] = false;

        return found ;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n , vector<bool>(m , false));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(dfs(i , j , board , word , visited , 0) == true){
                    return true;
                }
            }
        }

        return false;

    }
};
