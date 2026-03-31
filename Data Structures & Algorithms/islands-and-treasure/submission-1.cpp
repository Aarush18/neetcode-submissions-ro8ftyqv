class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int , int>> q;

        int n = grid.size();
        int m = grid[0].size();

        vector<pair <int,int>> directions = {{0 , 1} , {1 , 0} , {0 , -1} , {-1 , 0}};

        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0){
                    q.push({i , j});
                }
            }
        }

        while(!q.empty()){
            auto x = q.front().first;
            auto y = q.front().second;
            q.pop();

            for(auto [dx , dy] : directions){
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] ==2147483647){
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx , ny});
                }
            }
        }

    }
};
