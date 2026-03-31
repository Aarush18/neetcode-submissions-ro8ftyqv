class Solution {
private:
   int dfs(int i , int j , vector<vector<bool>>& visited , vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();

        if(i >= n || j >= m || i < 0 || j < 0 || visited[i][j] == true || grid[i][j] == 0){
            return 0;
        }

        visited[i][j] = true;

        return 1 + dfs(i + 1 , j , visited , grid ) 
                + dfs(i , j+ 1 , visited ,grid)
                + dfs(i - 1 , j , visited , grid)
                + dfs(i ,j - 1 , visited , grid);  
   }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n , vector<bool>(m , false));
        int maxi = 0 ;

        for(int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    maxi = max(maxi , dfs(i , j , visited , grid));
                }
            }
        }
        return maxi;
    }
};




