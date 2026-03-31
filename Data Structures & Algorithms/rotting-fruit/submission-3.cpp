class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int , int>> q;

        int fresh = 0;

        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        
        vector<pair<int , int>> dirs = {{0 ,1} , {1 , 0} ,{-1 , 0} , {0 , -1}};

        int mins = 0;
        while(!q.empty()){
            int size = q.size();
            bool rotten = false;

            for(int i = 0 ; i < size; i++){

                auto [x , y] = q.front();
                q.pop();

                for(auto [dx , dy] : dirs){
                    int nx = x + dx;
                    int ny = y + dy;

                    if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx , ny});
                        fresh--;
                        rotten = true;
                    }
                }
            }
            if(rotten) mins++;

        }

        if(fresh > 0){
            return -1;
        }
        return mins;
    }
};
