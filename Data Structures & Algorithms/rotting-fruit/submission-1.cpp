class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int , int>> q;

        int fresh = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int mins = 0 ;

        vector<pair<int , int>> dirs = {{0 ,1} , {1 , 0} ,{-1 , 0} , {0 , -1}};

        while(!q.empty()){

            int size = q.size();
            bool rotted = false;

            for(int i = 0 ; i < size ; i++){

            auto [x , y] = q.front();
            q.pop();
            

            for(auto [dx , dy] : dirs){
                int nx = x + dx; 
                int ny = y + dy;

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx , ny});
                    rotted = true;
                }
                }
            }
            if(rotted) mins++;
        }

        if(fresh == 0){
            return mins;
        }else{
            return -1;
        }
    }
};
