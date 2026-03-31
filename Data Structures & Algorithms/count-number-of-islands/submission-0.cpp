class Solution {
private:
    void dfs(int i , int j , vector<vector<bool>>& visited , vector<vector<char>>&grid){
       int n = grid.size();
       int m = grid[0].size();

       if(i >= n || j >= m || i < 0 || j < 0 || visited[i][j] == true || grid[i][j] == '0'){
         return ;
       }

       visited[i][j] = true;

        dfs(i + 1 , j , visited , grid);
        dfs(i , j+1 , visited ,grid); 
        dfs(i-1 , j , visited , grid) ;
        dfs(i , j - 1 , visited , grid) ;

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n , vector<bool>(m , false));
        int cnt = 0 ;

        for(int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    cnt++;
                    dfs(i , j , visited , grid);
                }
            }
        }
        return cnt;
    }
};
